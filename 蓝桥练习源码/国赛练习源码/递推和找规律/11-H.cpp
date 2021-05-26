#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int all[1010];
int stu[1010][3];
int n;
ll res;

int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>stu[i][0]>>stu[i][1]>>stu[i][2];
		all[i]=stu[i][0]+stu[i][1]+stu[i][2];
	}
	sort(all,all+n);
	 
	for(int i=0;i<n-1;++i){//只有n-1项 
		res+=(n-i-1)*all[i];
	}
	for(int i=0;i<n;++i){//有n项 
		res+=stu[i][0]+stu[i][1];
	} 
	cout<<res;
	
	return 0;
}

