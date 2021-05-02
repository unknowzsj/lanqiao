//
// Created by zhengwei.
//
/*
标题：波动数列

    观察这个数列：
    1 3 0 2 -1 1 -2 ...

    这个数列中后一项总是比前一项增加2或者减少3。

    栋栋对这种数列很好奇，他想知道长度为 n 和为 s 而且后一项总是比前一项增加a或者减少b的整数数列可能有多少种呢？

【数据格式】
    输入的第一行包含四个整数 n s a b，含义如前面说述。
    输出一行，包含一个整数，表示满足条件的方案数。由于这个数很大，请输出方案数除以100000007的余数。

例如，输入：
4 10 2 3
程序应该输出：
2

【样例说明】
这两个数列分别是2 4 1 3和7 4 1 -2。

【数据规模与约定】
对于10%的数据，1<=n<=5，0<=s<=5，1<=a,b<=5；
对于30%的数据，1<=n<=30，0<=s<=30，1<=a,b<=30；
对于50%的数据，1<=n<=50，0<=s<=50，1<=a,b<=50；
对于70%的数据，1<=n<=100，0<=s<=500，1<=a, b<=50；
对于100%的数据，1<=n<=1000，-1,000,000,000<=s<=1,000,000,000，1<=a, b<=1,000,000。

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

//x x+a x+2a x+3a x+(n-1)a  -->nx + (0+1+2+...+n-1)a == nx + (n(n-1)/2)a  == s  ->x的最小值
//x x-b x-2b x-3b x-(n-1)b  -->nx - (0+1+2+...+n-1)b == nx - (n(n-1)/2)b  == s  ->x的最大值
//解法1：枚举首项，深搜

#include <iostream>
#include <vector>
#include <cstring>

#define MOD  100000007
using namespace std;

typedef long long LL;
int n, s, a, b;
long long ans;

void printPath(const vector<int> &path);

void solve1();

void dp1();

void dp2();

void dp3();

/**
 *
 * @param x 上一项
 * @param cnt 截止上一项已经有多少个
 * @param sum 截止上一项已经求得的和
 */
void dfs(LL x, int cnt, int sum, vector<int> path) {
    if (cnt == n) {
        if (sum == s) {
            ans++;
        }
//        printPath(path);
        if (ans > MOD)ans %= MOD;
        return;
    }
    path.push_back(x + a);
    dfs(x + a, cnt + 1, sum + x + a, path);

    path.erase(path.end() - 1);
    path.push_back(x - b);
    dfs(x - b, cnt + 1, sum + x - b, path);
}

void printPath(const vector<int> &path) {
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void solve2();

int main(int argc, const char *argv[]) {
    scanf("%d %d %d %d", &n, &s, &a, &b);
//    solve1();
//    solve2();
//    dp1();
//    dp2();
    dp3();
    return 0;
}

/*一维数组*/
void dp3() {
    int t = n * (n - 1) / 2;
    int dp[t + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = i * (i + 1) / 2; j >= i; --j) {//减少j的枚举
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    for (LL ta = 0; ta <= t; ++ta) {
        LL i = s - ta * a + (t - ta) * b;
        if (i % n == 0)
            (ans += dp[ta]) %= MOD;
    }
    cout << ans << endl;
}

/*2行的数组滚动使用*/
void dp2() {
    int t = n * (n - 1) / 2;
    int dp[2][t + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 1;

    int row = 0;
    for (int i = 1; i < n; ++i) {
        row = 1 - row;
        for (int j = 1; j <= i * (i + 1) / 2; ++j) {//这里可以减少枚举
            if (i > j) dp[row][j] = dp[1 - row][j] % MOD;
            else dp[row][j] = (dp[1 - row][j] + dp[1 - row][j - i]) % MOD;
        }
    }
//    必须用LL，因为s+tb有可能超出int  10^9+10^6*10^6
    for (LL ta = 0; ta <= t; ++ta) {
        LL i = s - ta * a + (t - ta) * b;
        if (i % n == 0)
            (ans += dp[row][ta]) %= MOD;//选择性地累加最后一行
    }
    cout << ans << endl;

}

void dp1() {
    int t = n * (n - 1) / 2;//最终式子中a或b的最大的个数（系数）
    int dp[n][t + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= t; ++j) {
            if (i > j) dp[i][j] = dp[i - 1][j] % MOD;
            else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i]) % MOD;
        }
    }
    for (LL ta = 0; ta <= t; ++ta) {
        LL i = s - ta * a + (t - ta) * b;
        if (i % n == 0)
            (ans += dp[n - 1][ta]) %= MOD;
    }
    cout << ans << endl;
}

void solve2() {
    int t = n * (n - 1) / 2;
    LL x;
    LL x1 = (s - a * t) / n;
    LL x2 = (s + b * t) / n;
//    枚举首项
    for (x = x1; x <= x2; x++) {
//        对x进行初步检测，有的x，无论怎么搭配a，b的数目，都不能得出s
        for (int ta = 0; ta <= t; ++ta) {//枚举a的数目[0,t]
            LL cal = x * n + ta * a - (t - ta) * b;
            if (cal == s) {//减少对x的枚举
                vector<int> path;
                path.push_back(x);
                dfs(x, 1, x, path);
            }
        }

    }
    printf("%lli\n", ans);
}

void solve1() {
    int t = n * (n - 1) / 2;//最终式子中a或b的最大的个数（系数）
    LL x;
//    枚举首项
    LL x1 = (s - a * t) / n;
    LL x2 = (s + b * t) / n + 1;
    for (x = x1; x <= x2; x++) {
        vector<int> path;
        path.push_back(x);
        dfs(x, 1, x, path);
    }
    printf("%lli\n", ans);
}