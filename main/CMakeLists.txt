idf_component_register(SRCS "main.cpp" "waveshare_setup/waveshare_rgb_lcd_port.c" "lgfx_setup/lgfx_setup.cpp" "lcd_test/lcd_test.cpp"
                    PRIV_REQUIRES spi_flash
                    INCLUDE_DIRS "."
                    REQUIRES driver LovyanGFX
                    )
