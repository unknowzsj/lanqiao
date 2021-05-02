//
// Created by zhengwei.
//

/*
最大比例

X星球的某个大奖赛设了M级奖励。每个级别的奖金是一个正整数。
并且，相邻的两个级别间的比例是个固定值。
也就是说：所有级别的奖金数构成了一个等比数列。比如：
16,24,36,54
其等比值为：3/2

现在，我们随机调查了一些获奖者的奖金数。
请你据此推算可能的最大的等比值。

输入格式：
第一行为数字 N (0<N<100)，表示接下的一行包含N个正整数
第二行N个正整数Xi(Xi<1 000 000 000 000)，用空格分开。每个整数表示调查到的某人的奖金数额

要求输出：
一个形如A/B的分数，要求A、B互质。表示可能的最大比例系数

测试数据保证了输入格式正确，并且最大比例是存在的。

例如，输入：
3
1250 200 32

程序应该输出：
25/4

再例如，输入：
4
3125 32 32 200

程序应该输出：
5/2

再例如，输入：
3
549755813888 524288 2

程序应该输出：
4/1

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 3000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long LL;
int N;
LL data[100];

struct Ratio {
    LL x, y;

    Ratio(LL _x, LL _y) : x(_x), y(_y) {
        LL _gcd = gcd(x, y);
        x /= _gcd;
        y /= _gcd;
    }

    LL gcd(LL a, LL b) {
        if (b == 0)return a;
        return gcd(b, a % b);
    }
};

vector<Ratio> ratios;
map<LL, map<LL,LL> > all_ex;//all_ex[x][pow]==x开pow次方
map<LL, map<LL,LL> > all_log;//all_log[x][y]==log_y_x，y的多少次方是x？
void init(){
    for (int i = 2; i < 1e6; ++i) {//底数
        LL cur=(LL)i*i;
        int pow=2;
        while(cur<1e12){
            all_ex[cur][pow]=i;
            all_log[cur][i]=pow;
            pow++;
            cur*=i;
        }
    }
}
/**
 * 对x开pow次方
 * @param x
 * @param pow
 * @return
 */
LL extract(LL x,LL pow){
    if(pow==1)return x;
    if(x==1)return 1;
    if(all_ex[x].find(pow)!=all_ex[x].end())//意味着x可以开pow整数次方
        return all_ex[x][pow];
    else
        return -1;
}
/**
 * 求log_base_x
 * @param base
 * @param x
 * @return
 */
LL log(LL base,LL x){
    if(base==x)return 1;
    if(all_log[x].find(base)!=all_log[x].end())//意味着可以得打一个k，base的k次方是x
        return all_log[x][base];
    return -1;
}
int main(int argc, const char *argv[]) {
    init();
    freopen("/Users/zhengwei/CLionProjects/lanqiaobei2019/2016_C_A/data10/in8.txt","r",stdin);
//处理输入
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &data[i]);
    }
//排序
    sort(data, data + N);
    //处理只有两项的特殊情况
    if(N==2){
        Ratio ans = Ratio(data[1], data[0]);
        cout << ans.x << "/" << ans.y << endl;
        return 0;
    }
//求两两比值，以分数形式存储，vector
    for (int i = 0; i < N - 1; ++i) {
        if (data[i + 1] != data[i])//去重
            ratios.push_back(Ratio(data[i + 1], data[i]));
    }
//对第一个比值开1~..pow(极限为40).次方，作为基数，如果这个基数也是其他比值的基数的话，该基数就是答案
    for (int pow = 1; pow <= 40; ++pow) {
        Ratio ra0 = ratios[0];
        LL x = ra0.x;
        LL y = ra0.y;
        LL base_x = extract(x, pow);//对x开pow次方，作为基数，去尝试
        LL base_y = extract(y, pow);//对y开pow次方，作为基数，去尝试
        if (base_x == -1 || base_y == -1)continue;//开不出，continue
//        能开：就要去确认所有比值的分子是fx的整数次方，所有比值的分母是fy的整数次方
//计px=getPow(xx,base_x),py=getPow(yy,base_y)，要求必须是整数且px==py
        bool all_match = true;
        for (int i = 1; i < ratios.size(); ++i) {
            LL xx = ratios[i].x;
            LL yy = ratios[i].y;
            LL log_x = log(base_x,xx);
            LL log_y = log(base_y,yy);
            if(base_y==1&&yy==1)log_y=log_x;
            if (log_x == -1 || log_y == -1 || log_x != log_y) {
                all_match = false;
                break;
            }
        }
        if (all_match) {
            Ratio ans = Ratio(base_x, base_y);
            cout << ans.x << "/" << ans.y << endl;
            return 0;
        }

    }
    return 0;
}