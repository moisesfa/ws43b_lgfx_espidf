#include "lgfx_setup.hpp"

LGFX lcd;

LGFX::LGFX(void) {
  {
    auto cfg = _panel_instance.config();
    cfg.memory_width  = TFT_HOR_RES;
    cfg.memory_height = TFT_VER_RES;
    cfg.panel_width   = TFT_HOR_RES;
    cfg.panel_height  = TFT_VER_RES;
    cfg.offset_x = 0;
    cfg.offset_y = 0;
    _panel_instance.config(cfg);
  }

  {
    auto cfg = _bus_instance.config();
    cfg.panel = &_panel_instance;

    cfg.pin_d0 = 14;
    cfg.pin_d1 = 38;
    cfg.pin_d2 = 18;
    cfg.pin_d3 = 17;
    cfg.pin_d4 = 10;

    cfg.pin_d5 = 39;
    cfg.pin_d6 = 0;
    cfg.pin_d7 = 45;
    cfg.pin_d8 = 48;
    cfg.pin_d9 = 47;
    cfg.pin_d10 = 21;

    cfg.pin_d11 = 1;
    cfg.pin_d12 = 2;
    cfg.pin_d13 = 42;
    cfg.pin_d14 = 41;
    cfg.pin_d15 = 40;

    cfg.pin_henable = 5;
    cfg.pin_vsync   = 3;
    cfg.pin_hsync   = 46;
    cfg.pin_pclk    = 7;

    cfg.freq_write = 14000000;

    cfg.hsync_polarity     = 0;
    cfg.hsync_front_porch  = 8;
    cfg.hsync_pulse_width  = 4;
    cfg.hsync_back_porch   = 8;

    cfg.vsync_polarity     = 0;
    cfg.vsync_front_porch  = 8;
    cfg.vsync_pulse_width  = 4;
    cfg.vsync_back_porch   = 8;

    cfg.pclk_active_neg = 0;
    cfg.de_idle_high    = 0;
    cfg.pclk_idle_high  = 0;

    _bus_instance.config(cfg);
  }

  _panel_instance.setBus(&_bus_instance);

  {
    auto cfg = _touch_instance.config();
    cfg.x_min = 0;
    cfg.x_max = TFT_HOR_RES - 1;
    cfg.y_min = 0;
    cfg.y_max = TFT_VER_RES - 1;
    cfg.pin_int = TOUCH_INT;
    cfg.pin_rst = TOUCH_RST;
    cfg.bus_shared = false;
    cfg.offset_rotation = 0;
    cfg.i2c_port = I2C_NUM_1;
    cfg.pin_sda = TOUCH_SDA;
    cfg.pin_scl = TOUCH_SCL;
    cfg.freq = 400000;
    cfg.i2c_addr = 0x14;
    _touch_instance.config(cfg);
    _panel_instance.setTouch(&_touch_instance);
  }

  setPanel(&_panel_instance);
}