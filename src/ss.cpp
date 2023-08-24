#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>

#include "ss.h"


int DoubleEq(const double a, const double b)
{
    assert(isfinite(a));

    return fabs(a-b) < DBL_EPSILON;
}


int IsDoubleZero(const double a)
{
    return DoubleEq(a, 0.);
}


int SolveLinear(const double a, const double b, double* x)
{
    assert(isfinite(a));
    assert(isfinite(b));

    assert(x != NULL);

    if (IsDoubleZero(a))
    {
        return IsDoubleZero(b) ? INF_ROOTS : NO_ROOTS;
    }
     else // a != 0
    {
        *x = -b / a;
        return ONE_ROOT;
    }
}

int SolveSquare(const double a, const double b, const double c,
                double* x1, double* x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (IsDoubleZero(a))
    {
        return SolveLinear(b, c, x1);
    }
     else // a != 0
    {
        double d = b*b - 4*a*c;

        if (IsDoubleZero(d))
        {
            *x1 = -b / (2*a);
            return ONE_ROOT;
        }
         else if (d < 0)
        {
            return NO_ROOTS;
        }
         else // d > 0
        {
            double sqrt_d = sqrt(d);

            *x1 = (-b - sqrt_d) / (2*a);
            *x2 = (-b + sqrt_d) / (2*a);

            return TWO_ROOTS;
        }
    }
}

