#include<bits/stdc++.h>
using namespace std;

int main(){
	priority_queue<int,vector<int>,greater<int> > que;
	int n,sum=0;
	int min1,min2,min;
	cin>>n;
	int num[n];
	for(int i=0;i<n;++i){
		cin>>num[i];
	}
	for(int i=0;i<n;++i){
		que.push(num[i]);
	}
	
	while(que.size()!=1){
		min1=que.top();
		que.pop();
		min2=que.top();
		que.pop();
		min=min1+min2;
		sum += min;
		que.push(min);
	}
	printf("%d",sum);
	
	return 0;
} 
