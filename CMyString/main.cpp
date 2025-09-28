#include <iostream>
#include "CMyString.h"

using namespace std;

int main(void)
{
	CMyString str1;

	str1.setData("Hello");
	cout << str1.getData() << endl;

	CMyString str2(str1);
	cout << str2.getData() << endl;

	CMyString str3;
	str3 = str1;
	cout << str3.getData() << endl;

	return 0;
}