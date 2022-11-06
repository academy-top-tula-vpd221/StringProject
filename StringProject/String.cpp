#include "String.h"

String operator+(String s1, String s2)
{
	String sresult;
	sresult.length = s1.length + s2.length;
	sresult.array = new char[sresult.length + 1];
	int index{};
	for (int i = 0; i < s1.length; i++)
		sresult.array[index++] = s1.array[i];
	for (int i = 0; i < s2.length; i++)
		sresult.array[index++] = s2.array[i];
	
	return sresult;
}

String operator+(String s, const char* cstr)
{
	return s + String(cstr);
}

String operator+(const char* cstr, String s)
{
	return s + String(cstr);
}

std::ostream& operator<<(std::ostream& out, String s)
{
	out << s.array;
	return out;
}

//std::istream& operator>>(std::istream& in, String s)
//{
//	// in >>
//}

int String::Length()
{
	return this->length;
}

bool String::Empty()
{
	return !this->length;
}

String String::operator=(String s)
{
	if (this->array)
		delete array;
	this->length = s.length;
	this->array = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
		this->array[i] = s.array[i];
	this->array[this->length] = '\0';

	return *this;
}

String String::operator=(const char* cstr)
{
	String s(cstr);
	*this = s;

	return *this;
}

String String::operator+=(String s)
{
	*this = *this + s;
	return *this;
}

String String::operator+=(const char* cstr)
{
	return *this = *this + String(cstr);
}

String String::operator+=(char symbol)
{
	char* cstr = new char[this->length + 2];
	for (int i = 0; i < this->length; i++)
		cstr[i] = this->array[i];
	this->length++;
	cstr[this->length - 1] = symbol;
	cstr[this->length] = '\0';

	delete this->array;
	this->array = cstr;

	return *this;
}

char String::operator[](int index)
{
	return this->array[index];
}
