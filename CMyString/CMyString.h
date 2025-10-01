#pragma once

class CMyString
{
public:
	CMyString();
	explicit CMyString(const char* param);
	CMyString(const CMyString& rhs);
	~CMyString();
	
	// Getter �Լ� - ��ü ���� ������ �������� �ʱ� ���� ���ȭ
	const char* getData() const;
	size_t getLength() const;

	// Setter �Լ� - �޾ƿ� ������ �������� �ʱ� ���� ���ȭ
	void setData(const char* pParam);

	// Deep copy ���
	void operator=(const CMyString& rhs);

	// ù ��° const - �޴� ��� ���� �Ұ�, �� ��° const - �ִ� ��� ���� �Ұ�
	// ������ ��ȯ ���
	operator const char* () const;

private:
	// ������ ����� ���ÿ� �ʱ�ȭ
	char* m_data = nullptr;
	size_t length = 0;
};