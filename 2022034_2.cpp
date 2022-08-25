/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-06-26 00:01:08
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-06-30 01:30:12
 */

#include <iostream>
#include <queue>
using namespace std;
int *limits;

struct Record
{
    int id1;
    int id2;
    int limit;
    int valid_day;
    bool operator<(const Record &a) const
    {
        return valid_day > a.valid_day;
    }
};
inline int get_real_id(int i, int j)
{
    if (i >= j)
    {
        return i * (i + 1) / 2 + j;
    }
    else
        return j * (j + 1) / 2 + i;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int max_id = (n + 1) * (n + 2) / 2;
    limits = new int[max_id];
    priority_queue<Record> records;
    for (int i = 0; i < max_id; i++)
    {
        limits[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            int real_id = get_real_id(u, v);
            limits[real_id] += x;
            records.push(Record{u, v, x, i + y - 1});
        }
        int l;
        cin >> l;
        while (l--)
        {
            int id, max = 0, max_id = 0;
            cin >> id;
            for (int j = 1; j <= n; j++)
            {
                int real_id = get_real_id(id, j);
                if (limits[real_id] > max)
                {
                    max = limits[real_id];
                    max_id = j;
                }
            }
            cout << max_id << endl;
        }
        int p, q;
        cin >> p >> q;
        if (p || q)
        {
            int isolate = 0;
            int object[n + 1] = {0};
            for (int j = 1; j <= n; j++)
            {
                int max = 0;
                bool sign = true;
                for (int k = 1; k <= n; k++)
                {
                    int real_id = get_real_id(j, k);
                    if (limits[real_id] > max)
                    {
                        max = limits[real_id];
                        sign = false;
                        object[j] = k;
                    }
                }
                if (sign)
                    isolate++;
            }
            if (p)
                cout << isolate << endl;
            if (q)
            {
                int pair_count = 0;
                for (int j = 1; j <= n; j++)
                {
                    // cout << "object[" << j << "]=" << object[j] << " " << object[object[j]] << endl;
                    if (object[object[j]] == j)
                        pair_count++;
                }
                cout << pair_count / 2 << endl;
            }
        }
        if (!records.empty())
        {
            while (records.top().valid_day == i)
            {
                limits[get_real_id(records.top().id1, records.top().id2)] -= records.top().limit;
                records.pop();
            }
        }
    }
    return 0;
}