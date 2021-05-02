#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int num[3];
    
    scanf("%d%d%d",&num[0],&num[1],&num[2]);
    sort(num,num+3);
    for(int i=0;i<3;i++){
        printf("%d ",num[i]);
    }
}
