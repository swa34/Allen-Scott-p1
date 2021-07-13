
#include "Matrix.h"

using namespace std;
/*constructor all initialized to 0*/
Matrix::Matrix(uint rows = 0, uint cols = 0) {
  rowN = rows;
  colN = cols;

  matrix = new double *[rowN];
  for (auto i = 0; i < rowN; i++) {
	matrix[i] = new double[colN];
  }
  for (uint i = 0; i < rowN; i++) {
	for (uint j = 0; j < colN; j++) {
	  matrix[i][j] = 0;
	}
  }
}
/*initializer list constructor*/
Matrix::Matrix(const i_list &list) {
  i_list::iterator listGet;
  initializer_list<double> tem = *(list.begin());
  rowN = list.size();
  colN = tem.size();
  matrix = new double *[rowN];
  for (uint i = 0; i < rowN; i++) {
	matrix[i] = new double[colN];
  }
  uint i = 0;
  for (listGet = list.begin(); listGet != list.end(); listGet++) {
	initializer_list<double> col = *(listGet);
	uint j = 0;
	initializer_list<double>::iterator listCol;
	for (listCol = col.begin(); listCol != col.end(); listCol++) {
	  matrix[i][j] = *listCol;
	  ++j;
	}
	++i;
  }
}
/*copy constructor */
Matrix::Matrix(const Matrix &m) {
  rowN = m.numRows();
  colN = m.numCols();
  matrix = new double *[rowN];
  for (uint i = 0; i < rowN; i++) {
	matrix[i] = new double[colN];
  }
  for (uint i = 0; i < rowN; i++) {
	for (uint j = 0; j < colN; j++) {
	  matrix[i][j] = m.at(i, j);
	}
  }
}
/*destructor */
Matrix::~Matrix() {
  for (uint i = 0; i < rowN; i++) {
	delete[] matrix[i];
  }
  delete[] matrix;
}
/*add scalar */
Matrix Matrix::add(double s) const {
  Matrix temp(*this);
  for (uint i = 0; i < rowN; i++) {
	for (uint j = 0; j < colN; j++) {
	  temp.at(i, j) += s;
	}
  }
  return temp;
}
/*add this matrix to another only if in same dimension*/
Matrix Matrix::add(const Matrix &m) const {
  Matrix temp(*this);
  if (rowN == m.numRows() && colN == m.numCols()) {
	for (uint i = 0; i < rowN; i++) {
	  for (uint j = 0; j < colN; j++) {
		temp.at(i, j) += m.at(i, j);
	  }
	}
  } else {
	cout << "Not allowed to add Matrix in different dimension\n";
  }
  return temp;
}
/*subtract scalar */
Matrix Matrix::subtract(double s) const {
  Matrix temp(*this);
  for (uint i = 0; i < rowN; i++) {
	for (uint j = 0; j < colN; j++) {
	  temp.at(i, j) -= s;
	}
  }
  return temp;
}
/*subtract this matrix from another only if in same dimension*/
Matrix Matrix::subtract(const Matrix &m) const {
  Matrix temp(*this);
  if (rowN == m.numRows() && colN == m.numCols()) {
	for (uint i = 0; i < rowN; i++) {
	  for (uint j = 0; j < colN; j++) {
		temp.at(i, j) -= m.at(i, j);
	  }
	}
  } else {
	cout << "Not allowed to subtract from matrix in different dimension\n";
  }
  return temp;
}
/*multiply by scalar */
Matrix Matrix::multiply(double s) const {
  Matrix temp(*this);
  for (uint i = 0; i < rowN; i++) {
	for (uint j = 0; j < colN; j++) {
	  temp.at(i, j) *= s;
	}
  }
  return temp;
}
/*multiply this matrix by another matrix
 * ONLY if numCols() of the first == numRows()
 * of the second. if not, returns copy of calling matrix.
 */
Matrix Matrix::multiply(const Matrix &m) const {
  if (this->colN == m.numRows()) {
	Matrix temp(this->rowN, m.numCols());
	double sum;
	for (uint i = 0; i < temp.numRows(); i++) {
	  for (uint j = 0; j < temp.numCols(); j++) {
		sum = 0;
		for (uint k = 0; k < this->colN; k++) {
		  sum += this->at(i, k) * m.at(k, j);
		}
		temp.at(i, j) = sum;
	  }
	}
	return temp;
  } else {
	Matrix same(*this);
	return same;
  }
}
/*divide by scalar unless scalar = 0 */
Matrix Matrix::divide(double s) const {
  Matrix temp(*this);
  for (uint i = 0; i < rowN; i++) {
	for (uint j = 0; j < colN; j++) {
	  temp.at(i, j) /= s;
	}
  }
  return temp;
}
/*transposes matrix */
Matrix Matrix::t() const {
  Matrix temp(this->colN, this->rowN);
  for (uint i = 0; i < temp.numRows(); i++) {
	for (uint j = 0; j < temp.numCols(); j++) {
	  temp.at(i, j) = this->at(j, i);
	}
  }
  return temp;
}
/*number of rows */
const uint Matrix::numRows() const {
  return rowN;
}
/*number of columns
 */
const uint Matrix::numCols() const {
  return colN;
}
/*get/set element at row/col*/
double &Matrix::at(uint row, uint col) {
  return (matrix[row][col]);
}
/*get/set element when obj is const */
const double &Matrix::at(uint row, uint col) const {
  return matrix[row][col];
}

double &Matrix::operator()(uint row, uint col) {
  return matrix[row][col];
}
/*change the operator + add(double s)*/
Matrix Matrix::operator+(double s) {
  return this->add(s);
}

Matrix Matrix::operator+(const Matrix &m) {
  return this->add(m);
}

Matrix Matrix::operator-(double s) {
  return this->subtract(s);
}

Matrix Matrix::operator-(const Matrix &m) {
  return this->subtract(m);
}

Matrix Matrix::operator*(double s) {
  return this->multiply(s);
}

Matrix Matrix::operator*(const Matrix &m) {
  return this->multiply(m);
}

Matrix Matrix::operator/(double s) {
  return this->divide(s);
}

Matrix Matrix::operator=(const Matrix &m) {
  for (uint i = 0; i < rowN; i++) {
	delete[] matrix[i];
  }
  delete[] matrix;
  rowN = m.numRows();
  colN = m.numCols();
  matrix = new double *[rowN];
  for (uint i = 0; i < rowN; i++) {
	matrix[i] = new double[colN];
  }
  for (uint i = 0; i < rowN; i++) {
	for (uint j = 0; j < colN; j++) {
	  matrix[i][j] = m.at(i, j);
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
  for (uint i = 0; i < rowN; i++) {
	delete[] matrix[i];
  }
  delete[] matrix;
  i_list::iterator listGet;
  initializer_list<double> temp = *(list.begin());
  rowN = list.size();
  colN = temp.size();
  matrix = new double *[rowN];
  for (uint i = 0; i < rowN; i++) {
	matrix[i] = new double[colN];
  }
  uint i = 0;
  for (listGet = list.begin(); listGet != list.end(); listGet++) {
	initializer_list<double> col = *(listGet);
	uint j = 0;
	initializer_list<double>::iterator listCol;
	for (listCol = col.begin(); listCol != col.end(); listCol++) {
	  matrix[i][j] = *listCol;
	  ++j;
	}
	++i;
  }
  return *this;
}

ostream &operator<<(ostream &out, const Matrix &m) {
  if (m.numRows() == 0 || m.numCols() == 0) {
	out << "Empty\n";
	return out;
  } else {
	for (uint i = 0; i < m.numRows(); i++) {
	  out << "[ ";
	  for (uint j = 0; j < m.numCols(); j++) {
		out << (m.at(i, j));
		if (j + 1 < m.numCols()) out << ", ";
	  }
	  out << " ]\n";
	}
	return out;
  }
}

Matrix operator+(double s, const Matrix &m) {
  return m.add(s);
}

Matrix operator-(double s, const Matrix &m) {
  Matrix temp(m);
  for (uint i = 0; i < m.numRows(); i++) {
	for (uint j = 0; j < m.numCols(); j++) {
	  temp(i, j) = (s - m.at(i, j));
	}
  }
  return temp;
}
Matrix operator*(double s, const Matrix &m) {
  return m.multiply(s);
}
Matrix operator/(double s, const Matrix &m) {
  Matrix temp(m);
  for (uint i = 0; i < m.numRows(); i++) {
	for (uint j = 0; j < m.numCols(); j++) {
	  temp(i, j) = (s / m.at(i, j));
	}
  }
  return temp;
}
Matrix Matrix::operator-() {
  return this->multiply(-1);
}