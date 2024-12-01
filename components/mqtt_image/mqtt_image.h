#pragma once
#include "esphome/core/color.h"
#include "esphome/components/display/display.h"
#include "esphome/components/image/image.h"

#ifdef USE_LVGL
#include "esphome/components/lvgl/lvgl_proxy.h"
#endif  // USE_LVGL


class MQTTImage : public image::Image {

    public:
        MQTTImage(const uint8_t *data_start, int width, int height);
};