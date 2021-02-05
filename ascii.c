#include <stdio.h>
#include "bitmap.h"
char ascii[] = { '#', '#', '@', '%', '=', '+', '*', ':', '-', '.', ' ' };

char* asciiLess8(IMAGE* img, int x, int y){
    //TODO: processing
    return ascii;
}
char* ascii8(IMAGE* img, int x, int y){
    RGBQUAD* pixel = ((RGBQUAD*)(img->extra))+*(IDX(img,x,y));
    unsigned short gray = (pixel->rgbRed + pixel->rgbGreen + pixel->rgbBlue) / 3;
    return ascii+(gray * sizeof(ascii) / 256);
}
char* ascii16(IMAGE* img, int x, int y){
    RGB16* pixel = (RGB16*)IDX(img,x,y);
    unsigned short gray = img->bi.compression
        ? ( R565(*pixel) + G565(*pixel) + B565(*pixel) )
        : ( R555(*pixel) + G555(*pixel) + B555(*pixel) );
    return ascii+(gray * sizeof(ascii) / (img->bi.compression?  128 : 96));
}
char* ascii24(IMAGE* img, int x, int y){
    RGBTRIPLE* pixel = (RGBTRIPLE *)IDX(img,x,y);
    unsigned short gray = (pixel->rgbtRed + pixel->rgbtGreen + pixel->rgbtBlue) / 3;
    return ascii+(gray * sizeof(ascii) / 256);
}
char* ascii32(IMAGE* img, int x, int y){
    RGBQUAD* pixel = (RGBQUAD*)IDX(img,x,y);
    unsigned short gray = (pixel->rgbRed + pixel->rgbGreen + pixel->rgbBlue) / 3;
    return ascii+(gray * sizeof(ascii) / 256);
}
char* (*asciifunc[])(IMAGE*,int,int) = {asciiLess8,ascii8,ascii16,ascii24,ascii32};

int toASCII(char* src, char* dst){
    FILE *fpTXT;
    IMAGE img;
    if(!readImage(&img,src)) return 0;
    
    fpTXT = fopen(dst, "w");
    if (fpTXT == NULL){ freeImage(&img); return 0; }

    char* (*ascii)(IMAGE*,int,int) = asciifunc[img.sizPxl];
    for (int y=img.bi.height-1; y>=0; --y){
        for (int x=0; x<img.bi.width; ++x){
            char* c = ascii(&img,x,y);
            fprintf(fpTXT, "%c%c", *c, *c);
        }
        fprintf(fpTXT, "\n");
    }
    fclose(fpTXT);
    
    freeImage(&img);
    return 1;
}