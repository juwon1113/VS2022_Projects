#pragma once

class CMyString
{
public:
	CMyString();
	// ������ ��ȯ ����� �����ϱ� ���ؼ� explicit�� ���
	// ������ ��ȯ ����� �ӽ� ��ü�� �����ϱ� ������ ��ȿ�����̴�.
	explicit CMyString(const char* param);
	CMyString(const CMyString& rhs);
	CMyString(CMyString&& rhs) noexcept;
	~CMyString();
	
	// Getter �Լ� - ��ü ���� ������ �������� �ʱ� ���� ���ȭ
	const char* getData() const;
	size_t getLength() const;

	// Setter �Լ� - �޾ƿ� ������ �������� �ʱ� ���� ���ȭ
	void setData(const char* pParam);

	// Deep copy ���
	CMyString& operator=(const CMyString& rhs);

	// ù ��° const - �޴� ��� ���� �Ұ�, �� ��° const - �ִ� ��� ���� �Ұ�
	// ������ ��ȯ ���
	operator const char* () const;

	// �̵� Ŀ��� ������
	CMyString& operator=(CMyString&& rhs) noexcept;

private:
	// ������ ����� ���ÿ� �ʱ�ȭ
	char* m_data = nullptr;
	size_t length = 0;
};