#include "png_gen.hh"

int main() {
    RGB green {0, 0xff, 0};
    RGB white {0, 0, 0};

    PngGen(3, 3)
            .setPixel(0, 0, green)
            .setPixel(1, 0, green)
            .setPixel(2, 0, green)
            .setPixel(0, 1, green)
            .setPixel(1, 1, green)
            .setPixel(2, 1, green)
            .setPixel(0, 2, green)
            .setPixel(1, 2, green)
            .setPixel(2, 2, green)
            .save("out1.png");

    PngGen(3, 3)
            .setPixel(0, 0, white)
            .setPixel(1, 0, green)
            .setPixel(2, 0, white)
            .setPixel(0, 1, green)
            .setPixel(1, 1, white)
            .setPixel(2, 1, green)
            .setPixel(0, 2, white)
            .setPixel(1, 2, green)
            .setPixel(2, 2, white)
            .save("out2.png");
}
