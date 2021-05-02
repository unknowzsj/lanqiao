#include<iostream>
#include<queue>
using namespace std;
//超时 
int N;
int sum[1000];
queue<int> res;
//完全二叉树，计算层数
int layer(int n){
	int l=1;
	for(int i=1;i<1000;++i){
		l=l*2;
		if((l-1)==n) return i;
	}
} 
void bfs(int cur,int ly,int a[]){
	//退出 
	if(cur==ly) return; 
	//第cur层的个数，坐标起点都是num 
	int num=(1<<(cur-1));
	//把每层的数存入队列 
	for(int i=num;i<num+num;++i){
		res.push(a[i]); 
	}
}
int main(){
	cin>>N;
	int lys=layer(N);
	int a[N+1];
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	//初始化
	sum[1]=a[1]; 
	res.push(a[1]);
	//第二层开始 
	int cur=1;
	int t=res.size(); 
	while(!res.empty()){
		int b=res.front();
		sum[cur]+=b;
		res.pop();
		t--;
		//计算下一层 
		if(t==0){
			cur++; 
			bfs(cur,lys,a);
			t=res.size();
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
