#include <iostream>
#include <string>

using namespace std;
int main() 
{
	string name;
	cin >> name;
	int letters = 1;

	for (int i = 1; i < name.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			
			if(name[i]!=name[j])
			{
				if (j == (i - 1))
				{
					letters++;
				}
				continue;
			}
			else
			{
				break;
			}
			
		}
	}
	if (letters % 2 == 0)
	{
		cout << "CHAT WITH HER!";
	}
	else
	{
		cout << "IGNORE HIM!";
	}
}
