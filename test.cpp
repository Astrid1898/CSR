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

int main()
{
    int n;
    int a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    double sqrtD = 0, average = 0, addition = 0;
    for (int i = 0; i < n; i++)
    {
        addition += a[i];
    }
    average = addition / n;
    for (int i = 0; i < n; i++)
    {
        sqrtD = sqrtD + pow(a[i] - average, 2);
    }
    sqrtD = sqrtD / n;
    sqrtD = pow(sqrtD, 0.5);
    double result[100];
    for (int i = 0; i < n; i++)
    {
        result[i] = (a[i] - average) / sqrtD;
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%f\n", result[i]);
    }
    printf("%lf", result[n - 1]);
    return 0;

}