#include<bits/stdc++.h>
using namespace std;

int main(){
	int age[100][100];
	int num,j=0;
	int k=-1;
	
	scanf("%d",&num);
	while(num!=0){
		for(int i=0;i<num;i++){
			scanf("%d",&age[j][i]);
		}
		sort(age[j],age[j]+num);
		j++;
		scanf("%d",&num);
	}
	
	while(j){
		for(int i=0;i<100;i++){
			if(age[j-1][i]<1) break;
			printf("%d ",age[j-1][i]);
		}
		printf("\n");
		j--;
	}
}
