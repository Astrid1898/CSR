#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);

vector<vector<bool>> achievable;


int main()
{
	IOS;

	int m, n;
	cin >> m >> n;
	achievable = vector(n+1, vector(n+1, false));
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		achievable[a][b] = true;
	}

	for (int k = 1; k <= n; k++)
	{
		for(int i=1;i<=n;i++)
			for (int j = 1; j <= n; j++)
			{
				if (achievable[i][k]&& achievable[k][j])
					achievable[i][j] = true;
			}
	}

	int cnt = 0;


	for (int i = 1; i <=n ; i++)
		for (int j = i+1; j <=n; j++)
		{
			if (achievable[i][j] && achievable[j][i])
				cnt++;
		}

	cout << cnt << endl;
	return 0;
}