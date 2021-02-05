#include "bitmap.h"

int main(void){
	/*toASCII("source/lena/8.bmp","result/lena/8.txt");
    toASCII("source/lena/16_555.bmp","result/lena/16_555.txt");
    toASCII("source/lena/16_565.bmp","result/lena/16_565.txt");
    toASCII("source/lena/24.bmp","result/lena/24.txt");
    toASCII("source/lena/32.bmp","result/lena/32.txt");*/
    contrast("source/lena/8.bmp","result/lena/8_contrast.bmp");
    contrast("source/lena/16_555.bmp","result/lena/16_555_contrast.bmp");
    contrast("source/lena/16_565.bmp","result/lena/16_565_contrast.bmp");
    contrast("source/lena/24.bmp","result/lena/24_contrast.bmp");
    contrast("source/lena/32.bmp","result/lena/32_contrast.bmp");
    /*gray("source/lena/8.bmp","result/lena/8_gray.bmp");
    gray("source/lena/16_555.bmp","result/lena/16_555_gray.bmp");
    gray("source/lena/16_565.bmp","result/lena/16_565_gray.bmp");
    gray("source/lena/24.bmp","result/lena/24_gray.bmp");
    gray("source/lena/32.bmp","result/lena/32_gray.bmp");
    invert("source/lena/8.bmp","result/lena/8_invert.bmp");
    invert("source/lena/16_555.bmp","result/lena/16_555_invert.bmp");
    invert("source/lena/16_565.bmp","result/lena/16_565_invert.bmp");
    invert("source/lena/24.bmp","result/lena/24_invert.bmp");
    invert("source/lena/32.bmp","result/lena/32_invert.bmp");
    mirror("source/lena/8.bmp","result/lena/8_mirror.bmp");
    mirror("source/lena/16_555.bmp","result/lena/16_555_mirror.bmp");
    mirror("source/lena/16_565.bmp","result/lena/16_565_mirror.bmp");
    mirror("source/lena/24.bmp","result/lena/24_mirror.bmp");
    mirror("source/lena/32.bmp","result/lena/32_mirror.bmp");
    
	
    toASCII("source/mandrill/8.bmp","result/mandrill/8.txt");
    toASCII("source/mandrill/16_555.bmp","result/mandrill/16_555.txt");
    toASCII("source/mandrill/16_565.bmp","result/mandrill/16_565.txt");
    toASCII("source/mandrill/24.bmp","result/mandrill/24.txt");
    toASCII("source/mandrill/32.bmp","result/mandrill/32.txt");*/
    contrast("source/mandrill/8.bmp","result/mandrill/8_contrast.bmp");
    contrast("source/mandrill/16_555.bmp","result/mandrill/16_555_contrast.bmp");
    contrast("source/mandrill/16_565.bmp","result/mandrill/16_565_contrast.bmp");
    contrast("source/mandrill/24.bmp","result/mandrill/24_contrast.bmp");
    contrast("source/mandrill/32.bmp","result/mandrill/32_contrast.bmp");
    /*gray("source/mandrill/8.bmp","result/mandrill/8_gray.bmp");
    gray("source/mandrill/16_555.bmp","result/mandrill/16_555_gray.bmp");
    gray("source/mandrill/16_565.bmp","result/mandrill/16_565_gray.bmp");
    gray("source/mandrill/24.bmp","result/mandrill/24_gray.bmp");
    gray("source/mandrill/32.bmp","result/mandrill/32_gray.bmp");
    invert("source/mandrill/8.bmp","result/mandrill/8_invert.bmp");
    invert("source/mandrill/16_555.bmp","result/mandrill/16_555_invert.bmp");
    invert("source/mandrill/16_565.bmp","result/mandrill/16_565_invert.bmp");
    invert("source/mandrill/24.bmp","result/mandrill/24_invert.bmp");
    invert("source/mandrill/32.bmp","result/mandrill/32_invert.bmp");
    mirror("source/mandrill/8.bmp","result/mandrill/8_mirror.bmp");
    mirror("source/mandrill/16_555.bmp","result/mandrill/16_555_mirror.bmp");
    mirror("source/mandrill/16_565.bmp","result/mandrill/16_565_mirror.bmp");
    mirror("source/mandrill/24.bmp","result/mandrill/24_mirror.bmp");
    mirror("source/mandrill/32.bmp","result/mandrill/32_mirror.bmp");
	
    toASCII("source/parrots/8.bmp","result/parrots/8.txt");
    toASCII("source/parrots/16_555.bmp","result/parrots/16_555.txt");
    toASCII("source/parrots/16_565.bmp","result/parrots/16_565.txt");
    toASCII("source/parrots/24.bmp","result/parrots/24.txt");
    toASCII("source/parrots/32.bmp","result/parrots/32.txt");*/
    contrast("source/parrots/8.bmp","result/parrots/8_contrast.bmp");
    contrast("source/parrots/16_555.bmp","result/parrots/16_555_contrast.bmp");
    contrast("source/parrots/16_565.bmp","result/parrots/16_565_contrast.bmp");
    contrast("source/parrots/24.bmp","result/parrots/24_contrast.bmp");
    contrast("source/parrots/32.bmp","result/parrots/32_contrast.bmp");
    /*gray("source/parrots/8.bmp","result/parrots/8_gray.bmp");
    gray("source/parrots/16_555.bmp","result/parrots/16_555_gray.bmp");
    gray("source/parrots/16_565.bmp","result/parrots/16_565_gray.bmp");
    gray("source/parrots/24.bmp","result/parrots/24_gray.bmp");
    gray("source/parrots/32.bmp","result/parrots/32_gray.bmp");
    invert("source/parrots/8.bmp","result/parrots/8_invert.bmp");
    invert("source/parrots/16_555.bmp","result/parrots/16_555_invert.bmp");
    invert("source/parrots/16_565.bmp","result/parrots/16_565_invert.bmp");
    invert("source/parrots/24.bmp","result/parrots/24_invert.bmp");
    invert("source/parrots/32.bmp","result/parrots/32_invert.bmp");
    mirror("source/parrots/8.bmp","result/parrots/8_mirror.bmp");
    mirror("source/parrots/16_555.bmp","result/parrots/16_555_mirror.bmp");
    mirror("source/parrots/16_565.bmp","result/parrots/16_565_mirror.bmp");
    mirror("source/parrots/24.bmp","result/parrots/24_mirror.bmp");
    mirror("source/parrots/32.bmp","result/parrots/32_mirror.bmp");
	
    toASCII("source/pepper/8.bmp","result/pepper/8.txt");
    toASCII("source/pepper/16_555.bmp","result/pepper/16_555.txt");
    toASCII("source/pepper/16_565.bmp","result/pepper/16_565.txt");
    toASCII("source/pepper/24.bmp","result/pepper/24.txt");
    toASCII("source/pepper/32.bmp","result/pepper/32.txt");*/
    contrast("source/pepper/8.bmp","result/pepper/8_contrast.bmp");
    contrast("source/pepper/16_555.bmp","result/pepper/16_555_contrast.bmp");
    contrast("source/pepper/16_565.bmp","result/pepper/16_565_contrast.bmp");
    contrast("source/pepper/24.bmp","result/pepper/24_contrast.bmp");
    contrast("source/pepper/32.bmp","result/pepper/32_contrast.bmp");
    /*gray("source/pepper/8.bmp","result/pepper/8_gray.bmp");
    gray("source/pepper/16_555.bmp","result/pepper/16_555_gray.bmp");
    gray("source/pepper/16_565.bmp","result/pepper/16_565_gray.bmp");
    gray("source/pepper/24.bmp","result/pepper/24_gray.bmp");
    gray("source/pepper/32.bmp","result/pepper/32_gray.bmp");
    invert("source/pepper/8.bmp","result/pepper/8_invert.bmp");
    invert("source/pepper/16_555.bmp","result/pepper/16_555_invert.bmp");
    invert("source/pepper/16_565.bmp","result/pepper/16_565_invert.bmp");
    invert("source/pepper/24.bmp","result/pepper/24_invert.bmp");
    invert("source/pepper/32.bmp","result/pepper/32_invert.bmp");
    mirror("source/pepper/8.bmp","result/pepper/8_mirror.bmp");
    mirror("source/pepper/16_555.bmp","result/pepper/16_555_mirror.bmp");
    mirror("source/pepper/16_565.bmp","result/pepper/16_565_mirror.bmp");
    mirror("source/pepper/24.bmp","result/pepper/24_mirror.bmp");
    mirror("source/pepper/32.bmp","result/pepper/32_mirror.bmp");
	
    toASCII("source/sailboat/8.bmp","result/sailboat/8.txt");
    toASCII("source/sailboat/16_555.bmp","result/sailboat/16_555.txt");
    toASCII("source/sailboat/16_565.bmp","result/sailboat/16_565.txt");
    toASCII("source/sailboat/24.bmp","result/sailboat/24.txt");
    toASCII("source/sailboat/32.bmp","result/sailboat/32.txt");*/
    contrast("source/sailboat/8.bmp","result/sailboat/8_contrast.bmp");
    contrast("source/sailboat/16_555.bmp","result/sailboat/16_555_contrast.bmp");
    contrast("source/sailboat/16_565.bmp","result/sailboat/16_565_contrast.bmp");
    contrast("source/sailboat/24.bmp","result/sailboat/24_contrast.bmp");
    contrast("source/sailboat/32.bmp","result/sailboat/32_contrast.bmp");
    /*gray("source/sailboat/8.bmp","result/sailboat/8_gray.bmp");
    gray("source/sailboat/16_555.bmp","result/sailboat/16_555_gray.bmp");
    gray("source/sailboat/16_565.bmp","result/sailboat/16_565_gray.bmp");
    gray("source/sailboat/24.bmp","result/sailboat/24_gray.bmp");
    gray("source/sailboat/32.bmp","result/sailboat/32_gray.bmp");
    invert("source/sailboat/8.bmp","result/sailboat/8_invert.bmp");
    invert("source/sailboat/16_555.bmp","result/sailboat/16_555_invert.bmp");
    invert("source/sailboat/16_565.bmp","result/sailboat/16_565_invert.bmp");
    invert("source/sailboat/24.bmp","result/sailboat/24_invert.bmp");
    invert("source/sailboat/32.bmp","result/sailboat/32_invert.bmp");
    mirror("source/sailboat/8.bmp","result/sailboat/8_mirror.bmp");
    mirror("source/sailboat/16_555.bmp","result/sailboat/16_555_mirror.bmp");
    mirror("source/sailboat/16_565.bmp","result/sailboat/16_565_mirror.bmp");
    mirror("source/sailboat/24.bmp","result/sailboat/24_mirror.bmp");
    mirror("source/sailboat/32.bmp","result/sailboat/32_mirror.bmp");*/
    return 0;
}