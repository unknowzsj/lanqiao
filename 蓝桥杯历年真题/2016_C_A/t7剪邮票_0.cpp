//
// Created by zhengwei.
//
/*
剪邮票

如【图1.jpg】, 有12张连在一起的12生肖的邮票。
现在你要从中剪下5张来，要求必须是连着的。
（仅仅连接一个角不算相连）
比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。

请你计算，一共有多少种不同的剪取方法。

请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

//此题和13年剪格子有相似之处，但是那个题的限制条件是格子数值之和为总和的一半，此题则限制只能是5个格子
//单纯的dfs无法解决T字型连通方案
//本题的解决办法是，找出任意5个格子，判断是否连通
#include <algorithm>
#include <iostream>

using namespace std;

int ans;

bool check(int arr[12]);

void dfs(int g[3][4], int i, int j);

int main(int argc, const char *argv[]) {
    int per[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    do {
        if (check(per))
            ans++;
    } while (next_permutation(per, per + 12));
    cout << ans << endl;
    return 0;
}

bool check(int arr[12]) {
    int g[3][4];
    memset(g, 0, sizeof(g));
//将相应位置标注为1
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (arr[i * 4 + j] == 1)g[i][j] = 1;
        }
    }
//    经典连通块计算
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (g[i][j] == 1) {
                dfs(g, i, j);
                cnt++;
            }
        }
    }
    return cnt == 1;
}

void dfs(int g[3][4], int i, int j) {
    g[i][j] = 0;
    if (i + 1 <= 2 && g[i + 1][j] == 1) dfs(g, i + 1, j);
    if (i - 1 >= 0 && g[i - 1][j] == 1) dfs(g, i - 1, j);
    if (j + 1 <= 3 && g[i][j + 1] == 1) dfs(g, i, j + 1);
    if (j - 1 >= 0 && g[i][j - 1] == 1) dfs(g, i, j - 1);
}
