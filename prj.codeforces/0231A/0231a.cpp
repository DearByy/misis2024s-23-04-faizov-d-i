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
	vector<int> answ;
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
				j += 1;
			}
		}
		if (j >= 2)
		{
			answ.push_back(1);
		}
		else
		{
			answ.push_back(0);
		}
	}
	int sumansw = std::accumulate(answ.begin(), answ.end(), 0);
	cout << sumansw;
}

