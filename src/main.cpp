#include <stdio.h>
#include <math.h>

#include "ss.h"
#include "io.h"

#ifdef TESTS
    #include "ss_testing.h"
#endif


int main(void)
{
    #ifdef TESTS
        RunTestsFromFile("ss_tests.txt");
    #endif

    printf("# This program solves square equations in real numbers\n"
           "# Enter the values for coefficients a, b and c:\n");

    double a = NAN, b = NAN, c = NAN;
    ScanCoefficients(&a, &b, &c);

    double x1 = NAN, x2 = NAN;
    int n_roots = SolveSquare(a, b, c, &x1, &x2);

    PrintResult(n_roots, x1, x2);

    return 0;
}
