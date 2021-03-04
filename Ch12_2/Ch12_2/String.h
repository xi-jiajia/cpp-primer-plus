#ifndef STRING_H_
#define STRING_H_

#include <iostream>
#include <cstring>

class String
{
private:
	char* str;
	int len;
	static int num_strings; // ��̬���ݳ�Ա��
	static const int CINLIM = 80; // const���ݳ�Ա��
public:
	String(const char* s);
	String();
	String(const String& s);
	~String();

	String& operator=(const String& s);
	String& operator=(const char* c); // ʹ��C����ַ���������=���������
	char& operator[](int i);
	const char& operator[](int i) const;
	friend String operator+(const char* c, const String& s); // ����������+�������������Ϊ��Ԫ�����෽����
	friend String operator+(const String& s1, const String& s2);
	friend bool operator<(const String& s1, const String& s2);
	friend bool operator>(const String& s1, const String& s2);
	friend bool operator==(const String& s1, const String& s2);
	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);
	
	int lenth() const { return len; }
	void Stringlow();
	void Stringup();
	int Has(char c) const;
	static int HowMany();
};

#endif

