/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-07-29 01:11:13
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-07-29 01:48:59
 */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    string isbn;
    cin >> isbn;
    int sum = 0;
    int this_num = 0;
    for (int i = 1; i <= 9; i++)
    {
        while (isbn[this_num] == '-')
            this_num++;
        sum += (isbn[this_num] ^ 48) * i;
        this_num++;
    }
    sum = sum % 11;
    if (isbn[isbn.length() - 1] == 'X')
    {
        if (sum == 10)
            cout << "Right";
        else
            cout << isbn.substr(0, isbn.length() - 1) << setw(1) << sum;
    }
    else
    {
        if (sum == (isbn[isbn.length() - 1] ^ 48))
            cout << "Right";
        else if (sum != 10)
            cout << isbn.substr(0, isbn.length() - 1) << setw(1) << sum;
        else
            cout << isbn.substr(0, isbn.length() - 1) << "X";
    }
    return 0;
}