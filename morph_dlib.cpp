//
// Created by VF on 7. 10. 2015.
//

#include "morph_dlib.h"
#include <dlib/geometry.h>

using namespace dlib;

point Pp_dl(0, 0);
point Qp_dl(0, 4);
point P_dl(-32, 32);
point Q_dl(-27, 35);

point perp(const point &pt){
    return point(pt.x(), pt.y());
}

float u_func(point &X, point &Q, point &P) {
    point a = X-P;
    point b = Q-P;
    float m = b.length();
    return a.dot(b) / m;
}

float v_func(point &X, point &Q, point &P) {
    point a = X-P;
    point b = perp(Q-P);
    float m = b.length();
    return a.dot(b) / m;
}

point x_prime(float u, float v, point &Pp, point &Qp) {
    point a = Qp - Pp;
    point ap = perp(a);
    return Pp + u*a + (v*ap) / a.length();
}

void morph_image_dlib() {
    for (int y = 0; y < 256; y++) {
        for (int x = 0; x < 256; x++) {
            point X(x, y);
            float u = u_func(X, Q_dl, P_dl);
            float v = v_func(X, Q_dl, P_dl);
            point Xp = x_prime(u, v, Pp_dl, Qp_dl);
        }
    }
}
