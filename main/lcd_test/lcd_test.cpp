#include "lcd_test.hpp"

#include "waveshare_setup/waveshare_rgb_lcd_port.h"
#include "lgfx_setup/lgfx_setup.hpp"


void lcd_test(void)
{

    waveshare_esp32_s3_rgb_lcd_init(); // Initialize the Waveshare ESP32-S3 RGB LCD  
    lcd.init();
    lcd.setRotation(0);    
    
    lcd.fillScreen(TFT_RED);
    vTaskDelay(pdMS_TO_TICKS(500));
    lcd.fillScreen(TFT_GREEN);
    vTaskDelay(pdMS_TO_TICKS(500));
    lcd.fillScreen(TFT_BLUE);
    vTaskDelay(pdMS_TO_TICKS(500));
    
    lcd.fillScreen(TFT_BLACK);
      
    // lcd.startWrite();  
    // for (uint32_t x = 0; x < 10; ++x) {
    //     for (uint32_t y = 0; y < 10; ++y) {
    //     lcd.drawPixel(x, y, TFT_YELLOW);
    //     }
    // }
    // lcd.endWrite();    

    lcd.setColor(0xFF0000U);   
    lcd.fillRoundRect(175, 100, 50, 200, 20);     // ancho 1, alto 10
    lcd.fillRoundRect(575, 100, 50, 200, 20);     // ancho 1, alto 10
    //lcd.fillRect(100, 50, 55, 200, TFT_GREEN);  // un solo pixel (1x1)

    // lcd.setFont(&fonts::Font0);
    // lcd.setTextSize(4);
    // lcd.setCursor(180, 20);
    // lcd.setTextColor(TFT_WHITE);
    // lcd.print("Hola desde Esp Idf");

    // lcd.drawString("Texto", 180, 110);  
}