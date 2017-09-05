#include <stdio.h>
#include "test/common/expect_death.h"
#include "Halide.h"

using namespace Halide;

int main(int argc, char **argv) {
    HALIDE_EXPECT_DEATH(argc, argv);

    Var x, y;

    Buffer<int> input(5, 5);
    Func f;
    f(x, y) = input(x, y) * 2;
    f.vectorize(x, 8).vectorize(y, 8);

    // Should result in an error
    Buffer<int> out = f.realize(5, 5);

    printf("Success!\n");
    return 0;
}
