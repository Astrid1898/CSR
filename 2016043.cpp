/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-09-11 01:40:09
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-11 20:17:48
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);

class Node
{
private:
    string name;
    bool is_dir;
    int num_of_children;
    Node **children;
    Node *father;

public:
    Node(string n, bool d) : name(n), is_dir(d)
    {
        children = nullptr;
        father = nullptr;
        num_of_children = 0;
    }

    void set_father(Node *n)
    {
        father = n;
    }

    void set_children_num(int num)
    {
        children = new Node *[num];
    }

    void add_child(Node *c)
    {
        children[num_of_children++] = c;
    }

    string get_name()
    {
        return name;
    }

    Node *get_father()
    {
        return father;
    }

    Node **get_children()
    {
        return children;
    }

    int get_children_num()
    {
        return num_of_children;
    }
};

int main()
{
    IOS;
    Node *root = new Node("/", true);
    Node *d1 = new Node("d1", true);
    Node *d2 = new Node("d2", true);
    Node *d3 = new Node("d3", true);
    Node *d4 = new Node("d4", true);
    Node *f1 = new Node("f1", false);
    Node *f2 = new Node("f2", false);
    Node *f3 = new Node("f3", false);
    Node *f4 = new Node("f4", false);
    Node *f1_2 = new Node("f5", false);

    root->set_children_num(2);
    root->add_child(d1);
    root->add_child(d2);
    d1->set_children_num(2);
    d1->add_child(f1);
    d1->add_child(d2);
    d2->set_children_num(3)
        d2->add_child(d3);
    d2->add_child(d4);
    d2->add_child(f4);
    d3->set_children_num(1);
    d3->add_child(f2);
    d4->set_children_num(1);
    d4->add_child(f1_2);

    return 0;
}