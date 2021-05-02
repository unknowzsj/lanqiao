#include<iostream>
#include<queue>
using namespace std;
//时间限制未通过，感觉是平台问题 
int N;
int sum[100];
//求层数 
int layer(int n){
	int l;
	for(int i=1;i<100;++i){
		l=(1<<i); 
		if((l-1)==n) return i;
	}
} 

int main(){
	cin>>N;
	int lys=layer(N);
	int a[N+1];
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	//计算每一层的和 
	for(int i=1;i<=lys;++i){
		int num=(1<<(i-1));
		for(int j=num;j<2*num;++j){
			sum[i]+=a[j];
		}			
	}
	int max=0;
	int s=0;
	//找到最大值 
	for(int i=1;i<=lys;++i){
		if(sum[i]>max){
			max=sum[i];
		}
	}
	//找到最大值的最小坐标 
	for(int i=1;i<=lys;++i){
		if(sum[i]==max){
			s=i;
			break;
		}
	}
	cout<<s<<endl;
	
	return 0;
}
