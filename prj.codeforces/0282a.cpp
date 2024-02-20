#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int count;
	cin >> count;
	string str;
	int X = 0;
	for (int i = 0; i < count; i++)
	{
		cin >> str;
		if (str == "X++" || str == "++X")
		{
			X++;
		}
		if (str == "X--" || str == "--X")
		{
			X--;
		}
	}
	cout << X;
}
