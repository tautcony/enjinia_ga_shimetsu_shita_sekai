#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string title;
        int cnt;
        cin >> title >> cnt;
        if (cnt == 3) {
            cout << title << endl;
        }
    }
    return 0;
}