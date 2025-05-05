#pragma once

#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>

#define TFT_HOR_RES 800
#define TFT_VER_RES 480

#define TOUCH_SDA 8
#define TOUCH_SCL 9
#define TOUCH_INT 4
#define TOUCH_RST -1

class LGFX : public lgfx::LGFX_Device {
public:
  lgfx::Bus_RGB _bus_instance;
  lgfx::Panel_RGB _panel_instance;
  lgfx::Touch_GT911 _touch_instance;

  LGFX(void);
};

extern LGFX lcd;