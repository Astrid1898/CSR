/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-22 01:36:12
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-22 12:58:47
 */
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> record;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (temp > 0)
        {
            if (record.count(temp) == 0)
                record.insert({temp, 0});
            record[temp]++;
        }
        else
        {
            temp = -temp;
            if (record.count(temp) == 0)
                record.insert({temp, 0});
            record[temp]--;
        }
    }
    int total = 0;
    for (auto iter = record.begin(); iter != record.end(); iter++)
    {
        if (iter->second == 0)
            total++;
    }
    cout << total;
    return 0;
}