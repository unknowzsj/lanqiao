#include<iostream> 
#include<algorithm>

using namespace std;

//二分查找库函数 
int main(){
	int a[6]={2,5,3,9,1,4};
	
	//二分排序 
	sort(a,a+6);
	for(int i=0;i<6;i++){		
		printf("%d",a[i]);
	}
	
	//二分查找  binary_search(a + begin, a + end, k, cmp);
	// 返回true和false 
	int res;
	res=binary_search(a,a+6,9);
	printf("\n%d\n",res); 
	
	//二分查找第一个大于等于K的数的位置
	//lower_bound(a + begin, a + end, k, cmp);
 	int sta;
 	sta=lower_bound(a,a+6,2)-a+1;//减去初始地址，初始为0，+1 
 	printf("%d\n",sta);
	
	//二分查找第一个大于K的数的位置
	// upper_bound(a + begin, a + end, k, cmp);
	int sta1;
	sta1=upper_bound(a,a+6,4)-a+1;
	printf("%d",sta1);
	 
	return 0;	
}
