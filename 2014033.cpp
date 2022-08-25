/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-24 16:48:10
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-26 02:42:54
 */
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;
int main()
{

    string format_string;
    cin >> format_string;
    map<char, bool> para;
    for (int i = 0; i < format_string.length(); i++)
    {
        if (format_string[i] != ':')
        {
            para[format_string[i]] = false;
        }
        else
        {
            para[format_string[i - 1]] = true;
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string order;
        getchar();
        getline(cin, order);
        istringstream orders(order);
        map<string, string> parsed_order;
        string order_part;
        orders >> order_part;
        while (orders)
        {
            order_part.clear();
            orders >> order_part;
            if (order_part.empty())
                break;
            else if (order_part[0] == '-' && para.count(order_part[1]))
            {
                if (para[order_part[1]])
                {
                    string tmp;
                    orders >> tmp;
                    if (tmp.empty())
                        break;
                    parsed_order[order_part] = tmp;
                }
                else
                {
                    parsed_order[order_part] = "";
                }
            }
            else
                break;
        }
        cout << "Case " << i << ": ";
        for (auto iter = parsed_order.begin(); iter != parsed_order.end(); iter++)
        {
            cout << iter->first << " ";
            if (!(iter->second.empty()))
                cout << iter->second << " ";
        }
        cout << endl;
    }
    return 0;
}