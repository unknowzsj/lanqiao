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

int a[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};//它的每个排列代表着12选5的一个方案
int ans;

void dfs(int g[3][4], int i, int j) {
    g[i][j] = 0;
    if (i - 1 >= 0 && g[i - 1][j] == 1)dfs(g, i - 1, j);
    if (i + 1 <= 2 && g[i + 1][j] == 1)dfs(g, i + 1, j);
    if (j - 1 >= 0 && g[i][j - 1] == 1)dfs(g, i, j - 1);
    if (j + 1 <= 3 && g[i][j + 1] == 1)dfs(g, i, j + 1);
}

bool check(int path[12]) {
    int g[3][4];
//    将某个排列映射到二维矩阵上
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (path[i * 4 + j] == 1) g[i][j] = 1;
            else g[i][j] = 0;
        }
    }
    int cnt = 0;//连通块的数目
//    g上面就有5个格子被标记为1，现在才用dfs做连通性检查，要求只有一个连通块
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

bool vis[12];

void f(int k, int path[12]) {
    if (k == 12) {
        if (check(path)) {
            ans++;
        }
    }
    for (int i = 0; i < 12; ++i) {
        if (i>0&&a[i]==a[i-1]&&!vis[i-1])continue;//现在准备选取的元素和上一个元素相同，但是上一个元素还没被使用

        if(!vis[i]){//没有被用过的元素可以抓入到path
            vis[i]=true;//标记为已访问
            path[k]=a[i];//将a[i]填入到path[k]中
            f(k + 1, path);//递归
            vis[i]=false;//回溯
        }

    }
}

int main(int argc, const char *argv[]) {
    int path[12];
    f(0, path);
    printf("%d", ans);
    return 0;
}
