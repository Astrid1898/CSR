/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-05 13:54:45
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-05 14:18:05
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

const int DAY_OF_LEAP_YEAR_MONTHS[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int DAY_OF_COMMON_YEAR_MONTHS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 4 == 0 && year % 100 != 0)
        return true;
    return false;
}

int main()
{
    int y, d;
    cin >> y >> d;
    const int *day_of_year_months = is_leap_year(y) ? DAY_OF_LEAP_YEAR_MONTHS : DAY_OF_COMMON_YEAR_MONTHS;
    int this_month = 1;
    while (d >= day_of_year_months[this_month])
    {
        d -= day_of_year_months[this_month];
        this_month++;
    }

    if (d == 0)
    {
        cout << this_month - 1 << endl
             << day_of_year_months[this_month - 1] << endl;
    }
    else
    {
        cout << this_month << endl
             << d;
    }

    return 0;
}