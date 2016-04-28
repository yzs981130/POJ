/*02:Integer Inquiry
 *程序设计实习 / 2015程序设计实习之上机练习题
 *http://cxsjsx.openjudge.cn/2015finalpractice/02/
 */
#include <iostream>
#include <string>
using namespace std;
int ans[102] = {0}, tmp[102];
int main()
{
    string str;
    while (cin >> str && str != "0")
    {
        for (int i = 0; i < str.length(); i++)
            tmp[i] = str[str.length() - i - 1] - '0';
        for (int i = 0; i < 101; i++)
        {
            ans[i] += tmp[i];
            if (ans[i] > 9)
            {
                ans[i] -= 10;
                ans[i + 1]++;
            }
        }
    }
    int pos = 101;
    while (ans[pos] == 0)
        pos--;
    for (int i = pos; i >= 0; i--)
        cout << ans[i];
    cout << endl;
    system("pause");
    return 0;
}