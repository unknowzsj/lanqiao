//
// Created by zhengwei.
//
/*
标题：油漆面积

X星球的一批考古机器人正在一片废墟上考古。
该区域的地面坚硬如石、平整如镜。
管理人员为方便，建立了标准的直角坐标系。

每个机器人都各有特长、身怀绝技。它们感兴趣的内容也不相同。
经过各种测量，每个机器人都会报告一个或多个矩形区域，作为优先考古的区域。

矩形的表示格式为(x1,y1,x2,y2)，代表矩形的两个对角点坐标。

为了醒目，总部要求对所有机器人选中的矩形区域涂黄色油漆。
小明并不需要当油漆工，只是他需要计算一下，一共要耗费多少油漆。

其实这也不难，只要算出所有矩形覆盖的区域一共有多大面积就可以了。
注意，各个矩形间可能重叠。

本题的输入为若干矩形，要求输出其覆盖的总面积。

输入格式：
第一行，一个整数n，表示有多少个矩形(1<=n<10000)
接下来的n行，每行有4个整数x1 y1 x2 y2，空格分开，表示矩形的两个对角顶点坐标。
(0<= x1,y1,x2,y2 <=10000)

输出格式：
一行一个整数，表示矩形覆盖的总面积面积。

例如，
输入：
3
1 5 10 10
3 1 20 20
2 7 15 17

程序应该输出：
340

再例如，
输入：
3
5 2 10 6
2 7 12 10
8 1 15 15

程序应该输出：
128

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。
*/
/*线段树+扫描线，模板题*/
#include <stdio.h>
#include <algorithm>

using namespace std;

/*辅助的数据结构：扫描线*/
struct Line {
    int x1, x2, h, f;//左右坐标，纵坐标（高度），f=1为入边，f=-1为出边
    Line() {}

    Line(int _l, int _r, int _h, int _f) : x1(_l), x2(_r), h(_h), f(_f) {}

    /*按高度排序*/
    bool operator<(const Line &l) const {
        return h < l.h;
    }
};

/*线段树的定义*/
struct SegTree {
    int pl, pr, cnt, len;//左端点编号，右端点编号，被覆盖次数，两个端点之间被覆盖的长度
    SegTree() : cnt(0), len(0) {}

    SegTree *lson, *rson;
};


const int N = 10000;
int n;
int X[N << 1];//记录所有的横坐标
//int PL=0,PR;
Line lines[N];

/*构建区间树*/
SegTree *buildTree(int pl, int pr) {
    SegTree *t = new SegTree();
    t->pl = pl;
    t->pr = pr;
    if (pl == pr)return t;
    int mid = ((pl + pr) >> 1);
    t->lson = buildTree(pl, mid);
    t->rson = buildTree(mid + 1, pr);
    return t;
}

void updateLength(SegTree *pTree, int tl, int tr) {
    if (pTree->cnt) {
        pTree->len = X[tr] - X[tl-1];//将区间树上的端点（序号）反入到X中求得二维坐标上的实际横坐标
    } else if (tl == tr) {
        pTree->len = 0;
    } else {//负数
        pTree->len = pTree->lson->len + pTree->rson->len;
    }

}

void update(SegTree *tree, int pl, int pr, int value) {
    int tl = tree->pl;
    int tr = tree->pr;
    if (pl <= tl && pr >= tr) {
        tree->cnt += value;
        updateLength(tree, tl, tr);
        return;;
    }
    int m = (tl + tr) >> 1;
    if (pl <= m) update(tree->lson, pl, pr, value);
    if (pr > m) update(tree->rson, pl, pr, value);
    updateLength(tree, tl, tr);


}

int ans;

int main(int argc, const char *argv[]) {
    freopen("/Users/zhengwei/CLionProjects/lanqiaobei2019/2017_C_A/data10/in6.txt", "r", stdin);
    scanf("%d", &n);

    int x1, y1, x2, y2;
    int index = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        X[index] = x1;
        lines[index] = Line(x1, x2, y1, 1);//高度1
        index++;

        X[index] = x2;
        lines[index] = Line(x1, x2, y2, -1);//高度2
        index++;
    }
//    大体上就有了2n个横坐标，2n条水平线段
    sort(X, X + index);//所有横坐标点排序
    sort(lines, lines + index);//扫描线排序，从低到高
    /*离散化横坐标*/
    int X_end = unique(X, X + index) - X;//去重返回值是一个迭代器，它指向的是去重后容器中不重复序列的最后一个元素的下一个元素
//    PR=X_end;
//    初始化线段树
    SegTree *root = buildTree(1, X_end);
//    从低到高，遍历扫描线
    for (int i = 0; i < index; ++i) {
        int pl = lower_bound(X, X + X_end, lines[i].x1) - X;//二分查找，记录下标，代表是第几个点
        int pr = lower_bound(X, X + X_end, lines[i].x2) - X;//二分查找，记录下标，代表是第几个点
        update(root, pl+1, pr, lines[i].f);
        ans += root->len * (lines[i + 1].h - lines[i].h);//宽度*高度

    }
    printf("%d\n", ans);
    return 0;
}