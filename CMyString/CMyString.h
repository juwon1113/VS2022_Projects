#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();
	char* getData();
	void setData(const char* pParam);

private:
	// ������ ����� ���ÿ� �ʱ�ȭ
	char* m_data = nullptr;
};