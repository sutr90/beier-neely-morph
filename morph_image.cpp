//
// Created by VF on 7. 10. 2015.
//

#include <cmath>
#include "morph_image.h"

Point Pp(0, 0);
Point Qp(0, 4);
Point P(-32, 32);
Point Q(-27, 35);

int dot(Point &a, Point &b) { return a.x * b.x + a.y * b.y; }

float norm(Point &a) { return (float) sqrt((float) a.x * a.x + a.y * a.y); }

float u_func(Point &X, Point &Q, Point &P) {
    Point a(X.x - P.x, X.y - P.y);
    Point b(Q.x - P.x, Q.y - P.y);
    float m = norm(b);
    return dot(a, b) / m;
}

float v_func(Point &X, Point &Q, Point &P) {
    Point a(X.x - P.x, X.y - P.y);
    Point b(Q.y - P.y, -(Q.x - P.x));
    float m = norm(b);
    return dot(a, b) / m;
}

Point x_prime(float u, float v, Point &Pp, Point &Qp) {
    Point a(Qp.x - Pp.x, Qp.y - Pp.y);
    Point ap(Qp.y - Pp.y, -(Qp.x - Pp.x));
    float m = norm(a);
    Point res(Pp.x + u * a.x + ((v * ap.x) / m),
              Pp.y + u * a.y + ((v * ap.y) / m));
    return res;
}

void morph_image() {
    for (int y = 0; y < 256; y++) {
        for (int x = 0; x < 256; x++) {
            Point X(x, y);
            float u = u_func(X, Q, P);
            float v = v_func(X, Q, P);
            Point Xp = x_prime(u, v, Pp, Qp);
        }
    }
}
