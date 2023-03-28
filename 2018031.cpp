//
// Created by zhaojiangfeng on 2023/3/22.
//

#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);

    int n;
    int pre_score = 1, total_score = 0;

    while (true)
    {
        cin >> n;
        switch (n)
        {
            case 0:
                cout << total_score << endl;
                return 0;
            case 1:
                pre_score=1;
                total_score+=1;
                break;
            case 2:
                if(pre_score==1)
                {
                    total_score+=2;
                    pre_score=2;
                }
                else
                {
                    total_score=total_score+pre_score+2;
                    pre_score+=2;
                }
        }

    }


    return 0;
}
