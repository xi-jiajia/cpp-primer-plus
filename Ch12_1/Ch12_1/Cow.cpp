#include <iostream>
#include <cstring>
#include "Cow.h"

Cow::Cow()
{
	name[0] = '\0'; // 对字符串数据成员的初始化?
	hobby = nullptr;
	weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strncpy_s(name, nm, 20);
	if (strlen(nm) >= 20) // strlen()与sizeof()区别?
	{
		name[19] = '\0';
	}
	else
	{
		name[strlen(nm)] = '\0';
	}
	hobby = new char[strlen(ho) + 1];
	strcpy_s(hobby, (strlen(ho) + 1), ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy_s(name, 20, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, (strlen(c.hobby) + 1), c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c)
	{
		return *this;
	}
	if (hobby != nullptr) // 对nullptr的判断？
	{
		delete[] hobby;
	}
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(name, 20, c.name);
	strcpy_s(hobby, (strlen(c.hobby) + 1), c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	if (hobby == nullptr)
	{
		std::cout << "This Cow's info is Empty!" << std::endl;
		return;
	}
	else
	{
		std::cout << "This is Information of COW." << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Hobby: " << hobby << std::endl;
		std::cout << "Weight: " << weight << std::endl;
	}
}