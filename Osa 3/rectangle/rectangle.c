#include "rectangle.h"
#include <stdlib.h>

Rectangle * createRectangle(void)
{
    Rectangle *rect = malloc(sizeof(Rectangle));
    
    if (rect == NULL) {
        return NULL;
    }
    
    rect->width = 0;
    rect->height = 0;
    rect->origin.x = 0;
    rect->origin.y = 0;
    
    return rect;
}

Rectangle * createRectangle2(Point p)
{
    Rectangle *rect = malloc(sizeof(Rectangle));

    if (rect == NULL) {
        return NULL;
    }
    
    rect->width = 0;
    rect->height = 0;
    rect->origin.x = p.x;
    rect->origin.y = p.y;

    return rect;
}

Rectangle * createRectangle3(int w, int h)
{
    Rectangle *rect = malloc(sizeof(Rectangle));
    
    if (rect == NULL) {
        return NULL;
    }
    
    rect->width = w;
    rect->height = h;
    rect->origin.x = 0;
    rect->origin.y = 0;
    
    return rect;
}

Rectangle * createRectangle4(Point p, int w, int h)
{
    Rectangle *rect = malloc(sizeof(Rectangle));
    
    if (rect == NULL) {
        return NULL;
    }
    
    rect->width = w;
    rect->height = h;
    rect->origin.x = p.x;
    rect->origin.y = p.y;
    
    return rect;
}

void move(Rectangle *r, int x, int y)
{
    r->origin.x = x;
    r->origin.y = y;
}

int getArea(const Rectangle *r)
{
    return r->height * r->width;
}