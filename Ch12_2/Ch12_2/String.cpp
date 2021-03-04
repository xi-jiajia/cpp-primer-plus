#include <iostream>
#include <cstring>
#include "String.h"

int String::num_strings = 0; // 静态数据成员的初始化？

String::String(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, (len + 1), s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, (len + 1), s.str);
	num_strings++;
}

String::~String()
{
	delete[] str;
	num_strings--;
}

String& String::operator=(const String& s)
{
	if (this == &s)
	{
		return *this;
	}
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, (len + 1), s.str);
	return *this;
}

String& String::operator=(const char* c)
{
	delete[] str;
	len = strlen(c);
	str = new char[len + 1];
	strcpy_s(str, (len + 1), c);
	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

String operator+(const char* c, const String& s)
{
	String result;
	result.len = strlen(c) + s.len;
	result.str = new char[result.len + 1];
	strcpy_s(result.str, (result.len + 1), c);
	strcat_s(result.str, (result.len + 1), s.str);
	return result;
}

String operator+(const String& s1, const String& s2)
{
	String result;
	result.len = s1.len + s2.len;
	result.str = new char[result.len + 1];
	strcpy_s(result.str, (result.len + 1), s1.str);
	strcat_s(result.str, (result.len + 1), s2.str); // 关于strcat_s()？
	return result;
}

bool operator<(const String& s1, const String& s2)
{
	return(strcmp(s1.str, s2.str) < 0); // 关于strcmp()？
}

bool operator>(const String& s1, const String& s2)
{
	return(strcmp(s1.str, s2.str) > 0);
}

bool operator==(const String& s1, const String& s2)
{
	return(strcmp(s1.str, s2.str) == 0);
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& s) // 重载>>运算符？
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
	{
		s = temp;
	}
	while (is && is.get() != '\n')
	{
		continue;
	}
	return is;
}

void String::Stringlow()
{
	for (int i = 0; i < len; i++)
	{
		str[i] = tolower(str[i]);
	}
}

void String::Stringup()
{
	for (int i = 0; i < len; i++)
	{
		str[i] = toupper(str[i]);
	}
}

int String::Has(char c) const
{
	int result = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			result++;
		}
	}
	return result;
}

int String::HowMany() // 静态成员函数?
{
	return num_strings;
}