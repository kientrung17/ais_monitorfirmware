# Lộ trình phát triển & Cập nhật (Roadmap) - Mạch Monitor (Cập nhật)

Lộ trình này đã được điều chỉnh để phản ánh thiết kế phần cứng đo dòng đơn (CT_CH1), thuật toán mô phỏng Oxy/pH mịn màng theo hình Sin và kiến trúc truyền tải sóng LoRa qua mạch trung gian (Bridge).

---

## Giai đoạn 1: Dọn dẹp & Tái thiết kế (Hiện tại)
*   [x] Xóa các Task cũ không tương thích chân và thiết kế lại sơ đồ hoạt động.
*   [x] Cập nhật tài liệu Đặc tả logic (`logic_spec.md`) mô tả thuật toán giả lập Oxy/pH và chặng truyền LoRa.
*   [x] Làm sạch file bootstrap `MyMain.cpp` tránh lỗi biên dịch.

---

## Giai đoạn 2: Lập trình Logic Đo đạc & Giả lập mịn màng
*   [ ] **Đo dòng điện thực tế:** Viết lại Task đo dòng cho một kênh duy nhất `CT_CH1` (GPIO 36) sử dụng thuật toán tính RMS.
*   [ ] **Thuật toán giả lập Oxy và pH:** Triển khai hàm mô phỏng hình Sin (chạy theo thời gian thực) để tạo ra các đường cong biến thiên sinh học tuyệt đẹp cho chỉ số Oxy (5.0 - 7.5 mg/L) và pH (7.5 - 8.5), tránh rác đồ thị trên App.
*   [ ] **Giám sát mất pha:** Viết lại logic đọc mất pha 3 pha độc lập (`PHA1`, `PHA2`, `PHA3` lần lượt trên GPIO 33, 25, 26) tạo bitmask báo trạng thái nguồn.

---

## Giai đoạn 3: Tích hợp sóng LoRa (Monitor ➡️ Bridge)
*   [ ] Tích hợp thư viện điều khiển chip LoRa (như SX1278 hoặc tương đương) kết nối qua giao tiếp SPI của ESP32.
*   [ ] Xây dựng cấu trúc gói tin LoRa gọn nhẹ chứa: `deviceId`, `ampe`, `oxy`, `pH`, `voltage_pin`, `temperature`, và `phaseLostMask`.
*   [ ] Cấu hình công suất phát LoRa tối ưu để đảm bảo truyền xuyên suốt từ ao nuôi về tới mạch Bridge trung gian.

---

