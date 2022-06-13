/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-06-04 23:41:51
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-06-08 13:38:02
 */
#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Node
{
private:
    int block;
    int id;
    int num;
    set<int> tasks;
    int tasksCount;
    static unordered_map<int, set<int>> load;

public:
    bool hasTask(int taskId)
    {
        return !(load[block].find(taskId) == load[block].end());
    }
    bool hasNodeTask(int taskId)
    {
        return !(tasks.find(taskId) == tasks.end());
    }
    int getId()
    {
        return this->id;
    }
    int getBlock()
    {
        return this->block;
    }
    void setTask(int taskId)
    {
        tasks.insert(taskId);
        load[block].insert(taskId);
        tasksCount++;
    }
    int taskCount()
    {
        return tasksCount;
    }
    Node(int id, int block)
    {
        this->id = id;
        this->block = block;
        tasksCount = 0;
    }
};
unordered_map<int, set<int>> Node::load;

void checkCondition1(vector<Node *> &selectedNode, int na)
{
    // cout << "启动第一个筛选函数: " << na << endl;
    vector<Node *>::iterator iter = selectedNode.begin();
    while (iter != selectedNode.end())
    {
        // cout << "第一个筛选函数循环中,当前大小为: " << selectedNode.size() << endl;
        if ((*iter)->getBlock() != na)
        {
            selectedNode.erase(iter);
        }
        else
            iter++;
    }
    // cout << "筛选后的大小为: " << selectedNode.size() << endl;
}

void checkCondition2(vector<Node *> &selectedNode, int pa)
{
    vector<Node *>::iterator iter = selectedNode.begin();
    while (iter != selectedNode.end())
    {
        if ((*iter)->hasTask(pa))
            iter++;
        else
            selectedNode.erase(iter);
    }
}

void checkCondition3(vector<Node *> &selectedNode, int paa)
{
    vector<Node *>::iterator iter = selectedNode.begin();
    while (iter != selectedNode.end())
    {
        if ((*iter)->hasNodeTask(paa))
            selectedNode.erase(iter);
        else
            iter++;
    }
}

bool cmp(Node *a, Node *b)
{
    return a->taskCount() == b->taskCount() ? a->getId() < b->getId() : a->taskCount() < b->taskCount();
}

int main()
{
    int n, m;
    cin >> n >> m;
    Node *nodes[n + 1];
    int blockCount[m + 1]{0};

    int nodeBlock = -1;

    for (int i = 1; i <= n; i++)
    {
        cin >> nodeBlock;
        nodes[i] = new Node(i, nodeBlock);
        blockCount[nodeBlock]++;
    }

    int g;
    cin >> g;
    int f, a, na, pa, paa, paar;
    while (g--)
    {
        cin >> f >> a >> na >> pa >> paa >> paar;
        // cout << f << a << na << pa << paa << paar << endl;
        // cout << blockCount[na] << endl;
        if (na && blockCount[na] == 0)
        {
            while (f--)
                cout << 0 << " ";
            cout << endl;
            continue;
        }
        while (f--)
        {
            vector<Node *> selectedNode(nodes + 1, nodes + n + 1);
            // cout << "开始筛选" << endl;
            // cout << selectedNode[0]->getId() << endl;
            if (na)
                checkCondition1(selectedNode, na);
            // cout << "筛选1" << endl;
            // cout << selectedNode[0]->getId() << endl;
            if (pa)
                checkCondition2(selectedNode, pa);
            if (paa)
            {
                if (paar == 0)
                {
                    vector<Node *> tmp;
                    tmp = selectedNode;
                    // cout << "tmp=" << tmp.size() << "sel=" << selectedNode.size() << " ";
                    checkCondition3(selectedNode, paa);
                    if (selectedNode.empty())
                    {
                        selectedNode = tmp;
                        // cout << "替换" << tmp.size() << endl;
                    }
                }
                else
                    checkCondition3(selectedNode, paa);
            }
            // cout << "查看是否筛选正确" << endl;
            int selectedNodeId = 0;
            if (!selectedNode.empty())
            {
                sort(selectedNode.begin(), selectedNode.end(), cmp);
                selectedNodeId = selectedNode[0]->getId();
                selectedNode[0]->setTask(a);
            }
            cout << selectedNodeId << " ";
        }
        cout << endl;
    }

    return 0;
}