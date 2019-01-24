#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> t;
        cnt += t > 5;
    }
    cout << cnt << endl;

    return 0;
}