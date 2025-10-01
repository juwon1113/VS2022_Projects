#include <iostream>
#include "CMyString.h"

using namespace std;

// 기본 생성자
CMyString::CMyString() {
	cout << "CMyString()" << endl;
}

// 명시적 변환 생성자
// explicit는 헤더파일에만 작성 가능
CMyString::CMyString(const char* param) {
	cout << "CMyString(const char*)" << endl;
	this->setData(param);
}

// Deep copy를 위한 복사 생성자
// 원본을 보호하기 위해 const를 사용
// 참조: 완전한 상태만 받을 수 있음
CMyString::CMyString(const CMyString& rhs) {
	cout << "CMyString(const CMyString&)" << endl;
	this->setData(rhs.getData());
}

// noexcept: 이동 사용 보장하기 위한 장치(예외 발생 시 복사 사용)
// && 사용 이유: 곧 사라질 임시 객체의 포인터를  안전하게 사용하기 위함
// 임시 객체 -> 자동 이동, 일반 객체 -> std::move()로 수동 이동
// 일반 객체 이동 후 원본은 사용 금지
CMyString::CMyString(CMyString&& rhs) noexcept {
	cout << "CMyString(CMyString&&) - move" << endl;
	this->m_data = rhs.m_data;
	this->length = rhs.length;
	rhs.m_data = nullptr;
	rhs.length = 0;
}

// 소멸자
CMyString::~CMyString() {
	cout << "~CMyString()" << endl;
	delete[] m_data;
}

// 주소를 반환하는 함수
// 주소를 반환받을 때는 포인터 변수로 받아야 한다.
// const 멤버 함수로 객체 상태 변경 불가
const char* CMyString::getData() const {
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
CMyString& CMyString::operator=(const CMyString& rhs) {
	if (this != &rhs)		// 자기 대입 방지 (s1 = s1)
	{
		this->setData(rhs.getData());
	}

	// this는 포인터이므로 *this를 사용해서 원본 반환
	return *this;
}

// 형변환 연산자 (const char*로의 암묵적 변환)
CMyString::operator const char* () const {
	return m_data;
}

// 이동 대입 연산자
// 생성자의 경우 빈 데이터이므로 해제 불가능
// 이동 대입 연산자의 경우 데이터가 들어있으므로 해제 필수
CMyString& CMyString::operator=(CMyString&& rhs) noexcept {
	cout << "operator=(CMyString&&) - move" << endl;
	if (this != &rhs)		// 자기 대입 방지
	{
		delete[] m_data;

		m_data = rhs.m_data;
		length = rhs.length;
		rhs.m_data = nullptr;
		rhs.length = 0;
	}

	// this는 포인터이므로 *this를 사용해서 원본 반환
	return *this;
}