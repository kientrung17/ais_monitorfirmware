#include "MyMain.h"
#include "common/common.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void timer_callback(void *arg) { 
    processTimer100Hz(); 
}

void app_main() {
    // Hiện toàn bộ log từ DEBUG trở xuống
    esp_log_level_set("*", ESP_LOG_DEBUG); 
    
    // Khởi chạy các task vụ
    startAllTask();
    vTaskDelay(pdMS_TO_TICKS(1000));

    // Khởi tạo timer 1kHz (1ms) cho các phép tính toán cần thiết
    const esp_timer_create_args_t timer_args = {
        .callback = &timer_callback,
        .name = "100HzTimer"
    };
    esp_timer_handle_t timer_handle;
    ESP_ERROR_CHECK(esp_timer_create(&timer_args, &timer_handle));
    ESP_ERROR_CHECK(esp_timer_start_periodic(timer_handle, 1000)); // 1,000 µs = 1ms
    
    vTaskDelay(pdMS_TO_TICKS(100));
}
