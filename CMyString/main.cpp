#include <iostream>
#include "CMyString.h"

using namespace std;

int main(void)
{
	CMyString str;

	str.setData("Hello");
	cout << str.getData() << endl;

	str.setData("World");
	cout << str.getData() << endl;

	return 0;
}