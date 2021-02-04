#include "bitmap.h"

void contrastLess8(IMAGE* img){
    //TODO: processing
    return;
}
void contrast8(IMAGE* img){
    int temp;
    for(RGBQUAD* p=((RGBQUAD*)(img->extra))+(img->bi.clrUsed-1);p>=(RGBQUAD*)(img->extra);--p){
        temp=(p->rgbRed)*(p->rgbRed>0x7F ? 1.15 : 0.85);
        p->rgbRed=(temp>0xFF ? 0xFF : temp);
        temp=(p->rgbGreen)*(p->rgbGreen>0x7F ? 1.15 : 0.85);
        p->rgbGreen=(temp>0xFF ? 0xFF : temp);
        temp=(p->rgbBlue)*(p->rgbBlue>0x7F ? 1.15 : 0.85);
        p->rgbBlue=(temp>0xFF ? 0xFF : temp);
    }
}
void contrast16(IMAGE* img){
    unsigned short r,g,b;
    if(img->bi.compression){
        for (int y=img->bi.height-1; y>=0; --y)
            for (int x=img->bi.width-1; x>=0; --x){
                RGB16* p = (RGB16*) IDX(img,x,y);
                r=(R565(*p))*((R565(*p))>0x0F ? 1.1 : 0.9);
                g=(G565(*p))*((G565(*p))>0x1F ? 1.15 : 0.85);
                b=(B565(*p))*((B565(*p))>0x0F ? 1.1 : 0.9);
                *p=RGB565((r>0x1F ? 0x1F : r),(g>0x3F ? 0x3F : g),(b>0x1F ? 0x1F : b));
            }
    }
    else{
        for (int y=img->bi.height-1; y>=0; --y)
            for (int x=img->bi.width-1; x>=0; --x){
                RGB16* p = (RGB16*) IDX(img,x,y);
                r=(R555(*p))*((R555(*p))>0x0F ? 1.1 : 0.9);
                g=(G555(*p))*((G555(*p))>0x0F ? 1.1 : 0.9);
                b=(B555(*p))*((B555(*p))>0x0F ? 1.1 : 0.9);
                *p=RGB555((r>0x1F ? 0x1F : r),(g>0x1F ? 0x1F : g),(b>0x1F ? 0x1F : b));
            }
    }
}
void contrast24(IMAGE* img){
    int temp;
    for (int y=img->bi.height-1; y>=0; --y)
        for (int x=img->bi.width-1; x>=0; --x){
            RGBTRIPLE* p = (RGBTRIPLE*) IDX(img,x,y);
            temp=(p->rgbtRed)*(p->rgbtRed>0x7F ? 1.15 : 0.85);
            p->rgbtRed=(temp>0xFF ? 0xFF : temp);
            temp=(p->rgbtGreen)*(p->rgbtGreen>0x7F ? 1.15 : 0.85);
            p->rgbtGreen=(temp>0xFF ? 0xFF : temp);
            temp=(p->rgbtBlue)*(p->rgbtBlue>0x7F ? 1.15 : 0.85);
            p->rgbtBlue=(temp>0xFF ? 0xFF : temp);
        }
}
void contrast32(IMAGE* img){
    int temp;
    for (int y=img->bi.height-1; y>=0; --y)
        for (int x=img->bi.width-1; x>=0; --x){
            RGBQUAD* p = (RGBQUAD*) IDX(img,x,y);
            temp=(p->rgbRed)*(p->rgbRed>0x7F ? 1.15 : 0.85);
            p->rgbRed=(temp>0xFF ? 0xFF : temp);
            temp=(p->rgbGreen)*(p->rgbGreen>0x7F ? 1.15 : 0.85);
            p->rgbGreen=(temp>0xFF ? 0xFF : temp);
            temp=(p->rgbBlue)*(p->rgbBlue>0x7F ? 1.15 : 0.85);
            p->rgbBlue=(temp>0xFF ? 0xFF : temp);
        }
}
void (*contrastfunc[])(IMAGE*) = {contrastLess8,contrast8,contrast16,contrast24,contrast32};

int contrast(char* src, char* dst){
    IMAGE img;
    
    if(!readImage(&img,src)) return 0;

    contrastfunc[img.sizPxl](&img);

    if(!writeImage(&img,dst)) return 0;
    freeImage(&img);
    return 1;
}