#include<bits/stdc++.h>
using namespace std;
int n;
int mp[10010][10010];
int jall,oall;
int l,b,r,t;
int mx,my;

int main(){
	cin>>n;
	//统计所有的覆盖点 
	for(int i=0;i<n;++i){
		cin>>l>>b>>r>>t;
		//更新地图
		for(int x=l;x<r;++x){
			for(int y=b;y<t;++y){
				++mp[x][y];
			}
		}
		//确定遍历范围 
		mx=max(mx,r);
		my=max(my,t); 
	}
	
	for(int i=1;i<=mx;++i){
		for(int j=1;j<=my;++j){
			if(mp[i][j]%2==0&&mp[i][j]!=0) oall++;
			else if(mp[i][j]%2==1) jall++; 
		}
	} 
	cout<<jall<<endl<<oall;
	
	return 0;
}
