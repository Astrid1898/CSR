/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-31 02:14:21
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-31 02:17:19
 */
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    map<int, int> record;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;
        record[id]++;
        cout << record[id] << " ";
    }

    return 0;
}