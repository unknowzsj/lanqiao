#include<iostream>
#include<map>
using namespace std;
map<int,bool> res;
int N;
//超时，应该时map的while搜寻产生的 
int main(){
	cin>>N;
	int val[N];
	for(int i=0;i<N;++i){
		cin>>val[i];
	}
	//初始化 
	res[val[0]]=true;
	for(int i=1;i<N;++i){
		//当已经存在，则+1 
		while(res[val[i]]){
			val[i]++;
		}
		//不重复时置true 
		res[val[i]]=true;
	}
	
	for(int i=0;i<N;++i){
		cout<<val[i]<<" ";
	}
} 
