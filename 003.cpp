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
1 1 1 1 1 3 7 8 9 10

输出：
3

说明：
输入的第一行表示共有10块雨花石，第二行表示这些石头的重量分别为1、1、1、1、1、9、8、3、7、10。在一种平均分配的方案下，
可以选择1,1,1,1,1,9,7和10,8,3两种方式，其中第一种方式只需取出重量为10,8,3的3块石头，而第二种方式则需要取出4块石头，因此输出3（取出的石头数量最少）。


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#ifdef __GNUC__
#define POPCOUNT __builtin_popcount
#elif defined(_MSC_VER)
#include <intrin.h>
#define POPCOUNT __popcnt
#endif
#include <bitset>
int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;
    std::vector<int> m(n);
    std::vector<int> dp(1001, 0);
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
    sort(m.begin(), m.end(), std::greater<int>());
    auto half = sum / 2;
    // 暴力枚举
    for (long long i = 0; i < (1 << n) + 1; i++)
    {
        long long sum = 0;
        for (long long j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += m[j];
            }
        }
        if (sum == half)
        {
            // std::cout << __builtin_popcount(i) << std::endl;
            std::cout << POPCOUNT(i) << ' ' << std::bitset<32>(i) << std::endl;
            // return 0;
        }
    }

    // 动态规划
    dp[0] = 1;
    for (int i = 1; i < m.size(); i++)
    {
        for (int j = half; j >= m[i]; j--)
        {
            dp[j] = dp[j - m[i]] + 1;
        }
        if (dp[half])
        {
            std::cout << dp[half] << std::endl;
            return 0;
        }
    }
    return 0;
}