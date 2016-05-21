/*2506:Tiling
 *百练
 *http://bailian.openjudge.cn/practice/2506
 */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAX 260
int ans[MAX][MAX];
int main()
{
    int n, i, j, beyond, p;
    while (cin >> n)
    {
        memset(ans, 0, sizeof(ans));
        ans[0][0] = 1;
        ans[1][0] = 1;
        ans[2][0] = 3;
        if (n <= 2)
        {
            printf("%d\n", ans[n][0]);
        }
        else
        {
            int cnt = 1;
            for (i = 3; i <= n; ++i)
            {
                beyond = 0; //记录是否超过十
                p = 0;
                for (j = 0; j < cnt; ++j)
                {
                    p = ans[i - 2][j] * 2 + ans[i - 1][j] + beyond;
                    ans[i][j] = p % 10;
                    beyond = p / 10;
                }
                if (beyond)//位数增加一位时的处理
                {
                    ans[i][cnt] = beyond;
                    cnt++;
                }
            }
            for (i = cnt - 1; i >= 0; --i)
                cout << ans[n][i];
            cout << endl;
        }
    }
    system("pause");
    return 0;
}