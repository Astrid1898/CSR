//
// Created by zhaojiangfeng on 2022/9/17.

//普通的存储方法会超时，本来用vector只存储有树的节点即可，但因为题目并没有
//说给的节点一定是有序的，所以为了保证次序，这里用了map结构，写起来会复杂一些。
//


#include <bits/stdc++.h>

using namespace std;


#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    IOS;

//    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);
    int n, l, s, x, y;
    cin >> n >> l >> s;

    map<int, set<int>> has_tree;


    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        has_tree[x].insert(y);
    }

    bool map[s + 1][s + 1];
    memset(map, 0, sizeof(map));

    int tmp;
    for (int i = s; i >= 0; i--)
    {
        for (int j = 0; j <= s; j++)
        {
            cin >> tmp;
            if (tmp)
                map[i][j] = true;
        }
    }

    int cnt = 0;
    bool sign = true;
    for (auto iter1 = has_tree.begin(); iter1 != has_tree.end() && (iter1->first <= l - s); iter1++)
    {
        for (auto iter2 = has_tree[iter1->first].begin();
             iter2 != has_tree[iter1->first].end() && *iter2 <= l - s; iter2++)
        {
            for (int i2 = 0; i2 <= s; i2++)
            {
                for (int j2 = 0; j2 <= s; j2++)
                {
                    int i = iter1->first + i2;
                    int j = *iter2 + j2;
                    if (map[i2][j2])
                    {
                        if (has_tree[i].empty() || has_tree[i].find(j) == has_tree[i].end())
                        {
                            sign = false;
                        }

                    }
                    else
                    {
                        if (!has_tree[i].empty() && has_tree[i].find(j) != has_tree[i].end())
                            sign = false;
                    }
                }
            }
            if (sign)
                cnt++;
            else
                sign = true;
        }
    }

    cout << cnt;
    return 0;
}