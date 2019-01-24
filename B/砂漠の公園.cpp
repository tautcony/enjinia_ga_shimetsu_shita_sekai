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
    vector<vector<int> > mat(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char c;
            cin >> c;
            mat[i][j] = (c == 'W' ? 2: c == 'D' ? 1 : 0);
        }
    }
    int yst = -1;
    int max_score = 0;
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j) sum += mat[i][j];
        if (sum > max_score)
        {
            yst = i;
            max_score = sum;
        }
    }
    cout << yst + 1 << " " << max_score << " ";
    int w = 0, d = 0, l = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i != yst)
        {
            int s = mat[yst][i];
            if (s == 2) ++w;
            else if (s == 1) ++d;
            else ++l;
        }
    }
    cout << w << " " << d << " " << l << "\n";
    
    return 0;
}