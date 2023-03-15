//
// Created by zhaojiangfeng on 2023/3/14.
//

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


//将所有可能出现的英文和对应的数字存储起来
unordered_map<string,int> text={
        {"jan",1},{"feb",2},{"mar",3},{"apr",4},{"may",5},
        {"jun",6},{"jul",7},{"sep",9},{"aug",8},{"oct",10},
        {"nov",11},{"dec",12},{"mon",1},{"tue",2},{"wed",3},
        {"thu",4},{"fri",5},{"sat",6},{"sun",0}
};

//定义非闰年每月的天数
int M[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int point(string str)
{
    if(str.size()==3) transform(str.begin(),str.end(),str.begin(), ::tolower);
}



int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt","r",stdin);

    int n;
    string s,t;
    cin>>n>>s>>t;
    for(int i=0;i<n;i++)
    {
        string mintutes,hours,day,month,weekday,command;
        cin>>mintutes>>hours>>day>>month>>weekday>>command;

    }

}
