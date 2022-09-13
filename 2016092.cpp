//
// Created by zhaojiangfeng on 2022/9/13.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
vector<int> result;
bool ticket[101] = {false};

void get_tickets_unadjacent(int orders)
{
    int cnt=0;
    for(int i=1;i<101&&cnt<orders;i++)
    {
        if(!ticket[i])
        {
            ticket[i]=true;
            result.push_back(i);
            cnt++;
        }

    }
    return;





}


bool get_tickets_adjacent(int orders)
{
    int cnt=0;
    for(int i=0;i<20;i++)
    {
        cnt=0;
        for(int j=1;j<=5;j++)
        {
            if(!ticket[5*i+j])
                cnt++;
            else
                cnt=0;
            if(cnt==orders)
            {
                for(int k=5*i+j+1-cnt;k<=5*i+j;k++)
                {
                    ticket[k]=true;
                    result.push_back(k);
                }
                return true;
            }
        }
    }
    return false;
}





int main()
{
    IOS;

    int n;
    cin >> n;
    int orders;
    for (int i = 0; i < n; i++)
    {
        result.clear();
        cin >> orders;
        if(orders==1)
        {
            get_tickets_unadjacent(1);
        }
        else
        {
            if(!get_tickets_adjacent(orders))
            {
                get_tickets_unadjacent(orders);
            }
        }

        for (int j = 0; j < result.size(); j++)
        {
            cout << result[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

