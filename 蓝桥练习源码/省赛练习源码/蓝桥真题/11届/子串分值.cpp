#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
//二分法不适合该题，--错误-- 
string str;
int n;
int cts=0;
//判定是否存在 
map<string,bool> statue;

int main(){
	cin>>str;
	n=str.size();
	long long s=(1<<n)-1;
	string res[s];
	for(int i=(1<<n)-1;i>0;--i){
		string strs;
		int o=0; 
		for(int j=n-1;j>=0;--j){
			if(((i>>j)&1)==1){
				strs=strs+str[j];
			}
		}
		//判断是否已经出现过该子集 
		if(!statue[strs]){
			//判断单独的个数 
			cout<<strs<<endl;
			statue[strs]=true;
			for(int k=0;k<strs.size();++k){
				bool c=false;
				for(int l=0;l<strs.size()&&l!=k;++l){
					if(strs[k]==strs[l]) c=true;
				}
				if(!c) cts++; 
			}
		} 
	}
	cout<<cts<<endl;
	
	return 0; 
} 
