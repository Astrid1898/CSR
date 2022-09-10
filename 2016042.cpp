//一步一步模拟就行了，我太着急想用好一点的方法，没行到只有90分。

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
vector<PII> v, u;
const int N = 20;
const int M = 6;
int a[N][N];
int b[M][M];
int main()
{
    int n, flag = 1;
    for (int i = 1; i <= 15; i++) //把数据读进去
        for (int j = 1; j <= 10; j++)
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            scanf("%d", &b[i][j]);

    cin >> n;

    for (int i = 1; i <= 4; i++) //把板块图转移到方格图
        for (int j = n, k = 1; j <= n + 3; j++, k++)
        {
            a[i][j] = b[i][k];
            if (a[i][j])
                v.push_back({i, j});
        }

    int length = v.size();
    while (flag)
    {
        u.clear();
        for (int j = length - 1; j >= 0; j--) //一步一步移动方格，从下往上移
        {
            a[v[j].first][v[j].second] -= 1;
            v[j].first += 1;
            if (v[j].first > 15 || a[v[j].first][v[j].second])
                flag = 0;
            //如果越界，或者下面已经有方格了
            a[v[j].first][v[j].second] += 1;
        }
        if (!flag)
        {
            for (int j = 0; j < length; j++) //再把已经移好的方格退回一秒
            {
                a[v[j].first][v[j].second] -= 1;
                a[v[j].first - 1][v[j].second] += 1;
            }
            break;
        }
    }
    for (int i = 1; i <= 15; i++) //输出方格图
    {
        for (int j = 1; j <= 10; j++)
        {
            if (j == 1)
                cout << a[i][j];
            else
                cout << " " << a[i][j];
        }
        cout << endl;
    }
}