#include <iostream>
#include <vector>


using namespace std;
int x, y, z;
int main() 
{
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int tempX, tempY, tempZ;
		cin >> tempX >> tempY >> tempZ;
		x += tempX;
		y += tempY;
		z += tempZ;
	}
	if (x == 0 && y == 0 && z == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
