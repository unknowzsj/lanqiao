#include<bits/stdc++.h>
using namespace std;
//to_string”√≤ª¡À 
int main(){
	int count=0;
	for(int i=1;i<=2020;++i){
		string str=to_string(i);
		for(int j=0;j<str.size();++j){
			if(str[j]=='2') count++;
		} 
	}
	cout<<count<<endl;
} 
