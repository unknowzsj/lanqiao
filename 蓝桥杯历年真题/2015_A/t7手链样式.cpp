//
// Created by zhengwei.
//
/*
手链样式

小明有3颗红珊瑚，4颗白珊瑚，5颗黄玛瑙。
他想用它们串成一圈作为手链，送给女朋友。
现在小明想知道：如果考虑手链可以随意转动或翻转，一共可以有多少不同的组合样式呢？

请你提交该整数。不要填写任何多余的内容或说明性的文字。

*/
//有重复元素的圆排列与环排列的计数问题

//全排列，特殊去重

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
    string s = "aaabbbbccccc";
    vector<string> v1;
    int ans = 0;
    do {
        //排出重复，对于v1中的每个元素进行检查，如果存在s的旋转或者翻转，则跳过
        int i = 0;
        for (; i < v1.size(); ++i) {
            if (v1[i].find(s) != string::npos)
                break;
        }
        //s不可用的情况
        if (i != v1.size())
            continue;
        string s2 = s + s;
        v1.push_back(s2);//用于判断旋转的情况
        reverse(s2.begin(), s2.end());
        v1.push_back(s2);//将s的翻转放入vector中

        ans++;
    } while (next_permutation(s.begin(), s.end()));
    cout << ans << endl;
    return 0;
}
