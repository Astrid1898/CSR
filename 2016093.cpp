//
// Created by zhaojiangfeng on 2022/9/13.
//


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


class retinue
{
private:
    int hp;
    int attack;

public:
    retinue(int h, int a)
    {
        this->hp = h;
        this->attack = a;
    }

    int get_hp()
    {
        return this->hp;
    }

    int get_attack()
    {
        return this->attack;
    }

    bool minus_hp(int h)
    {
        this->hp -= h;
        if (this->hp > 0)
            return true;
        else
            return false;
    }

    retinue()
    {
        this->hp = 0;
        this->attack = 0;
    }


};

class player : public retinue
{
private:
    vector<retinue> retinues;
    bool is_alive;
public:
    player(int h, int a) : retinue(h, a)
    {
        is_alive=true;
    }

    int get_retinue_num()
    {
        return retinues.size();
    }

    void attack(player &p, int att_id, int def_id)
    {
        int att = this->retinues[att_id - 1].get_attack();
        if (def_id != 0)
        {
            int def_att = p.be_attacked(def_id, att);
            if (!retinues[att_id - 1].minus_hp(def_att))
            {
                this->retinues.erase(retinues.begin() + att_id - 1);
            }
        }
        else
        {
            int def_att = p.be_attacked(def_id, att);
            if(!this->minus_hp(def_att))
            {
                this->is_alive=false;
            }
        }

    }

    int be_attacked(int def_id, int att)
    {
        int result = this->retinues[def_id - 1].get_attack();
        if (!this->retinues[def_id - 1].minus_hp(att))
        {
            this->retinues.erase(retinues.begin() + def_id - 1);
        }
        return result;
    }

    void summon(int id,int a,int hp)
    {
        this->retinues.insert(retinues.begin()+id-1, retinue(a,hp));
    }
};


int main()
{
    IOS;

    int n;
    cin >> n;
    player player1(7, 5);
    return 0;
}