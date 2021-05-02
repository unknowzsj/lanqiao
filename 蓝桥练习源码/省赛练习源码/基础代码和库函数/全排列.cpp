#include<algorithm>
#include<iostream>

using namespace std;

//全排列，需要有序，字符也可以 
int main(){
	int a[4]={3,2,4,5};
	char str[4]="abc";
	sort(a,a+4);
	do{
		for(int i=0;i<4;i++){
			printf("%d",a[i]);
		}
		printf("\n"); 
	}while(next_permutation(a,a+4));
	
	//字符
	sort(str,str+3); 
	do{
		for(int i=0;i<3;i++){
			printf("%s",str[i]);
		}
		printf("\n");
	}while(next_permutation(str,str+3));
	
	return 0;
} 
