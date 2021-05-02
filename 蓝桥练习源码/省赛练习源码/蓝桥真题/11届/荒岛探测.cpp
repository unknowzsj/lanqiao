#include<iostream>
#include<cstdlib>
#include<ctime> 
#include<algorithm>
#include<cmath>
using namespace std;

int xa,ya,xb,yb,L;
//int x1,y1,x2,y2,x3,y3; 
double Random(int start,int end){
	int dis=end-start;//区间大小 
	//rand()/(RAND_MAX+1.0)是产生0-1的随机浮点数
	//区间乘以随机数加上开端便可以在区间内取随机浮点数
	//随机整数rand() % dis + start 
	return start+dis*(rand()/double(RAND_MAX));
}
double solve(int x1,int y1,int x2,int y2,int x3,int y3){
	int ax=x2-x1;
	int ay=y2-y1;
	int bx=x3-x1;
	int by=y3-y1;
	
	return ((ax*by-bx*ay)/2.0)>0? (ax*by-bx*ay)/2.0:-((ax*by-bx*ay)/2.0);
}
int main(){
	int x1,y1,x2,y2,x3,y3;
	int b=300000; 
	//记录在其中的点 
	double cts1=0;
	double cts2=0; 
	//输入
	cin>>xa>>ya>>xb>>yb>>L;
	cin>>x1>>y1>>x2>>y2>>x3>>y3; 
	double x[b];
	double y[b];
	//找到生成区间 
	int minx=min(x1,min(x2,x3));
	int miny=min(y1,min(y2,y3));
	int maxx=max(x1,max(x2,x3));
	int maxy=max(y1,max(y2,y3));
	//生成100000个是随机点 
	srand((int)time(0));
	for(int i=0;i<b;++i){
		x[i]=Random(minx,maxx);
		y[i]=Random(miny,maxy);
	}
	double sum=solve(x1,y1,x2,y2,x3,y3);
	//判断点是否在三角形内 
	for(int i=0;i<b;++i){
		double k=0;
		k=k+solve(x1,y1,x2,y2,x[i],y[i]);
		k=k+solve(x1,y1,x3,y3,x[i],y[i]);
		k=k+solve(x3,y3,x2,y2,x[i],y[i]); 
		//在三角形中 
		if(k==sum){
			cts1++;
			if(sqrt((x[i]-xa)*(x[i]-xa)+(y[i]-ya)*(y[i]-ya))+sqrt((x[i]-xb)*(x[i]-xb)+(y[i]-yb)*(y[i]-yb))<= L){
				cts2++;
			} 
		}
	}
	double S=(cts2/cts1)*sum;
	printf("%.2f",S);
	
	return 0; 
} 
