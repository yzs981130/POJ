/*1458:Common Subsequence
 *∞Ÿ¡∑
 *http://bailian.openjudge.cn/practice/1458/
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[210], b[210];
    while (scanf("%s%s", a + 1, b + 1) != EOF)
    {
        int table[210][210], i, j;
        int lena = strlen(a + 1);
        int lenb = strlen(b + 1);
        for (i = 0; i <= lena; i++)
            table[i][0] = 0;
        for (i = 0; i <= lenb; i++)
            table[0][i] = 0;
        for (i = 1; i <= lena; i++)
        {
            for (j = 1; j <= lenb; j++)
            {
                if (a[i] == b[j])
                    table[i][j] = table[i - 1][j - 1] + 1;
                else if (table[i - 1][j] > table[i][j - 1])
                    table[i][j] = table[i - 1][j];
                else
                    table[i][j] = table[i][j - 1];
            }
        }
        printf("%d\n", table[lena][lenb]);
    }
    system("pause");
    return 0;
}