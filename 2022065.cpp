#include <bits/stdc++.h>

using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int main()
{

    freopen("D:\\zjf\\csp\\csp\\csp\\in.txt", "r", stdin);

    int n, q;
    cin >> n >> q;
    double points[n][2];

    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    double d, ra;
    int id, l, r;
    double a, b, s, x, y;

    for (int i = 0; i < q; i++)
    {
        cin >> id >> l >> r;

        switch (id)
        {
            case 1:
                cin >> a >> b;
                for (int j = l - 1; j < r; j++)
                {
                    points[j][0] += a;
                    points[j][1] += b;
                }
                break;
            case 2:
                cin >> a >> b >> s;
                for (int j = l - 1; j < r; j++)
                {
                    x = points[j][0] - a;
                    y = points[j][1] - b;
                    d = sqrt(x * x + y * y);
                    ra = atan2(y, x) + s;
                    points[j][0] = d * cos(ra) + a;
                    points[j][1] = d * sin(ra) + b;

                }
                break;

            case 3:
                cin >> a >> b >> s;
                for (int j = l - 1; j < r; j++)
                {
                    points[j][0] = (points[j][0] - a) * s + a;
                    points[j][1] = (points[j][1] - b) * s + b;
                }
                break;

            case 4:
                cin >> s >> b;
                for (int j = l - 1; j < r; j++)
                {
                    x = points[j][0];
                    y = points[j][1]-b;
                    d = sqrt(x * x + y * y);
                    ra = 2 * s - atan2(y, x);
                    points[j][0] = d * cos(ra);
                    points[j][1] = d * sin(ra) + b;
                }
                break;

            case 5:
                cin >> s >> b;
                for (int j = l - 1; j < r; j++)
                {
                    x = points[j][0];
                    y = points[j][1]-b;
                    ra = atan2(y, x) - s;
                    d = sqrt(x * x + y * y) * cos(ra);

                    points[j][0] = d * cos(s);
                    points[j][1] = d * sin(s) + b;
                }
                break;

            case 6:
            {
                double totalX = 0;
                double totalY = 0;

                for (int j = l - 1; j < r; j++)
                {
                    totalX += points[j][0];
                    totalY += points[j][1];
                }
                cout << setiosflags(ios::fixed) << setprecision(6);
                cout << totalX / (r - l + 1) << " " << totalY / (r - l + 1) << endl;
            }
                break;

            case 7:
            {
                cin >> a >> b;
                double total = 0;
                for (int j = l - 1; j < r; j++)
                {
                    total += (points[j][0] - a) * (points[j][0] - a) + (points[j][1] - b) * (points[j][1] - b);
                }
                cout << setiosflags(ios::fixed) << setprecision(6);
                cout << total << endl;
            }
                break;

            default:
                break;

        }
    }


    return 0;
}