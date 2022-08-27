/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-24 16:48:10
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-27 02:09:15
 */

/*
 *这道题目主要考查的是sstream的用法，使用sstream将一串字符使用空格分开，使用十分方便
 *这里有错误别我踩到了，就是sstream为空的时候，使用>>依然是不会报错的。并且，原先接受
 *输出流的变量，会保持之前的值，导致程序出现难以察觉的bug。
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