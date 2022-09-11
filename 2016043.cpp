/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-11 01:40:09
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-12 01:57:40
 *
 *
 * 一开始被题目给的目录结构给迷惑了，导致没有理清思路，在错误的道路上越州越远。
 * 读题也很重要，要准确理解题意。很显然，根据经验就可以知道路径解析并不需要知道
 * 具体的目录结构，所以题目只是帮助理解。
 *
 * 还有就是这里由于用到了getchar和cin cout等方法，并不能取消同步。
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int pos, num;
    string curDir;
    cin >> num >> curDir;
    getchar();
    for (int i = 0; i < num; i++)
    {
        string line;
        getline(cin, line);
        if (line[0] != '/')
            line = curDir + "/" + line;

        if (line.size() == 0)
            line = curDir;

        while ((pos = line.find("//")) != -1)
        {
            int count = 2;
            while (line[pos + count] == '/')
                count++;
            line.erase(pos, count - 1);
        }

        while ((pos = line.find("/../")) != -1)
        {
            if (pos == 0)
                line.erase(pos + 1, 3);
            else
            {
                int spos;
                spos = line.rfind("/", pos - 1);
                line.erase(spos, pos - spos + 3);
            }
        }

        while ((pos = line.find("/./")) != -1)
        {
            line.erase(pos + 1, 2);
        }

        if (line.size() > 1 && line[line.size() - 1] == '/')
            line.erase(line.size() - 1);
        cout << line << endl;
    }
    return 0;
}