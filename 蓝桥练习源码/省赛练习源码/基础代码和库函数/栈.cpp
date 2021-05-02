#include<iostream>
#include<stack>

using namespace std;

//先进后出 
int main(){
	
	stack<int> s;
	s.push(1);//压栈 
	s.push(2);
	s.push(3);
	s.push(4);
	printf("%d\n",s.top());
	s.pop();//弹栈 
	printf("%d",s.top());
	
} 
