#pragma once

class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& rhs);
	~CMyString();
	
	// Getter �Լ� - ��ü ���� ������ �������� �ʱ� ���� ���ȭ
	char* getData() const;
	size_t getLength() const;

	// Setter �Լ� - �޾ƿ� ������ �������� �ʱ� ���� ���ȭ
	void setData(const char* pParam);

	void operator=(const CMyString& rhs);

private:
	// ������ ����� ���ÿ� �ʱ�ȭ
	char* m_data = nullptr;
	size_t length = 0;
};