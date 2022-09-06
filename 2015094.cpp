/*
* һ��ʼʹ��vector����洢ͼ������ʹ��warshell�㷨ȥ�������������ڵ�֮�����ͨ�ԣ�
* �ȳ�ʱ�ֳ��ڴ档��vector��Ϊ��ͨ����֮�����ڴ泬�����Ƶ����⣬��������warshell����
* O(n^3)��ʱ�临�ӶȻ���̫�ߣ����³�ʱ�����˱��˵Ľⷨ��ѧ��Tarjan�㷨����˳�����
* �������£�https://blog.csdn.net/qq_43294914/article/details/103325000
*/

#include<bits/stdc++.h>



using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);


const int N = 1e6 + 1;

struct node
{
	int v, next;
} edge[N];

int sum[N];
int dfn[N], low[N];
int st[N], h[N], visitd[N], cnt, tot, top;

void add(int x, int y)
{
	edge[++cnt].next = h[x];
	edge[cnt].v = y;
	h[x] = cnt;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++tot;
	st[++top] = u;
	visitd[u] = 1;

	for (int i = h[u]; i != -1; i = edge[i].next)
	{
		if (!dfn[edge[i].v])
		{
			tarjan(edge[i].v);
			low[u] = min(low[u], low[edge[i].v]);
		}
		else if(visitd[edge[i].v])
		{
			low[u] = min(low[u], low[edge[i].v]);
		}
	}

	if (low[u] == dfn[u])
	{
		do
		{
			sum[u]++;
			visitd[st[top]] = 0;
			top--;
		} while (u != st[top + 1]);
	}

	return;

}

int main()
{
	IOS;
	
	memset(h, -1, sizeof(h));
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		add(x, y);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
			tarjan(i);
	}
	

	int ans = 0;
		
	for (int i = 1; i <= n; i++)
	{
		if (sum[i])
		{
			ans += (sum[i] - 1) * sum[i] / 2;
		}
	}

	cout << ans;
	return 0;
}