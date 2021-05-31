#include<bits/stdc++.h>;
using namespace std;
int n;
int node[510][2];
int mx;
int res[3];
//计算面积 
int S(int a,int b,int c){
	return node[a][0]*node[b][1]-node[a][0]*node[c][1]+node[b][0]*node[c][1]-node[b][0]*node[a][1]+node[c][0]*node[b][1]-node[c][0]*node[a][1]; 
}
int main(){
	cin>>n;
	for(int i=0;i<n;++i) cin>>node[i][0]>>node[i][1];
	//三重遍历 
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			for(int l=0;l<n;++l){
				if(i==j||i==l||j==l) continue;//不能重复点
				if(S(i,j,l)>mx){
					mx=S(i,j,l);
					res[0]=i;
					res[1]=j;
					res[2]=l;
				}
			}
		}
	}
	//输出 
	for(int i=0;i<3;++i){
		cout<<res[i]<<" ";
	}
	
	return 0;
}
