#include <iostream>
#include <cctype>
#include <Windows.H>
using namespace std;

int StrLen(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
void remove_symbol(char str[], char symbol);
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
	const int n = 256;
	char str[n]="Аргентина     манит      негра";
	cout << "введите строки:";
	//cin >> str;
	//cin.getline(str, n);
	cout << str << endl;
	cout << "Длина Введенной строки:" << StrLen(str) << endl;
   // to_upper(str);
	//cout << str << endl;
	//to_lower(str);
	shrink(str);
	//cout << str << endl;
	cout<<is_palindrome(str)<<endl;
	//char str[] = "Hello";
	cout << str << endl;
}
	int StrLen(char str[])
	{	
		int i = 0;
		for (; str[i]; i++);
		return i;
	}

	/*void to_upper(char str[])
	{
		char ch;

		for (int i = 0; i < strlen(str); i++) 
		{
			ch = toupper(str[i]);

			cout << ch;
		}
		cout << endl;
	}*/
	
	void to_upper(char str[])
	{
		//если элемент строки str[i]-маленькая буква
		
		for (int i = 0; str[i]; i++)
		{
			if (
				str[i] >= 'a' && str[i] <= 'z'||
				str[i] >= 'а' && str[i] <= 'я'
				)
				str[i] -= 32;//тогда его в большую букву.
		}
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
 
	void shrink(char str[])
	{
		for (int i = 0; str[i]; i++)
		{
			while (str[i] == ' ' && str[i+1] == ' ')
			{
				for (int j =i; str[j]; j++)str[j] = str[j + 1];
			}
		}
	}


	void remove_symbol(char str[], char symbol)
	{
		for (int i = 0; str[i]; i++)
		{
			while (str[i] == symbol)
			{
				for (int j = i; str[j]; j++)str[j] = str[j + 1];
			}
		}
	}
	
	bool is_palindrome(char str[])
	{
		char* buffer = new char[strlen(str) + 1]{};
		for (int i = 0; str[i]; i++)buffer[i] = str[i];
		remove_symbol(buffer,' ');
		cout << str << endl;
		int n = strlen(buffer);
		to_upper(buffer);
		for (int i = 0;i< n / 2; i++)
		{
			if (buffer[i] != buffer[n - 1 - i])
			{
				delete buffer;
				return false;
			}
		}
		delete buffer;
		return true;
	}