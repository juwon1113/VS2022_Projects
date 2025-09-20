#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();
	
	// Getter �Լ� - ��ü ���� ������ �������� �ʱ� ���� ���ȭ
	char* getData() const;
	size_t getLength() const;

	// Setter �Լ� - �޾ƿ� ������ �������� �ʱ� ���� ���ȭ
	void setData(const char* pParam);

private:
	// ������ ����� ���ÿ� �ʱ�ȭ
	char* m_data = nullptr;
	size_t length = 0;
};