/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-19 01:03:23
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-10-08 23:52:50
 */


/*
 * 难点在于想到存储下所有镜面上的反射点，然后按照顺序排列，依次找下一个放射点
 */

#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);


enum class LightDir
{
    X_POS = 0,
    Y_POS = 1,
    X_NEG = 2,
    Y_NEG = 3,
};

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};


inline int sgn(int x)
{
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

struct point
{
    int x, y;

    bool operator==(const point &p) const
    {
        return x == p.x && y == p.y;
    }
};

typedef pair<point, int> point_with_int;
const point NULL_POINT = {INT_MAX, INT_MAX};
const point_with_int NULL_PD = {NULL_POINT, -1};


struct mirror
{
    int x1, x2, y1, y2, k, id;
    double a;


} mirrors[100001];

istream &operator>>(istream &in, mirror &m)
{
    in >> m.x1 >> m.y1 >> m.x2 >> m.y2 >> m.a;
    if (m.x1 > m.x2)
    {
        swap(m.x1, m.x2);
        swap(m.y1, m.y2);
    }
    m.k = (m.y2 - m.y1) / (m.x2 - m.x1);
    return in;
}

class space
{
private:
    map<int, map<int, int>> psx, psy;

public:
    void add_point(int x, int y, int id)
    {
        auto it = psx.find(y);
        if (it == psx.end())
        {
            map<int, int> add;
            add.insert({x, id});
            psx.insert({y, add});
        }
        else
        {
            it->second.insert({x, id});
        }

        it = psy.find(x);
        if (it == psy.end())
        {
            map<int, int> add;
            add.insert({y, id});
            psy.insert({x, add});
        }
        else
        {
            it->second.insert({y, id});
        }

    }

    void del_point(int x, int y)
    {
        psx[y].erase(x);
        psy[x].erase(y);
    }

    void add_mirror(mirror m)
    {
        for (int x = m.x1 + 1, y = m.y1 + m.k; x < m.x2; x++, y += m.k)
        {
            add_point(x, y, m.id);
        }
    }

    void del_mirror(mirror m)
    {
        for (int x = m.x1 + 1, y = m.y1 + m.k; x < m.x2; x++, y += m.k)
        {
            del_point(x, y);
        }
    }

    point_with_int find_nearest_reflect_point(point p, LightDir d)
    {
        if (d == LightDir::X_POS || d == LightDir::X_NEG)
        {
            auto it = psx.find(p.y);
            if (it == psx.end()) return NULL_PD;
            map<int, int>::iterator it2;
            if (d == LightDir::X_POS)
            {
                it2 = it->second.upper_bound(p.x);
                if (it2 == it->second.end())
                        return NULL_PD;
            }
            else
            {
                it2=it->second.lower_bound(p.x);
                if(it2==it->second.begin()) return NULL_PD;
                --it2;
            }
            return {{it2->first,p.y},it2->second};
        }
        else
        {
            auto it=psy.find(p.x);
            if(it==psy.end()) return NULL_PD;
            map<int,int>::iterator it2;
            if(d==LightDir::Y_POS)
            {
                it2=it->second.upper_bound(p.y);
                if(it2==it->second.end())
                    return NULL_PD;
            }
            else
            {
                it2=it->second.lower_bound(p.y);
                if(it2==it->second.begin())
                    return NULL_PD;
                --it2;
            }

            return {{p.x,it2->first},it2->second};
        }
    }


}instance;


LightDir next_dir(LightDir dir,int mirror_k)
{
    if(dir==LightDir::X_POS)
        return mirror_k==1?LightDir::Y_POS:LightDir::Y_NEG;
    else if(dir==LightDir::X_NEG)
        return mirror_k==-1?LightDir::Y_POS:LightDir::Y_NEG;
    else if(dir==LightDir::Y_POS)
        return mirror_k==1?LightDir::X_POS:LightDir::X_NEG;
    else
        return mirror_k==-1?LightDir::X_POS:LightDir::X_NEG;
}



pair<point,int> test_source(point p,LightDir d,double I,int T)
{
    do
    {
        point_with_int ret=instance.find_nearest_reflect_point(p,d);
        point p2=ret.first;
        int id=ret.second;
        int dist=abs(p.x-p2.x)+abs(p.y-p2.y);
        if(p2==NULL_POINT||dist>T)
        {
            p.x+=dx[(int)d]*T;
            p.y+=dy[(int)d]*T;
            break;
        }
        p=p2;
        d=next_dir(d,mirrors[id].k);

        I=I*mirrors[id].a;
        if(I<1.0)
        {
            return{{0,0},0};
        }
        T-=dist;

    }while(T>0);
    return {p,int(I)};
}




int main()
{
    IOS;
    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);
    int m, id;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> id;
        switch (id)
        {
            case 1:
            {
                cin >> mirrors[i];
                mirrors[i].id = i;
                instance.add_mirror(mirrors[i]);
                break;
            }
            case 2:
            {
                int k;
                cin >> k;
                instance.del_mirror(mirrors[k-1]);
                break;
            }
            case 3:
            {
                double I;
                int x, y, d, t;
                cin >> x >> y >> d >> I >> t;
                auto ans=test_source({x,y},(LightDir)d,I,t);
                cout<<ans.first.x<<" "<<ans.first.y<<" "<<ans.second<<endl;
                break;
            }
        }
    }

    return 0;
}