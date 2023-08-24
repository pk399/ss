// ss.h

enum NUMBER_OF_ROOTS
{
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};

// Equation solver
int DoubleEq(const double a, const double b);
int IsDoubleZero(const double a);

int SolveLinear(const double a, const double b, double* x);
int SolveSquare(const double a, const double b, const double c,
                double* x1, double* x2);

char* to_str(int n_roots);


//const int INF_ROOTS = -1;
