/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-18 00:53:56
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-18 03:00:48
 */
#include <bits/stdc++.h>

using namespace std;

struct role
{
    string name;
    int nv, no, nn;
    set<string> nv_name;
    set<string> no_name;
    set<string> nn_name;
    bool all_nv = false, all_no = false, all_nn = false;
};

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

int main()
{
    IOS;

    // freopen("CSR/in.txt", "r", stdin);

    map<string, int> name2num;
    map<string, set<int>> user2num;
    map<string, set<int>> group2num;

    int n, m, q;
    cin >> n >> m >> q;
    role roles[n];

    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> roles[i].name;
        name2num[roles[i].name] = i;

        cin >> roles[i].nv;
        for (int j = 0; j < roles[i].nv; j++)
        {
            cin >> tmp;
            roles[i].nv_name.insert(tmp);
            if (tmp == "*")
                roles[i].all_nv = true;
        }

        cin >> roles[i].no;
        for (int j = 0; j < roles[i].no; j++)
        {
            cin >> tmp;
            roles[i].no_name.insert(tmp);
            if (tmp == "*")
                roles[i].all_no = true;
        }

        cin >> roles[i].nn;
        if (roles[i].nn == 0)
            roles[i].all_nn = true;
        for (int j = 0; j < roles[i].nn; j++)
        {
            cin >> tmp;
            roles[i].nn_name.insert(tmp);
        }
    }

    string name;
    int num;
    for (int i = 0; i < m; i++)
    {
        cin >> name;
        int idx = name2num[name];
        cin >> num;
        string type, u_name;
        for (int j = 0; j < num; j++)
        {
            cin >> type >> u_name;
            if (type == "u")
            {
                user2num[u_name].insert(idx);
            }
            else
            {
                group2num[u_name].insert(idx);
            }
        }
    }

    string user_name, op, src_type, src_name, user_group;
    int ng;
    vector<string> user_groups;
    for (int i = 0; i < q; i++)
    {
        cin >> user_name >> ng;
        for (int j = 0; j < ng; j++)
        {
            cin >> user_group;
            user_groups.push_back(user_group);
        }
        cin >> op >> src_type >> src_name;

        int allowed = 0;

        for (string g_name : user_groups)
        {
            if (allowed == 1)
                break;
            if (group2num.find(g_name) != group2num.end())
            {
                for (auto iter = group2num[g_name].begin(); iter != group2num[g_name].end() && allowed == 0; iter++)
                {
                    if (roles[*iter].all_nv || roles[*iter].nv_name.find(op) != roles[*iter].nv_name.end())
                    {
                        if (roles[*iter].all_no || roles[*iter].no_name.find(src_type) != roles[*iter].no_name.end())
                        {
                            if (roles[*iter].all_nn || roles[*iter].nn_name.find(src_name) != roles[*iter].nn_name.end())
                                allowed = 1;
                        }
                    }
                }
            }
        }

        if (user2num.find(user_name) != user2num.end() && allowed == 0)
        {
            for (auto iter = user2num[user_name].begin(); iter != user2num[user_name].end() && allowed == 0; iter++)
            {
                if (roles[*iter].all_nv || roles[*iter].nv_name.find(op) != roles[*iter].nv_name.end())
                {
                    if (roles[*iter].all_no || roles[*iter].no_name.find(src_type) != roles[*iter].no_name.end())
                    {
                        if (roles[*iter].all_nn || roles[*iter].nn_name.find(src_name) != roles[*iter].nn_name.end())
                            allowed = 1;
                    }
                }
            }
        }

        cout << allowed << endl;
    }
    return 0;
}