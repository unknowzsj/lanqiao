//
// Created by zhengwei.
//

/*
标题：魔方状态

二阶魔方就是只有2层的魔方，只由8个小块组成。
如图p1.png所示。

小明很淘气，他只喜欢3种颜色，所以把家里的二阶魔方重新涂了颜色，如下：

前面：橙色
右面：绿色
上面：黄色
左面：绿色
下面：橙色
后面：黄色

请你计算一下，这样的魔方被打乱后，一共有多少种不同的状态。

如果两个状态经过魔方的整体旋转后，各个面的颜色都一致，则认为是同一状态。

请提交表示状态数的整数，不要填写任何多余内容或说明文字。
*/
/*
---------------------
作者：豌豆苞谷
        来源：CSDN
        原文：https://blog.csdn.net/qq_35222235/article/details/79725363
版权声明：本文为博主原创文章，转载请附上博文链接！*/

#include <vector>
#include <set>
#include <iostream>

using namespace std;
typedef char st[8][7];
st start = {{"oybbgb"},
            {"oygbbb"},
            {"bygbby"},
            {"bybbgy"},
            {"obbogb"},
            {"obgobb"},
            {"bbgoby"},
            {"bbbogy"}};
st q[4000000];
set<string> all_state;
int ans, front, tail;


string to_string(st &a) {
    string ans;
    for (int i = 0; i < 8; ++i) {
        ans += a[i];
    }
    return ans;
}

//上层的块的旋转，面的相对位置调换
void ucell(char *a) {
    swap(a[0], a[2]);
    swap(a[2], a[5]);
    swap(a[5], a[4]);
}

//上层顺时针旋转
void u(st &s) {
    ucell(s[0]);
    ucell(s[1]);
    ucell(s[2]);
    ucell(s[3]);
//    块的相对位置调换
    swap(s[1], s[0]);
    swap(s[2], s[1]);
    swap(s[3], s[2]);

}

//右层旋转是面的位置变化
void rcell(char *a) {
    swap(a[1], a[0]);
    swap(a[0], a[3]);
    swap(a[3], a[5]);
}

void r(st &s)//魔方右层顺时针转
{
    rcell(s[1]);
    rcell(s[2]);
    rcell(s[6]);
    rcell(s[5]);
//    块的位置变化
    swap(s[2], s[1]);
    swap(s[5], s[1]);
    swap(s[6], s[5]);
}

void fcell(char *a) {
    swap(a[2], a[1]);
    swap(a[1], a[4]);
    swap(a[4], a[3]);
}

void f(st &s)//前面一层 顺时针转
{
    fcell(s[0]);
    fcell(s[1]);
    fcell(s[4]);
    fcell(s[5]);
    swap(s[1], s[5]);
    swap(s[0], s[1]);
    swap(s[4], s[0]);
}

void uwhole(st &s)//整个魔方从顶部看 顺时针转 用于判重
{
    u(s);//上层旋转
//    下层旋转
    ucell(s[4]);
    ucell(s[5]);
    ucell(s[6]);
    ucell(s[7]);
//    完成自旋后，块的位置变动
    swap(s[5], s[4]);
    swap(s[6], s[5]);
    swap(s[7], s[6]);
}

void fwhole(st &s)//整个魔方从前面看 顺时针转 用于判重
{
    f(s);
    fcell(s[2]);
    fcell(s[6]);
    fcell(s[7]);
    fcell(s[3]);
    swap(s[2], s[6]);
    swap(s[3], s[2]);
    swap(s[7], s[3]);
}

void rwhole(st &s)//整个魔方从右边看 顺时针转 用于判重
{
    r(s);
    rcell(s[0]);
    rcell(s[3]);
    rcell(s[4]);
    rcell(s[7]);
    swap(s[3], s[7]);
    swap(s[0], s[3]);
    swap(s[4], s[0]);
}


bool try_insert(st &s) {
    st k;
    memcpy(k, s, sizeof(start));
    for (int i = 0; i < 4; i++) {
        fwhole(k);
        for (int j = 0; j < 4; j++) {
            uwhole(k);
            for (int q = 0; q < 4; q++) {
                rwhole(k);
                if (all_state.count(to_string(k)) == 1) {
                    return false;
                }
            }
        }
    }
    all_state.insert(to_string(k));
    return true;

}

void solve() {
    front = 0;
    tail = 1;
    all_state.insert(to_string(start));
    memcpy(q[front], start, sizeof(start));//填充q[0]，相当于第一个状态入队列
    while (front < tail) {
        /*将其所有变形，尝试加入set中*/
        memcpy(q[tail], q[front], sizeof(start));//拷贝到tail
        u(q[tail]);//上层顺时针旋转
        if (try_insert(q[tail])) {
            tail++;//扩展队列
        }
        memcpy(q[tail], q[front], sizeof(start));//拷贝到tail
        r(q[tail]);//右层顺时针旋转
        if (try_insert(q[tail])) {
            tail++;//扩展队列
        }
        memcpy(q[tail], q[front], sizeof(start));//拷贝到tail
        f(q[tail]);//前顺时针旋转
        if (try_insert(q[tail])) {
            tail++;//扩展队列
        }
        front++;//弹出队首
//        cout << front << " " << tail << endl;
    }

    cout << front << endl;
}

int main(int argc, const char *argv[]) {
    solve();
    return 0;
}