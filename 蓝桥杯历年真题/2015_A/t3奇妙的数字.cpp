//
// Created by zhengwei.
//

/*
奇妙的数字

小明发现了一个奇妙的数字。它的平方和立方正好把0~9的10个数字每个用且只用了一次。
你能猜出这个数字是多少吗？

请填写该数字，不要填写任何多余的内容。
*/
#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

void i2s(int num, string &str) {
    stringstream ss;
    ss << num;
    ss >> str;
}

bool check(string s) {
    set<char> ss;
    for (int i = 0; i < s.length(); ++i) {
        ss.insert(s[i]);
    }
    return s.size()==10&&ss.size()==10;
}

int main(int argc, const char *argv[]) {
    for (int i = 1; i < 100000; ++i) {
        string s1, s2;
        i2s(i * i, s1);
        i2s(i * i * i, s2);
        if (check(s1 + s2)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

//69