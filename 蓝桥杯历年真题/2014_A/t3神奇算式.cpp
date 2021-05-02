//
// Created by zhengwei.
//

/*
标题：神奇算式

    由4个不同的数字，组成的一个乘法算式，它们的乘积仍然由这4个数字组成。

    比如：

210 x 6 = 1260
8 x 473 = 3784
27 x 81 = 2187

    都符合要求。

    如果满足乘法交换律的算式算作同一种情况，那么，包含上边已列出的3种情况，一共有多少种满足要求的算式。

    请填写该数字，通过浏览器提交答案，不要填写多余内容（例如：列出所有算式）。

*/
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

bool check(int src, int r);

using namespace std;
int ans;

int main(int argc, const char *argv[]) {
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i != j)
                for (int k = 0; k < 10; ++k) {
                    if (k != i && k != j)
                        for (int l = 0; l < 10; ++l) {
                            if (l != i && l != j && l != k) {
                                int src = i * 1000 + j * 100 + k * 10 + l;//ijkl四位数
                                //验证
                                if (j != 0) {
                                    int r1 = i * (j * 100 + k * 10 + l);//乘法结果
                                    if (check(src, r1)) {
                                        printf("%d * %d\n", i,j * 100 + k * 10 + l);
                                        ans++;
                                    }
                                }
                                //验证
                                if (k != 0) {
                                    int r2 = (i * 10 + j) * (k * 10 + l);//乘法结果
                                    if ((i * 10 + j)< (k * 10 + l)&&check(src, r2)) {
                                        printf("%d *   %d\n", i * 10 + j, k * 10 + l);
                                        ans++;
                                    }
                                }
//                                if (l != 0) {
//                                    int r3 = (i * 100 + j * 10 + k) * (l);//乘法结果
//                                    if (check(src, r3)) {
//                                        printf("%d * %d\n", i * 100 + j * 10 + k,  l);
//                                        ans++;
//                                    }
//                                }
                            }
                        }
                }
        }
    }

    cout << ans << endl;
    return 0;
}

bool check(int src, int r) {
//    先转字符串，排序，比较
    string src_str, r_str;
    stringstream ss;
    ss << src;
    ss >> src_str;
    stringstream ss1;
    ss1 << r;
    ss1 >> r_str;
    sort(r_str.begin(), r_str.end());
    sort(src_str.begin(), src_str.end());
    if (r_str == src_str) {
        return true;
    }
    return false;
}