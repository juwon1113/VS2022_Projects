#pragma once

class CMyString
{
public:
	CMyString();
	explicit CMyString(const char* param);
	CMyString(const CMyString& rhs);
	~CMyString();
	
	// Getter 함수 - 객체 안의 변수를 변경하지 않기 위해 상수화
	const char* getData() const;
	size_t getLength() const;

	// Setter 함수 - 받아온 변수를 변경하지 않기 위해 상수화
	void setData(const char* pParam);

	// Deep copy 기능
	void operator=(const CMyString& rhs);

	// 첫 번째 const - 받는 사람 수정 불가, 두 번째 const - 주는 사람 수정 불가
	// 묵시적 변환 기능
	operator const char* () const;

private:
	// 포인터 선언과 동시에 초기화
	char* m_data = nullptr;
	size_t length = 0;
};