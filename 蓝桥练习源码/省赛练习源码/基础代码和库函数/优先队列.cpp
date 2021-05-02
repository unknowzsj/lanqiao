#include<cstdio>
#include<queue>
using namespace std;

int main(){
	priority_queue<int> big_heap;
	priority_queue< int,vector<int>,greater<int> > small_heap;
	
	big_heap.push(1);
	big_heap.push(2);
	big_heap.push(3);
	big_heap.push(4);
	
	small_heap.push(1);
	small_heap.push(2);
	small_heap.push(3);
	small_heap.push(4);
	
	printf("%d\n",big_heap.top());
	printf("%d\n",small_heap.top()); 
} 
