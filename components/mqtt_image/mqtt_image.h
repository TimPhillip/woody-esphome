#pragma once
#include "esphome/core/component.h"
#include "esphome/core/color.h"
#include "esphome/components/display/display.h"
#include "esphome/components/image/image.h"
#include "esphome/components/mqtt/custom_mqtt_device.h"
#include "esphome/core/log.h"

namespace esphome{
namespace mqtt_image{

class MQTTImage : public Component, public image::Image, public mqtt::CustomMQTTDevice{

    public:
        MQTTImage(const uint8_t *data_start, int width, int height, std::string& topic);
        void setup() override;
        void on_image_update(const std::string& topic, const std::string& payload);

    protected:
        std::string& mqtt_topic_;
};

}
}

