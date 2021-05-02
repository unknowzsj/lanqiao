#include<cstdio>
#include<cstring>
using namespace std;
//已完成，未通过测试点 
const int MAX=100;

int main(){
	//A-65
	char bfsec[MAX];
	char afsec[MAX];
	int cmp1[MAX];
	int cmp2[MAX];
	int len;
	bool flag=true;
	 
	for(int i=0;i<MAX;i++){
		cmp1[i]=-1;
		cmp2[i]=-1;
	}

	scanf("%s",afsec);
	scanf("%s",bfsec);
	len=strlen(afsec);
	//每个位置都+1了，导致错误 
	for(int i=0;i<len;i++){
		cmp1[bfsec[i]-'A'+1]++;
		cmp2[afsec[i]-'A']++;
	}

	for(int i=0;i<len;i++){
		if(cmp1[i]!=cmp2[i]) flag=false; 
	}
	
	if(flag==true) printf("YES");
	else printf("NO");
} 
