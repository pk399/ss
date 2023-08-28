//! @brief Reference input for TestSquare.
struct TestInput
{
    double a;
    double b;
    double c;


    double x1;
    double x2;

    int n_roots;
};


//! @brief Represents n_roots as a string.
//!
//! @param [in] n_roots Member of the NUMBER_OF_ROOTS enum
//!
//! @return String containing n_roots representation written in English.
const char* to_str(int n_roots);


//! @brief Runs one test for SolveSquare.
//!
//! @param [in] test_number Prints this number when failed
//! @param [in] test_input Reference values for the test
//! @return 0 if successful, 1 if failed
//!
//! @note Prints nothing when the test was successful.
int TestSquare(int test_number, const TestInput* test_input);


//! @brief Reads double from file.
//!
//! @param [in] file Pointer to file to be read
//! @param [out] n Double that will be given read value
//!
//! Used because scanf does not read NaN values.
void FileScanDoubleOrNaN(FILE* file, double* n);


//! @brief Fill an array with TestInputs from file.
//!
//! @param [in] tests_file Pointer to a file to be read
//! @param [out] test_inputs Array that will be written to
//! @param [in] test_inputs_size Size of the array and the number of test in a file
//!
//! @warning If the file has incorrect formatting,
//! the function will stop an error, partially filling an array.
void ParseTests(FILE* tests_file, TestInput test_inputs[], int test_inputs_size);


//! @param [in] path Path to file containing tests
//! @return Number of failed tests, -1 if file could not be opened.
//!
//! @todo Add an enum specifying error returns.
int RunTestsFromFile(const char path[]);


#define dbg_printf(str) \
    printf("Failed in function %s:%d\n", __PRETTY_FUNCTION__, __LINE__); \
    printf(str)
