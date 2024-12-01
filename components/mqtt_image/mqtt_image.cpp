#include "mqtt_image.h"

#include "esphome/core/hal.h"


#ifdef USE_LVGL
lv_img_dsc_t *Image::get_lv_img_dsc() {
  // lazily construct lvgl image_dsc.
  if (this->dsc_.data != this->data_start_) {
    this->dsc_.data = this->data_start_;
    this->dsc_.header.always_zero = 0;
    this->dsc_.header.reserved = 0;
    this->dsc_.header.w = this->width_;
    this->dsc_.header.h = this->height_;
    this->dsc_.data_size = this->get_width_stride() * this->get_height();
    switch (this->get_type()) {
      case IMAGE_TYPE_BINARY:
        this->dsc_.header.cf = LV_IMG_CF_ALPHA_1BIT;
        break;

      case IMAGE_TYPE_GRAYSCALE:
        this->dsc_.header.cf = LV_IMG_CF_ALPHA_8BIT;
        break;

      case IMAGE_TYPE_RGB24:
        this->dsc_.header.cf = LV_IMG_CF_RGB888;
        break;

      case IMAGE_TYPE_RGB565:
#if LV_COLOR_DEPTH == 16
        this->dsc_.header.cf = this->has_transparency() ? LV_IMG_CF_TRUE_COLOR_ALPHA : LV_IMG_CF_TRUE_COLOR;
#else
        this->dsc_.header.cf = LV_IMG_CF_RGB565;
#endif
        break;

      case IMAGE_TYPE_RGBA:
#if LV_COLOR_DEPTH == 32
        this->dsc_.header.cf = LV_IMG_CF_TRUE_COLOR;
#else
        this->dsc_.header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA;
#endif
        break;
    }
  }
  return &this->dsc_;
}
#endif  // USE_LVGL