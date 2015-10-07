//
// Created by VF on 7. 10. 2015.
//

#ifndef MORPH_MORPH_IMAGE_H
#define MORPH_MORPH_IMAGE_H

typedef struct _Point {
public:
    int x;
    int y;

    _Point(int _x, int _y) : x(_x), y(_y) { }

    _Point(float _x, float _y) : x((int) _x), y((int) _y) { }
} Point;

void morph_image();

#endif //MORPH_MORPH_IMAGE_H
