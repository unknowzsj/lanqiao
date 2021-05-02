#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
//cin和printf可以混用 
int n;
int main(){
	scanf("%d",&n);
	int grades[n];
	//如果使用int将会出错 
	double sum=0;
	for(int i=0;i<n;++i){
		cin>>grades[i];
		sum+=grades[i];
	}
	sort(grades,grades+n);
	//最高分 
	printf("%d\n",grades[n-1]);
	//最高分 
	printf("%d\n",grades[0]);
	//平均分
	double avg=sum/n;
	//这里小数部分会四舍五入 
	printf("%.2f\n",avg);
	//4位有效数字
	cout<<setprecision(4)<<avg<<endl; 
	//cout--2两位小数 
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<avg<<endl;
	
	
	 
}
