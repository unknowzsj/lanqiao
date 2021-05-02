//
// Created by zhengwei.
//

/*
标题：方格分割

6x6的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。

如图：p1.png, p2.png, p3.png 就是可行的分割法。

试计算：
包括这3种分法在内，一共有多少种不同的分割方法。
注意：旋转对称的属于同一种分割法。

请提交该整数，不要填写任何多余的内容或说明文字。

*/

#include <iostream>

using namespace std;
int ans;
int dire[][2] = {{-1, 0},
                 {1,  0},
                 {0,  -1},
                 {0,  1}};
int vis[7][7];


void dfs(int x, int y) {
    if (x == 0 || y == 0 || x == 6 || y == 6) {
        ans++;
        return;
    }
//    当前的点标注为已访问
    vis[x][y] = 1;
//    对称点也标注为已访问
    vis[6 - x][6 - y] = 1;
    for (int k = 0; k < 4; ++k) {
        int nx = x + dire[k][0];
        int ny = y + dire[k][1];
//            新坐标
        if (nx < 0 || nx > 6 || ny < 0 || ny > 6)continue;
        if (!vis[nx][ny]) {
            dfs(nx, ny);
        }

    }
    vis[x][y] = 0;
    vis[6 - x][6 - y] = 0;//对称

}

int main(int argc, const char *argv[]) {
    dfs(3, 3);
    cout << ans / 4 << endl;
    return 0;
}