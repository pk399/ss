//! @brief Prints quadratic equation solutions nicely.
//!
//! @param [in] n_roots Member of the NUMBER_OF_ROOTS enum
//! @param [in] x1 First solution
//! @param [in] x2 Second solution
//!
//! Prints out text saying how
//! many roots there are
//! and roots themselves.
//!
//! @note If you have less than 2 roots some of them
//! are not used, and can be any value.
void PrintResult(int n_roots, double x1, double x2);


//! @brief Gets 3 coefficients from the user.
//!
//! @param [out] a Coefficient a to be written
//! @param [out] b Coefficient b to be written
//! @param [out] c Coefficient c to be written
//!
//! Gets coefficients by looping
//! until the user enters 3
//! valid consecutive double values.
//!
//! @note Does not prompt anything.
void ScanCoefficients(double* a, double* b, double* c);


/// @brief Clears the input buffer.
//!
//! Clear all characters
//! from input buffer until
//! and including a new line.
void ClearBuffer(void);
