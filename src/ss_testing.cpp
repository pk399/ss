#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "ss.h"
#include "ss_testing.h"

char* to_str(int num_of_roots)
{
    switch( num_of_roots )
    {
        case NO_ROOTS:
            return "no roots";

        case ONE_ROOT:
            return "one root";

        case TWO_ROOTS:
            return "two roots";

        case INF_ROOTS:
            return "infinite roots";

        default:
           dbg_printf("Reached default case!!!!!\n");
    }
}


/*void PrintNRootsText(const int n_roots)
{
    switch (n_roots)
    {
        case NO_ROOTS:
            printf("no roots");
            //break;

        case ONE_ROOT:
            printf("one root");
            //break;

        case TWO_ROOTS:
            printf("two roots");
            //break;

        case INF_ROOTS:
            printf("infinite number of roots");
            //break;

        default:
            // __PRETTY_FUNCTION__, __LINE__
            //printf("%s:%d", __PRETTY_FUNCTION__, __LINE__);
            dbg_printf( "Reached default case!\n");
            //PrintIllegalNRootsValue("PrintNRootsText", n_roots);
    }
}*/

int TestSquare(int test_number, const TestInput* test_ref)
{
    double x1 = NAN, x2 = NAN;
    int n_roots = SolveSquare(test_ref->a, test_ref->b,
                              test_ref->c, &x1, &x2);

    if ( test_ref->n_roots != n_roots ||
         ( (test_ref->n_roots > 0) && !DoubleEq(test_ref->x1, x1) ) ||
         ( (test_ref->n_roots > 1) && !DoubleEq(test_ref->x2, x2) ) )
    {
        printf("a=%.2f, b=%.2f, c=%.2f - Failure!\n",
               test_ref->a, test_ref->b, test_ref->c);
        printf("\tTest #%d\n", test_number);


        //if (exp_n_roots != n_roots)
            printf("\tExpected %s, but got %s\n",
                   to_str(test_ref->n_roots), to_str(n_roots));

            /*printf("\tExpected ");
            //PrintNRootsText(exp_n_roots);
            printf(", got ");
            PrintNRootsText(n_roots);
            printf("\n");*/


        //if ((n_roots > 0) && !DoubleEq(exp_x1, x1))
            printf("\tExpected x1 = %.3f, got %.3f\n", test_ref->x1, x1);

        //if ((n_roots > 1) && !DoubleEq(exp_x2, x2))
            printf("\tExpected x2 = %.3f, got %.3f\n", test_ref->x2, x2);

        return 1;
    }

    return 0;
}

void FileScanDoubleOrNaN(FILE* file, double* n)
{
    char n_str[BIG_NUM] = "";
    fscanf(file, "%s", n_str);

    if (strcmp(n_str, "nan") == 0)
    {
        *n = NAN;
    }
     else
    {
        *n = atof(n_str);
    }
}

void ParseTests(FILE* tests_file, TestInput test_inputs[], int test_inputs_size)
{
    // ScanDoubles(tests_file, coeffs, &coeffs_size);
    // fscanf( test_file, "%lf %lf %lf %lf %lf %d",
    // TestInput* test_inputs

    // fscanf( "%lf %lf ...", &test_inputs[i].a, &test_inputs[i].b

    for (int i = 0; i < test_inputs_size; i++)
    {
        TestInput test_input = {NAN, NAN, NAN, INF_ROOTS, NAN, NAN};

        fscanf(tests_file, "%lf %lf %lf %d", &test_input.a, &test_input.b, &test_input.c,
               &test_input.n_roots);
        FileScanDoubleOrNaN(tests_file, &test_input.x1);
        FileScanDoubleOrNaN(tests_file, &test_input.x2);

        //printf("%f\n", test_input.x2);

        test_inputs[i] = test_input;
    }
}

int RunTestsFromFile(char path[])
{
    printf("Running tests from %s...\n", path);

    FILE* tests_file = fopen(path, "r");

    if (tests_file == NULL)
    {
        printf("%s: ERROR: Can't open file with tests\n", __PRETTY_FUNCTION__);
        return 0;
    }

    int n = 0;
    fscanf(tests_file, "%d", &n);

    TestInput* test_inputs = (TestInput*) malloc(n * sizeof(TestInput));
    // realloc( test_inputs, 2 * n );


    ParseTests(tests_file, test_inputs, n);
    fclose(tests_file);
    //char s[n];
    // float* arr = (float*)malloc(32);
    // arr[0]

    /*TestInput test_inputs[] = { { 1., 2., 1., ONE_ROOT, -1., NAN },
                                { 1., -2., 1., TWO_ROOTS, 1., NAN } };*/

    int failed_tests = 0;

    for (int i = 0; i < n; i++)
    {
        failed_tests += TestSquare(i+1, &test_inputs[i]);
    }

    free(test_inputs);

    if (failed_tests == 0)
    {
        printf("All tests were successful!\n");
    }
     else
    {
        printf("Tests failed: %d\n", failed_tests);
    }

    return failed_tests;

    /*TestSquare(2, 1., -2., 1., ONE_ROOT, 1., NAN);
    TestSquare(3, 1., 0, -4., TWO_ROOTS, -2., 2.);
    TestSquare(4, 1., 0, 1., NO_ROOTS, NAN, NAN);
    TestSquare(0, 0, 0, INF_ROOTS, NAN, NAN);
    TestSquare(0, 0, 1., NO_ROOTS, NAN, NAN);
    TestSquare(1., -5., 4., TWO_ROOTS, 1., 4.);
    TestSquare(1., -7., 12., TWO_ROOTS, 3., 4.);  */
}
