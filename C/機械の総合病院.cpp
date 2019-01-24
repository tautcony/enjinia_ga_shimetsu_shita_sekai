#include <iostream>
#include <string>
#include <vector>


using namespace std;

string gao(string t)
{
    bool flag = t.length() >= 6;
    bool ec = false, nc = false;
    for(int i = 0; i < t.length(); ++i)
    {
        char c = t[i];
        if (c >= 'A' && c <= 'Z')
        {
            t[i] = c - 'A' + 'a';
        }
    }
    for(int i = 0; i < t.length(); ++i)
    {
        char c = t[i];
        if (i >= 2 && c == t[i - 1] && t[i - 1] == t[i - 2]) {
            flag = false;
            break;
        }
        if (c >= 'a' && c <= 'z')
        {
            ec = true;
        }
        if (c >= '0' && c <= '9')
        {
            nc = true;
        }
    }
    return (flag && ec && nc ? "Valid" : "Invalid");
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string t;
    cin >> t;
    cout << gao(t) << "\n";
    return 0;
}