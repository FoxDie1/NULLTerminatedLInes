#include <iostream>
#include <Windows.H>
using namespace std;

int StrLen(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
void remove_symbol(char str[], char symbol);
bool is_polindrom(char str[]);
bool is_integer(char str[]);
bool is_bin(char str[]);
bool is_hex(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(121);
	const int n = 256;
	char str[n];// = "Show     Must    Go   On";
	cout << "введите строку:";
	cin >> str;
	//cin.getline(str, n);
	cout << str << endl;
	cout << "Длина введенной строки:"<<StrLen(str) << endl;
	//to_upper(str);
	//cout << str << endl;
	//to_lower(str);
	//cout << str << endl;
	//shrink(str);
	//cout << str << endl;
	//is_polindrom(str);
	//cout << str << endl;
	cout << "Введите число:"; cin >> str;
	cout<<is_integer(str)<<endl;
	cout << is_bin(str) << endl;
	//cout << is_hex(str) << endl;
}

int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'a' && str[i] <= 'z' ||
			str[i] >= 'а' && str[i] <= 'я')
			str[i] -= 32;
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= 'А' && str[i] <= 'Я')
			str[i] += 32;
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] = symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}

bool is_polindrom(char str[])
{
	char* buffer = new char[StrLen(str) + 1]{};
	for (int i = 0; str[i]; i++)buffer[i] = str[i];
	remove_symbol(buffer,' ');
	cout << str << endl;
	int n = StrLen(buffer);
	to_upper(buffer);
	for (int i = 0; i < n / 2; i++)
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
//следующие задания через цикл фор и ифы
bool is_integer(char str[])
{
	int i = 0;
	while (str[i] >= '0'&& str[i] <= '9')i++;
	if (str[i])
	{
		return false;
	}
	return true;	
}

bool is_bin(char str[])
{
	int i = 0;
	const int n = 4;
	char a[n] = "01";
	while (str[i] == a[i])i++;
	if (str[i]!=a[i])
	{
		return false;
	}
	return true;
}
bool is_hex(char str[])
{
	int i = 0;
	const int n = 17;
	char a[n]="0123456789ABCDEF";
	while (str[i] == a[i])i++;
	if (str[i] != a[i])
	{
		return false;
	}
	return true;
}