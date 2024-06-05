#include <iostream>
using namespace std;

int main()
{
    int n, m, ans;
    cin >> n;
    m = 0;
    ans = 1e5;
    int *a = new int [n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if (n == 1){
        cout << abs(a[0]);
    } else{
        for (int i = 0; i < n - 1; i++){
            m = min(abs(a[i]), abs(a[i + 1]));
            ans = min(ans, m);
            }
        cout << ans;
}
}
