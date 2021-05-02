//
// Created by zhengwei.
//

/*
寒假作业

现在小学的数学题目也不是那么好玩的。
看看这个寒假作业：

   □ + □ = □
   □ - □ = □
   □ × □ = □
   □ ÷ □ = □

   (如果显示不出来，可以参见【图7-1.jpg】)

每个方块代表1~13中的某一个数字，但不能重复。
比如：
 6  + 7 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

以及：
 7  + 6 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

就算两种解法。（加法，乘法交换律后算不同的方案）

你一共找到了多少种方案？


请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

*/

#include <cstdio>
using namespace std;
int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
int ans;
bool check(){
    if(a[0]+a[1]==a[2]&&
       a[3]-a[4]==a[5]&&
       a[6]*a[7]==a[8]&&
       a[9]%a[10]==0&&
       a[9]/a[10]==a[11])
        return true;
    return false;
}
void f(int k){
    if(k==13){
        if(check()){
            printf("%d+%d=%d  %d-%d=%d  %d*%d=%d  %d/%d=%d\n",
                   a[0],a[1],a[2],
                   a[3],a[4],a[5],
                   a[6],a[7],a[8],
                   a[9],a[10],a[11]);
            ans++;
        }
    }
    for (int i = k; i < 13; ++i) {
        {int t=a[i];a[i]=a[k];a[k]=t;}
//        提前排除，提升效率
        if((k==2&&a[0]+a[1]!=a[2]) || k==5&&a[3]-a[4]!=a[5]){
            {int t=a[i];a[i]=a[k];a[k]=t;}
            continue;
        }
        f(k+1);
        {int t=a[i];a[i]=a[k];a[k]=t;}
    }
}
int main(int argc, const char * argv[]) {
    f(0);
    printf("%d\n",ans);
    return 0;
}