#include <iostream>


using namespace std;

int main() 
{
	int extra = 0;
	int n;
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			extra++;
		}
	}	
	cout << extra;
}
