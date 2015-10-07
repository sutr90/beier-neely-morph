//
// Created by VF on 7. 10. 2015.
//

#include "morph_dlib.h"
#include <dlib/geometry.h>

using namespace dlib;

point MorphSingleLine::perp(const point &pt) {
    return point(-pt.y(), pt.x());
}

double MorphSingleLine::u_func(point &X, point &Q, point &P) {
    point a = X - P;
    point b = Q - P;
    double m = b.length();
    return a.dot(b) / m;
}

double MorphSingleLine::v_func(point &X, point &Q, point &P) {
    point a = X - P;
    point b = perp(Q - P);
    double m = b.length();
    return a.dot(b) / m;
}

point MorphSingleLine::x_prime(double u, double v, point &Pp, point &Qp) {
    point a = Qp - Pp;
    point ap = perp(a);
    return Pp + u * a + (v * ap) / a.length();
}

void MorphSingleLine::morph_image_dlib() {
    double u, v;
    for (int y = 0; y < 256; y++) {
        for (int x = 0; x < 256; x++) {
            point X(x, y);
            u = u_func(X, Q, P);
            v = v_func(X, Q, P);
            point Xp = x_prime(u, v, Pp, Qp);
        }
    }
}

MorphSingleLine::MorphSingleLine(line from, line to) : Pp(from.first), Qp(from.second), P(to.first), Q(to.second) {

}
