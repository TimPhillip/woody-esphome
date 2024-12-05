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
    this->subscribe("test_topic", &MQTTImage::on_image_update);
}

void MQTTImage::on_image_update(const std::string& topic, const std::string& payload){
        ESP_LOGW("mqtt_image", "Received Payload in MQTTImage");
}

}
}