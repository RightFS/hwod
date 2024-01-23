/*
给定坐标轴上的一组线段，线段的起点和终点均为整数并且长度不小于1，请你从中找到最少数量的线段，这些线段可以覆盖住所有线段。

输入描述
第一行输入为所有线段的数量，不超过10000，后面每行表示一条线段，格式为”x,y”，
x和y 分别表示起点和终点，取值范围是[-10^5 ，10^5]。
输出描述

最少线段数量，为正整数。
输入
5
1,4
2,5
3,6
1,9
4,6

输出
1

输入
5
1,4
2,5
3,6
3,9
4,6

输出
2

输入
3
1,4
2,5
3,6
输出
2

输入
3
1,4
2,8
6,9
输出
3

输入
7
-100000,100000
-100000,-99999
99999,100000  
0,1
-1,0
-2,-1
-3,-2
输出
1
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    while (1)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> lines(n);
        int a, b;
        char spliter;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> spliter >> b;
            lines[i] = make_pair(a, b);
        }
        sort(lines.begin(), lines.end(), [](pair<int, int> a, pair<int, int> b)
             { 
                if(a.first==b.first){
                    return a.second > b.second;
                }
                return a.first < b.first; });
        auto res = 1;
        auto start = lines[0].first;
        auto end = lines[0].second;
        for (int i = 1; i < n; i++)
        {
            if (end < lines[i].second)
            {
                int flag = 0;
                end = lines[i].second;
                res++;
                for (auto j = i - 1; j >= 0; j--)
                {
                    if (lines[i].first <= lines[j].second)
                    {
                        flag = i - j - 1;
                    }
                }
                res -= flag;
            }
        }
        cout << res << endl;
    }
}
