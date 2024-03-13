#include <iostream>


using namespace std;

int main() 
{
	int n;
	cin >> n;
	int count = 0;
	int max = 0;


	for (int i = 0; i < n; i++) {

		int enter, exit;
		cin >> exit >> enter;
		count += enter;
		count -= exit;
		if (count > max) {
			max = count;
		}
	}
	cout << max;
}
