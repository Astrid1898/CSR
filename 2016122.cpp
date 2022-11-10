/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-11-05 19:57:45
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-11-09 21:42:59
 */
#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

/*
 *题目说好的整百，其实无所谓，对精度要求比较宽泛，这里还是将最后两位置0了
 * 扣税：
 * 1500元以最多缴纳45元
 * 4500元部分最多缴纳345元
 * 9000元部分最多缴纳1245元
 * 35000元部分最多缴纳7745元
 * 55000元部分最多缴纳13745
 * 80000元部分最多缴纳22495元
 */




int main()
{
    IOS;

//    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);

    int t, salary;
    cin >> t;

    if (t <= 3500)
        salary = t;
    else if (t <= 4955)
    {
        salary = (t - 3500) *100/97 + 3500;
    }
    else if (t <= 7655)
    {
        salary = (t - 4955) *100/90 + 5000;
    }
    else if (t <= 11255)
    {
        salary = (t - 7655) *100/80 + 8000;
    }
    else if (t <= 30755)
    {
        salary = (t - 11255) *100/75 + 12500;
    }
    else if (t<=44755)
    {
        salary=(t-30755)*100/70+38500;
    }
    else if (t<=61005)
    {
        salary=(t-44755)*100/65+58500;
    }
    else
    {
        salary=(t-61005)*100/55+83500;
    }


    salary = salary*100/100;
    cout << salary << endl;
    return 0;
}