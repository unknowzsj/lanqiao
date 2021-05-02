//
// Created by zhengwei.
//
/*
题目标题: 排它平方数

    小明正看着 203879 这个数字发呆。

    原来，203879 * 203879 = 41566646641

    这有什么神奇呢？仔细观察，203879 是个6位数，并且它的每个数位上的数字都是不同的，并且它平方后的所有数位上都不出现组成它自身的数字。

    具有这样特点的6位数还有一个，请你找出它！

    再归纳一下筛选要求：
    1. 6位正整数
    2. 每个数位上的数字不同
    3. 其平方数的每个数位不含原数字的任何组成数位

答案是一个6位的正整数。

请通过浏览器提交答案。
注意：只提交另一6位数，题中已经给出的这个不要提交。
注意：不要书写其它的内容（比如：说明性的文字）。*/


#include <iostream>
#include <sstream>

using namespace std;

bool check(long long x, long long xx);

void i2s(long long, string &basic_string);

using namespace std;

int main(int argc, const char *argv[]) {
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j != i)
                for (int k = 0; k < 10; ++k) {
                    if (k != i && k != j)
                        for (int l = 0; l < 10; ++l) {
                            if (l != i && l != j && l != k)
                                for (int m = 0; m < 10; ++m) {
                                    if (m != i && m != j && m != k && m != l)
                                        for (int n = 0; n < 10; ++n) {
                                            if (n != i && n != j && n != k && n != l && n != m) {
                                                long long x = i * 100000 + j * 10000 + k * 1000 + l * 100 + m * 10 + n;
                                                if (check(x, x * x)) {
                                                    cout << x << " " << x * x << endl;
                                                }
                                            }
                                        }
                                }
                        }
                }
        }
    }
    return 0;
}

/**
 * 检查xx中是否含有x中的数字
 * @param x
 * @param xx
 * @return
 */
bool check(long long x, long long xx) {
    string s_x, s_xx;
    i2s(x, s_x);
    i2s(xx, s_xx);
    for (int i = 0; i < s_x.length(); ++i) {
        if (s_xx.find(s_x[i]) != string::npos) {
            return false;
        }
    }
    return true;
}

void i2s(long long x, string &basic_string) {
    stringstream ss;
    ss << x;
    ss >> basic_string;
}