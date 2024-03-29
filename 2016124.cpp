//
// Created by zhaojiangfeng on 2022/10/31.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int inf=0x08080808;


int main()
{
    IOS;

    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);
    int n;
    cin>>n;
    int num[n+1],dp[n+1][n+1],p[n+1][n+1],sum[n+1];
    for(int i=1;i<=n;i++)
        cin>>num[i];

    memset(dp,inf,sizeof(dp));
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+num[i];
        dp[i][i]=0;
        p[i][i]=i;
    }

    //这里l是步长，i是起始位置，因为要使用平行四边形优化，所以先固定步长，在里面变动起始位置。
    //这样就会出现在每次求dp[i][j]的时候，p[i][j-1]和p[i+1][j]都已经求出，因为后两者的步长都是
    //l-1
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i+l-1<=n;i++)
        {
            int j=i+l-1;
            for(int k=p[i][j-1];k<=p[i+1][j];k++)
            {
                int w=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                if(w<dp[i][j])
                {
                    dp[i][j]=w;
                    p[i][j]=k;
                }

            }

        }
    }

    cout<<dp[1][n];

    return 0;
}