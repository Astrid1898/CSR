/*
 * @Descripttion:
 * @version:
 * @Author: Zhao Jiangfeng
 * @Date: 2022-05-28 23:40:43
 * @LastEditors: Zhao Jiangfeng
 * @LastEditTime: 2022-09-06 02:33:29
 */

//#include <bitset>
//#include <ctime>
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <set>
//#include <map>
//#include <queue>
//using namespace std;

// int main()
// {
//     const int N = 2000000;
//     clock_t cstart = clock();

//     bitset<N + 1> b;
//     int count = 0;
//     int i;
//     for (i = 2; i <= N; i++)
//     {
//         b.set(i);
//     }
//     i = 2;
//     while (i * i <= N)
//     {
//         if (b.test(i))
//         {
//             count++;
//             int k = i * 2;
//             while (k <= N)
//             {
//                 b.reset(k);
//                 k += i;
//             }
//         }
//         i++;
//     }
//     while (i <= N)
//     {
//         if (b.test(i))
//             count++;
//         i++;
//     }

//     clock_t cend = clock();
//     double mills = 1000.0 * (cend - cstart) / CLOCKS_PER_SEC;

//     cout << count << " primes\n"
//          << mills << " milliseconds\n";
//     return 0;
// }

// int main()
// {
//     // unordered_map<int, int> m;
//     map<int, int> m;
//     m[4] = 6;
//     m[2] = 7;
//     // for (auto iter = m.begin(); iter != m.end(); iter++)
//     // cout << (*iter).first << endl;
//     // for (int i = 0; i < 3; i++)
//     // {
//     //     a[i] = new int(i);
//     // }
//     // vector<int *> b(a, a + 3);
//     // cout << *b[1];
//     int *a = new int[10];
//     for (int i = 0; i < 10; i++)
//     {
//         a[i] = i;
//     }
//     int* c = a + 2;
//     cout << c[0];
//     return 0;
// }

//int main()
//{
//    string s1, s2;
//    cin >> s1;
//    getline(cin, s2);
//    cout << "s1=" << s1 << ";" << endl;
//    cout << "s2=" << s2 << ";" << endl;
//    return 0;
//}

#include<stdio.h>
#include<math.h>

//int main()
//{
//    int n;
//    int a[100];
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//    double sqrtD = 0, average = 0, addition = 0;
//    for (int i = 0; i < n; i++)
//    {
//        addition += a[i];
//    }
//    average = addition / n;
//    for (int i = 0; i < n; i++)
//    {
//        sqrtD = sqrtD + pow(a[i] - average, 2);
//    }
//    sqrtD = sqrtD / n;
//    sqrtD = pow(sqrtD, 0.5);
//    double result[100];
//    for (int i = 0; i < n; i++)
//    {
//        result[i] = (a[i] - average) / sqrtD;
//    }
//    for (int i = 0; i < n - 1; i++)
//    {
//        printf("%f\n", result[i]);
//    }
//    printf("%lf", result[n - 1]);
//    return 0;
//
//}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

double m[] = {0,1500,4500,9000,35000,55000,80000,200000};
double suiLv[] = {1,0.97,0.90,0.80,0.75,0.70,0.65,0.55};
double num[10];

int main()
{

    double t;
    scanf("%lf",&t);
    if(t <= 3500)
        printf("%.0f\n",t);
    else
    {
        int idx = 6;
        double  p = t - 3500;
        num[0] = 0;
        for(int i=1; i<=7; i++)
        {
            num[i] = num[i-1] + (m[i]-m[i-1])* (1 - suiLv[i]);
            //cout<<num[i]<<endl;
        }
        for(int i=1; i<=7; i++)
        {
            if(num[i] + p < m[i]) // 找到第一个上线
            {
                idx = i;
                //cout<<"idx: "<<idx<<endl;
                break;
            }
        }
        double tmp = p - (m[idx-1] - num[idx-1]); // 小部分额度收税
        double ans = m[idx-1] + tmp / suiLv[idx] + 3500;
        printf("%.0f",ans);

    }
    return 0;
}