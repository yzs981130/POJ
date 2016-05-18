/*1080:Human Gene Functions
 *����
 *http://bailian.openjudge.cn/practice/1080/
 */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
const int inf = -5;  //����С

int score['T' + 1]['T' + 1];  //���ֱ�

void initial(void)  //���
{
    score['A']['A'] = 5;
    score['C']['C'] = 5;
    score['G']['G'] = 5;
    score['T']['T'] = 5;
    score['-']['-'] = inf;
    score['A']['C'] = score['C']['A'] = -1;
    score['A']['G'] = score['G']['A'] = -2;
    score['A']['T'] = score['T']['A'] = -1;
    score['A']['-'] = score['-']['A'] = -3;
    score['C']['G'] = score['G']['C'] = -3;
    score['C']['T'] = score['T']['C'] = -2;
    score['C']['-'] = score['-']['C'] = -4;
    score['G']['T'] = score['T']['G'] = -2;
    score['G']['-'] = score['-']['G'] = -2;
    score['T']['-'] = score['-']['T'] = -1;
    return;
}

int max(int a, int b, int c)
{
    int k = (b > c ? b : c);
    return a > k ? a : k;   //ע�������������ֵʱ��a>b?a:(b>c?b:c)��C++���Ǵ����
}                     //b��ֵû����Ϊ(b>c?b:c)���ı䣬������������������ֵ

int main(int i, int j)
{
    initial();

    int test;
    cin >> test;
    while (test--)
    {
        /*Input*/

        int len1, len2;

        cin >> len1;
        char* s1 = new char[len1 + 1];
        cin >> s1;

        cin >> len2;
        char* s2 = new char[len2 + 1];
        cin >> s2;

        int **dp = new int*[len1 + 1];   //���붯̬��ά���飬��һά
        dp[0] = new int[len2 + 1];

        /*Initial*/

        dp[0][0] = 0;
        for (i = 1; i <= len1; i++)
        {
            dp[i] = new int[len2 + 1];  //���붯̬��ά���飬�ڶ�ά
            dp[i][0] = dp[i - 1][0] + score[s1[i - 1]]['-'];   //ע���±꣬dp�����Ǵ�1��ʼ��s1��s2���Ǵ�0��ʼ
        }
        for (j = 1; j <= len2; j++)
            dp[0][j] = dp[0][j - 1] + score['-'][s2[j - 1]];

        /*Dp*/

        for (i = 1; i <= len1; i++)
            for (j = 1; j <= len2; j++)
            {
                int temp1 = dp[i - 1][j] + score[s1[i - 1]]['-'];
                int temp2 = dp[i][j - 1] + score['-'][s2[j - 1]];
                int temp3 = dp[i - 1][j - 1] + score[s1[i - 1]][s2[j - 1]];
                dp[i][j] = max(temp1, temp2, temp3);
            }

        cout << dp[len1][len2] << endl;

        delete[] dp;
    }
    system("pause");
    return 0;
}