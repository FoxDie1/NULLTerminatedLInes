#include <iostream>
#include <cctype>
#include <Windows.H>
using namespace std;

int StrLen(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
bool is_integer(char str[]);
bool is_bin(char str[]);
bool is_hex(char str[]);



void main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(121);
	//char str[] = {'H','e','l','l','o',0};
	const int n = 20;
	char str[n];
	cout << "введите строки:";
	//cin >> str;
	cin.getline(str, n);
	cout << str << endl;
	cout << "ƒлина ¬веденной строки:" << StrLen(str) << endl;
    to_upper(str);
	to_lower(str);
	//char str[] = "Hello";
	//cout << str << endl;
}
	int StrLen(char str[])
	{	
		int i = 0;
		for (; str[i]; i++);
		return i;
	}

	void to_upper(char str[])
	{
		char ch;

		for (int i = 0; i < strlen(str); i++) 
		{

			// convert str[i] to uppercase
			ch = toupper(str[i]);

			cout << ch;
		}
		cout << endl;
	}
	
	void to_lower(char str[])
	{
		char ch;

		for (int i = 0; i < strlen(str); i++) 
		{

			// convert str[i] to uppercase
			ch = tolower(str[i]);

			cout << ch;
		}
		cout << endl;
	}