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
    string line,last,level;
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












        if(line[0]=='\"')
        {
            if(last.empty())
            {
                auto it_sep=find(line.begin(),line.end(),':');
                if(it_sep!=line.end())
                {
                    string key=line.substr(1,it_sep-line.begin()-1);
                    auto tmp=key.find_last_of('\"');
                    key.erase(tmp,1);
                    if(level[0]!='.')
                        last=level+'.'+key;
                    else
                        last=key;
                }
            }
            else
            {
                auto it_sep=find(line.begin(),line.end(),',');
                if(it_sep!=line.end())
                {
                    string value=line.substr(1,it_sep-line.begin()-1);
                    auto tmp=value.find_last_of('\"');
                    value.erase(tmp,1);
                    if(level[0]=='.')
                        mp[last]="STRING "+value;
                    else
                        mp[level+"."+last]="STRING "+value;
                    last.clear();
                }
            }
        }
        else if(line[0]=='{')
        {
            if(level.empty())
            {
                level.push_back('.');
            }
            else
            {
                if(level[0]=='.')
                {
                    mp[last] = "OBJECT";
                    level.clear();
                    level=last;
                }
                else
                {
                    mp[level + '.' + last] = "OBJECT";
                    level=level+"."+last;
                }
            }
        }



    }

    for(int i=0;i<m;i++)
    {

    }
    return 0;
}