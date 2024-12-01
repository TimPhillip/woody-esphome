#pragma once
#include "esphome/core/color.h"
#include "esphome/components/display/display.h"
#include "esphome/components/image/image.h"

#ifdef USE_LVGL
#include "esphome/components/lvgl/lvgl_proxy.h"
#endif  // USE_LVGL


class MQTTImage : public image::Image {

    public:
        MQTTImage(const uint8_t *data_start, int width, int height);
        Color get_pixel(int x, int y, Color color_on = display::COLOR_ON, Color color_off = display::COLOR_OFF) const;
        int get_width() const override;
        int get_height() const override;
        const uint8_t *get_data_start() const { return this->data_start_; }

        /// Return the stride of the image in bytes, that is, the distance in bytes
        /// between two consecutive rows of pixels.
        uint32_t get_width_stride() const { return (this->width_ * 16u + 7u) / 8u; }
        void draw(int x, int y, display::Display *display, Color color_on, Color color_off) override;

        void set_transparency(bool transparent) { transparent_ = transparent; }
        bool has_transparency() const { return transparent_; }

        #ifdef USE_LVGL
        lv_img_dsc_t *get_lv_img_dsc();
        #endif
    protected:
        Color get_rgb565_pixel_(int x, int y) const;

        int width_;
        int height_;
        const uint8_t *data_start_;
        bool transparent_;
        #ifdef USE_LVGL
        lv_img_dsc_t dsc_{};
        #endif
};