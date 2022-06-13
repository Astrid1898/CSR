/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-05-28 16:53:31
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-06-14 01:52:43
 */
#include <cstdio>
#define fi(i, l, r) for (int i = (l); i <= (r); ++i)
#define fd(i, r, l) for (int i = (r); i >= (l); --i)

using namespace std;

int n, m, t;
int x, y;
int a[300005];

template <typename T>
void Read(T &x)
{
    x = 0;
    T k = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            k = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    x *= k;
}
template <typename T>
void Print(T x)
{
    if (x < 0)
    {
        putchar('-');
        Print(-x);
        return;
    } //这个return很重要，某些情况可能出错
    if (x > 9)
        Print(x / 10);
    putchar((x % 10) ^ 48);
}

int main(void)
{
    Read(n);
    Read(m);
    Read(t);
    while (n--)
    {
        Read(x);
        Read(y);
        a[x - y < 0 ? 1 : x - y + 1]++;
        a[x + 1]--;
    }
    fi(i, 1, 300004)
        a[i] += a[i - 1];
    while (m--)
    {
        Read(x);
        Print(a[x + t]);
        putchar('\n');
    }
    return 0;
}
