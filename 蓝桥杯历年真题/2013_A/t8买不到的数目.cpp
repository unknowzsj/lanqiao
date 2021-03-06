//
//  Created by zhengwei on 2019/1/25.
//  Copyright © 2019 lanqiao. All rights reserved.
//
/*
 
 标题：买不到的数目
 
 小明开了一家糖果店。他别出心裁：把水果糖包成4颗一包和7颗一包的两种。糖果不能拆包卖。
 
 小朋友来买糖的时候，他就用这两种包装来组合。当然有些糖果数目是无法组合出来的，比如要买 10 颗糖。
 
 你可以用计算机测试一下，在这种包装情况下，最大不能买到的数量是17。大于17的任何数字都可以用4和7组合出来。
 
 本题的要求就是在已知两个包装的数量时，求最大不能组合出的数字。
 
 输入：
 两个正整数，表示每种包装中糖的颗数(都不多于1000)
 
 要求输出：
 一个正整数，表示最大不能买到的糖数
 
 不需要考虑无解的情况
 
 例如：
 用户输入：
 4 7
 程序应该输出：
 17
 
 再例如：
 用户输入：
 3 5
 程序应该输出：
 7
 
 
 资源约定：
 峰值内存消耗 < 64M
 CPU消耗  < 3000ms
 
 
 请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
 
 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
 
 注意: main函数需要返回0
 注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
 注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。
 
 提交时，注意选择所期望的编译器类型。
 
 */

//ax+by=C,不定方程的解 a=4,b=7,C=17 这种情况下，xy实际上有解，7*2+（7-4）==3*7 -1*4
//a,b互质，一定有解且解的数目无穷
//C是gcd(a,b)的倍数，方程一定有解，而且有无穷多解

//条件：一定有解=》a,b互质
//条件2：xy都是大于等于0的整数，在这个限定条件下有的C是无解的，那么C的上界是多少呢？至多是a*b

#include <iostream>
#include <set>

using namespace std;

int main(int argc, const char *argv[]) {
    int a, b;
    scanf("%d %d", &a, &b);
    set<int> ss;
//    枚举a*x+b*y的值，上边界是a*b
    for (int x = 0; a * x <= a * b; ++x) {
        for (int y = 0; a * x + b * y <= a * b; ++y) {
            ss.insert(ss.end(), a * x + b * y);
        }
    }
    for (int i = a * b; i >= 0; --i) {
        if (ss.find(i) == ss.end())//i不在set中，那么i就是答案
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}