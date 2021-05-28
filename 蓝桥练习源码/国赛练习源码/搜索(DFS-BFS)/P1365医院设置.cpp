#include<bits/stdc++.h>
using namespace std;
int n;
struct Node{
	int peo;
	int lft,rgt;
}node[110];

int main(){
	cin>>n;
	for(int i=0;i<n;++i){//Ê÷µÄ¹¹Ôì 
		int a,b;
		cin>>node[i].peo;
		cin>>a>>b;
		if(a>0) node[i].lft=a;
		if(b>0) node[i].rgt=b;
	}
	
	
} 
