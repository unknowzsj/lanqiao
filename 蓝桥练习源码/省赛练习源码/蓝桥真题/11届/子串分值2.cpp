#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
//二分法不适合该题，应该用 
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
		vector<char> strs; 
		for(int j=n-1;j>=0;--j){
			if(((i>>j)&1)==1){
				strs.push_back(str[j]);
			}
		}
		//利用vector进行排序 
		sort(strs.begin(),strs.end());
		string s="";
		for(int y=0;y<strs.size();++y){
			s=s+strs[y];
		}
		//判断是否已经出现过该子集 
		if(!statue[s]){
			//判断单独的个数,计数更加准确 
			statue[s]=true;
			for(int k=0;k<s.size();++k){
				int c=0;
				for(int l=0;l<s.size();++l){
					if(s[k]==s[l]){
						c++; 
					}
				}
				if(c==1) cts++; 
			}
		} 
	}
	cout<<cts<<endl;
	
	return 0; 
} 
