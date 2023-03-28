//
// Created by zjf on 2023/3/23.
//

#include<bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

struct ball
{
    bool to_left;
    int id;
    bool update;

    explicit ball(int id) : id(id), to_left(true)
    {}

    ball(bool toLeft, int id, bool update) : to_left(toLeft), id(id), update(update)
    {}

    ball()
    {}
};



void get_next(vector<vector<ball>> & balls,int* positions)
{
    if(!balls[0].empty())
    {
        balls[0][0].to_left= true;
        balls[0][0].update= false;
    }
    if(!balls[balls.size()-1].empty())
    {
        balls[balls.size()-1][0].to_left=false;
        balls[balls.size()-1][0].update=false;
    }

    for(int i=1;i<balls.size()-1;i++)
    {
        if(balls[i].size()==2)
        {
            balls[i][0].to_left=!balls[i][0].to_left;
            balls[i][1].to_left=!balls[i][1].to_left;
            balls[i][0].update= false;
            balls[i][1].update= false;
        }
        else if(balls[i].size()==1)
        {
            balls[i][0].update=false;
        }
    }

    for(int i=0;i<balls.size();i++)
    {
        for(auto iter=balls[i].begin();iter!=balls[i].end();)
        {
            if(!iter->update)
            {
                if(iter->to_left)
                {
                    positions[iter->id]=i+1;
                    balls[i+1].push_back(ball(iter->to_left,iter->id,true));
                    balls[i].erase(iter);
                }
                else
                {
                    positions[iter->id]=i-1;
                    balls[i-1].push_back(ball(iter->to_left,iter->id,true));
                    balls[i].erase(iter);
                }

            }
            else
                iter++;
        }

    }


}

int main()
{
    IOS;
    freopen("D:\\code\\CODE_C\\C_Single\\CSR\\in.txt", "r", stdin);
    int n, l, t;
    cin >> n >> l >> t;
    vector<vector<ball>> balls(l+1);


    //其实这里position是冗余的，也不必记录小球id，因为在任意时刻，小球在线段上都是顺序分布的
    int positions[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>positions[i];
        balls[positions[i]].push_back(ball(i));
    }

    for(int i=0;i<t;i++)
    {
        get_next(balls,positions);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<positions[i]<<" ";
    }
    return 0;
}