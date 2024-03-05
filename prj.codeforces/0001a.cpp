#include <iostream>


using namespace std;
int main() 
{
	long long  x1, x2, a;
	cin >> x1 >> x2 >> a;
	long long  width = (x1 + a - 1) / a;
	long long  length = (x2 + a - 1) / a;
	long long answ = width * length;
	cout << answ;

}
