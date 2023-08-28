enum NUMBER_OF_ROOTS
{
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};


//! @brief Checks if two doubles are equal.
//!
//! @param [in] a First number
//! @param [in] b Second number
//! @return 1 if they are equal, 0 otherwise.
//!
//! @note Uses an epsilon defined in float.h: DBL_EPSILON.
int DoubleEq(const double a, const double b);


int IsDoubleZero(const double a);

//! @brief Rounds to 0 if close
//!
//! @param [in] a Double value
//! @return 0 if close to it, a otherwise
//!
//! Used because a function can return -0, so round it
double DoubleRoundIfZero(const double a);


//! @brief Solves a linear equation.
//!
//! @param [in] a Coefficient a
//! @param [in] b Coefficient b
//! @param [out] x Solution to be written
//! @return Number of roots.
//!
//! @warning If the equation has 0 or infinite solutions,
//! x will not be touched.
int SolveLinear(const double a, const double b, double* x);


//! @brief Solves a quadratic equation.
//!
//! @param [in] a Coefficient a
//! @param [in] b Coefficient b
//! @param [in] c Coefficient c
//! @param [out] x1 First Solution to be written
//! @param [out] x2 Second Solution to be written
//! @return Number of roots.
//!
//! @warning If the equation has less than 2 solutions,
//! some x's will not be touched:\n
//! 0 and infinite solutions - x1 and x2,\n
//! 1 solution - x2.
int SolveSquare(const double a, const double b, const double c,
                double* x1, double* x2);
