#include<bits/stdc++.h>
using namespace std;

int main(){
	//字符可以直接当数组用 
	string word;
	cin>>word;
	int n;
	cin>>n;
	int maxl=0;
	
	/*************错误解答************* 
	  删除最大的字典序的字母--思路出错
	while(n--){
		int maxw='A'-1;
		for(int i=0;i<word.size();++i){
			if(word[i]>maxw){
				maxw=word[i];
				maxl=i;
			} 
		}
		//erase(pos,n)从pos开始删除掉n各数 
		word.erase(maxl,1); 
	}
	***********************************/
	
	//位数越小留的越小
	while(n--){
		if(word[0]>word[1]) word.erase(0,1);
		else word.erase(1,1);
	} 
	cout<<word<<endl;
	/* 删除最小位和下一位的较大值 ，删除了一个则重新比较 
	    while(n--){
        for(int i=0;i<str.size();++i){
            if(str[i]>str[i+1]){
                str.erase(i,1);
                break;
            }
        }
    }
	*/
	
	
	return 0;
}
