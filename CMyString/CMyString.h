#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();
	char* getData();
	void setData(const char* pParam);

private:
	// 포인터 선언과 동시에 초기화
	char* m_data = nullptr;
};