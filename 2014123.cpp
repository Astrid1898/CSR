/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-31 18:28:22
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-31 20:43:33
 *
 *
 * 这里主要是考虑输入如何结束。在oj中使用cin>>str的返回值显然是可以的，但是
 * 在自己测试代码的时候并不能如此使用。应为这个走了一些弯路。
 *
 * 另外，题目并没有考虑撤销撤销语句之后会发生什么，是一大漏洞吧。
 */
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

#define MAX 5007

typedef struct
{
    string m;
    double p;
    int s;
    bool e;
} investor;

investor invesotrs[MAX];
set<double> st;

int main()
{
    int m = 0;
    while (cin >> invesotrs[m].m)
    {
        if (invesotrs[m].m == "cancel")
        {
            cin >> invesotrs[m].s;
            invesotrs[invesotrs[m].s - 1].e = true;
            m++;
            continue;
        }
        cin >> invesotrs[m].p >> invesotrs[m].s;
        ++m;
    }

    for (int i = 0; i < m; i++)
    {
        if (invesotrs[i].m != "cancel" && !invesotrs[i].e)
            st.insert(invesotrs[i].p);
    }

    long long m_sum = 0;
    double p = 0.0;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        double po = *it;
        long long sumb = 0, sums = 0, sum = 0;
        for (int i = 0; i < m; i++)
        {
            if (invesotrs[i].m == "sell" && !invesotrs[i].e && invesotrs[i].p <= po)
                sums += invesotrs[i].s;
        }
        for (int i = 0; i < m; i++)
        {
            if (invesotrs[i].m == "buy" && !invesotrs[i].e && invesotrs[i].p >= po)
                sumb += invesotrs[i].s;
        }
        sum = min(sums, sumb);

        if (sum >= m_sum)
        {
            m_sum = sum;
            p = po;
        }
    }

    printf("%.2f ", p);
    printf("%lld", m_sum);
    return 0;
}
