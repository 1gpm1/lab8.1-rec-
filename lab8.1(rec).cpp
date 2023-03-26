#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str, int i)
{
	if (str[i + 1] != 0) {
		if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3]) {
			return 1 + Count(str, i + 1);
		}
		else
			return Count(str, i + 1);
	}
	else
		return 0;
}
void Replace(char* str, int j)
{
	if (str[j] != 0) {
		str[j] = str[j + 2];
		Replace(str, j + 1);
	}
}
void Change(char* str, int i)
{
	if (str[i + 1] != 0) {
		if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3]) {
			str[i] = '*';
			str[i + 1] = '*';

			Replace(str, i + 2);
		}
		Change(str, i + 1);
	}
}
int main()
{
	char str[101];

	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	cout << "There is " << Count(str, 1) << " four simular char in line" << endl;

	Change(str, 0);

	cout << str << endl;

	return 0;
}
