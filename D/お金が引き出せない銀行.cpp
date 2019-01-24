#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;
    int rest = n - w;
    if (rest < 0)
    {
        cout << "error\n";
    }
    else
    {
        cout << rest << endl;
    }
    return 0;
}