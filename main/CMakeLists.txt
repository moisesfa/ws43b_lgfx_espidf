idf_component_register(SRCS "main.cpp" "waveshare/waveshare_rgb_lcd_port.c" "lgfx_setup/lgfx_setup.cpp"
                    PRIV_REQUIRES spi_flash
                    INCLUDE_DIRS "."
                    REQUIRES driver LovyanGFX
                    )
