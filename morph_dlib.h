//
// Created by VF on 7. 10. 2015.
//

#ifndef MORPH_MORPH_DLIB_H
#define MORPH_MORPH_DLIB_H

#include <utility>
#include <dlib/geometry/vector.h>
#include <dlib/array2d/array2d_kernel.h>
#include <dlib/pixel.h>

typedef std::pair<dlib::point, dlib::point> line;

class MorphSingleLine {
private:
    dlib::point Pp, Qp, P, Q;
public:
    MorphSingleLine(line from, line to);
    void morph_image_dlib(dlib::array2d<dlib::rgb_pixel>& img_in, dlib::array2d<dlib::rgb_pixel>& img_out);

    dlib::point perp(const dlib::point &pt);

    double u_func(dlib::point &X, dlib::point &Q, dlib::point &P);

    double v_func(dlib::point &X, dlib::point &Q, dlib::point &P);

    dlib::point x_prime(double u, double v, dlib::point &Pp, dlib::point &Qp);
};

#endif //MORPH_MORPH_DLIB_H
