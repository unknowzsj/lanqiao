//
// Created by zhengwei.
//
/*
标题：跳蚱蜢

如图 p4-1.png 所示：
有9只盘子，排成1个圆圈。
其中8只盘子内装着8只蚱蜢，有一个是空盘。
我们把这些蚱蜢顺时针编号为 1~8

每只蚱蜢都可以跳到相邻的空盘中，
也可以再用点力，越过一个相邻的蚱蜢跳到空盘中。

请你计算一下，如果要使得蚱蜢们的队形改为按照逆时针排列，
并且保持空盘的位置不变（也就是1-8换位，2-7换位,...），至少要经过多少次跳跃？

注意：要求提交的是一个整数，请不要填写任何多余内容或说明文字。

*/


#include <iostream>
#include <queue>
#include <set>

using namespace std;
char *start = "012345678";
char *target = "087654321";

struct StateAndLevel {
    char *state;
    int level;
    int pos0;

    StateAndLevel(char *_state, int _level, int _pos0) : state(_state), level(_level), pos0(_pos0) {}
};

struct cmp {
    bool operator()(char *a, char *b) {
        return strcmp(a, b) < 0;
    }
};

queue<StateAndLevel> q;
set<char *, cmp> allState;

void swap(char *s, int a, int b) {
    char t = s[a];
    s[a] = s[b];
    s[b] = t;
}

void addNei(char *state, int pos, int newPos, int le) {
    char *new_state = (char *) malloc(9 * sizeof(char));
    strcpy(new_state, state);
    //交换
    swap(new_state, pos, newPos);
    if (allState.find(new_state) == allState.end()) {
        allState.insert(new_state);
        q.push(StateAndLevel(new_state, le + 1, newPos));
    }
}

int main(int argc, const char *argv[]) {
    q.push(StateAndLevel(start, 0, 0));
    allState.insert(start);

    while (!q.empty()) {
        StateAndLevel sal = q.front();
        char *state = sal.state;
        int le = sal.level;
        if (strcmp(state, target) == 0) {//当前演变的状态已经是目标状态
            cout << le << endl;
            return 0;
        }
        int pos0 = sal.pos0;

        int new_pos = (pos0 - 1 + 9) % 9;
        addNei(state, pos0, new_pos, le);
        new_pos = (pos0 - 2 + 9) % 9;
        addNei(state, pos0, new_pos, le);
        new_pos = (pos0 + 1 + 9) % 9;
        addNei(state, pos0, new_pos, le);
        new_pos = (pos0 + 2 + 9) % 9;
        addNei(state, pos0, new_pos, le);
        q.pop();
    }
    return 0;
}
