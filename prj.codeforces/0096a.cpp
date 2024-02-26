#include <iostream>
#include <string>


using namespace std;
int main() 
{
	string str;
	cin >> str;
	int count = 1;
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == str[i - 1])
		{
			count++;
		}
		else
		{
			count = 1;
		}
		if (count == 7) 
		{
			cout << "YES";
			break;
		}
	}
	if (count != 7)
	{
		cout << "NO";
	}
}
