#include <iostream>


using namespace std;

int main() {
	string str;
	cin >> str;
	int sum = 0;
	int i = 0;
	for (; i < str.size(); i++)
	{
		if (str[i] == 'h') {
			i++;
			sum++;
			break;
		}
	}
	for (; i < str.size(); i++)
	{
		if (str[i] == 'e') {
			i++;
			sum++;
			break;
		}
	}
	for (; i < str.size(); i++)
	{
		if (str[i] == 'l') {
			i++;
			sum++;
			break;
		}
	}
	for (; i < str.size(); i++)
	{
		if (str[i] == 'l') {
			i++;
			sum++;
			break;
		}
	}
	for (; i < str.size(); i++)
	{
		if (str[i] == 'o') {
			i++;
			sum++;
			break;
		}
	}
	if (sum == 5)
	{
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}
