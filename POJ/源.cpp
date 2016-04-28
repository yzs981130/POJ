/*04:判断闰年
 *程序设计实习 / 2015程序设计实习之上机练习题
 *http://cxsjsx.openjudge.cn/2015finalpractice/04/
 */
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
        cout << 'Y' << endl;
    else
        cout << 'N' << endl;
    system("pause");
    return 0;
}