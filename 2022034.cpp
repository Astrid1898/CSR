/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-06-08 13:46:12
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-06-14 01:50:15
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class computer
{
private:
    int *limits;
    int number_of_computer;
    map<int, vector<pair<int, int>>> valid_day;

public:
    computer(int n)
    {
        limits = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            limits[i] = 0;
        }
        number_of_computer = n;
    }

    void add_limits(int v, int limit, int days, int today)
    {
        limits[v] += limit;
        if (valid_day.find(today + days - 1) != valid_day.end())

            valid_day[today + days - 1].push_back(make_pair(v, limit));
        else
        {
            valid_day[today + days - 1] = vector<pair<int, int>>();
            valid_day[today + days - 1].push_back(make_pair(v, limit));
        }
    }

    void update(int today)
    {
        // cout << "更新第" << today << "天" << endl;
        map<int, vector<pair<int, int>>>::iterator iter = valid_day.begin();
        while (iter != valid_day.end() && (*iter).first < today)
        {
            for (int i = 0; i < (*iter).second.size(); i++)
            {

                limits[(*iter).second[i].first] -= (*iter).second[i].second;
                if (limits[(*iter).second[i].first] < 0)
                    limits[(*iter).second[i].first] = 0;
            }
            // cout << "剩余数量" << valid_day.size() << endl;
            iter = valid_day.erase(iter);
        }
    }

    vector<int> find_request()
    {
        // cout << "开始查找" << endl;
        int max = 0;
        vector<int> ans;
        int key_object = 0;
        for (int i = 1; i <= number_of_computer; i++)
        {
            if (limits[i] == 0)
                ans.push_back(0);
            else if (limits[i] > max)
            {
                // cout << "limit=" << limits[i] << endl;
                key_object = i;
                max = limits[i];
            }
        }
        if (key_object > 0)
            ans.insert(ans.begin(), key_object);
        // cout << "找到的结果" << ans[0] << endl;
        return ans;
    }
};

int main()
{
    // cout << "开始运行" << endl;
    int n, m, k, l, q, p, u, v, x, y;
    // cout << "声明变量" << endl;
    cin >> n >> m;
    // cout << "读入变量" << n << " " << m;
    computer *computers[n + 1];
    for (int i = 1; i <= n; i++)
    {
        computers[i] = new computer(n);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        // cout << "k=" << k << endl;
        while (k--)
        {
            cin >> u >> v >> x >> y;
            computers[u]->add_limits(v, x, y, i);
            computers[v]->add_limits(u, x, y, i);
        }
        for (int j = 1; j <= n; j++)
        {
            computers[j]->update(i);
        }
        cin >> l;
        while (l--)
        {
            int request_id;
            cin >> request_id;
            vector<int> result = computers[request_id]->find_request();
            if (result.empty())
                cout << 0 << endl;
            else
                cout << result[0] << endl;
        }

        cin >> p >> q;
        // cout << "p,q=" << p << " " << q << endl;
        if (p || q)
        {
            //     cout << "p或者q" << endl;
            vector<vector<int>> result;
            for (int j = 1; j <= n; j++)
            {
                result.push_back(computers[j]->find_request());
            }
            // cout << "result中的例子" << result[0][0] << endl;
            if (p)
            {
                // cout << "p被启动" << endl;
                int isolate = 0;
                for (auto iter : result)
                {
                    if (iter.front() == 0)
                        isolate++;
                }
                // cout << "测试";
                cout << isolate << endl;
            }
            if (q)
            {
                // cout << "测试q" << endl;
                int pair_count = 0;
                int pairs[n + 1]{0};
                // cout << "pairs=" << pairs[n] << endl;
                for (int id = 1; id <= n; id++)
                {
                    if (result[id - 1].front() != 0)
                        pairs[id] = result[id - 1].front();
                }
                // cout << pairs[n];
                map<int, int> computer_pair;
                for (int id = 1; id <= n; id++)
                {
                    if (pairs[id] && pairs[pairs[id]] == id)
                    {
                        computer_pair[id] = pairs[id];
                        computer_pair[pairs[id]] = id;
                    }
                }
                pair_count = computer_pair.size() / 2;
                cout << pair_count << endl;
            }
        }
    }
    return 0;
}