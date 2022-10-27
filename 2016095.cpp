//
// Created by zhaojiangfeng on 2022/10/27.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Point
{
    int x, y;
};

bool cmpByX(const Point &a, const Point &b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

bool cmpByY(const Point &a, const Point &b)
{
    return a.y == b.y ? a.x < b.x : a.y < b.y;
}

bool cmp(const vector<Point> &a, const vector<Point> b)
{
    return a.size() < b.size();
}


int findX(const vector<Point> &sameY, int x)
{
    if (x <= sameY[0].x)
        return 0;
    int l = 0, r = sameY.size();
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (sameY[mid].x == x)
        {
            return 0;
        }
        else
        {
            if (sameY[mid].x < x)
                l = mid;
            else
                r = mid;
        }

    }
    return min(l + 1, int(sameY.size() - l - 1));
}


int findY(const vector<Point> &sameX, int y)
{
    if (y <= sameX[0].y)
        return 0;
    int l = 0, r = sameX.size();
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (sameX[mid].y == y)
        {
            return 0;
        }
        else if (sameX[mid].y < y)
            l = mid;
        else
            r = mid;
    }
    return min(l + 1, int(sameX.size() - l - 1));
}

int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);

    int n, q, a, b;
    cin >> n >> q;
    vector<Point> myVec(n);
    for (int i(0); i < n; i++)
    {
        cin >> myVec[i].x >> myVec[i].y;
    }

    vector<Point> myVec0(myVec);

    sort(myVec.begin(), myVec.end(), cmpByX);
    sort(myVec0.begin(), myVec0.end(), cmpByY);

    vector<vector<Point>> sameX(1);
    vector<vector<Point>> sameY(1);

    int index = 0;
    sameX[index].push_back(myVec[0]);
    for (int i(1); i < myVec.size(); i++)
    {
        if (myVec[i].x == myVec[i - 1].x)
        {
            sameX[index].push_back(myVec[i]);
        }
        else
        {
            if (sameX[index].size() == 1)
            {
                sameX[index][0] = myVec[i];
            }
            else
            {

                sameX.push_back(vector<Point>());
                index++;
                sameX[index].push_back(myVec[i]);
            }
        }
    }

    index = 0;
    sameY[index].push_back(myVec0[0]);
    for (int i(1); i < myVec0.size(); i++)
    {
        if (myVec0[i].y == myVec0[i - 1].y)
            sameY[index].push_back(myVec0[i]);
        else
        {
            if (sameY[index].size() == 1)
            {
                sameY[index][0] = myVec0[i];
            }
            else
            {
                sameY.push_back(vector<Point>());
                index++;
                sameY[index].push_back(myVec0[i]);
            }
        }
    }

    bool f = 1;

    sort(sameX.begin(), sameX.end(), cmp);
    sort(sameY.begin(), sameY.end(), cmp);
    int maxnum = 0, count = 0;

    for (int i(0); i < sameX.size(); i++)
    {
        for (int j(0); j < sameY.size(); j++)
        {
            int x = sameX[i][0].x;
            int y = sameY[j][0].y;
            int res = min(findX(sameY[j], x), findY(sameX[i], y));
            if (res > maxnum)
            {
                maxnum = res;
                count = 1;
                while (!sameX.empty() && sameX.back().size() <= 2 * maxnum - 1)
                    sameX.pop_back();
                while (!sameY.empty() && sameY.back().size() <= 2 * maxnum - 1)
                    sameY.pop_back();
            }
            else if (res == maxnum)
                count++;
        }
    }
    if (q == 1)
        cout << maxnum << endl;
    else
        cout << count << endl;
    return 0;

}
