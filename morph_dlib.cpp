//
// Created by VF on 7. 10. 2015.
//

#include "morph_dlib.h"
#include <dlib/geometry.h>
#include <dlib/image_transforms/assign_image.h>

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

void MorphSingleLine::morph_image_dlib(dlib::array2d<dlib::rgb_pixel>& img_in, dlib::array2d<dlib::rgb_pixel>& img_out) {
    double u, v;
    dlib::rgb_pixel grey(127, 127, 127);
    assign_all_pixels(img_out, grey);

    for (int y = 0; y < 256; y++) {
        for (int x = 0; x < 256; x++) {
            point X(x, y);
            u = u_func(X, Q, P);
            v = v_func(X, Q, P);
            point Xp = x_prime(u, v, Pp, Qp);
            if (Xp.x() >= 0 && Xp.x() < img_in.nc() && Xp.y() >= 0 && Xp.y() < img_in.nr()) {
                img_out[y][x] = img_in[Xp.y()][Xp.x()];
            }
        }
    }
}

MorphSingleLine::MorphSingleLine(line from, line to) : Pp(from.first), Qp(from.second), P(to.first), Q(to.second) {

}
