/*
题目描述
MELON是一个热爱雨花石的人，他拥有一堆数量为n的精美雨花石，每块石头的重量都不相同。
现在，MELON想要将这些雨花石平均分给他的朋友S和W，以使两人所得到的石头的重量相等。
你需要设计一个程序，来帮助MELON确认是否可以实现这样的平均分配。

输入描述：

第一行输入雨花石的个数n，满足0 < n < 31。
第二行输入n个用空格分隔的雨花石的重量m[0] m[1] … m[n-1]，满足0 < m[k] < 1001。
请注意，不需要考虑异常输入的情况。

输出描述：
如果存在一种平均分配方案，输出从当前雨花石中最少需要取出的石头数量。如果无法平均分配，则输出-1。

示例1：
输入：
4
1 1 2 2

输出：
2

说明：
输入的第一行表示共有4块雨花石，第二行表示这些石头的重量分别为1、1、2、2。在一种平均分配的方案下，
只需取出重量为1和2的两块石头，所以输出2。

示例2：
输入：
10
1 1 1 1 19 8 3 7 10

输出：
3

说明：
输入的第一行表示共有10块雨花石，第二行表示这些石头的重量分别为1、1、1、1、19、8、3、7、10。在一种平均分配的方案下，
可以选择1,1,1,1,1,9,7和10,8,3两种方式，其中第一种方式只需取出重量为10,8,3的3块石头，而第二种方式则需要取出4块石头，因此输出3（取出的石头数量最少）。


思路: 先从大的选, 如果超过了一半就从小的放, 换一个比这还小的, 如果还超就换个更小的,直到找到一个合适的. 如果找不到就再丢一下大一点的, 重复上述过程. 如果最后还是找不到就输出-1.
19 10 8 7 3 1 1 1 1
sum= 52
half= 26
19+10 = 29 0 1
19+8 = 27 0 2
19+7 = 26 0 3

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;
    std::vector<int> m(n);
    std::stack<int> index;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> m[i];
    }
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += m[i];
    }
    if (sum % 2 != 0)
    {
        std::cout << -1 << std::endl;
        return 0;
    }
    int half = sum / 2;
    std::sort(m.begin(), m.end(), std::greater<int>());
    int temp = 0;
    int current_drop;
    bool flag = true;
    for (int i = 0; i < m.size() && flag; i++)
    {
        temp += m[i];
        index.push(i);
        if (temp == half)
        {
            break;
        }
        if (temp > half)
        {
            temp -= m[index.top()];
            for (int j = 0; j < index.top(); j++)
            {
                temp += m[j];
                index.push(j);
                if (temp == half)
                {
                    // exit
                    flag = false;
                    break;
                }
                if (temp > half)
                {
                    temp -= m[index.top()];
                    index.pop();
                }
            }
        }
    }
    std::cout << index.size() << std::endl;
    return 0;
}