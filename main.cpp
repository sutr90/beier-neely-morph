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
    save_png(result, "../../result_single.png");
    uint64 end = GetTimeMs64();
    cout << end - start << endl;


    start = GetTimeMs64();
    std::vector<line> lines_from = {line(point(79, 216), point(79, 52)),
                                    line(point(84, 46), point(190, 46))};

    std::vector<line> lines_to = {line(point(79, 216), point(79, 52)),
                                  line(point(84, 46), point(186, 17))};

    MorphMultipleLines mml = MorphMultipleLines(lines_from, lines_from);
    mml.morph_image_dlib(img, result, 300, 1, 0);

    end = GetTimeMs64();
    cout << end - start << endl;

    save_png(result, "../../result_multi.png");
    return 0;
}

