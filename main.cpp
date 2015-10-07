#include <iostream>
#include "GetTimeMs.h"
#include "morph_dlib.h"


using namespace std;
using namespace dlib;

int main(int argc, char *argv[]) {
    uint64 start = GetTimeMs64();

    point Pp(0, 0);
    point Qp(0, 4);
    point P(-32, 32);
    point Q(-27, 35);
    line from = std::make_pair(Pp, Qp);
    line to = std::make_pair(P, Q);

    MorphSingleLine msl = MorphSingleLine(from, to);
    msl.morph_image_dlib();

    uint64 end = GetTimeMs64();

    cout << end - start;
    return 0;
}

