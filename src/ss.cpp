#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>

#include "ss.h"


int DoubleEq(const double a, const double b)
{
    assert(isfinite(a));

    return fabs(a - b) < DBL_EPSILON;
}


int IsDoubleZero(const double a)
{
    return DoubleEq(a, 0.);
}


double DoubleRoundIfZero(const double a)
{
    if (fabs(a) < DBL_EPSILON)
    {
        return 0;
    }

    return a;
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

    // a != 0

    *x = -b / a;
    *x = DoubleRoundIfZero(*x);

    return ONE_ROOT;
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

    // a != 0

    double d = b*b - 4*a*c;

    if (IsDoubleZero(d))
    {
        *x1 = -b / (2*a);
        *x1 = DoubleRoundIfZero(*x1);

        return ONE_ROOT;
    }

    if (d < 0)
    {
        return NO_ROOTS;
    }

    // d > 0

    double sqrt_d = sqrt(d);

    *x1 = (-b - sqrt_d) / (2*a);
    *x1 = DoubleRoundIfZero(*x1);

    *x2 = (-b + sqrt_d) / (2*a);
    *x2 = DoubleRoundIfZero(*x2);

    return TWO_ROOTS;
}

