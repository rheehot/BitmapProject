#include "bitmap.h"
#define DISPERSE(VAL,MAX,FAC) (((MAX)>>1)+(((VAL)-((MAX)>>1))*(FAC)))
#define INRANGE(VAL,MAX) (((VAL)>(MAX))?(MAX):(((VAL)<0)?0:(VAL)))

void contrastLess8(IMAGE* img){
    //TODO: processing
    return;
}
void contrast8(IMAGE* img){
    for(RGBQUAD* p=((RGBQUAD*)(img->extra))+(img->bi.clrUsed-1);p>=(RGBQUAD*)(img->extra);--p){
        short temp=DISPERSE(p->rgbRed,0xFF,1.5);
        p->rgbRed=INRANGE(temp,0xFF);
        temp=DISPERSE(p->rgbGreen,0xFF,1.5);
        p->rgbGreen=INRANGE(temp,0xFF);
        temp=DISPERSE(p->rgbBlue,0xFF,1.5);
        p->rgbBlue=INRANGE(temp,0xFF);
    }
}
void contrast16(IMAGE* img){
    short r,g,b;
    if(img->bi.compression){
        for (int y=img->bi.height-1; y>=0; --y)
            for (int x=img->bi.width-1; x>=0; --x){
                RGB16* p = (RGB16*) IDX(img,x,y);
                r=DISPERSE(R565(*p),0x1F,1.3);
                g=DISPERSE(G565(*p),0x3F,1.4);
                b=DISPERSE(B565(*p),0x1F,1.3);
                *p=RGB565(INRANGE(r,0x1F),INRANGE(g,0x3F),INRANGE(b,0x1F));
            }
    }
    else{
        for (int y=img->bi.height-1; y>=0; --y)
            for (int x=img->bi.width-1; x>=0; --x){
                RGB16* p = (RGB16*) IDX(img,x,y);
                r=DISPERSE(R555(*p),0x1F,1.3);
                g=DISPERSE(G555(*p),0x1F,1.3);
                b=DISPERSE(B555(*p),0x1F,1.3);
                *p=RGB555(INRANGE(r,0x1F),INRANGE(g,0x1F),INRANGE(b,0x1F));
            }
    }
}
void contrast24(IMAGE* img){
    for (int y=img->bi.height-1; y>=0; --y)
        for (int x=img->bi.width-1; x>=0; --x){
            RGBTRIPLE* p = (RGBTRIPLE*) IDX(img,x,y);
            short temp=DISPERSE(p->rgbtRed,0xFF,1.5);
            p->rgbtRed=INRANGE(temp,0xFF);
            temp=DISPERSE(p->rgbtGreen,0xFF,1.5);
            p->rgbtGreen=INRANGE(temp,0xFF);
            temp=DISPERSE(p->rgbtBlue,0xFF,1.5);
            p->rgbtBlue=INRANGE(temp,0xFF);
        }
}
void contrast32(IMAGE* img){
    for (int y=img->bi.height-1; y>=0; --y)
        for (int x=img->bi.width-1; x>=0; --x){
            RGBQUAD* p = (RGBQUAD*) IDX(img,x,y);
            short temp=DISPERSE(p->rgbRed,0xFF,1.5);
            p->rgbRed=INRANGE(temp,0xFF);
            temp=DISPERSE(p->rgbGreen,0xFF,1.5);
            p->rgbGreen=INRANGE(temp,0xFF);
            temp=DISPERSE(p->rgbBlue,0xFF,1.5);
            p->rgbBlue=INRANGE(temp,0xFF);
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