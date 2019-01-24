#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    string ans = arr[0];
    for (int i = 1; i < n; ++i)
    {
        string tmp;
        for (int j = 0; j <= ans.size() && j <= arr[i].size(); ++j)
        {
            if (ans.substr(ans.size() - j, j) == arr[i].substr(0, j))
            {
                tmp = ans + arr[i].substr(j, arr[i].size() - j);
            }
        }
        if (tmp != "")
        {
            ans = tmp;
        }
    }
    cout << ans << endl;
    
    return 0;
}