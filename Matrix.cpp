
#include "Matrix.h"
#include <list>
#include <string>
#include <iostream>
#include "Matrix.h"
#include <iterator>
using namespace std;
/*
 This constructor will accept two uint variables
 ,rows and cols. It will then create a matrix with
 the respect number of rows and cols and assign 0
 for each element.
 @param rows uint variable for numbers of row
 @param cols uint variable for number of column
 @return None
 */
Matrix::Matrix(uint rows = 0, uint cols = 0) {
  rowN = rows;
  colN = cols;

  matrix = new double *[rowN];
  for (uint r = 0; r < rowN; r++) {
	matrix[r] = new double[colN];
  }
  for (uint r = 0; r < rowN; r++) {
	for (uint c = 0; c < colN; c++) {
	  matrix[r][c] = 0;
	}
  }
}
/*
 This constructor will accept a list of list
 which has double as its elements and base on the
 data from the list of list to create a matrix.
 @param list a constant i_list referance
 @return None
 */
Matrix::Matrix(const i_list &list) {
  i_list::iterator listGet;
  initializer_list<double> tem = *(list.begin());
  rowN = list.size();
  colN = tem.size();
  matrix = new double *[rowN];
  for (uint r = 0; r < rowN; r++) {
	matrix[r] = new double[colN];
  }
  uint r = 0;
  for (listGet = list.begin(); listGet != list.end(); listGet++) {
	initializer_list<double> col = *(listGet);
	uint c = 0;
	initializer_list<double>::iterator listCol;
	for (listCol = col.begin(); listCol != col.end(); listCol++) {
	  matrix[r][c] = *listCol;
	  ++c;
	}
	++r;
  }
}
/*
 This constructor will accept another Matrix
 referance and make a deep copy of that matrix
 @param m a constant Matrix referance
 @return None
 */
Matrix::Matrix(const Matrix &m) {
  rowN = m.numRows();
  colN = m.numCols();
  matrix = new double *[rowN];
  for (uint r = 0; r < rowN; r++) {
	matrix[r] = new double[colN];
  }
  for (uint r = 0; r < rowN; r++) {
	for (uint c = 0; c < colN; c++) {
	  matrix[r][c] = m.at(r, c);
	}
  }
}
/*
 This distructor will delete the matrix
 so that when the program ends. There should
 not be any data left.
 @param None
 @return None
 */
Matrix::~Matrix() {
  for (uint r = 0; r < rowN; r++) {
	delete[] matrix[r];
  }
  delete[] matrix;
}
/*
 This function will make a deep copy of
 the current matrix and add the number
 s(double) from the argument
 @param s double number
 @return Matrix a new Matrix object
 */
Matrix Matrix::add(double s) const {
  Matrix tem(*this);
  for (uint r = 0; r < rowN; r++) {
	for (uint c = 0; c < colN; c++) {
	  tem.at(r, c) += s;
	}
  }
  return tem;
}
/*
 This function will make a deep copy of
 the current matrix and add the numbers
 from the other matrix,m.
 @param m a constant Matrix referance
 @return Matrix a new Matrix object
 */
Matrix Matrix::add(const Matrix &m) const {
  Matrix tem(*this);
  if (rowN == m.numRows() && colN == m.numCols()) {
	for (uint r = 0; r < rowN; r++) {
	  for (uint c = 0; c < colN; c++) {
		tem.at(r, c) += m.at(r, c);
	  }
	}
  } else {
	cout << "You are trying to add two matrixs, but they are in different dimension\n";
  }
  return tem;
}
/*
 This function will make a deep copy of
 the current matrix and subtract the number
 s(double) from the argument.
 @param s double number
 @return Matrix a new Matrix object
 */
Matrix Matrix::subtract(double s) const {
  Matrix tem(*this);
  for (uint r = 0; r < rowN; r++) {
	for (uint c = 0; c < colN; c++) {
	  tem.at(r, c) -= s;
	}
  }
  return tem;
}
/*
 This function will make a deep copy of
 the current matrix and subtract the numbers
 from the other matrix,m.
 @param m a constant Matrix referance
 @return Matrix a new Matrix object
 */
Matrix Matrix::subtract(const Matrix &m) const {
  Matrix tem(*this);
  if (rowN == m.numRows() && colN == m.numCols()) {
	for (uint r = 0; r < rowN; r++) {
	  for (uint c = 0; c < colN; c++) {
		tem.at(r, c) -= m.at(r, c);
	  }
	}
  } else {
	cout << "You are trying to subtract two matrixs, but they are in different dimension\n";
  }
  return tem;
}
/*
 This function will make a deep copy of
 the current matrix and multiply a number
 s(double)
 @param s double number
 @return Matrix a new Matrix object
 */
Matrix Matrix::multiply(double s) const {
  Matrix tem(*this);
  for (uint r = 0; r < rowN; r++) {
	for (uint c = 0; c < colN; c++) {
	  tem.at(r, c) *= s;
	}
  }
  return tem;
}
/*
 This function will make a deep copy of
 the current matrix and multiply another
 matrix,m if their column and row's number
 are the same.
 @param m a constant Matrix referance
 @return Matrix a new Matrix object
 */
Matrix Matrix::multiply(const Matrix &m) const {
  if (colN == m.numRows()) {
	Matrix tem(rowN, m.numCols());
	for (uint mainR = 0; mainR < rowN; mainR++) {
	  for (uint otherC = 0; otherC < m.numCols(); otherC++) {
		double newV = 0;
		for (uint otherR = 0; otherR < m.numRows(); otherR++) {
		  newV += matrix[mainR][otherR] * m.at(otherR, otherC);
		}
		tem.at(mainR, otherC) = newV;
	  }
	}
	return tem;
  } else {
	cout << "Try to do mutiply a matrix, but different dimension\n";
	Matrix tem(0, 0);
	return tem;
  }
}
/*
 This function will make a deep copy of
 the current matrix and divide all the
 element with the number s(double)
 @param s double number
 @return Matrix a new Matrix object
 */
Matrix Matrix::divide(double s) const {
  Matrix tem(*this);
  for (uint r = 0; r < rowN; r++) {
	for (uint c = 0; c < colN; c++) {
	  tem.at(r, c) /= s;
	}
  }
  return tem;
}
/*
 This function will create a matrix with
 the dimension of row and column swopping
 with each other and the assign the data
 respectly.
 @param None
 @return Matrix a new Matrix object
 */
Matrix Matrix::t() const {
  Matrix tem(colN, rowN);
  for (uint r = 0; r < rowN; r++) {
	for (uint c = 0; c < colN; c++) {
	  tem.at(c, r) = this->at(r, c);
	}
  }
  return tem;
}
/*
 This function will return the number
 of rows
 @param None
 @return uint of rows number
 */
const uint Matrix::numRows() const {
  return rowN;
}
/*
 This function will return the number
 of columns
 @param None
 @return uint of column number
 */
const uint Matrix::numCols() const {
  return colN;
}
/*
 This function will get the element
 from row of row and column of col
 @param row a uint variable
 @param col a uint variable
 @return double referance
 */
double &Matrix::at(uint row, uint col) {
  return (matrix[row][col]);
}
/*
 This function will get the element
 from row of row and column of col
 @param row a uint variable @param col a uint variable
 @return a constant double referance
 */
const double &Matrix::at(uint row, uint col) const {
  return matrix[row][col];
}
/*
 This function will change the operator ()
 so that the variable Matrix can work as the function
 at(uint row, uint col)
 @param row a uint variable
 @param col a uint variable
 @return a double referance
 */
double &Matrix::operator()(uint row, uint col) {
  return matrix[row][col];
}
/*
 This function will change the operator +
 so that the variable Matrix can work as the function
 add(double s)
 @param s double number
 @return Matrix a new Matrix object
 */
Matrix Matrix::operator+(double s) {
  return this->add(s);
}
/*
 This function will change the operator +
 so that the variable Mastrix can work as the function
 add(const Matrix & m)
 @param m a constant Matrix referance
 @return Matrix a new Matrix object
 */
Matrix Matrix::operator+(const Matrix &m) {
  return this->add(m);
}
/*
 This function will change the operator -
 so that the variable Mastrix can work as the function
 subtract(double s)
 @param s double number
 @return Matrix a new Matrix object
 */
Matrix Matrix::operator-(double s) {
  return this->subtract(s);
}
/*
 This function will change the operator -
 so that the variable Matrix can work as the function
 substract(const Matrix &m)
 @param m a constant Matrix referance
 @return Matrix a new Matrix object
 */Matrix Matrix::operator-(const Matrix &m) {
  return this->subtract(m);
}
/*
 This function will change the operator *
 so that the variable Matrix can work as the function
 multiply(double s)
 @param s double number
 @return Matrix a new Matrix object
 */
Matrix Matrix::operator*(double s) {
  return this->multiply(s);
}
/*
 This function will change the operator *
 so that the variable Matrix can work as the
 function multiply(const Matrix & m)
 @param m a constant Matrix referance
 @return Matrix a new Matrix object
 */
Matrix Matrix::operator*(const Matrix &m) {
  return this->multiply(m);
}
/*
 This function will change the operator /
 so that the variable Matrix can work as the
 function divide(double s)
 @param s double number
 @return Matrix a new Matrix object
 */
Matrix Matrix::operator/(double s) {
  return this->divide(s);
}
/*
 This function will change the operator =
 so that the variable Matrix can work as the
 constructor Matrix(const Matrix & m)
 @param m a constant Matrix referance
 @return Matrix a new Matrix object
 */
Matrix Matrix::operator=(const Matrix &m) {
  for (uint r = 0; r < rowN; r++) {
	delete[] matrix[r];
  }
  delete[] matrix;
  rowN = m.numRows();
  colN = m.numCols();
  matrix = new double *[rowN];
  for (uint r = 0; r < rowN; r++) {
	matrix[r] = new double[colN];
  }
  for (uint r = 0; r < rowN; r++) {
	for (uint c = 0; c < colN; c++) {
	  matrix[r][c] = m.at(r, c);
	}
  }
  return *this;
}
/*
 This function will change the operator =
 so that the variable Matrix can work as the
 constructor Matrix(const i_list & list)
 @param list a constant i_list referance
 @return Matrix a new Matrix object
 */
Matrix Matrix::operator=(const i_list &list) {
  for (uint r = 0; r < rowN; r++) {
	delete[] matrix[r];
  }
  delete[] matrix;
  i_list::iterator listGet;
  initializer_list<double> tem = *(list.begin());
  rowN = list.size();
  colN = tem.size();
  matrix = new double *[rowN];
  for (uint r = 0; r < rowN; r++) {
	matrix[r] = new double[colN];
  }
  uint r = 0;
  for (listGet = list.begin(); listGet != list.end(); listGet++) {
	initializer_list<double> col = *(listGet);
	uint c = 0;
	initializer_list<double>::iterator listCol;
	for (listCol = col.begin(); listCol != col.end(); listCol++) {
	  matrix[r][c] = *listCol;
	  ++c;
	}
	++r;
  }
  return *this;
}
/*
 This function will change the operator <<
 so that std::cout can print out the way we
 want for Matrix object
 @param out ostream referance
 @param m constant Matirx referance
 @return ostream object (string)
 */
ostream &operator<<(ostream &out, const Matrix &m) {
  if (m.numRows() == 0 || m.numCols() == 0) {
	out << "Empty\n";
	return out;
  } else {
	for (uint r = 0; r < m.numRows(); r++) {
	  out << "[ ";
	  for (uint c = 0; c < m.numCols(); c++) {
		out << (m.at(r, c));
		if (c + 1 < m.numCols()) out << ", ";
	  }
	  out << " ]\n";
	}
	return out;
  }
}
/* This function will change the operator + from
 number to Matrix object so that it can work as
 Matrix add a constant number
 @param s double number
 @param m constant Matrix referance
 @return Matrix a new Matrix object
 */
Matrix operator+(double s, const Matrix &m) {
  return m.add(s);
}
/*
 This function will change the operator - from
 number to Matrix object so that it can work as
 the number substract to each element in the
 Matrix
 @param s double number
 @param m constant Matrix referance
 @return Matrix a new Matrix object
 */
Matrix operator-(double s, const Matrix &m) {
  Matrix tem(m);
  for (uint r = 0; r < m.numRows(); r++) {
	for (uint c = 0; c < m.numCols(); c++) {
	  tem(r, c) = (s - m.at(r, c));
	}
  }
  return tem;
}
/*
 This function will change the operator * from
 number to Matrix object so that it can work as
 the number times every element in the Matrix
 @param s double number
 @param m constant Matrix referance
 @return Matrix a new Matrix object
 */
Matrix operator*(double s, const Matrix &m) {
  return m.multiply(s);
}
/*
 This function will change the operator / from
 number to Matrix object so that it can work as
 every element from the Matrix divied by the number
 @param s double number
 @param m constant Matrix referance
 @return Matrix a new Matrix object
 */
Matrix operator/(double s, const Matrix &m) {
  Matrix tem(m);
  for (uint r = 0; r < m.numRows(); r++) {
	for (uint c = 0; c < m.numCols(); c++) {
	  tem(r, c) = (s / m.at(r, c));
	}
  }
  return tem;
}/*
 This function will change the operator - to
 make every element times a negative 1
 @param None
 @return Matrix a new Matrix object
 */
Matrix Matrix::operator-() {
  return this->multiply(-1);
}