#include "Matrix.h"

//Main method
int main() {
  cout << "---------------------------------------" << endl;
  Matrix test1(3, 5); // uninitialized 3x5
  cout << "Test for rows and cols constructor: \n" << test1 << endl;
  cout << "---------------------------------------" << endl;
  Matrix test2{{0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9}}; // initialized 5x2
  cout << "Test sequence constructor: \n" << test2 << endl;
  cout << "---------------------------------------" << endl;
  Matrix test3(test1); // copy of 'test1'
  cout << "Test copy constructor: \n" << test3 << endl;//should output test1
  cout << "---------------------------------------" << endl;
  Matrix test4{{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}}; //initialized 2x5
  cout << "Test fully initialized Matrix: \n" << test4 << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix test2: \n" << test2 << endl;
  cout << "Test add scalar 2 to Matrix test2: \n" << test2.add(2) << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix test2: \n" << test2 << endl;
  cout << "Test to add Matrix test2 to Matrix test2: \n" << test2.add(test2) << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix test4: \n" << test4 << endl;
  cout << "Test subtract scalar 2 from Matrix test4: \n" << test4.subtract(2) << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix test4: \n" << test4 << endl;
  cout << "Test to subtract Matrix test4 from Matrix test4: \n" << test4.subtract(test4) << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix test2: \n" << test2 << endl;
  cout << "Test multiply scalar 5 to Matrix test2: \n" << test2.multiply(5) << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix test2: \n" << test2 << endl;
  cout << "Matrix test4: \n" << test4 << endl;
  cout << "Test multiply test2 by Matrix test4: \n" << test2.multiply(test4) << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix test2: \n" << test2 << endl;
  cout << "Test divide scalar 5 by Matrix test2: \n" << test2.divide(5) << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix test2: \n" << test2 << endl;
  cout << "Transpose test4 Matrix: \n" << test4.t() << endl;
  cout << "---------------------------------------" << endl;
  cout << "Test number if rows: \n" << test1.numRows() << endl;
  cout << "Test number if columns: \n" << test1.numCols() << endl;
  cout << "---------------------------------------" << endl;
  cout << "Test set index values using at(row,col): \n" << endl;
  test1.at(0, 0) = 5;
  test1.at(1, 3) = 7;
  test1.at(1, 4) = 9;
  cout << "Modified matrix: \n" << test1 << endl;
  cout << "---------------------------------------" << endl;
  cout << "Examples from project sheet: \n";
  Matrix a(2, 2);
  a.at(0, 0) = 1; // [ 1, 2 ]

  a.at(0, 1) = 2; // [ 1, 3 ]
  a.at(1, 0) = 1;
  a.at(1, 1) = 3;
  cout << a << endl;
  Matrix b(2, 1);
  b.at(0, 0) = 3; // [ 3 ]
  b.at(1, 0) = 2; // [ 2 ]
  cout << b << endl;
  Matrix c = a.multiply(b);
  cout << "[ " << c.at(0, 0) << " ]" << endl // [ 7 ]
	   << "[ " << c.at(1, 0) << " ]" << endl; // [ 9 ]
  cout << "---------------------------------------" << endl;
  cout << "**Random tests to test functionality of Matrix**" << endl;
  cout << "test 2 + test 2 " << endl;
  cout << (test2 + test2) << endl;
  cout << "---------------------------------------" << endl;
  cout << " Test 2 / 3.7  \n" << test2 / 3.7 << endl;
  cout << "---------------------------------------" << endl;
  cout << "copy with overload without constructor: " << endl;
  test1 = test2;
  cout << test1 << endl;

}//main

