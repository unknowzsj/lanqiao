//
// Created by zhengwei.
//
/*
方格填数

如下的10个格子
   +--+--+--+
   |  |  |  |
+--+--+--+--+
|  |  |  |  |
+--+--+--+--+
|  |  |  |
+--+--+--+

（如果显示有问题，也可以参看【图7-1.jpg】）

填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）

一共有多少种可能的填数方案？

请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int ans;

bool check(){
         if(abs(a[0]-a[1])==1||
            abs(a[0]-a[3])==1||
            abs(a[0]-a[4])==1||
            abs(a[0]-a[5])==1||

            abs(a[1]-a[2])==1||
            abs(a[1]-a[4])==1||
            abs(a[1]-a[5])==1||
            abs(a[1]-a[6])==1||

            abs(a[2]-a[5])==1||
            abs(a[2]-a[6])==1||

            abs(a[3]-a[4])==1||
            abs(a[3]-a[7])==1||
            abs(a[3]-a[8])==1||

            abs(a[4]-a[5])==1||
            abs(a[4]-a[7])==1||
            abs(a[4]-a[8])==1||
            abs(a[4]-a[9])==1||

            abs(a[5]-a[6])==1||
            abs(a[5]-a[8])==1||
            abs(a[5]-a[9])==1||

            abs(a[6]-a[9])==1||

            abs(a[7]-a[8])==1||

            abs(a[8]-a[9])==1)
             return false;
    return true;
}

/*考虑第k个位置，一般从0开始*/
void f(int k) {
//出口
    if (k == 10) {
        bool b = check();
        if(b)
            ans++;
        return;
    }


    for (int i = k; i < 10; ++i) {
        //尝试将位置i与位置k交换，以此确定k位的值
        {
            int t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
        f(k + 1);
//        回溯
        {
            int t = a[i];
            a[i] = a[k];
            a[k] = t;
        }

    }
}

int main(int argc, const char *argv[]) {
    f(0);
    cout << ans << endl;
    return 0;
}