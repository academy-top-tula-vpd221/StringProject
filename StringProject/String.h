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

	int Length();
	bool Empty();

	String operator=(String s);
	String operator=(const char*);

	friend String operator+(String, String);
	friend String operator+(String, const char*);
	friend String operator+(const char*, String);

	String operator+=(String);
	String operator+=(const char*);
	String operator+=(char);
	String operator+=(int) = delete;

	char operator[](int);

	void Clear(); // очистка строки
	
	String Insert(int, char);
	String Insert(int, const char*);
	String Insert(int, String);

	String Erase(int index, int count);

	int Compare(String);
	int Compare(const char*);

	bool Contains(String);
	bool Contains(const char*);

	String SubStr(int index, int count);

	String Replace(int index, int count, String);
	String Replace(int index, int count, const char*);

	int IndexOf(String);
	int IndexOf(const char*);

	int IndexLastOf(String);
	int IndexLastOf(const char*);

	friend std::ostream& operator<<(std::ostream& out, String s);
	//friend std::istream& operator>>(std::istream& in, String s);
};

