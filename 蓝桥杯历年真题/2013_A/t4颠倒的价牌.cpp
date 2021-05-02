//
// Created by zhengwei.
//
/*

 标题: 颠倒的价牌


 小李的店里专卖其它店中下架的样品电视机，可称为：样品电视专卖店。

 其标价都是4位数字（即千元不等）。

 小李为了标价清晰、方便，使用了预制的类似数码管的标价签，只要用颜色笔涂数字就可以了（参见p1.jpg）。

 这种价牌有个特点，对一些数字，倒过来看也是合理的数字。如：1 2 5 6 8 9 0 都可以。这样一来，如果牌子挂倒了，有可能完全变成了另一个价格，
 比如：1958 倒着挂就是：8561，差了几千元啊!!

 当然，多数情况不能倒读，比如，1110 就不能倒过来，因为0不能作为开始数字。

 有一天，悲剧终于发生了。某个店员不小心把店里的某两个价格牌给挂倒了。并且这两个价格牌的电视机都卖出去了!

 庆幸的是价格出入不大，其中一个价牌赔了2百多，另一个价牌却赚了8百多，综合起来，反而多赚了558元。

 请根据这些信息计算：赔钱的那个价牌正确的价格应该是多少？


 答案是一个4位的整数，请通过浏览器直接提交该数字。
 注意：不要提交解答过程，或其它辅助说明类的内容。

 * */
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void i2s(int num, string &str) {
    stringstream ss;
    ss << num;
    ss >> str;
}

void s2i(string &str, int &num) {
    stringstream ss;
    ss << str;
    ss >> num;
}

char to(char x) {
    if (x == '6')return '9';
    else if (x == '9')return '6';
    else return x;
}

string reverse(const string &str) {
    string ans;
    for (int i = 3; i >= 0; --i) {
        ans.insert(ans.end(), to(str[i]));
    }
    return ans;
}

struct price {
    int a, b, c;//原始价格，错误价格，差
};
vector<price> v1;//存储-200多的
vector<price> v2;//存储+800多的

int main(int argc, const char *argv[]) {
//    cout<<reverse("1958")<<endl;
// 枚举所有四位数中可以颠倒的
//将其颠倒过来，与原来的数值做差，将-200多和+800的记录下来，分别记录在两个集合中
//遍历两个集合将-+两两求和，结果为558的即为正确答案
    for (int i = 1000; i < 10000; ++i) {
        string str;
        i2s(i, str);
        if (str.find('3') != string::npos || str.find('4') != string::npos || str.find('7') != string::npos ||
            str.rfind('0') == 3)
            continue;
        string r = reverse(str);
        int r_int;
        s2i(r, r_int);//r_int就是翻转后的价格，i是原始价格
        int plus = r_int - i;
        if (plus > -300 && plus < -200) {
            price p = {i, r_int, plus};
            v1.push_back(p);
        } else if (plus > 800 && plus < 900) {
            price p = {i, r_int, plus};
            v2.push_back(p);
        }

//        此时，v1存储了-200多的，v2存储了+800多的
        for (int i = 0; i < v1.size(); ++i) {
            for (int j = 0; j < v2.size(); ++j) {
                if (v1[i].c + v2[j].c == 558) {
                    printf("%d %d %d %d %d %d\n", v1[i].a, v1[i].b, v1[i].c, v2[j].a, v2[j].b, v2[j].c);
                }
            }
        }

    }
    return 0;
}