/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-03 20:51:45
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-04 01:59:51
 *
 * 题目本身不难，练习一下语法，注意日期变动的边界条件即可
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

class date
{
private:
    int year;
    int month;
    int day;

public:
    static int DAY_OF_LEAP_YEAR_MONTHS[12];
    static int DAY_OF_COMMON_YEAR_MONTHS[12];
    date(int y, int m, int d) : year(y), month(m), day(d) {}

    static bool is_leap_year(int y)
    {
        if (y % 400 == 0)
            return true;
        else if (y % 4 == 0 && y % 100 != 0)
            return true;
        return false;
    }

    friend int operator-(const date &b, const date &a)
    {
        int cnt = 0;
        if (date::is_leap_year(a.year))
        {
            for (int i = a.month + 1; i <= 12; i++)
            {
                cnt += date::DAY_OF_LEAP_YEAR_MONTHS[i - 1];
            }
            cnt += date::DAY_OF_LEAP_YEAR_MONTHS[a.month - 1] - a.day;
        }
        else
        {
            for (int i = a.month + 1; i <= 12; i++)
            {
                cnt += date::DAY_OF_COMMON_YEAR_MONTHS[i - 1];
            }
            cnt += date::DAY_OF_COMMON_YEAR_MONTHS[a.month - 1] - a.day;
        }

        for (int i = a.year + 1; i < b.year; i++)
        {
            if (date::is_leap_year(i))
                cnt += 366;
            else
                cnt += 365;
        }

        if (date::is_leap_year(b.year))
        {
            for (int i = 1; i < b.month; i++)
            {
                cnt += date::DAY_OF_LEAP_YEAR_MONTHS[i - 1];
            }
            cnt += b.day;
            if (a.year == b.year)
                cnt -= 366;
        }
        else
        {
            for (int i = 1; i < b.month; i++)
            {
                cnt += date::DAY_OF_COMMON_YEAR_MONTHS[i - 1];
            }
            cnt += b.day;
            if (a.year == b.year)
                cnt -= 365;
        }

        return cnt;
    }

    friend ostream &operator<<(ostream &_out, date &d)
    {
        cout << setfill('0') << setw(4) << d.year << '/'
             << setw(2) << d.month << "/" << setw(2) << d.day << endl;
        return _out;
    }
};

int date::DAY_OF_LEAP_YEAR_MONTHS[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int date::DAY_OF_COMMON_YEAR_MONTHS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    IOS;

    int a, b, c, y1, y2;
    cin >> a >> b >> c >> y1 >> y2;

    date init = date(1850, 1, 1);
    for (int i = y1; i <= y2; i++)
    {
        date this_day = date(i, a, 1);
        int gap = this_day - init;
        // cout << "gap=" << gap << endl;
        //一周从第0天开始
        int day_of_weak = (gap % 7 + 1) % 7;
        int first = c - 1 - day_of_weak;
        if (first < 0)
            first += 7;
        int day = 1 + first + (b - 1) * 7;
        // cout << day << endl;
        // cout << day_of_weak << endl;

        if (date::is_leap_year(i))
        {
            if (day <= date::DAY_OF_LEAP_YEAR_MONTHS[a - 1])
            {
                date tmp = date(i, a, day);
                cout << tmp;
            }
            else
                cout << "none" << endl;
        }
        else
        {
            if (day <= date::DAY_OF_COMMON_YEAR_MONTHS[a - 1])
            {
                date tmp = date(i, a, day);
                cout << tmp;
            }
            else
                cout << "none" << endl;
        }
    }

    return 0;
}