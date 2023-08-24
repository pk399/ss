#include <stdio.h>
#include <math.h>

#include "ss.h"
#include "ss_main.h"
#include "ss_testing.h"


int main(void)
{
    // run_tests()
    // test_square( 1, 2, 1, -1, -1);
    //
    RunTestsFromFile("ss_tests.txt");

    printf("# This program solves square equations in real numbers\n");
    printf("# Enter the values for coefficients a, b and c:\n");

    double a = NAN, b = NAN, c = NAN;
    int result = 0;

    while (1)
    {
        result = scanf("%lf%lf%lf", &a, &b, &c);

        // while( scanf(...) != 3 )
        if (result == 3)
        {
            break;
        }
        else
        {
            printf("# Incorrect input\n");
            // clear_buffer();
            //while (getchar() != '\n') {}
            ClearBuffer();
        }
    }

    //double roots[]
    double x1 = NAN,x2 = NAN;
    int n_roots = SolveSquare(a, b, c, &x1, &x2);

    // print roots function
    switch (n_roots)
    {
        case NO_ROOTS:
            printf("# This equation has no solutions\n");
            break;

        case ONE_ROOT:
            printf("# This equation has one solution:\n");
            printf("%.2lf\n", x1);
            break;

        case TWO_ROOTS:
            printf("# This equation has two solutions:\n");
            printf("%.2lf\n%.2lf\n", x1, x2);
            break;

        case INF_ROOTS:
            printf("# This equation has infinite number of solutions\n");
            break;

        default:
            //PrintIllegalNRootsValue("main", n_roots);
            dbg_printf("Reached default case!!!!\n");
            return 1;
    }

    return 0;
}


void ClearBuffer(void)
{
    while (getchar() != '\n')
        continue;
}
