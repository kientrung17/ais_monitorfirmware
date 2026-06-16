# Đặc tả logic hoạt động - Mạch Monitor 3 Pha (Cập nhật)

Tài liệu này đặc tả chi tiết logic xử lý phần mềm mới cho mạch Monitor, bao gồm việc đo dòng đơn, giả lập Oxy/pH mịn màng (tránh nhiễu biểu đồ) và truyền dữ liệu qua LoRa.

---

## 1. Logic Đo Đạc & Mô Phỏng Cảm Biến

Để tối ưu hóa phần cứng và báo cáo khoa học, mạch Monitor được cấu hình hoạt động như sau:

### 1.1. Đo Dòng Điện Tải Thực Tế (Chỉ dùng CT_CH1)
*   **Chân kết nối:** GPIO 36 (ADC1_CH0 - nhãn `CT_CH1`)
*   **Logic đo đạc:**
    *   Lấy mẫu burst tần số cao liên tục trong 100ms để bắt trọn sóng sin 50Hz của dòng AC.
    *   Sử dụng thuật toán RMS để tính dòng hiệu dụng thực tế đưa vào biến `ampe_ch1`.
    *   Hai kênh dòng còn lại (`CT_CH2` và `CT_CH3`) tạm thời không xử lý do phần cứng giới hạn.

### 1.2. Mô Phỏng Dữ Liệu Cảm Biến Oxy (DO) và pH (Smooth Simulation)
Vì phần cứng không gắn cảm biến vật lý nhưng báo cáo cần hiển thị dữ liệu sinh động, hệ thống sử dụng thuật toán mô phỏng hình Sin (Smooth Simulation) để giả lập dữ liệu sinh học mịn màng theo thời gian thực (tuyệt đối không dùng hàm `random()` ngẫu nhiên vô tội vạ để tránh làm rác biểu đồ):

*   **Mô phỏng pH:**
    *   Tạo hàm biến thiên mịn trong dải **7.5 đến 8.5** mô phỏng chu kỳ pH tăng nhẹ buổi chiều (do tảo quang hợp hấp thụ CO2) và giảm nhẹ buổi sáng:
        $$pH(t) = 8.0 + 0.4 \times \sin(\omega t) + \text{nhiễu\_nhẹ}$$
*   **Mô phỏng Oxy hòa tan (DO):**
    *   Tạo hàm biến thiên mịn trong dải **5.0 đến 7.5 mg/L** mô phỏng chu kỳ Oxy cạn dần về đêm (do sinh vật hô hấp) và tăng lại ban ngày (do quang hợp):
        $$DO(t) = 6.25 + 1.1 \times \sin(\omega t + \phi) + \text{nhiễu\_nhẹ}$$

---

## 2. Mô Hình Truyền Tải Không Dây (LoRa ➡️ Bridge ➡️ ESP-NOW)

Mô hình truyền thông của hệ thống được tái cấu trúc thành 2 chặng thông qua mạch trung gian (Bridge):

```mermaid
graph LR
    Monitor[Mạch Monitor] -- "1. Sóng LoRa" --> Bridge[Mạch Bridge Trung Gian]
    Bridge -- "2. Sóng ESP-NOW" --> Control[Mạch Gateway / ControlHub]
```

### 2.1. Chặng 1: Truyền từ Monitor sang Bridge (Sử dụng LoRa)
*   Mạch Monitor được trang bị khối phát sóng không dây LoRa kết nối qua SPI:
    *   `MISO_LORA` $\rightarrow$ GPIO 21
    *   `MOSI_LORA` $\rightarrow$ GPIO 23
    *   `SCK_LORA` $\rightarrow$ GPIO 19? (theo sơ đồ chân `common.h`)
    *   `NSS_LORA` $\rightarrow$ GPIO 13 (chân chọn chip)
    *   `RESET_LORA` $\rightarrow$ GPIO 14
    *   `IRQ_LORA` $\rightarrow$ GPIO 27
*   Định kỳ mỗi 5 - 10 giây, Monitor đóng gói gói tin trạng thái (gồm dòng tải thực tế, Oxy/pH mô phỏng và bitmask mất pha) rồi phát đi qua sóng **LoRa**.

### 2.2. Chặng 2: Trung chuyển tại mạch Bridge (LoRa ➡️ ESP-NOW)
*   **Mạch Bridge** đóng vai trò là trạm trung chuyển trung gian đặt ở vị trí thuận lợi:
    1.  Nhận gói tin chứa dữ liệu Monitor qua sóng **LoRa**.
    2.  Trích xuất dữ liệu, chuyển đổi định dạng và đóng gói lại thành struct `EspNowMonitorPayload` của ESP-NOW.
    3.  Phát gói tin **ESP-NOW** đến mạch Gateway (`controlhub`) để cập nhật lên Cloud và App.
