#pragma once

class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& rhs);
	~CMyString();
	
	// Getter 함수 - 객체 안의 변수를 변경하지 않기 위해 상수화
	char* getData() const;
	size_t getLength() const;

	// Setter 함수 - 받아온 변수를 변경하지 않기 위해 상수화
	void setData(const char* pParam);

	void operator=(const CMyString& rhs);

private:
	// 포인터 선언과 동시에 초기화
	char* m_data = nullptr;
	size_t length = 0;
};