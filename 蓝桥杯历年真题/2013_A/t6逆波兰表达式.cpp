//
//  Created by zhengwei on 2019/1/25.
//  Copyright © 2019 lanqiao. All rights reserved.
//
/*

 标题：逆波兰表达式

 正常的表达式称为中缀表达式，运算符在中间，主要是给人阅读的，机器求解并不方便。

 例如：3 + 5 * (2 + 6) - 1

 而且，常常需要用括号来改变运算次序。

 相反，如果使用逆波兰表达式（前缀表达式）表示，上面的算式则表示为：

 - + 3 * 5 + 2 6 1

 不再需要括号，机器可以用递归的方法很方便地求解。

 为了简便，我们假设：

 1. 只有 + - * 三种运算符
 2. 每个运算数都是一个小于10的非负整数

 下面的程序对一个逆波兰表示串进行求值。
 其返回值为一个结构：其中第一元素表示求值结果，第二个元素表示它已解析的字符数。

 struct EV
 {
 int result;  //计算结果
 int n;       //消耗掉的字符数
 };

 struct EV evaluate(char* x)
 {
 struct EV ev = {0,0};
 struct EV v1;
 struct EV v2;

 if(*x==0) return ev;

 if(x[0]>='0' && x[0]<='9'){
 ev.result = x[0]-'0';
 ev.n = 1;
 return ev;
 }

 v1 = evaluate(x+1);
 v2 = _____________________________;  //填空位置

 if(x[0]=='+') ev.result = v1.result + v2.result;
 if(x[0]=='*') ev.result = v1.result * v2.result;
 if(x[0]=='-') ev.result = v1.result - v2.result;
 ev.n = 1+v1.n+v2.n;

 return ev;
 }


 请分析代码逻辑，并推测划线处的代码，通过网页提交。
 注意：仅把缺少的代码作为答案，千万不要填写多余的代码、符号或说明文字！！


 */

#include <iostream>
#include <cstring>

using namespace std;
struct EV {
    int result;  //计算结果
    int n;       //消耗掉的字符数
};

struct EV evaluate(char *x) {
    struct EV ev = {0, 0};
    struct EV v1;
    struct EV v2;

    if (*x == 0) return ev;

    if (x[0] >= '0' && x[0] <= '9') {
        ev.result = x[0] - '0';//字符转数字'1'-'0'=1
        ev.n = 1;
        return ev;
    }
//- + 3 * 5 + 2 6 1
    v1 = evaluate(x + 1);
    v2 = evaluate(x + 1 + v1.n);  //填空位置

    if (x[0] == '+') ev.result = v1.result + v2.result;
    if (x[0] == '*') ev.result = v1.result * v2.result;
    if (x[0] == '-') ev.result = v1.result - v2.result;
    ev.n = 1 + v1.n + v2.n;

    return ev;
}

int main(int argc, const char * argv[]) {
    string s="-+3*5+261";
    const EV &ev = evaluate((char*)(s.c_str()));
    cout<<ev.result<<endl;
    return 0;
}