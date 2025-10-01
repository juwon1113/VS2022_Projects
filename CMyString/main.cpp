#include <iostream>
#include "CMyString.h"

using namespace std;

CMyString getstr() {
	CMyString str;
	str.setData("hello");
	return str;
}

int main(void)
{
	CMyString str1;
	str1 = ::getstr();
	cout << str1 << endl;

	CMyString str2(move(::getstr()));

	return 0;
}