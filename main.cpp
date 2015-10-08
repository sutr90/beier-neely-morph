#include <iostream>
#include "GetTimeMs.h"
#include "morph_dlib.h"

#include <dlib/image_io.h>

using namespace std;
using namespace dlib;

int main(int argc, char *argv[]) {

    array2d<rgb_pixel> img;
    load_image(img, "../../file.png");

    array2d<rgb_pixel> result(img.nr(), img.nc());

    uint64 start = GetTimeMs64();

    point Pp(0, 0);
    point Qp(0, 4);
    point P(0, 0);
    point Q(0, 8);
    line from = std::make_pair(Pp, Qp);
    line to = std::make_pair(P, Q);

    MorphSingleLine msl = MorphSingleLine(from, to);
    msl.morph_image_dlib(img, result);

    uint64 end = GetTimeMs64();


    std::vector<point> from =

    cout << end - start;

    save_png(result, "../../result.png");
    return 0;
}

