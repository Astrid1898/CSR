//
// Created by zhaojiangfeng on 2022/10/11.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main()
{
    IOS;

    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);


    map<int,pair<int,int>> dangerous_area;
    map<int,set<int>> dangerous_people;
    int n;
    cin>>n;
    int d,u,r,ri,mi,pij;
    for(int i=0;i<n;i++)
    {

        //�ȴ�������߷��յ������б�
        cin >> ri >> mi;
        for (int j = 0; j < ri; j++)
        {
            cin >> pij;
            if (dangerous_area.find(pij) != dangerous_area.end())
            {
                dangerous_area[pij].second = i + 6;
            }
            else
            {
                dangerous_area[pij] = make_pair(i, i + 6);
            }

        }

        //��ǰһ�ս���߷��գ����ҽ����޷�����Ϣ�ĵ�������߷��գ�ͬʱ��������ʸõ���������߷��յ��û�
        for (auto it = dangerous_area.begin(); it != dangerous_area.end();)
        {
            if (it->second.second < i)
            {
                int area=it->first;
                for(auto it2=dangerous_people.begin();it2!=dangerous_people.end();)
                {
                    if(it2->second.find(area)!=it2->second.end())
                    {
                        it2->second.erase(area);
                        if(it2->second.empty()){dangerous_people.erase(it2++);}
                        else{it2++;}
                    }
                    else
                    {
                        it2++;
                    }
                }
                dangerous_area.erase(it++);
            }
            else
            {
                it++;
            }
        }



        //��������û����õ�����Ϣ
        for(int j=0;j<mi;j++)
        {
            cin>>d>>u>>r;
            if(dangerous_area.find(r)!=dangerous_area.end())
            {
                int begin=dangerous_area[r].first;
                if(d>=begin)
                {
                    dangerous_people[u].insert(r);

                }
            }
        }

//        cout<<"�ڵ� "<<i<<" �죬�߷��յ���һ���� "<<dangerous_area.size()<<" ��,�ֱ���: ";
//        for (auto it = dangerous_area.begin(); it != dangerous_area.end(); it++)
//        {
//            cout<<it->first<<" ";
//        }
//        cout<<endl;
//
//        cout<<"�ڵ� "<<i<<" ��, ����������һ���� "<<dangerous_people.size()<<" �ˣ��ֱ���: ";
        cout<<i;
        for(auto it=dangerous_people.begin();it!=dangerous_people.end();it++)
        {
            cout<<" "<<it->first;
        }
        cout<<endl;


    }

    return 0;
}