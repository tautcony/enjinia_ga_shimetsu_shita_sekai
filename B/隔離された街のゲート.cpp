#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    int x = 0, y = 0;
    while(n--) {
        char c;
        cin >> c;
        switch(c)
        {
            case 'U': ++y; break;
            case 'D': --y; break;
            case 'L': --x; break;
            case 'R': ++x; break;
        }
        if (x < 0 || x >= w || y < 0 || y >= h) {
            cout << "invalid\n";
            return 0;
        }
    }
    cout << "valid\n";

    return 0;
}