const int BIG_NUM = 100;


struct TestInput
{
    double a;
    double b;
    double c;
    int n_roots;
    double x1;
    double x2;
};


void FileScanDoubleOrNaN(FILE* file, double* n);

int TestSquare(int test_number, TestInput test_input);
void ParseTests(FILE* tests_file, TestInput test_inputs[], int test_inputs_size);
int RunTestsFromFile(char path[]);


#define dbg_printf(str) \
    printf("Failed in function %s:%d\n", __PRETTY_FUNCTION__, __LINE__); \
    printf(str)
