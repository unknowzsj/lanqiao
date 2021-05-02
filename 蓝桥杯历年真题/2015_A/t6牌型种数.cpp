//
// Created by zhengwei.
//
/*
牌型种数

小明被劫持到X赌城，被迫与其他3人玩牌。
一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张。
这时，小明脑子里突然冒出一个问题：
如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？

请填写该整数，不要填写任何多余的内容或说明文字。
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string pai[13];

int countOf(vector<string> path, string p) {
    int ans = 0;
    for (int i = 0; i < path.size(); ++i) {
        if (path[i] == p)
            ans++;
    }
    return ans;
}

int ans;

void f(int k, vector<string> path) {

    if (k == 0)ans++;
    for (int i = 0; i < 13; ++i) {
        if (countOf(path, pai[i]) == 4)continue;
        path.push_back(pai[i]);//拼接，代表采纳这张牌
        f(k - 1, path);
        path.erase(path.end() - 1);
    }
}

void i2s(int num, string &str) {
    stringstream ss;
    ss << num;
    ss >> str;
}

int main(int argc, const char *argv[]) {
    for (int i = 1; i <= 13; ++i) {
        i2s(i, pai[i - 1]);
    }
    vector<string> v;
    f(13, v);
    cout << ans << endl;
    return 0;
}

