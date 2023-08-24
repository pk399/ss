#include <stdio.h>

#include "ss.h"
#include "io.h"
#include "ss_testing.h"


void PrintResult(int n_roots, double x1, double x2)
{
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
            dbg_printf("Reached default case!\n");
    }
}


void ScanCoefficients(double* a, double* b, double* c)
{
    while(scanf("%lf%lf%lf", a, b, c) != 3)
    {
        printf("# Incorrect input\n");
        ClearBuffer();
    }
}


void ClearBuffer(void)
{
    while (getchar() != '\n')
        continue;
}

