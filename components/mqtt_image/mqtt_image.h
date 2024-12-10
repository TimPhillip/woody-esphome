#pragma once
#include "esphome/core/component.h"
#include "esphome/core/color.h"
#include "esphome/components/display/display.h"
#include "esphome/components/image/image.h"
#include "esphome/components/mqtt/mqtt_component.h"
#include "esphome/core/log.h"

namespace esphome{
namespace mqtt_image{

class MQTTImage : public image::Image, public mqtt::MQTTComponent{

    public:
        MQTTImage(const uint8_t *data_start, int width, int height, const std::string& topic);
        void setup() override;
        void on_image_update(const std::string& topic, const std::string& payload);

        void send_discovery(JsonObject root, mqtt::SendDiscoveryConfig &config);
        std::string component_type() const;

    protected:
        const std::string mqtt_topic_;
};

}
}

