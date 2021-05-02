#include<cstdio>
#include<queue>

using namespace std;

//先进先出 
int main(){
	queue<int> q;
	q.push(1);//入队列 
	q.push(2);
	q.push(3);
	q.push(4);
	printf("%d\n",q.front());
	q.pop();//出队列 
	printf("%d",q.front());
} 
