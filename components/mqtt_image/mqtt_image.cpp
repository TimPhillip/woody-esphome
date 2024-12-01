#include "mqtt_image.h"
#include "esphome/core/hal.h"


MQTTImage::MQTTImage(const uint8_t *data_start, int width, int height):
image::Image(
  data_start, width, height, image::ImageType::RGB_565 
){

}