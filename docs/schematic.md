# Bản đồ chân & Sơ đồ phần cứng MCU - Mạch Monitor 3 Pha

Tài liệu này ghi chú chi tiết sơ đồ chân kết nối của MCU **ESP32 WROOM 32 (U8)** dựa trên bản vẽ nguyên lý phần cứng thiết bị.

---

## 1. Bản đồ chân kết nối MCU (U8 Pinout Mapping)

| Chân MCU | Tên Trên Mạch | Hướng IO | Chức Năng Chi Tiết |
| :--- | :--- | :--- | :--- |
| **SENSOR_VP (Pin 4)** | `CT_CH1` | Input (ADC1_CH0) | Đo dòng điện Pha 1 (Cảm biến dòng CT) |
| **SENSOR_VN (Pin 5)** | `CT_CH2` | Input (ADC1_CH3) | Đo dòng điện Pha 2 (Cảm biến dòng CT) |
| **IO34 (Pin 6)** | `CT_CH3` | Input (ADC1_CH6) | Đo dòng điện Pha 3 (Cảm biến dòng CT) |
| **IO35 (Pin 7)** | `CHECK_BAT` | Input (ADC1_CH7) | Đo điện áp pin dự phòng (Cầu phân áp trở) |
| **IO32 (Pin 8)** | `ADC_V_RMS` | Input (ADC1_CH4) | Đo điện áp AC hiệu dụng của lưới điện |
| **IO33 (Pin 9)** | `PHA1` | Input (GPIO 33) | Phát hiện trạng thái Pha 1 (Cách ly quang) |
| **IO25 (Pin 10)** | `PHA2` | Input (GPIO 25) | Phát hiện trạng thái Pha 2 (Cách ly quang) |
| **IO26 (Pin 11)** | `PHA3` | Input (GPIO 26) | Phát hiện trạng thái Pha 3 (Cách ly quang) |
| **IO21 (Pin 33)** | `DS18B20` | Bi-directional (GPIO 21)| Giao tiếp cảm biến nhiệt độ 1-Wire DS18B20 |
| **IO18 (Pin 30)** | `CTR_COI` | Output (GPIO 18) | Điều khiển còi chip cảnh báo (Buzzer) |
| **IO2 (Pin 24)** | `Led Status` | Output (GPIO 2) | LED hiển thị trạng thái hoạt động của mạch |
| **IO15 (Pin 23)** | `BTN Mode Reset`| Input (GPIO 15) | Nút nhấn cấu hình chế độ / Reset cài đặt |

---

## 2. Ghi chú khối chức năng phần cứng

### 2.1. Khối truyền thông không dây LoRa (Sẵn sàng mở rộng)
Dựa trên schematic, mạch có thiết kế sẵn các đường kết nối LoRa nối vào bus SPI và các chân điều khiển của ESP32:
*   `MISO_LORA` $\rightarrow$ GPIO 19? (Pin 31 - nhãn trên mạch ghi MISO LORA tại IO19/SCK LORA tùy phiên bản bản vẽ).
*   `NSS_LORA` $\rightarrow$ GPIO 13 (Pin 16)
*   `SCK_LORA` $\rightarrow$ GPIO 19 hoặc 18.
*   `IRQ_LORA` $\rightarrow$ GPIO 27
*   `RESET_LORA` $\rightarrow$ GPIO 14
*   `MOSI_LORA` $\rightarrow$ GPIO 23 (Pin 37)

### 2.2. Khối mô-đun SIM (GPRS/4G - Sẵn sàng mở rộng)
Mạch được thiết kế sẵn các đường giao tiếp UART và chân điều khiển mô-đun SIM để truyền dữ liệu trực tiếp lên cloud nếu không dùng Gateway:
*   `TX_SIM` $\rightarrow$ GPIO 16 (Pin 27)
*   `RX_SIM` $\rightarrow$ GPIO 17 (Pin 28)
*   `RESET_SIM` $\rightarrow$ GPIO 22 (Pin 36)
*   `WAKEUP_SIM` $\rightarrow$ GPIO 4 (Pin 26)
*   `WAKEUP` / `TXD0` / `RXD0` kết nối vào cổng nạp USB-UART.
