#include "mqtt_image.h"
#include "esphome/core/hal.h"


public MQTTImage::MQTTImage(const uint8_t *data_start, int width, int height):
image::Image(
  nullptr, 0, 0, image::ImageType::RGB_565 
){

}