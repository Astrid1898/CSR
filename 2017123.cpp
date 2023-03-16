//
// Created by zhaojiangfeng on 2023/3/14.
//

#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


//将所有可能出现的英文和对应的数字存储起来
unordered_map<string, int> text = {
        {"jan", 1},
        {"feb", 2},
        {"mar", 3},
        {"apr", 4},
        {"may", 5},
        {"jun", 6},
        {"jul", 7},
        {"sep", 9},
        {"aug", 8},
        {"oct", 10},
        {"nov", 11},
        {"dec", 12},
        {"mon", 1},
        {"tue", 2},
        {"wed", 3},
        {"thu", 4},
        {"fri", 5},
        {"sat", 6},
        {"sun", 0}
};

//定义非闰年每月的天数
int M[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int point(string str)
{
    //长度为3一定是英文
    if (str.size() == 3) transform(str.begin(), str.end(), str.begin(), ::tolower);
    //这个串不是英文
    if (text.count(str) == 0)
    {
        int t = stoi(str.c_str());//无需手动去前缀0
        return t;
    }
    else
        //这个串是英文
    {
        return text[str];
    }
}

class Time //处理时间的结构体模板
{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int week;
public:
    Time() {}

    Time(string str)
    {
        year = stoi(str.substr(0, 4).c_str());
        month = stoi(str.substr(4, 2).c_str());
        day = stoi(str.substr(6, 2).c_str());
        hour = stoi(str.substr(8, 2).c_str());
        minute = stoi(str.substr(10, 2).c_str());

        int t = 0;
        for (int i = 1970; i < year; i++)
            t += 365 + is_leap(i);
        for (int i = 1; i < month; i++)
            t += getday(i, year);
        t += day;
        week = (t + 4 - 1) % 7; //获取当天是周几
    }

    int getYear() const
    {
        return year;
    }

    int getMonth() const
    {
        return month;
    }

    int getDay() const
    {
        return day;
    }

    int getHour() const
    {
        return hour;
    }

    int getMinute() const
    {
        return minute;
    }

    int getWeek() const
    {
        return week;
    }

    //判断是否是闰年，对于整百的年份，要能被400整除，而对于非整百的年数，要能被4整除，才是闰年
    bool is_leap(int y)
    {
        return (y % 400 == 0) || ((y % 4 == 0) && y % 100);
    }

    //获取是一年中特定月份有多少天
    int getday(int m, int y)
    {
        if (m == 2) return M[2] + is_leap(y);
        return M[m];
    }

    //增加一分钟
    void add()
    {
        minute++;
        //处理进位比较麻烦
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
            {
                hour = 0;
                week = (week + 1) % 7;
                day++;
                if (day > getday(month, year))
                {
                    day = 1;
                    month++;
                    if (month == 13)
                    {
                        month = 1;
                        year++;
                    }

                }
            }
        }

    }

    //重载时间比较函数
    bool operator<(const Time &t) const
    {
        if (t.year != year) return year < t.year;
        if (t.month != month) return month < t.month;
        if (t.day != day) return day < t.day;
        if (t.hour != hour) return hour < t.hour;
        return minute < t.minute;
    }

//    输出时间
    void printtime()
    {
        printf("%04d%02d%2d%02d%02d ", year, month, day, hour, minute);
    }

};

//处理前五项存在-或,或*的情况
vector<int> workstr(string str, int n)
{
    vector<int> res(n);
    if (str == "*")
    {
        for (int i = 0; i < n; i++)
            res[i] = 1;
        return res;
    }
    else
    {
        //    先处理有,的情况，将整体按照,分割开来
        vector<string> val;
        for (int i = 0; i < str.size(); i++)
        {
            int j = i;
            string t;
            while (j < str.size() && str[j] != ',')
                t += str[j++];
            val.push_back(t);
            i = j;
        }
        //然后对每一项，分别处理其中可能存在的的-
        for(auto x:val)
        {
            if(x.find('-')==-1)
            {
                res[point(x)]=1;
            }
            else
            {
                int k=x.find('-');
                string str1=x.substr(0,k);
                string str2=x.substr(k+1);
                int l= point(str1); //找出左时间端点
                int r=point(str2);  //找出右时间端点
                for(int i=l;i<=r;i++)   //该区间内的时间均置1
                    res[i]=1;
            }


        }

    }
}


struct cmd
{
    //定义每个时间项数组，存储满足该命令的所有时间项
    vector<int> minutes;
    vector<int> hours;
    vector<int> days;
    vector<int> months;
    vector<int> weeks;
    string command;

    cmd() {}

    cmd(string mt, string h, string d, string mth, string w, string c)
    {
        minutes = workstr(mt, 60);
        hours = workstr(h, 24);
        days= workstr(d,32);
        months= workstr(mth,13);
        weeks= workstr(w,7);
        command=c;
    }
}C[21];


int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);


    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++)
    {
        string minutes, hours, day, month, weekday, command;
        cin >> minutes >> hours >> day >> month >> weekday >> command;
        C[i]=cmd(minutes,hours,day,month,weekday,command);
    }

    Time begin=Time(s);
    Time end=Time(t);

    for(auto i=begin;i<end;i.add())
    {
        int mth=i.getMonth(),d=i.getDay(),h=i.getHour(),m=i.getMinute(),w=i.getWeek();
        for(int j=0;j<n;j++)
        {
            if(C[j].months[mth] && C[j].days[d] && C[j].hours[h] && C[j].minutes[m] && C[j].weeks[w])
            {
                i.printtime();
                cout<<C[j].command<<endl;
            }

        }
    }
    return 0;
}
