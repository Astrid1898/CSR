/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-07 01:04:49
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-07 02:25:35
 *
 *
 * 这道题目明显超出了我的能力范围，而且参考比较少，放一个能找到的ac
 * 代码，这个代码我看了许久，卡在acmatch函数哪里不知道在干什么，记录
 * 下来以待后续可以读懂。
 * 代码链接 https://www.cnblogs.com/shenben/p/12653900.html
 */
#include <queue>
#include <stdio.h>
#include <memory.h>
using std::max;
using std::min;
typedef long long ll;
const int N = 103, sz = 26;
int n, cnt = 1, now, p, fail[N], tag[N], tr[N][sz];
char s[N << 1];
ll m, ans;
#define son (s[i] - 'a')
void insert()
{
    now = 1;
    for (int i = 0; s[i]; i++)
    {
        if (!tr[now][son])
            tr[now][son] = ++cnt;
        now = tr[now][son];
    }
    tag[now]++;
}
std::queue<int> q;
void acmatch()
{
    q.push(1);
    fail[1] = 0;
    for (int i = 0; i < sz; i++)
        tr[0][i] = 1;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        tag[now] += tag[fail[now]];
        for (int i = 0; i < sz; i++)
        {
            if (!tr[now][i])
                continue;
            for (p = fail[now]; p && !tr[p][i]; p = fail[p])
                ;
            fail[tr[now][i]] = p ? tr[p][i] : 1;
            q.push(tr[now][i]);
        }
    }
}
#undef son

struct matrix
{
    ll s[N][N];
    matrix()
    {
        memset(s, -0xf, sizeof s);
    }
} A;
matrix operator*(const matrix &a, const matrix &b)
{
    matrix c;
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            for (int k = 1; k <= cnt; k++)
            {
                c.s[i][j] = max(c.s[i][j], a.s[i][k] + b.s[k][j]);
            }
        }
    }
    return c;
}
matrix fpow(matrix a, ll p)
{
    matrix res;
    for (int i = 1; i <= cnt; i++)
        res.s[i][i] = 0;
    for (; p; p >>= 1, a = a * a)
        if (p & 1)
            res = res * a;
    return res;
}
int main()
{
    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s), insert();
    acmatch();
    for (int i = 1, p; i <= cnt; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            for (p = i; p && !tr[p][j]; p = fail[p])
                ;
            p = p ? tr[p][j] : 1;
            A.s[i][p] = tag[p];
        }
    }
    A = fpow(A, m);
    for (int i = 1; i <= cnt; i++)
        ans = max(ans, A.s[1][i]);
    printf("%lld", ans);
    return 0;
}