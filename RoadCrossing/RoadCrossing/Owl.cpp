#include"Owl.h"

Owl::Owl()
{
	mX = 1;
	mY = 25;
	A.a[0][0] = A.a[0][4] = ',';
	A.a[0][1] = A.a[0][2] = A.a[0][3] = A.a[2][1] = A.a[2][4] = '_';
	A.a[1][0] = A.a[2][0] = A.a[2][3] = '(';
	A.a[1][4] = ')';
	A.a[1][1] = A.a[1][3] = '6';
	A.a[1][2] = 'v';
	A.a[2][2] = '^';
	A.a[3][1] = A.a[3][3] = '"';
	A.a[3][0] = A.a[3][2] = A.a[3][4] = ' ';

}

void Owl::display()
{
	TextColor(14);
	Animal::display();
}
