#pragma once
#include "esphome/core/color.h"
#include "esphome/components/display/display.h"
#include "esphome/components/image/image.h"

namespace esphome{
namespace mqtt_image{

class MQTTImage : public image::Image {

    public:
        MQTTImage(const uint8_t *data_start, int width, int height);
};

}
}

