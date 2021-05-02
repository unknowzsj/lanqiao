#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1000];

char *rev(char *s) {
    int len = strlen(s);//sizeof(s) / sizeof(char);
    char *ans = (char*)malloc(len* sizeof(char));//(char *) malloc(sizeof(s));
    for (int i = 0; i < len; ++i) {
        ans[i] = s[len - 1 - i];
    }
    return ans;
}

int lcs(const char *s1, const char *s2,int len) {
    int dp[len][len];
    for (int i = 0; i < len; ++i) {
        if(s1[i]==s2[0])dp[0][i]=1;
        else dp[0][i]=(i==0?0:dp[0][i-1]);
    }

    for (int j = 0; j < len; ++j) {
        if(s2[j]==s1[0])dp[j][0]=1;
        else dp[j][0]= (j==0 ? 0:dp[j-1][0]);
    }
    for (int i = 1; i < len; ++i) {
        for (int j = 1; j < len; ++j) {
            if(s2[i]==s1[j])dp[i][j]= dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[len-1][len-1];
}

int main(int argc, const char *argv[]) {
//    cout<<lcs("ABDCDCBABC",rev("ABDCDCBABC"),10)<<endl;
freopen("/Users/zhengwei/CLionProjects/lanqiaobei2019/2016_C_A/data9/in2.txt","r",stdin);
    scanf("%s", &s);
    int len = strlen(s);
    int l = lcs(s, rev(s),len);
    printf("%d",len-l);
    return 0;
}