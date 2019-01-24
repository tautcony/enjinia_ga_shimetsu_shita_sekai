#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

enum DIR
{
    NOT = 0,
    L = 1,
    R = 1 << 1,
    U = 1 << 2,
    D = 1 << 3,
};

template<class T> inline T operator~ (T a) { return (T)~(int)a; }
template<class T> inline T operator| (T a, T b) { return (T)((int)a | (int)b); }
template<class T> inline T operator& (T a, T b) { return (T)((int)a & (int)b); }
template<class T> inline T operator^ (T a, T b) { return (T)((int)a ^ (int)b); }
template<class T> inline T& operator|= (T& a, T b) { return (T&)((int&)a |= (int)b); }
template<class T> inline T& operator&= (T& a, T b) { return (T&)((int&)a &= (int)b); }
template<class T> inline T& operator^= (T& a, T b) { return (T&)((int&)a ^= (int)b); }

class tatemono
{
    public:
    int index;
    int h;
    int w;
    int r;
    int c;
    DIR d;
    DIR dir_cal()
    {
        d = NOT;
        if (r == 1) d |= U;
        if (r == h) d |= D;
        if (c == 1) d |= L;
        if (c == w) d |= R;
        return d;
    }

    bool operator <(const tatemono &rhs)
    {
        return h * w < rhs.h * rhs.w;
    }
};

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h, w, n;
    cin >> h >> w >> n;
    vector<tatemono> arr(n);
    map<DIR, vector<tatemono> > dic;
    for (int i = 0; i < n; ++i)
    {
        arr[i].index = i + 1;
        cin >> arr[i].h >> arr[i].w >> arr[i].r >> arr[i].c;
        dic[arr[i].dir_cal()].push_back(arr[i]);
    }
    for (auto tp: dic)
    {
        sort(tp.second.begin(), tp.second.end());
    }
    vector<vector<int> > m(h, vector<int>(w));
    auto down = dic[D];
    int max_r = 0, curr_c = 0;
    for (auto item: down)
    {
        if (h >= item.h && w - curr_c >= item.w)
        {
            max_r = max(max_r, item.h);
            
            for (int i = 0; i < item.h; ++i)
            {
                for (int j = curr_c; j < curr_c + item.w; ++j)
                {
                    m[i][j] = item.index;
                }
            }
            curr_c += item.w;
        }
        else
        {
            break;
        }
    }

    curr_c = 0;
    auto up = dic[U];
    for (auto item: up)
    {
        if (h - max_r >= item.h && w - curr_c >= item.w)
        {
            // curr_r = max(curr_r, item.h);
            
            for (int i = h - item.h; i < h; ++i)
            {
                for (int j = curr_c; j < curr_c + item.w; ++j)
                {
                    m[i][j] = item.index;
                }
            }
            curr_c += item.w;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (j != 0) cout << " ";
            cout << m[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}