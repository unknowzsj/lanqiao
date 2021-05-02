#include<bits/stdc++.h>
using namespace std;
//超内存限制--减少重复的情况 
//输入的串
string start,fnd;
//队列中需要特殊的结构最好用结构体 
struct node{
	string s1;
}; 
//可以到达的位置 
int cha[6]={-3,-2,-1,1,2,3};
//中间状态转换 
queue<node> loc;
map<string,bool> statue; 
 
void jump(string start,int x){
	int q;
	//数组长度 
	int l=x;
	//找到杯子下标 
	for(int i=0;i<l;++i){
		if(start[i]=='*') q=i;
	}
	//进行跳跃 
	for(int i=0;i<6;i++){
		int ju=q+cha[i];
		if(ju<0 || ju>=l) continue;
		//选用新结点 
		node news;
		news.s1=start;
		news.s1[q]=news.s1[ju];
		news.s1[ju]='*';
		//防止重复计算和输入 
		if(!statue[news.s1]){
			statue[news.s1]=true;
			loc.push(news);
		}
	} 
}
/*直接利用字符串相等判断 
//判断是否达到目标效果 
bool check(char *start,char *end,int n){
	int k=0;
	for(int i=0;i<n;++i) if(start[i]==end[i]) k++;
	return (k==n ? true:false);
}
*/ 
int main(){
	//输入整理 
	cin>>start;
	cin>>fnd;
	int n=start.size();
	/*没必要 
	//初始和结束状态 
	char start[n],end[n];
	for(int i=0;i<n;++i){
		start[i]=sta[i];
		end[i]=ed[i];
	}
	*/
	//初始化 
	node sa;
	sa.s1=start;
	loc.push(sa);
	 
	int num=0;
	int t=loc.size();
	while(!loc.empty()){
		node st=loc.front();
		loc.pop();
		//如果成功，则跳出 
		if(st.s1==fnd){
			cout<<num<<endl;
			break;
		}
		jump(st.s1,n);
		t--;
		if(t==0){
			t=loc.size();
			num++; 
		}
		
	}
}
