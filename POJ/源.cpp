/*04:�ж�����
 *�������ʵϰ / 2015�������ʵϰ֮�ϻ���ϰ��
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