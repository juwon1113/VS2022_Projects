#include <iostream>
#include "CMyString.h"

using namespace std;

// 기본 생성자
CMyString::CMyString() {
	cout << "CMyString()" << endl;
}

// Deep copy를 위한 복사 생성자
// 원본을 보호하기 위해 const를 사용
CMyString::CMyString(const CMyString& rhs) {
	this->setData(rhs.getData());
}

CMyString::~CMyString() {
	cout << "~CMyString()" << endl;
	delete[] m_data;
}

// 주소를 반환하는 함수
// 주소를 반환받을 때는 포인터 변수로 받아야 한다.
// const 멤버 함수로 객체 상태 변경 불가
char* CMyString::getData() const {
	return m_data;
}

size_t CMyString::getLength() const {
	return this->length;
}

// 문자열 리터럴(큰따옴표로 감싼 문자열)은 const char* 타입이므로 char* 타입에는 전달 불가능
void CMyString::setData(const char* pParam)
{
	// 기존 메모리가 할당되어 있다면 메모리 누수를 방지하기 위해 해제한다.
	if (m_data != nullptr)
		delete[] m_data;

	// pParam의 길이를 구하고 +1을 하여 메모리 할당을 한다.
	size_t length = strlen(pParam);
	m_data = new char[length + 1];		// +1은 '\0'를 위한 공간

	// m_data에 pParam을 복사한다.
	strcpy_s(m_data, length + 1, pParam); // strcpy_s(대상, 대상 크기, 복사자)

	this->length = length;
}

// Deep copy를 위한 대입 연산자 오버로딩
// 주의: setter함수에 독립적인 메모리 할당이 진행되어야한다.
void CMyString::operator=(const CMyString& rhs) {
	this->setData(rhs.getData());
}