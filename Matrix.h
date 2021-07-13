#ifndef Matrix_h
#define Matrix_h
#include <string>
#include <initializer_list>
#include <iostream>
using namespace std;
typedef unsigned int uint;
typedef initializer_list<initializer_list<double>> i_list;
class Matrix {
 private:
  double ** matrix;
  uint rowN, colN;
 public:
  /**
   * Constructor. All elements initialized to 0.
   *
   * @param rows the number of desired rows
   * @param cols the number of desired cols
   */
  Matrix(uint rows, uint cols); // constructor (all elements initialized to 0)
  /**
  * Constructor. Uses initializer list.
  *
  * @param list the reference to the initializer list of doubles passed by the user. these will be the values in the matrix indices
  */
  Matrix(const i_list & list); // constructor (using initializer list)
  /**
   * Copy Constructor.
   *
   * @param m the matrix from which the calling matrix will copy
   */
  Matrix(const Matrix & m); // copy constructor
  /**
  * Deallocates memory that was created.
  */
  ~Matrix(); // destructor
  /**
   * Adds the scalar s to all of the values of the calling matrix.
   *
   * @param s the double value to add
   * @return new matrix with updated values reflecting the addition by the scalar s
   */
  Matrix add(double s) const; // add scalar to this matrix
  /**
   * Adds all the values in the given matrix to all the values in the calling matrix.
   * Note: 2 matrices can only be added if numRows() and numCols() of first == numRows() and numCols() of second
   *
   * @param m the const matrix that will be added to the calling matrix
   * @return new matrix reflecting the addition
   */
  Matrix add(const Matrix & m) const; // add this matrix and another matrix
  /**
   * Subtracts the scalar s from all the values of the calling matrix.
   *
   * @param s the double value to subtract
   * @return new matrix with updated values reflecting the subtraction by the scalar s
   */
  Matrix subtract(double s) const; // subtract scalar from this matrix
  /**
   * Subtracts all the values in the given matrix from the values of the calling matrix.
   * Note: 2 matrices can only be subtracted if numRows() and numCols() of first == numRows() and numCols() of second
   *
   * @param m the const matrix that will be subtracted from the calling matrix
   * @return new matrix reflecting the subtraction
   */
  Matrix subtract(const Matrix & m) const; // subtract another matrix from this matrix
  /**
  * Multiplies all the values in the calling matrix by the specified scalar.
  *
  * @param s the double value to multiply by
  * @return new matrix with updated values reflecting the multiplication by the scalar s
  */
  Matrix multiply(double s) const; // multiply this matrix by a scaler
  /**
   * Multiplies all the values in the calling matrix by the values in the given matrix. Uses matrix multiplication rules.
   * Note: 2 matrices can only be multiplied if numCols() of first == numRows() of second.
   *
   * @param m the const matrix that will be multiplied with the calling matrix
   * @return new matrix reflecting the multiplication. size will be numRows() of first x numCols() of second
   */
  Matrix multiply(const Matrix & m) const; // multiply this matrix by another matrix
  /**
   * Divides all the values in the calling matrix by the specified scalar.
   *
   * @param s the double value to divide by
   * @return new matrix with updated values reflecting the division by the scalar s
   */
  Matrix divide(double s) const; // divide this matrix by a scaler
  /**
  * Transposes the calling matrix, i.e. swaps the row values with the col values.
  *
  * @return a new, transposed version of the calling matrix
  */
  Matrix t() const; // transpose of this matrix

  /**
	* Gets the number of rows of the calling matrix.
	*
	* @return the number of rows
	*/
  const uint numRows() const;

  /**
   * Gets the number of cols of the calling matrix.
   *
   * @return the number of cols
   */
  const uint numCols() const;

  /**
   * Gets the element at row/col index.
   *
   * @param row the row of the desired value
   * @param col the col of the desired value
   * @return the double value at the specified row/col index
   */
  double & at(uint row, uint col);

  /**
   * Gets the element at row/col index. For use with const matrix.
   *
   * @param row the row of the desired value
   * @param col the col of the desired value
   * @return the const double value at the specified row/col index
   */
  const double & at (uint row, uint col) const; // get element at row,col (when using a const object)
  /**
  * Function call operator overload. Allows access of values at row/col indices of calling matrix without using at() function.
  *
  * @param row the row of the desired value
  * @param col the col of the desired value
  * @return the reference to the  double value at the specified row/col index
  */
  double & operator()(uint row, uint col);
  /**
  * Copy assignment operator overload. Copies values from one matrix into another without copy constructor.
  *
  * @param m the reference to the matrix whose values are being copied over
  * @return a reference to the matrix pointed to by 'this'
  */
  Matrix  operator=(const Matrix & m);
  /**
  * Copy assignment operator overload. Copies values from one matrix into another without copy constructor.
  *
  * @param list the reference to the matrix whose values are being copied in i_list over
  * @return a reference to the matrix pointed to by 'this'
  */
  Matrix operator=(const i_list & list);
  /**
 * Creates a new matrix whose values reflect the result of the scalar  being added to the Matrix.
 *
 * @param s the scalar
 * @return a new matrix containing the added values
 */
  Matrix operator+(double s);
/**
 * Creates a new matrix whose values reflect the result of Matrix being added to Matrix.
 * Only does the addition if dimensions of both Matrix are the same
 *
 * @param m the Matrix to be added
 * @return a new matrix containing the added values
 */
  Matrix operator+(const Matrix & m);
  /**
  * Creates a new matrix whose values reflect the result of the scalar  being subtracted from the Matrix.
  *
  * @param s the scalar
  * @return a new matrix containing the subtracted values
  */
  Matrix operator-(double s);
  /**
 * Creates a new matrix whose values reflect the result of Matrix being subtracted from the Matrix.
 * Only does the subtraction if dimensions of both Matrix are the same
 *
 * @param m the Matrix to subtracted
 * @return a new matrix containing the subtracted values
 */
  Matrix operator-(const Matrix & m);
  /**
   * Change the operator * from
   * number to Matrix object so that it can work as
   *	the number times every element in the Matrix
   * @param s double number
   * @param m constant Matrix reference
   * @return Matrix a new Matrix object
   */
  Matrix operator*(double s);
  /**
 * Creates a new matrix whose values reflect the result of multiplying the given 2 matrices.
 *
 * @param  Matrix m
 * @return a new matrix containing the multiplied values
 */

  Matrix operator*(const Matrix & m);
  /**
 * Creates a new matrix whose values reflect the result of one matrixs values being divided by scala.
 * Note: Only does the division if the divisor is not 0.
 *
 * @param s to be divided
 * @return a new matrix containing the divided values
 */
  Matrix operator/(double s);
  /**
  * Unary minus operator overload. Negates the values of the calling matrix.
  *
  * @return a matrix containing the negated values of the calling matrix
  */
  Matrix operator-();
  /**
 * Stream insertion operator overload.
 *
 * @param output the ostream reference into which the matrix output will be directed
 * @param matrix the matrix reference whose data will be directed into the ostream
 * @return reference to the ostream containing the desired matrix output
 */
  friend ostream& operator<<(ostream& out, const Matrix& matrix);


}; // Matrix
#endif /* Matrix_h */
