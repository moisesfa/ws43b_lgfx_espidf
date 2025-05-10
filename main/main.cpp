/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

#include "waveshare_rgb_lcd_port.h"
#include "lgfx_setup.hpp"

extern "C" void app_main(void)
{
    printf("Hello world!\n");
    waveshare_esp32_s3_rgb_lcd_init(); // Initialize the Waveshare ESP32-S3 RGB LCD 

    lcd.init();
    lcd.setRotation(0);    
    
    lcd.fillScreen(TFT_RED);
    vTaskDelay(pdMS_TO_TICKS(1000));
    lcd.fillScreen(TFT_GREEN);
    vTaskDelay(pdMS_TO_TICKS(1000));
    lcd.fillScreen(TFT_BLUE);
    vTaskDelay(pdMS_TO_TICKS(1000));
    
    lcd.fillScreen(TFT_BLACK);
      
    lcd.startWrite();  // SPIバス確保
    for (uint32_t x = 0; x < 10; ++x) {
        for (uint32_t y = 0; y < 10; ++y) {
        lcd.drawPixel(x, y, TFT_YELLOW);
        }
    }
    lcd.endWrite();    // SPIバス解放

    lcd.setColor(0xFF0000U);   
    lcd.fillRoundRect(50, 50, 25, 100, 10);  // ancho 1, alto 10
    lcd.fillRect(100, 50, 55, 200, TFT_GREEN); // un solo pixel (1x1)

    lcd.setFont(&fonts::Font0);
    lcd.setTextSize(4);
    lcd.setCursor(180, 20);
    lcd.setTextColor(TFT_WHITE);
    lcd.print("Hola desde Esp Idf");

    lcd.drawString("Texto", 180, 110);  
    
    /* Print chip information */
    esp_chip_info_t chip_info;
    uint32_t flash_size;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU core(s), %s%s%s%s, ",
           CONFIG_IDF_TARGET,
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
           (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
           (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "");

    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    printf("silicon revision v%d.%d, ", major_rev, minor_rev);
    if(esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
        printf("Get flash size failed");
        return;
    }

    printf("%" PRIu32 "MB %s flash\n", flash_size / (uint32_t)(1024 * 1024),
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());

    for (int i = 10; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
