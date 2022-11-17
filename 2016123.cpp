//
// Created by zhaojiangfeng on 2022/11/11.
//

/*
 * 理清其中关系就好，比较简单。给的空间比较大，有256M，可以不考虑空间的浪费问题
 */


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);
    int p, level, r, u, q;
    map<string, int> privilege;
    map<string, map<string, int>> roles;
    map<string, map<string, int>> users;
    string tmp;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> tmp;
        int index = tmp.find(':');
        if (index != tmp.npos)
        {
            level = stoi(tmp.substr(index + 1));
            privilege[tmp.substr(0, index)] = level;
        }
        else
            privilege[tmp] = -1;
    }

    cin >> r;
    int s, role_pri_level;
    string role, role_pri;
    for (int i = 0; i < r; i++)
    {
        cin >> role >> s;

        for (int j = 0; j < s; j++)
        {
            cin >> tmp;
            int index = tmp.find(':');
            if (index != tmp.npos)
            {
                role_pri_level = stoi(tmp.substr(index + 1));
                role_pri = tmp.substr(0, index);
            }
            else
            {
                role_pri_level = -1;
                role_pri = tmp;
            }
            if (roles.find(role) != roles.end() && roles[role].find(role_pri) != roles[role].end())
            {
                if (role_pri_level > roles[role][role_pri])
                    roles[role][role_pri] = role_pri_level;
            }
            else
                roles[role][role_pri] = role_pri_level;
        }
    }

    cin >> u;
    string user, u_role, u_pri;
    int u_pri_level, t;
    for (int i = 0; i < u; i++)
    {
        cin >> user >> t;
        for (int j = 0; j < t; j++)
        {
            cin >> tmp;
            for (auto it = roles[tmp].begin(); it != roles[tmp].end(); it++)
            {
                u_pri = it->first;
                u_pri_level = it->second;
                if (users.find(user) != users.end() && users[user].find(u_pri) != users[user].end())
                {
                    if (users[user][u_pri] < u_pri_level)
                        users[user][u_pri] = u_pri_level;
                }
                else
                    users[user][u_pri] = u_pri_level;

            }


        }
    }

    cin >> q;
    string q_pri;
    int q_pri_level;
    for (int i = 0; i < q; i++)
    {
        cin >> user >> tmp;

        int index = tmp.find(':');
        if (index != tmp.npos)
        {
            q_pri_level = stoi(tmp.substr(index + 1));
            q_pri = tmp.substr(0, index);
        }
        else
        {
            q_pri_level = -1;
            q_pri = tmp;
        }
        if (users.find(user) != users.end() && users[user].find(q_pri) != users[user].end())
        {
            if (q_pri_level <= users[user][q_pri])
            {
                if (q_pri_level == -1 && users[user][q_pri] != -1)
                    cout << users[user][q_pri] << endl;
                else
                    cout << "true" << endl;
            }
            else
                cout << "false" << endl;
        }
        else
        {
            cout << "false" << endl;
        }

    }

    return 0;
}