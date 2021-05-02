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

using namespace std;

int a[5][6];
int vis[10];
int ans;

bool check(int i,int j) {
    for (int x = i - 1; x <= i + 1; ++x) {
        for (int y = j - 1; y <= j + 1; ++y) {
            if (abs(a[x][y] - a[i][j]) == 1)
                return false;
        }
    }
    return true;
}

void f(int x, int y) {
    if (x == 3 && y == 4) {
        ans++;
        return;
    }
//    从0~9中抓一个
    for (int i = 0; i < 10; ++i) {
        if (vis[i] == 0) {//i没有被用过
            a[x][y] = i;//填数
            if(!check(x,y)){//不合法，恢复并continue
                a[x][y]=-10;
                continue;
            }
            vis[i] = 1;//标记为已访问
            if (y == 4)
                f(x + 1, 1);//换行
            else
                f(x, y + 1);//继续填右侧的格子
            {vis[i] = 0;//回溯
            a[x][y]=-10;}

        }
    }

}

void init() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            a[i][j] = -10;
        }
    }
}

int main(int argc, const char *argv[]) {
    init();
    f(1, 2);
    cout << ans << endl;
    return 0;
}