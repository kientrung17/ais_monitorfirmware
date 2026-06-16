[22:41:32 --- Rx] ets Jul 29 2019 12:21:46

rst:0x1 (POWERON_RESET),boot:0x12 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0030,len:6380
ho 0 tail 12 room 4
load:0x40078000,len:15916
load:0x40080400,len:3860
entry 0x40080630
I (29) boot: ESP-IDF 5.5.0 2nd stage bootloader
I (29) boot: compile time Jun 16 2026 21:58:18
I (29) boot: Multicore bootloader
I (31) boot: chip revision: v3.1
I (33) boot.esp32: SPI Speed      : 40MHz
I (37) boot.esp32: SPI Mode       : DIO
I (41) boot.esp32: SPI Flash Size : 4MB
I (44) boot: Enabling RNG early entropy source...
I (49) boot: Partition Table:
I (51) boot: ## Label            Usage          Type ST Offset   Length
I (58) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (64) boot:  1 factory          factory app      00 00 00010000 003ef000
I (71) boot: End of partition table
I (74) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=0dcc4h ( 56516) map
I (101) esp_image: segment 1: paddr=0001dcec vaddr=3ff80000 si
[22:41:32 105 Rx] ze=00020h (    32) load
I (101) esp_image: segment 2: paddr=0001dd14 vaddr=3ffb0000 size=02304h (  8964) load
I (108) esp_image: segment 3: paddr=00020020 vaddr=400d0020 size=20ea8h (134824) map
I (158) esp_image: segment 4: paddr=00040ed0 vaddr=3ffb2304 size=002b0h (   688) load
I (159) esp_image: segment 5: paddr=00041188 vaddr=40080000 size=10148h ( 65864) load
I (196) boot: Loaded app from partition at offset 0x10000
I (196) boot: Disabling RNG early entropy source...
I (206) cpu_
[22:41:32 101 Rx] start: Multicore app
I (214) cpu_start: Pro cpu start user code
I (215) cpu_start: cpu freq: 160000000 Hz
I (215) app_init: Application information:
I (215) app_init: Project name:     ais_monitorfirmware
I (220) app_init: App version:      1
I (223) app_init: Compile time:     Jun 16 2026 21:57:01
I (228) app_init: ELF file SHA256:  853b63676...
I (232) app_init: ESP-IDF:          5.5.0
I (236) efuse_init: Min chip rev:     v0.0
I (240) efuse_init: Max chip rev:     v3.99 
I (244) efuse_init: Chip rev:         v3.1
I (248) heap_init: Initializing. RAM available for dynamic allocation:
I (254) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (259) heap_init: At 3FFB3258 len 0002CDA8 (179 KiB): DRAM
I (264) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (270) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (275) heap_init: At 40090148 len 0000FEB8 (63 KiB): IRAM
I (282) spi_flash: detected chip: generic
I (284) spi_flash: flash io: dio
I (288) main_task: Started on CPU0
I (298) main_task: Calling app_main()
I (298) [info]MyMain: [src/MyMain.cpp:33:startAllTask] **************** Starting Monitor Skeleton ****************
I (298) [info]TaskMan
[22:41:32 104 Rx] ager: [components\ais_commonlib\src\architectureabs\taskmanager.cpp:36:registerProcessor] registerProcessor success
I (308) [info]TaskAbstract: [components\ais_commonlib\src\architectureabs\taskabstract.cpp:88:registerSemaphoreToQueueset] [SensorMeasureTask]Create semaphore 100Hz success: 51
I (328) [info]TaskManager: [components\ais_commonlib\src\architectureabs\taskmanager.cpp:36:registerProcessor] registerProcessor success
I (338) [info]TaskAbstract: [components\ais_commonlib\src\architectureabs\taskabstract.cpp:88:registerSemaphoreToQueueset] [LoraTask]Create semaphore 100Hz success: 52
I (348) [info]MyMain: [src/MyMain.cpp:16:StartSensorMeasureTask] Start Task Sensor Measure
I (358) [debug]TaskAbstract: [components\ais_commonlib\src\architectureabs\taskabstract.cpp:56:onStartProcess] Start process SensorMeasureTask
I (378) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:24:onInitProcess] Init ADC hardware (Oneshot Burst)...
I (388) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:89:initAdc] ADC1 init OK: Current (GPIO 39, Ch 3), AC Voltage (GPIO 32, Ch 4), Battery (GPIO 35, Ch 7)
I (398) [info]SensorMeasureTask: [src/task/sen
[22:41:32 100 Rx] sor_measure_task.cpp:104:initCalibration] ADC Calibration OK (eFuse line fitting)
I (408) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:215:initPhasePins] Initializing Phase loss detection pins...
I (418) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:223:initPhasePins] Phase pins (GPIO 33, 25, 26) initialized successfully.
I (438) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:31:onInitProcess] DS18B20 temperature sensor initialized successfully.
I (448) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:41:onInitProcess] adcBurstTask spawned successfully
I (458) [info]MyMain: [src/MyMain.cpp:25:StartLoraTask] Start Task LoRa
I (458) [debug]TaskAbstract: [components\ais_commonlib\src\architectureabs\taskabstract.cpp:56:onStartProcess] Start process LoraTask
I (478) LoraTask: Initializing LoRa on SPI3 (VSPI)...
I (478) [info]MyMain: [src/MyMain.cpp:49:startAllTask] Start All Task Success
I (488) SX127x: SX127x RegVersion (0x42) = 0x00 (Expected: 0x12)
I (498) SX127x: Frequency set to 433.0 MHz (FRF: 0x6C4000)
I (498) SX127x: Sync Word set to 0x54
I (498) LoraTask: LoRa initialized successfully. Frequency: 433.0 MHz, Sync Word: 0x54

[22:41:33 --- Rx] I (1588) main_task: Returned from app_main()

[22:41:34 849 Rx] I (2448) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:206:adcBurstTask] ADC burst sampling thread started
I (2548) [info]SensorMeasureTask: [src/task/sensor_measure_tas
[22:41:34 104 Rx] k.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=5.7mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=692]
I (2548) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (2568) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.02, Oxy: 5.15 mg/L

[22:41:34 321 Rx] I (2878) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (2878) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (2898) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.02, Oxy: 5.16 mg/L

[22:41:35 327 Rx] I (3208) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=3.5mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (3208) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (3228) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.01, Oxy: 5.13 mg/L

[22:41:35 317 Rx] I (3538) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.5mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (3538) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (3558) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.00, Oxy: 5.16 mg/L

[22:41:35 328 Rx] I (3868) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.9mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (3868) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (3888) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.01, Oxy: 5.19 mg/L

[22:41:36 320 Rx] I (4198) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.5mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (4198) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (4218) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 7.99, Oxy: 5.14 mg/L

[22:41:36 327 Rx] I (4528) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (4528) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (4548) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.04, Oxy: 5.13 mg/L

[22:41:36 318 Rx] I (4858) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.5mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (4858) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (4878) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.04, Oxy: 5.11 mg/L

[22:41:37 327 Rx] I (5188) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.4mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (5188) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (5208) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.04, Oxy: 5.11 mg/L

[22:41:37 309 Rx] I (5508) LoraTask: Sending sensor data via LoRa: ID=1, Ampe=0.01A, Oxy=5.11 mg/L, pH=8.04, Temp=-0.1 C, VoltAC=0.0V, PhaseMask=7
I (5518) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=11.1mV RMS_V=0.0mV | Current=0.07A Voltage=0.0V Bat=142mV [Samples=694]
I (5518) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (5538) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.04, Oxy: 5.15 mg/L

[22:41:37 327 Rx] I (5848) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=3.0mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=698]
I (5848) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (5868) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.04, Oxy: 5.14 mg/L

[22:41:38 317 Rx] I (6178) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.0mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=698]
I (6178) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (6198) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.03, Oxy: 5.16 mg/L

[22:41:38 324 Rx] E (6508) SX127x: Send packet timeout!
E (6508) LoraTask: Failed to send sensor data.
I (6508) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.9mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=698]
I (6518) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (6528) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.02, Oxy: 5.11 mg/L

[22:41:38 317 Rx] I (6838) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.1mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=694]
I (6838) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (6858) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.05, Oxy: 5.11 mg/L

[22:41:39 328 Rx] I (7168) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.6mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (7168) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (7188) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.05, Oxy: 5.15 mg/L

[22:41:39 321 Rx] I (7498) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.5mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (7498) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (7518) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.03, Oxy: 5.16 mg/L

[22:41:39 328 Rx] I (7828) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.9mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (7828) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (7848) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.05, Oxy: 5.17 mg/L

[22:41:40 323 Rx] I (8158) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=5.9mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (8158) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (8178) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.03, Oxy: 5.15 mg/L

[22:41:40 316 Rx] I (8488) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.9mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=693]
I (8488) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (8508) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.04, Oxy: 5.20 mg/L

[22:41:40 324 Rx] I (8818) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=5.8mV RMS_V=0.0mV | Current=0.07A Voltage=0.0V Bat=142mV [Samples=693]
I (8818) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (8838) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.06, Oxy: 5.14 mg/L

[22:41:41 319 Rx] I (9148) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=4.7mV RMS_V=0.0mV | Current=0.08A Voltage=0.0V Bat=142mV [Samples=693]
I (9148) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (9168) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.04, Oxy: 5.18 mg/L

[22:41:41 326 Rx] I (9478) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.9mV RMS_V=0.0mV | Current=0.09A Voltage=0.0V Bat=142mV [Samples=693]
I (9478) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (9498) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.03, Oxy: 5.19 mg/L

[22:41:41 318 Rx] I (9808) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.9mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=693]
I (9808) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (9828) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.06, Oxy: 5.11 mg/L

[22:41:42 326 Rx] I (10138) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=3.5mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (10138) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (10158) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.06, Oxy: 5.20 mg/L

[22:41:42 319 Rx] I (10468) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.3mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (10468) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (10488) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.06, Oxy: 5.16 mg/L
I (10508) LoraTask: Sending sensor data via LoRa: ID=1, Ampe=0.03A, Oxy=5.16 mg/L, pH=8.06, Temp=-0.1 C, VoltAC=0.0V, PhaseMask=7

[22:41:42 327 Rx] I (10798) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.6mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=698]
I (10798) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (10818) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.06, Oxy: 5.15 mg/L

[22:41:43 319 Rx] I (11128) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.6mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=698]
I (11128) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (11148) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.06, Oxy: 5.19 mg/L

[22:41:43 326 Rx] I (11458) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.5mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=698]
I (11458) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (11478) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.06, Oxy: 5.13 mg/L
E (11508) SX127x: Send packet timeout!
E (11508) LoraTask: Failed to send sensor data.

[22:41:43 314 Rx] I (11788) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.7mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (11788) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (11808) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.03, Oxy: 5.17 mg/L

[22:41:44 321 Rx] I (12118) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (12118) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (12138) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.04, Oxy: 5.15 mg/L

[22:41:44 328 Rx] I (12448) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.4mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (12448) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (12468) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.03, Oxy: 5.17 mg/L

[22:41:44 316 Rx] I (12778) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.8mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (12778) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (12798) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.05, Oxy: 5.20 mg/L

[22:41:45 324 Rx] I (13108) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.6mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (13108) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (13128) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.04, Oxy: 5.21 mg/L

[22:41:45 316 Rx] I (13438) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.8mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (13438) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (13458) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.04, Oxy: 5.20 mg/L

[22:41:45 326 Rx] I (13768) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.5mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (13768) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (13788) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.06, Oxy: 5.18 mg/L

[22:41:46 318 Rx] I (14098) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=7.6mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=693]
I (14098) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (14118) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.05, Oxy: 5.14 mg/L

[22:41:46 324 Rx] I (14428) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.9mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (14428) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (14448) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.07, Oxy: 5.20 mg/L

[22:41:46 330 Rx] I (14758) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (14758) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (14778) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.07, Oxy: 5.16 mg/L

[22:41:47 322 Rx] I (15088) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.4mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (15088) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (15108) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.04, Oxy: 5.19 mg/L

[22:41:47 326 Rx] I (15418) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (15418) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (15438) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.07, Oxy: 5.12 mg/L
I (15508) LoraTask: Sending sensor data via LoRa: ID=1, Ampe=0.03A, Oxy=5.12 mg/L, pH=8.07, Temp=-0.1 C, VoltAC=0.0V, PhaseMask=7

[22:41:47 319 Rx] I (15748) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.4mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=698]
I (15748) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (15768) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.05, Oxy: 5.21 mg/L

[22:41:48 324 Rx] I (16078) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=6.7mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=698]
I (16078) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (16098) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.07, Oxy: 5.21 mg/L

[22:41:48 316 Rx] I (16408) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.2mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=698]
I (16408) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (16428) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.09, Oxy: 5.19 mg/L
E (16508) SX127x: Send packet timeout!
E (16508) LoraTask: Failed to send sensor data.

[22:41:48 324 Rx] I (16738) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.8mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (16738) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (16758) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.06, Oxy: 5.18 mg/L

[22:41:49 329 Rx] I (17068) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.8mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (17068) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (17088) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.09, Oxy: 5.13 mg/L

[22:41:49 319 Rx] I (17398) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.9mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (17398) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (17418) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.07, Oxy: 5.15 mg/L

[22:41:49 326 Rx] I (17728) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=6.6mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=693]
I (17728) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (17748) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.06, Oxy: 5.17 mg/L

[22:41:50 317 Rx] I (18058) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.4mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (18058) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (18078) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.08, Oxy: 5.19 mg/L

[22:41:50 324 Rx] I (18388) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.7mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (18388) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (18408) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.08, Oxy: 5.13 mg/L

[22:41:50 315 Rx] I (18718) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.1mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (18718) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (18738) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.08, Oxy: 5.18 mg/L

[22:41:51 324 Rx] I (19048) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (19048) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (19068) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.08, Oxy: 5.13 mg/L

[22:41:51 317 Rx] I (19378) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=7.2mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=693]
I (19378) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (19398) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.08, Oxy: 5.15 mg/L

[22:41:51 323 Rx] I (19708) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.1mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (19708) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (19728) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.07, Oxy: 5.20 mg/L

[22:41:52 329 Rx] I (20038) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.6mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (20038) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (20058) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.11, Oxy: 5.15 mg/L

[22:41:52 323 Rx] I (20368) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.8mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (20368) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (20388) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.08, Oxy: 5.18 mg/L

[22:41:52 138 Rx] I (20508) LoraTask: Sending sensor data via LoRa: ID=1, Ampe=0.02A, Oxy=5.18 mg/L, pH=8.08, Temp=-0.1 C, VoltAC=0.0V, PhaseMask=7

[22:41:52 176 Rx] I (20698) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=3.9mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=698]
I (20698) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (20718) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.08, Oxy: 5.22 mg/L

[22:41:53 322 Rx] I (21028) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.6mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=698]
I (21028) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (21048) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.09, Oxy: 5.16 mg/L

[22:41:53 329 Rx] I (21358) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.9mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=698]
I (21358) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (21378) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.08, Oxy: 5.16 mg/L

[22:41:53 140 Rx] E (21508) SX127x: Send packet timeout!
E (21508) LoraTask: Failed to send sensor data.

[22:41:53 169 Rx] I (21688) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.00A Voltage=0.0V Bat=142mV [Samples=693]
I (21688) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (21708) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.06, Oxy: 5.20 mg/L

[22:41:54 314 Rx] I (22018) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=5.5mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (22018) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (22038) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.09, Oxy: 5.19 mg/L

[22:41:54 324 Rx] I (22348) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.5mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (22348) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (22368) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.11, Oxy: 5.16 mg/L

[22:41:54 316 Rx] I (22678) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.6mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (22678) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (22698) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.07, Oxy: 5.23 mg/L

[22:41:55 323 Rx] I (23008) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=3.0mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (23008) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (23028) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.10, Oxy: 5.21 mg/L

[22:41:55 317 Rx] I (23338) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.6mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (23338) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (23358) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.12, Oxy: 5.13 mg/L

[22:41:55 323 Rx] I (23668) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.9mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (23668) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (23688) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.09, Oxy: 5.21 mg/L

[22:41:56 328 Rx] I (23998) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.1mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (23998) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (24018) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.09, Oxy: 5.23 mg/L

[22:41:56 317 Rx] I (24328) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (24328) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (24348) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.08, Oxy: 5.17 mg/L

[22:41:56 324 Rx] I (24658) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.5mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (24658) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (24678) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.08, Oxy: 5.23 mg/L

[22:41:57 315 Rx] I (24988) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=4.0mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (24988) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (25008) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.12, Oxy: 5.23 mg/L

[22:41:57 323 Rx] I (25318) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.1mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (25318) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (25338) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.09, Oxy: 5.19 mg/L

[22:41:57 187 Rx] I (25508) LoraTask: Sending sensor data via LoRa: ID=1, Ampe=0.01A, Oxy=5.19 mg/L, pH=8.09, Temp=-0.1 C, VoltAC=0.0V, PhaseMask=7

[22:41:57 129 Rx] I (25648) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=5.6mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=698]
I (25648) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (25668) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.13, Oxy: 5.16 mg/L

[22:41:58 322 Rx] I (25978) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.3mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=698]
I (25978) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (25998) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.10, Oxy: 5.24 mg/L

[22:41:58 324 Rx] I (26308) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=6.0mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=698]
I (26308) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (26328) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.13, Oxy: 5.21 mg/L

[22:41:58 196 Rx] E (26508) SX127x: Send packet timeout!
E (26508) LoraTask: Failed to send sensor data.

[22:41:58 126 Rx] I (26638) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=5.1mV RMS_V=0.0mV | Current=0.07A Voltage=0.0V Bat=142mV [Samples=693]
I (26638) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (26658) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.09, Oxy: 5.21 mg/L

[22:41:59 320 Rx] I (26968) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=4.4mV RMS_V=0.0mV | Current=0.07A Voltage=0.0V Bat=142mV [Samples=693]
I (26968) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (26988) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.13, Oxy: 5.17 mg/L

[22:41:59 324 Rx] I (27298) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.8mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=693]
I (27298) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (27318) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.10, Oxy: 5.24 mg/L

[22:41:59 317 Rx] I (27628) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.1mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=693]
I (27628) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (27648) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.09, Oxy: 5.19 mg/L

[22:42:00 322 Rx] I (27958) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.8mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (27958) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (27978) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.13, Oxy: 5.24 mg/L

[22:42:00 316 Rx] I (28288) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.8mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (28288) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (28308) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.10, Oxy: 5.24 mg/L

[22:42:00 322 Rx] I (28618) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=5.8mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=693]
I (28618) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (28638) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.11, Oxy: 5.23 mg/L

[22:42:01 330 Rx] I (28948) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.1mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (28948) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (28968) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.10, Oxy: 5.18 mg/L

[22:42:01 319 Rx] I (29278) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.9mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (29278) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (29298) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.09, Oxy: 5.24 mg/L

[22:42:01 327 Rx] I (29608) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=6.9mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=693]
I (29608) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (29628) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.13, Oxy: 5.17 mg/L

[22:42:02 322 Rx] I (29938) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=5.8mV RMS_V=0.0mV | Current=0.08A Voltage=0.0V Bat=142mV [Samples=693]
I (29938) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (29958) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.10, Oxy: 5.18 mg/L

[22:42:02 329 Rx] I (30268) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.8mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=693]
I (30268) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (30288) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.11, Oxy: 5.21 mg/L

[22:42:02 231 Rx] I (30508) LoraTask: Sending sensor data via LoRa: ID=1, Ampe=0.05A, Oxy=5.21 mg/L, pH=8.11, Temp=-0.1 C, VoltAC=0.0V, PhaseMask=7
I (30598) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=11.4mV RMS_V=0.0mV | Current=0.11A Voltage=0.0V Bat=142mV [Samples=697]
I (30598) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Ma
[22:42:02 103 Rx] sk: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (30618) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.13, Oxy: 5.18 mg/L

[22:42:03 299 Rx] I (30928) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=3.7mV RMS_V=0.0mV | Current=0.07A Voltage=0.0V Bat=142mV [Samples=698]
I (30928) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (30948) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.13, Oxy: 5.25 mg/L

[22:42:03 321 Rx] I (31258) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=698]
I (31258) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (31278) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.13, Oxy: 5.17 mg/L

[22:42:03 234 Rx] E (31508) SX127x: Send packet timeout!
E (31508) LoraTask: Failed to send sensor data.
I (31588) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.0mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=694]
I (31588) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (31608) [debug
[22:42:03 101 Rx] ]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.14, Oxy: 5.24 mg/L

[22:42:04 292 Rx] I (31918) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.4mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (31918) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (31938) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.12, Oxy: 5.21 mg/L

[22:42:04 317 Rx] I (32248) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.9mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (32248) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (32268) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.11, Oxy: 5.20 mg/L

[22:42:04 323 Rx] I (32578) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.8mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (32578) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (32598) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.12, Oxy: 5.16 mg/L

[22:42:05 318 Rx] I (32908) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.3mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (32908) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (32928) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.15, Oxy: 5.25 mg/L

[22:42:05 326 Rx] I (33238) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=5.1mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (33238) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (33258) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.19 mg/L

[22:42:05 319 Rx] I (33568) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.9mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=693]
I (33568) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (33588) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.14, Oxy: 5.18 mg/L

[22:42:06 327 Rx] I (33898) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=6.2mV RMS_V=0.0mV | Current=0.08A Voltage=0.0V Bat=142mV [Samples=693]
I (33898) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (33918) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.13, Oxy: 5.25 mg/L

[22:42:06 318 Rx] I (34228) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=3.9mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=693]
I (34228) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (34248) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.18 mg/L

[22:42:06 324 Rx] I (34558) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.8mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (34558) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (34578) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.14, Oxy: 5.25 mg/L

[22:42:07 326 Rx] I (34888) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.3mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (34888) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (34908) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.12, Oxy: 5.26 mg/L

[22:42:07 317 Rx] I (35218) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=6.1mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=693]
I (35218) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (35238) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.13, Oxy: 5.23 mg/L

[22:42:07 283 Rx] I (35508) LoraTask: Sending sensor data via LoRa: ID=1, Ampe=0.05A, Oxy=5.23 mg/L, pH=8.13, Temp=-0.1 C, VoltAC=0.0V, PhaseMask=7
I (35548) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=3.7mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=694]
I (35548) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (35568) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.14, Oxy: 5.25 mg/L

[22:42:07 365 Rx] I (35878) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=3.3mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=698]
I (35878) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (35898) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.12, Oxy: 5.27 mg/L

[22:42:08 323 Rx] I (36208) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=3.9mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=698]
I (36208) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (36228) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.12, Oxy: 5.19 mg/L

[22:42:08 286 Rx] E (36508) SX127x: Send packet timeout!
E (36508) LoraTask: Failed to send sensor data.
I (36538) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=696]
I (36538) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (36558) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.21 mg/L

[22:42:08 355 Rx] I (36868) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=4.9mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (36868) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (36888) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.28 mg/L

[22:42:09 316 Rx] I (37198) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=6.4mV RMS_V=0.0mV | Current=0.07A Voltage=0.0V Bat=142mV [Samples=693]
I (37198) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (37218) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.14, Oxy: 5.20 mg/L

[22:42:09 322 Rx] I (37528) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.4mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=693]
I (37528) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (37548) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.18, Oxy: 5.25 mg/L

[22:42:09 315 Rx] I (37858) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=4.0mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=693]
I (37858) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (37878) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.14, Oxy: 5.24 mg/L

[22:42:10 325 Rx] I (38188) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (38188) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (38208) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.14, Oxy: 5.19 mg/L

[22:42:10 328 Rx] I (38518) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.2mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (38518) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (38538) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.28 mg/L

[22:42:10 323 Rx] I (38848) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=4.3mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (38848) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (38868) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.15, Oxy: 5.20 mg/L

[22:42:11 328 Rx] I (39178) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=4.8mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=693]
I (39178) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (39198) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.24 mg/L

[22:42:11 320 Rx] I (39508) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.5mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (39508) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (39528) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.29 mg/L

[22:42:11 324 Rx] I (39838) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.3mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (39838) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (39858) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.20 mg/L

[22:42:12 317 Rx] I (40168) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.4mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (40168) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (40188) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.15, Oxy: 5.25 mg/L

[22:42:12 325 Rx] I (40498) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=6.3mV RMS_V=0.0mV | Current=0.05A Voltage=0.0V Bat=142mV [Samples=693]
I (40498) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (40508) LoraTask: Sending sensor data via LoRa: ID=1, Ampe=0.05A, Oxy=5.25 mg/L, pH=8.15, Temp=-0.1 C, VoltAC=0.0V, PhaseMask=7
I (40518) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.14, Oxy: 5.20 mg/L

[22:42:12 332 Rx] I (40838) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1665mV DC_V=142mV | RMS_I=2.9mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=698]
I (40838) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (40858) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.20 mg/L

[22:42:13 323 Rx] I (41168) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=6.0mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=698]
I (41168) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (41188) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.15, Oxy: 5.25 mg/L

[22:42:13 325 Rx] I (41498) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.6mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=698]
I (41498) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (41518) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.30 mg/L
E (41528) SX127x: Send packet timeout!
E (41528) LoraTask: Failed to send sensor data.

[22:42:13 317 Rx] I (41828) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.9mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (41828) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (41848) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.22 mg/L

[22:42:14 325 Rx] I (42158) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.9mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (42158) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (42178) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.17, Oxy: 5.23 mg/L

[22:42:14 330 Rx] I (42488) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (42488) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (42508) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.19, Oxy: 5.21 mg/L

[22:42:14 323 Rx] I (42818) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=5.0mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (42818) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (42838) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.17, Oxy: 5.24 mg/L

[22:42:15 319 Rx] I (43148) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.8mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (43148) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (43168) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.18, Oxy: 5.24 mg/L

[22:42:15 327 Rx] I (43478) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=6.2mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=693]
I (43478) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (43498) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.17, Oxy: 5.26 mg/L

[22:42:15 319 Rx] I (43808) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.1mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=693]
I (43808) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (43828) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.31 mg/L

[22:42:16 326 Rx] I (44138) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=6.4mV RMS_V=0.0mV | Current=0.08A Voltage=0.0V Bat=142mV [Samples=693]
I (44138) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (44158) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.18, Oxy: 5.22 mg/L

[22:42:16 319 Rx] I (44468) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=4.6mV RMS_V=0.0mV | Current=0.09A Voltage=0.0V Bat=142mV [Samples=694]
I (44468) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (44488) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.18, Oxy: 5.27 mg/L

[22:42:16 325 Rx] I (44798) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.9mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=693]
I (44798) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (44818) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.16, Oxy: 5.24 mg/L

[22:42:17 315 Rx] I (45128) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.5mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=693]
I (45128) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (45148) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.20, Oxy: 5.25 mg/L

[22:42:17 322 Rx] I (45458) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=5.3mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=694]
I (45458) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (45478) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.18, Oxy: 5.29 mg/L
I (45508) LoraTask: Sending sensor data via LoRa: ID=1, Ampe=0.06A, Oxy=5.29 mg/L, pH=8.18, Temp=-0.1 C, VoltAC=0.0V, PhaseMask=7

[22:42:17 314 Rx] I (45788) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=7.3mV RMS_V=0.0mV | Current=0.09A Voltage=0.0V Bat=142mV [Samples=698]
I (45788) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (45808) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.20, Oxy: 5.26 mg/L

[22:42:18 320 Rx] I (46118) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.7mV RMS_V=0.0mV | Current=0.06A Voltage=0.0V Bat=142mV [Samples=698]
I (46118) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (46138) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.18, Oxy: 5.26 mg/L

[22:42:18 329 Rx] I (46448) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=2.8mV RMS_V=0.0mV | Current=0.04A Voltage=0.0V Bat=142mV [Samples=698]
I (46448) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (46468) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.19, Oxy: 5.29 mg/L
E (46508) SX127x: Send packet timeout!
E (46508) LoraTask: Failed to send sensor data.

[22:42:18 319 Rx] I (46778) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.0mV RMS_V=0.0mV | Current=0.03A Voltage=0.0V Bat=142mV [Samples=693]
I (46778) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (46798) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.18, Oxy: 5.25 mg/L

[22:42:19 327 Rx] I (47108) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.1mV RMS_V=0.0mV | Current=0.02A Voltage=0.0V Bat=142mV [Samples=693]
I (47108) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (47128) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.19, Oxy: 5.28 mg/L

[22:42:19 320 Rx] I (47438) [info]SensorMeasureTask: [src/task/sensor_measure_task.cpp:179:computeAndSendRms] DC_I=1666mV DC_V=142mV | RMS_I=3.1mV RMS_V=0.0mV | Current=0.01A Voltage=0.0V Bat=142mV [Samples=693]
I (47438) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:244:monitorPhaseLoss] Phase loss status - Mask: 7 (P1: 1, P2: 1, P3: 1), Lost Electric: 1
I (47458) [debug]SensorMeasureTask: [src/task/sensor_measure_task.cpp:273:simulateOxyPh] Simulated values - pH: 8.19, Oxy: 5.29 mg/L

