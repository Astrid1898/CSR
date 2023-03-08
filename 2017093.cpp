//
// Created by zhaojiangfeng on 2022/12/13.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<string,string> mp;

int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt","r",stdin);

    int n,m;
    cin>>n>>m;

    cin.clear();cin.ignore();
    string line,last,level,mode="key";
    for(int i=0;i<n;i++)
    {
        getline(cin,line);
        auto it=line.begin();
        while (it!=line.end())
        {
            if(*it==' ')
                it++;
            else
                break;
        }
        line.erase(line.begin(),it);
        cout<<line<<endl;

        if(line.empty())
            continue;

        auto iter1=line.find("\\\\",0,2);
        while (iter1!=line.npos)
        {
            line.erase(iter1,2);
            line.insert(line.begin()+iter1,'\\');
            iter1=line.find("\\\\",0,2);
//            cout<<line<<endl;
        }
        auto iter2=line.find("\\\"",0,2);
        while (iter2!=line.npos)
        {
            line.erase(iter2  ,2);
            line.insert(line.begin()+iter2,'\"');
            iter2=line.find("\\\"",0,2);
//            cout<<line<<endl;
        }

        auto it_begin





    }

    for(int i=0;i<m;i++)
    {

    }
    return 0;
}