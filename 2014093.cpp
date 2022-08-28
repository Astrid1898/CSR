/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-08-27 14:50:27
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-08-28 21:32:14
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string to_search;
    cin >> to_search;
    bool is_sensitive;
    cin >> is_sensitive;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        string sentence;
        cin >> sentence;
        string tmp = sentence;
        if (!is_sensitive)
        {
            transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
            transform(to_search.begin(), to_search.end(), to_search.begin(), ::tolower);
        }
        if (sentence.find(to_search) != string::npos)
        {
            cout << tmp << endl;
        }
    }

    return 0;
}