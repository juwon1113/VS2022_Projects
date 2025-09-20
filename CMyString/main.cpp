#include <iostream>
#include "CMyString.h"

using namespace std;

int main(void)
{
	CMyString str;

	str.setData("Hello");
	cout << str.getData() << endl;
	cout << "length: " << str.getLength() << endl;

	return 0;
}