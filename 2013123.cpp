/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-07-30 00:39:18
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-07-30 01:30:47
 */
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int height[n] = {0};
    int left[n];
    int right[n];
    fill(left, left + n, -1);
    fill(right, right + n, n);
    stack<int> mono_stack;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
        while (!mono_stack.empty() && height[mono_stack.top()] >= height[i])
        {
            right[mono_stack.top()] = i;
            mono_stack.pop();
        }
        if (!mono_stack.empty())
            left[i] = mono_stack.top();

        mono_stack.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (right[i] - left[i] - 1) * height[i]);
    }
    cout << ans;
    return 0;
}