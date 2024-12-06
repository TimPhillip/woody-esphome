#include "mqtt_image.h"
#include "esphome/core/hal.h"


namespace esphome{
namespace mqtt_image{


MQTTImage::MQTTImage(const uint8_t *data_start, int width, int height, std::string& topic):
image::Image(
  data_start, width, height, image::ImageType::IMAGE_TYPE_RGB565
){
    this->mqtt_topic_ = topic;
}

void MQTTImage::setup(){
    ESP_LOGD("mqtt_image", "MQTTImage Setup");
    this->subscribe(this->mqtt_topic_, &MQTTImage::on_image_update);
}

void MQTTImage::on_image_update(const std::string& topic, const std::string& payload){
    ESP_LOGD("mqtt_image", "Received Payload in MQTTImage");
}

}
} 