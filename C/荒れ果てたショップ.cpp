#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = a; i <= b; ++i)
    {
        string str = to_string(i);
        while(str.length() < n) str = "0" + str;
        cout << str << "\n";
    }
    return 0;
}