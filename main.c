#include "bitmap.h"

int main(void){
	toASCII("source/128x128_8.bmp","result/128x128_8.txt");
	toASCII("source/128x128_16_555.bmp","result/128x128_16_555.txt");
	toASCII("source/128x128_16_565.bmp","result/128x128_16_565.txt");
	toASCII("source/128x128_24.bmp","result/128x128_24.txt");
	toASCII("source/128x128_32.bmp","result/128x128_32.txt");
	gray("source/128x128_8.bmp","result/128x128_8_gray.bmp");
	gray("source/128x128_16_555.bmp","result/128x128_16_555_gray.bmp");
	gray("source/128x128_16_565.bmp","result/128x128_16_565_gray.bmp");
	gray("source/128x128_24.bmp","result/128x128_24_gray.bmp");
	gray("source/128x128_32.bmp","result/128x128_32_gray.bmp");
	invert("source/128x128_8.bmp","result/128x128_8_invert.bmp");
	invert("source/128x128_16_555.bmp","result/128x128_16_555_invert.bmp");
	invert("source/128x128_16_565.bmp","result/128x128_16_565_invert.bmp");
	invert("source/128x128_24.bmp","result/128x128_24_invert.bmp");
	invert("source/128x128_32.bmp","result/128x128_32_invert.bmp");
	mirror("source/128x128_8.bmp","result/128x128_8_mirror.bmp");
	mirror("source/128x128_16_555.bmp","result/128x128_16_555_mirror.bmp");
	mirror("source/128x128_16_565.bmp","result/128x128_16_565_mirror.bmp");
	mirror("source/128x128_24.bmp","result/128x128_24_mirror.bmp");
	mirror("source/128x128_32.bmp","result/128x128_32_mirror.bmp");
    return 0;
}