#pragma once
#include <iostream>
class String
{
	char* array;
	int length;
public:
	String() : length{ 0 }, array{ nullptr } {}
	String(const String& str) : length{ str.length }
	{
		array = new char[length + 1];
		for (int i = 0; i < length; i++)
			array[i] = str.array[i];
		array[length] = '\0';
	}
	String(const char* cstr) : length{ (int)strlen(cstr) }
	{
		array = new char[length + 1];
		for (int i = 0; i < length; i++)
			array[i] = cstr[i];
		array[length] = '\0';
	}
	String(char symbol, int count) : length{ count }
	{
		array = new char[length + 1];
		for (int i = 0; i < length; i++)
			array[i] = symbol;
		array[length] = '\0';
	}

	String(int) = delete;
	String(char) = delete;

	~String()
	{
		if (array)
			delete[] array;
	}

	friend std::ostream& operator<<(std::ostream& out, String s);
};

