#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;


int main() 
{
	int count;
	cin >> count;
	std::cin.ignore();// очищаю буфер входящего потока от \n
	int answ = 0;
	for (int i = 0; i < count; i++)
	{
		string str;
		getline(std::cin, str);
		int length = str.size();
		vector<int> arr;
		for (int i = 0; i < length; i++)
		{
			arr.push_back(str[i]);
		}
		vector<int> arr2;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] != 32)
			{
				arr2.push_back(arr[i]);
			}
		}
		int j = 0;

		for (int i = 0; i < arr2.size(); i++)
		{
			if (arr2[i] == 49)
			{
				j ++;
			}
		}
		if (j >= 2)
		{
			answ++;
		}
	}
	cout << answ;
}
