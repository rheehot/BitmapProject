#include "bitmap.h"

void grayLess8(IMAGE* img){
    //TODO: processing
    return;
}
void gray8(IMAGE* img){
    for(RGBQUAD* p=((RGBQUAD*)(img->extra))+(img->bi.clrUsed-1);p>=(RGBQUAD*)(img->extra);--p){
        p->rgbRed=p->rgbGreen=p->rgbBlue
            = ( (p->rgbRed) + (p->rgbGreen) + (p->rgbBlue) ) / 3;
    }
}
void gray16(IMAGE* img){
    if(img->bi.compression){
        for (int y=img->bi.height-1; y>=0; --y)
            for (int x=img->bi.width-1; x>=0; --x){
                RGB16* p = (RGB16*) IDX(img,x,y);
                unsigned short gray = (R565(*p) + (G565(*p)>>1) + B565(*p)) / 3;
                *p=RGB565(gray,gray<<1,gray);
            }
    }
    else{
        for (int y=img->bi.height-1; y>=0; --y)
            for (int x=img->bi.width-1; x>=0; --x){
                RGB16* p = (RGB16*) IDX(img,x,y);
                unsigned short gray = ( R555(*p) + G555(*p) + B555(*p) ) /3;
                *p=RGB555(gray,gray,gray);
            }
    }
}
void gray24(IMAGE* img){
    for (int y=img->bi.height-1; y>=0; --y)
        for (int x=img->bi.width-1; x>=0; --x){
            RGBTRIPLE* p = (RGBTRIPLE*) IDX(img,x,y);
            p->rgbtRed=p->rgbtGreen=p->rgbtBlue
                = ( (p->rgbtRed) + (p->rgbtGreen) + (p->rgbtBlue) ) / 3;
        }
}
void gray32(IMAGE* img){
    for (int y=img->bi.height-1; y>=0; --y)
        for (int x=img->bi.width-1; x>=0; --x){
            RGBQUAD* p = (RGBQUAD*) IDX(img,x,y);
            p->rgbRed=p->rgbGreen=p->rgbBlue
                = ( (p->rgbRed) + (p->rgbGreen) + (p->rgbBlue) ) / 3;
        }
}
void (*grayfunc[])(IMAGE*) = {grayLess8,gray8,gray16,gray24,gray32};

int gray(char* src, char* dst){
    IMAGE img;
    
    if(!readImage(&img,src)) return 0;

    grayfunc[img.sizPxl](&img);

    if(!writeImage(&img,dst)) return 0;
    freeImage(&img);
    return 1;
}