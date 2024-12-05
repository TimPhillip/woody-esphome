#include "mqtt_image.h"
#include "esphome/core/hal.h"


namespace esphome{
namespace mqtt_image{


MQTTImage::MQTTImage(const uint8_t *data_start, int width, int height):
image::Image(
  data_start, width, height, image::ImageType::IMAGE_TYPE_RGB565
){

}

void MQTTImage::setup(){

    this->subscribe("test_topic", [this](const std::string& topic, const std::string& payload){
        ESP_LOGW("Received Payload in MQTTImage");
    });

}

}
}