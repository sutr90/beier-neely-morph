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

    void morph_image_dlib(dlib::array2d<dlib::rgb_pixel> &img_in, dlib::array2d<dlib::rgb_pixel> &img_out);

    static dlib::point perp(const dlib::point &pt);

    static double u_func(dlib::point &X, dlib::point &Q, dlib::point &P);

    static double v_func(dlib::point &X, dlib::point &Q, dlib::point &P);

    static dlib::point x_prime(double u, double v, dlib::point &Pp, dlib::point &Qp);
};


class MorphMultipleLines {
private:
    std::vector<line> &from;
    std::vector<line> &to;
    double dist_segment(dlib::point X, line l, double u, double v);

public:
    MorphMultipleLines(std::vector<line> &from, std::vector<line> &to);

    void morph_image_dlib(dlib::array2d<dlib::rgb_pixel> &img_in, dlib::array2d<dlib::rgb_pixel> &img_out, double a,
                          double b, double p);


};


#endif //MORPH_MORPH_DLIB_H
