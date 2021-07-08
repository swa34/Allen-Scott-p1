#include "Matrix.h"


//Main method
int main(){
  cout << "---------------------------------------" << endl;
  Matrix a(3,5); // uninitialized 3x5
  cout << "Test for rows and cols constructor: \n" << a << endl;
  cout << "---------------------------------------" << endl;
  Matrix b{{0,1}, {2,3}, {4,5}, {6,7}, {8,9}}; // initialized 5x2
  cout << "Test sequence constructor: \n" << b << endl;
  cout << "---------------------------------------" << endl;
  Matrix c(a); // copy of 'a'
  cout << "Test copy constructor: \n" << c << endl;//should output a
  cout << "---------------------------------------" << endl;
  Matrix d{{0,1,2,3,4}, {5,6,7,8,9}, {10,11,12,13,14}}; //initialized 3x5
  cout << "Test fully initialized Matrix: \n" << d << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix b: \n" << b << endl;
  cout << "Test add scalar 2 to Matrix b: \n" << b.add(2) << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix b: \n" << b << endl;
  cout << "Test to add Matrix b to Matrix b: \n" << b.add(b) << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix d: \n" << d << endl;
  cout << "Test subtract scalar 2 from Matrix d: \n" << d.subtract(2) << endl;
  cout << "---------------------------------------" << endl;
  cout << "Matrix b: \n" << d << endl;
  cout << "Test to subtract Matrix b from Matrix b: \n" << b.subtract(b) << endl;
  cout << "---------------------------------------" << endl;
}//main

