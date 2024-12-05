#pragma once
#include "esphome/core/color.h"
#include "esphome/components/display/display.h"
#include "esphome/components/image/image.h"
#include "esphome/components/mqtt/mqtt_component.h"
#include "esphome/core/log.h"

namespace esphome{
namespace mqtt_image{

class MQTTImage : public image::Image, public mqtt::MQTTComponent{

    public:
        MQTTImage(const uint8_t *data_start, int width, int height);

        void setup() override;
    private:

};

}
}

