//
// Created by zhaojiangfeng on 2022/12/8.
//


/*
 * AC答案连接如下：https://blog.csdn.net/u013944294/article/details/79620059
 * 这里开了编译器优化，还改变了纵横坐标使用了局部缓存的原理，比较复杂
 * 题解方法采用dp的思路，没有看懂，有待后续理解
 */


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int maxn=5000;
const long long inf=0x3f3f3f3f3f3f3f3fLL;
long long n,m,A,B,Q,X_0,col[maxn][maxn],row[maxn][maxn];
long long dp[maxn],v;

int main()
{
    IOS;

    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt","r",stdin);

    cin>>n>>m>>A>>B>>Q>>X_0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
            col[j][i]=X_0=((long long )A*X_0+B)%Q;
    }

    for(int i=1;i<=n-2;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            row[j][i]=X_0=((long long) A*X_0+B)%Q;
        }
    }

    for(int i=0;i<n-1;i++)
    {
        dp[i]=col[0][i];
    }

    for(int i=1;i<n-1;i++)
    {
        v=dp[i-1]+row[0][i];
        dp[i]=dp[i]<v?dp[i]:v;
    }

    for(int i=n-3;i>=0;i--)
    {
        v=dp[i+1]+row[0][i+1];
        dp[i]=dp[i]<v?dp[i]:v;
    }






    return 0;
}