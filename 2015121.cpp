/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-08 00:19:26
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-08 01:25:44
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
	ios::syna_with_stdio(false); \
	cin.tie(0), cout.tie(0);

int main()
{
	char c;
	long long ans = 0;
	while ((c = getchar()) != '\n')
	{
		ans += c ^ 48;
	}

	cout << ans;

	return 0;
}
