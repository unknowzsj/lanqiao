#include<bits/stdc++.h>
using namespace std;

int main(){
	set<int> s;
	s.insert(1);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.erase(3); 
	//按顺序排序，且没有重复的数 
	for(set<int>::iterator i=s.begin();i!=s.end();++i){
		cout<<*i<<endl;
	}
	//find()返回指针 
	int m=*(s.find(2));
	cout<<m<<endl;
} 
