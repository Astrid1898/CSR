//
// Created by zhaojiangfeng on 2022/12/1.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);


    string line,last_line;
    bool is_paragraph=false,is_item=false;
    while(getline(cin,line))
    {
        if(line.empty())
        {
            if(is_paragraph)
            {
                last_line=last_line+"</p>";
                cout<<last_line<<endl;
                is_paragraph=false;
            }
            continue;
        }
        if(line[0]!='*'&&is_item)
        {
            is_item= false;
            cout<<"</ul>"<<endl;
        }

        auto it_= find(line.begin(),line.end(),'_');
        while(it_!=line.end())
        {
            line.erase(it_);
            line.insert(it_-line.begin(),"<em>");
            it_= find(it_,line.end(),'_');
            line.erase(it_);
            line.insert(it_-line.begin(),"</em>");
            it_= find(it_,line.end(),'_');
        }

        //标题的情况较为特殊，所以对其进行单独处理
        int head_level=std::count(line.begin(), line.end(),'#');
        if(head_level!=0)
        {
            if(is_paragraph)
            {
                last_line=last_line+"</p>";
                cout<<last_line<<endl;
                is_paragraph=false;
            }
            auto iter=line.begin();
            while(*iter=='#'||*iter==' ')
            {
                iter++;
            }
            line.erase(line.begin(),iter);

            string tmp="<h"+ to_string(head_level)+">";
            line="<h"+ to_string(head_level)+">"+line+"</h"+to_string(head_level)+">";
        }


        //然后看是段落还是列表
        else if(line[0]=='*')
        {
            if(is_paragraph)
            {
                last_line=last_line+"</p>";
                cout<<last_line<<endl;
                is_paragraph=false;
            }
            if(!is_item)
            {
                is_item= true;
                cout<<"<ul>"<<endl;
            }
            auto iter=line.begin();
            while(*iter=='*'||*iter==' ')
            {
                iter++;
            }
            line.erase(line.begin(),iter);
            line="<li>"+line+"</li>";
        }
        else if(!is_paragraph)
        {
            line="<p>"+line;
            last_line=line;
            is_paragraph= true;
            continue;
        }
        else
        {
            cout<<last_line<<endl;
            last_line=line;
            continue;
        }
        cout<<line<<endl;
    }

    if(is_paragraph)
    {
        last_line=last_line+"</p>";
        cout<<last_line<<endl;
        is_paragraph=false;
    }
    if(is_item)
    {
        cout<<"</ul>"<<endl;
    }


    return 0;
}