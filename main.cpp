#include <iostream>
#include "GetTimeMs.h"
#include "morph_dlib.h"

#include <dlib/image_io.h>

using namespace std;
using namespace dlib;

int main(int argc, char *argv[]) {

    array2d<rgb_pixel> img;
    load_image(img, "../../template.jpg");

    array2d<rgb_pixel> result(img.nr(), img.nc());

    uint64 start = GetTimeMs64();

    line from(point(86, 136), point(153, 136));
    line to(point(361, 121), point(401, 107));

    MorphSingleLine msl = MorphSingleLine(from, to);
    msl.morph_image_dlib(img, result);
    save_png(result, "../../result_single.png");
    uint64 end = GetTimeMs64();
    cout << "time " << end - start << endl;


    start = GetTimeMs64();
    std::vector<line> lines_from = {line(point(86, 137), point(153, 136)),
                                    line(point(93, 212), point(148, 210)),
                                    line(point(86, 137), point(93, 212)),
                                    line(point(153, 136), point(148, 210))};

    std::vector<line> lines_to = {line(point(361, 121), point(401, 107)),
                                  line(point(369, 162), point(414, 147)),
                                  line(point(361, 121), point(369, 162)),
                                  line(point(401, 107), point(414, 147))};

    MorphMultipleLines mml = MorphMultipleLines(lines_to, lines_from);
    mml.morph_image_dlib(img, result, 200, 1, 0);

    end = GetTimeMs64();
    cout << end - start << endl;

    save_png(result, "../../result_multi.png");
    return 0;
}

