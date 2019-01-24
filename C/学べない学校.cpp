#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, map<char, int> > d;

void init()
{
    d['g']['p'] = 1;
    d['p']['g'] = -1;
    d['g']['c'] = -1;
    d['c']['g'] = 1;
    d['c']['p'] = -1;
    d['p']['c'] = 1;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    init();
    int n;
    int A = 0, B = 0;
    cin >> n;
    char a, b;
    while(n--)
    {
        cin >> a >> b;
        int ret = d[a][b];
        if (ret == -1)
        {
            ++A;
        }
        else if (ret == 1)
        {
            ++B;
        }
    }
    cout << A << "\n" << B << "\n";
    
    return 0;
}