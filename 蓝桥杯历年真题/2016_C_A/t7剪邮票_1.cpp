//
// Created by zhengwei.
//
/*
剪邮票

如【图1.jpg】, 有12张连在一起的12生肖的邮票。
现在你要从中剪下5张来，要求必须是连着的。
（仅仅连接一个角不算相连）
比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。

请你计算，一共有多少种不同的剪取方法。

请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

//此题和13年剪格子有相似之处，但是那个题的限制条件是格子数值之和为总和的一半，此题则限制只能是5个格子
//单纯的dfs无法解决T字型连通方案
//本题的解决办法是，找出任意5个格子，判断是否连通

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int a[]={0,0,0,0,0,0,0,1,1,1,1,1};//它的每个排列代表着12选5的一个方案
int ans;
void dfs(int g[3][4],int i , int j){
    g[i][j]=0;
    if(i-1>=0&&g[i-1][j]==1)dfs(g,i-1,j);
    if(i+1<=2&&g[i+1][j]==1)dfs(g,i+1,j);
    if(j-1>=0&&g[i][j-1]==1)dfs(g,i,j-1);
    if(j+1<=3&&g[i][j+1]==1)dfs(g,i,j+1);
}
bool check(){
    int g[3][4];
//    将某个排列映射到二维矩阵上
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(a[i*4+j]==1) g[i][j]=1;
            else g[i][j]=0;
        }
    }
    int cnt=0;//连通块的数目
//    g上面就有5个格子被标记为1，现在才用dfs做连通性检查，要求只有一个连通块
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(g[i][j]==1){
                dfs(g,i,j);
                cnt++;
            }
        }
    }
    return cnt==1;
}
set<string> s1;
void a2s(string &s){
    for (int i = 0; i < 12; ++i) {
        s.insert(s.end(),a[i]+'0');
    }
}
bool isExist(){
    string a_str;
    a2s(a_str);
    if(s1.find(a_str)==s1.end()){
        s1.insert(a_str);
        return false;
    } else
        return true;
}
void f(int k){
    if(k==12){
        if(!isExist()&&check()){
            ans++;
        }
    }
    for (int i = k; i < 12; ++i) {
        {int t=a[i];a[i]=a[k];a[k]=t;}
        f(k+1);
        {int t=a[i];a[i]=a[k];a[k]=t;}
    }
}
int main(int argc, const char *argv[]) {
    f(0);
    printf("%d",ans);
//string _s;
//a2s(_s);
//cout<<_s<<endl;
    return 0;
}
