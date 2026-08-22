
void main() {
    PngGen.RGB green = new PngGen.RGB(0, 0xff, 0);
    PngGen.RGB white = new PngGen.RGB(0, 0, 0);

    new PngGen(3, 3)
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

    new PngGen(3, 3)
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
