//
// Created by zjf on 2023/3/16.
//

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int fatigues[502][502];

int main()
{
    IOS;
    memset(fatigues,0x3f,sizeof(fatigues));

    int n,m;
    cin>>n>>m;
    int t,a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>t>>a>>b>>c;
        int fatigue=c;
        if(t==1)
            fatigue=c*c;
        if(fatigues[a][b]>fatigue)
        {
            fatigues[a][b]=fatigue;
            fatigues[b][a]=fatigue;
        }
    }
    return 0;
}
