//使用矩阵快速幂去求解，只有50分，超时。既然作为最后一题，应该不至于这么简单
//估计还有其他的策略没有使用，可以加快速度。盲猜是逆矩阵
// Created by zhaojiangfeng on 2022/9/9.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAX = 1000;
bool a[MAX][MAX];
int m;
bool temp[MAX][MAX];
bool res[MAX][MAX];
bool b[MAX];
bool a_copy[MAX][MAX];

bool ans[MAX];

void multi(bool a[][MAX], bool b[][MAX])
{
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
                temp[i][j] = temp[i][j] ^ (a[i][k] & b[k][j]);
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = temp[i][j];
}


void multi2(bool a[][MAX], bool b[])
{
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        {
            ans[i] = ans[i] ^ (a[i][j] & b[j]);
        }

}


void fast_power(int k)
{
    memset(res, 0, sizeof(res));
    for (int i = 0; i < m; i++) res[i][i] = 1;
    while (k)
    {
        if (k & 1)
            multi(res, a);
        multi(a, a);
        k = k >> 1;
    }
}


int main()
{

    IOS;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            a_copy[i][j] = (c == '1');
        }
    }
    for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        b[i] = (c == '1');
    }

    int n;
    cin >> n;
    while (n--)
    {
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                a[i][j]=a_copy[i][j];
        int k;
        cin >> k;
        if (k == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << b[i] ;
            }
        }
        else
        {

            fast_power(k);
            multi2(res, b);
            for (int i = 0; i < m; i++)
            {
                cout << ans[i];
            }
        }
        cout<<endl;
    }

    return 0;
}