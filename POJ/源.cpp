/*03:Communication System
 *程序设计实习 / 2015程序设计实习之上机练习题
 *http://cxsjsx.openjudge.cn/2015finalpractice/03/
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 101

int main()
{
    int i, j;
    int t, n, m[N], k;
    int band[N][N], price[N][N], low, high, sump, minp;
    float ratio;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        low = 0xffff;
        high = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &m[i]);
            for (j = 1; j <= m[i]; j++)
            {
                scanf("%d%d", &band[i][j], &price[i][j]);
                if (band[i][j] < low)
                    low = band[i][j];
                if (band[i][j] > high)
                    high = band[i][j];
            }
        }
        ratio = 0.0;
        for (i = low; i <= high; i++)

        {
            sump = 0;
            for (j = 1; j <= n; j++)
            {
                minp = 0xffff;
                for (k = 1; k <= m[j]; k++)

                    if (band[j][k] >= i && price[j][k] < minp)
                    {
                        minp = price[j][k];
                    }
                sump += minp;

            }

            if (i * 1.0 / sump - ratio > 0)
                ratio = i * 1.0 / sump;
        }
        printf("%.3f\n", ratio);
    }
    system("pause");
    return 0;
}