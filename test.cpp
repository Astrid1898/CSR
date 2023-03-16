#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

//将所有可能出现的英文与对应的数组存储起来
unordered_map <string, int> text = {{"jan", 1}, {"feb", 2}, {"mar", 3}, {"apr", 4}, {"may", 5},
                                    {"jun", 6}, {"jul", 7}, {"sep", 9}, {"aug", 8}, {"oct", 10}, {"nov", 11}, {"dec", 12},
                                    {"mon", 1}, {"tue", 2}, {"wed", 3}, {"thu", 4}, {"fri", 5}, {"sat", 6}, {"sun", 0}};

//返回该时间项对应数组中的下标
int point(string str)
{
    //长度为3一定是英文
    if (str.size() == 3) transform(str.begin(), str.end(), str.begin(), ::tolower);
    if (text.count(str) == 0) //这个串不是英文
    {
        //while (x.size() > 1 && x[0] == '0') x.erase(0, 1);//去前缀0
        int t = stoi(str.c_str()); //不需要手动去前缀0
        return t;
    }
    else //这个串是英文
    {
        return text[str];
    }
}

//处理前五项存在-或，或*的情况
vector <int> workstr(string str, int n)
{
    vector <int> res(n);
    if (str == "*") //数组每一项都置为1
    {
        for (int i = 0; i < n; i ++) res[i] = 1;
        return res;
    }
    else
    {
        //先通过逗号进行分隔
        vector <string> val;
        for (int i = 0; i < str.size(); i ++)
        {
            int j = i;
            string t;
            while (j < str.size() && str[j] != ',') t += str[j ++]; //双指针
            val.push_back(t);
            i = j;
        }

        for (auto x : val) //对于每一项，再处理其中是否存在-
        {
            if (x.find('-') == -1) //说明不存在-
            {
                res[point(x)] = 1;
            }
            else //说明存在-
            {
                int k = x.find('-');
                string str1 = x.substr(0, k);
                string str2 = x.substr(k + 1);
                int l = point(str1); //找出时间的左端点
                int r = point(str2); //找出时间的右端点
                for (int i = l; i <= r; i ++) res[i] = 1; //该区间内的所有时间均置为1
            }
        }
    }
}

struct cmd
{
    //定义每个时间项数组，存储该命令满足的所有时间项
    vector <int> minute;
    vector <int> hours;
    vector <int> day;
    vector <int> months;
    vector <int> week;
    string command;

    //自己重载一定要加上这个
    cmd(){}

    cmd(string mt, string h, string d, string mth, string w, string c)
    {
        //memset(minute, 0, sizeof(minute));//初始就是0
        minute = workstr(mt, 60);
        hours = workstr(h, 24);
        day = workstr(d, 32);
        months = workstr(mth, 13);
        week = workstr(w, 7);
        command = c;
    }
}C[25]; //存储所有的命令

int M[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //定义不是闰年的12个月的天数，从下标1开始

struct time //时间结构体，模拟时间
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int week;

    time(){}
    time(string str)
    {
        year = stoi(str.substr(0, 4).c_str());
        month = stoi(str.substr(4, 2).c_str());
        day = stoi(str.substr(6, 2).c_str());
        hour = stoi(str.substr(8, 2).c_str());
        minute = stoi(str.substr(10, 2).c_str());

        int t = 0;
        for (int i = 1970; i < year; i ++) t += 365 + is_leap(i);
        for (int i = 1; i < month; i ++) t += getday(i, year);
        t += day;
        week = (t + 4 - 1) % 7; //计算星期几
    }

    //判断闰年
    bool is_leap(int y)
    {
        return (y % 400 == 0) || ((y % 4 == 0) && y % 100);
    }

    int getday(int m, int y) //获得y年m月的天数
    {
        if (m == 2) return M[2] + is_leap(y);
        return M[m];
    }

    void add() //加一分钟
    {
        minute ++;
        if (minute == 60)
        {
            minute = 0;
            hour ++;
            if (hour == 24)
            {
                hour = 0;
                week = (week + 1) % 7;
                day ++;
                if (day > getday(month, year))
                {
                    day = 1;
                    month ++;
                    if (month == 13)
                    {
                        month = 1;
                        year ++;
                    }
                }
            }
        }
    }

    bool operator< (const time &t) const //重载时间比较的函数
    {
        if (t.year != year) return year < t.year;
        if (t.month != month) return month < t.month;
        if (t.day != day) return day < t.day;
        if (hour != t.hour) return hour < t.hour;
        return minute < t.minute;
    }

    void printime() //输出时间
    {
        printf("%04d%02d%02d%02d%02d ", year, month, day, hour, minute);
    }
};
int main()
{
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++)
    {
        string minutes, hours, day, month, weekday, command;
        cin >> minutes >> hours >> day >> month >> weekday >> command;
        C[i] = cmd(minutes, hours, day, month, weekday, command);
        //cout << minutes << hours << day << month << weekday << command << endl;
    }

    struct time bn = time(s);
    struct time ed = time(t);

    for (auto i = bn; i < ed; i.add()) //时间
    {
        int mth = i.month, d = i.day, h = i.hour, m = i.minute, w = i.week;
        for (int j = 0; j < n; j++) //命令
        {
            //命令的时间项包含这一分钟的所有时间项时，说明这一分钟这条命令会被执行
            if (C[j].months[mth] && C[j].day[d] && C[j].hours[h] && C[j].minute[m] && C[j].week[w])
            {
                i.printime();
                //cout << C[j].command << " " << i.week << endl;
                cout << C[j].command << endl;
            }
        }
    }
    return 0;
}