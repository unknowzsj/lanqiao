//
// Created by zhengwei.
//
/*
标题：斐波那契

    斐波那契数列大家都非常熟悉。它的定义是：

    f(x) = 1                    .... (x=1,2)
    f(x) = f(x-1) + f(x-2)      .... (x>2)

    对于给定的整数 n 和 m，我们希望求出：
    f(1) + f(2) + ... + f(n)  的值。但这个值可能非常大，所以我们把它对 f(m) 取模。
    公式参见【图1.png】

    但这个数字依然很大，所以需要再对 mod 求模。

【数据格式】
输入为一行用空格分开的整数 n m mod (0 < n, m, mod < 10^18)
输出为1个整数

例如，如果输入：
2 3 5
程序应该输出：
0

再例如，输入：
15 11 29
程序应该输出：
25

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。
*/
//f(x) = f(x-1) + f(x-2) -->f(x+1)=f(x)+f(x-1)-->f(x)=f(x+1)-f(x-1)
//Σf(n)=f(n+2)-1
//原题等价于(f(n+2)-1)%f(m)%mod 等价于f(n+2)%f(m)%mod-1
// --> 如果m>=n+2，余f(m)没意义,等价于f(n+2)%mod-1
//-->  否则，一定要求f(m)
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned long long LL;

LL n, m, mod;

class M {
public:
    LL data[2][2];

    M() { memset(data, 0, sizeof(data)); }
};

void solve1() {
    LL a = 1;
    LL b = 1;
    if (m >= n + 2) {
        for (LL i = 3; i <= n + 2; ++i) {
            LL t = a;
            a = b;
            b += t;
        }
        printf("%llu\n", b % mod - 1);
    } else {//m<n+2
        LL fibM, fibN_2 = 0;
        for (LL i = 3; i <= n + 2; ++i) {
            LL t = a;
            a = b;
            b += t;
            if (i == m) fibM = b;
        }
        fibN_2 = b;
        printf("%llu %llu\n", fibN_2, fibN_2 % fibM % mod - 1);
    }


}

//将两个2*2的矩阵相乘
M *mul(M *m1, M *m2) {
    M *ans = new M();
    ans->data[0][0] = m1->data[0][0] * m2->data[0][0] + m1->data[0][1] * m2->data[1][0];
    ans->data[0][1] = m1->data[0][0] * m2->data[0][1] + m1->data[0][1] * m2->data[1][1];
    ans->data[1][0] = m1->data[1][0] * m2->data[0][0] + m1->data[1][1] * m2->data[1][0];
    ans->data[1][1] = m1->data[1][0] * m2->data[0][1] + m1->data[1][1] * m2->data[1][1];
    return ans;
}

//快速乘法
LL mm(LL a, LL b, LL mod) {
    if (a > b) {
        LL t = a;
        a = b;
        b = t;
    }
    LL x = 0;
    while (b != 0) {
        if ((b & 1) == 1) {
            x = (x + a) % mod;
        }
        a = (a * 2) % mod;
        b >>= 1;
    }
    return x;
}

//将两个2*2的矩阵相乘
M *mul(M *m1, M *m2, LL mod) {
    M *ans = new M();
    ans->data[0][0] = (mm(m1->data[0][0], m2->data[0][0], mod) + mm(m1->data[0][1], m2->data[1][0], mod)) % mod;
    ans->data[0][1] = (mm(m1->data[0][0], m2->data[0][1], mod) + mm(m1->data[0][1], m2->data[1][1], mod)) % mod;
    ans->data[1][0] = (mm(m1->data[1][0], m2->data[0][0], mod) + mm(m1->data[1][1], m2->data[1][0], mod)) % mod;
    ans->data[1][1] = (mm(m1->data[1][0], m2->data[0][1], mod) + mm(m1->data[1][1], m2->data[1][1], mod)) % mod;
    return ans;
}

//m的n次幂log(n)
M *mPow(M *m, LL n) {
    M *E = new M();//单位矩阵
    E->data[0][0] = 1;
    E->data[1][1] = 1;

    while (n != 0) {
        if (n & 1 == 1) {
            E = mul(E, m);
        }
        m = mul(m, m);//按平方倍增
        n >>= 1;
    }
    return E;
}

//m的n次幂log(n)
M *mPow(M *m, LL n, LL mod) {
    M *E = new M();//单位矩阵
    E->data[0][0] = 1;
    E->data[1][1] = 1;

    while (n != 0) {
        if ((n & 1) == 1) {
            E = mul(E, m, mod);
        }
        m = mul(m, m, mod);//按平方倍增
        n >>= 1;
    }
    return E;
}

LL fib(LL i) {
    //[1,1]B^(i-2)
    M *A = new M();
    A->data[0][0] = 1;
    A->data[0][1] = 1;
    M *B = new M();
    B->data[0][0] = 1;
    B->data[0][1] = 1;
    B->data[1][0] = 1;
    M *ans = mul(A, mPow(B, i - 2));
    return ans->data[0][0];
}

LL fib(LL i, LL mod) {
    //[1,1]B^(i-2)
    M *A = new M();
    A->data[0][0] = 1;
    A->data[0][1] = 1;
    M *B = new M();
    B->data[0][0] = 1;
    B->data[0][1] = 1;
    B->data[1][0] = 1;
    M *ans = mul(A, mPow(B, i - 2, mod), mod);
    return ans->data[0][0];
}

void solve2() {
    if (m >= n + 2) {
        printf("%llu\n", fib(n + 2, mod) - 1);
    } else {//m<n+2
        LL fibm = fib(m);
        printf("%llu\n", fib(n + 2, fibm) % mod - 1);
    }
}

int main(int argc, const char *argv[]) {
    scanf("%llu %llu %llu", &n, &m, &mod);
//    solve1();
//    for (int i = 3; i <= 10; ++i) {
//       cout<< fib(i)<<endl;
//    }
    solve2();
//cout<<mm(3,7,5);
    return 0;
}