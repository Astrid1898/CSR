/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-06 01:56:01
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-06 02:31:59
 *
 *
 * getline前要加getchar，还要注意cin之后立马getline，
 * 会有括号的存在。
 *
 * 主要是一些字符串string的操作，因为题目给的格式有问题的
 * 所以直接看了别人的答案。注意substr函数的下标，第一个参数是
 * 字符串的起始位置，第二个参数是读取几个字符，这一点不出问题几乎
 * 就没有什么难度了。
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

int main()
{

    int m, n;
    cin >> m >> n;

    getchar();

    vector<string> temp;
    for (int i = 0; i < m; i++)
    {
        string data;
        getline(cin, data);
        temp.push_back(data);
    }

    map<string, string> var;
    for (int i = 0; i < n; i++)
    {
        string key, value;
        cin >> key;
        getline(cin, value);
        var[key] = value.substr(2, value.size() - 3);
    }

    for (int i = 0; i < m; i++)
    {
        int one = 0, second = 0;
        while (1)
        {
            one = temp[i].find("{{ ", one);
            second = temp[i].find(" }}", one);
            if (one == (int)string::npos)
                break;

            string key = temp[i].substr(one + 3, second - one - 3);
            temp[i] = temp[i].replace(one, second - one + 3, var[key]);
            one += var.count(key) ? var[key].size() : 0;
        }
        cout << temp[i] << endl;
    }

    return 0;
}