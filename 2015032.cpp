#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

struct num
{
    int number;
    int times;
    num(int n, int t) : number(n), times(t) {}
};

bool cmp(const num &a, const num &b)
{
    return a.times != b.times ? a.times > b.times : a.number < b.number;
}

int main()
{
    IOS;

    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }

    vector<num> numbers;
    for (auto iter = cnt.begin(); iter != cnt.end(); iter++)
    {
        numbers.push_back(num(iter->first, iter->second));
    }

    sort(numbers.begin(), numbers.end(), cmp);

    for (auto iter : numbers)
    {
        cout << iter.number << " " << iter.times << endl;
    }
    return 0;
}
