#include<iostream>
#include<string> 
#include<algorithm>
using namespace std;

string N;
int m=0;
//月份和天 
string mon[]={"#","01","02","03","04","05","06",
			"07","08","09","10","11","12"};
string day[]={"#","01","02","03","04","05","06","07","08","09",
			"10","11","12","13","14","15","16","17","18","19",
			"20","21","22","23","24","25","26","27","28","29",
			"30","31"};
//baba形式的回文只有下面的 
string ba[]={"10100101","20200202","21211212","30300303",
			 "40400404","50500505","60600606",
			 "70700707","80800808","90900909"}; 
int main(){
	cin>>N;
	//回文，由范围知不考虑闰年 
	string hw[365]; 
	//记录回文年 
	for(int i=1;i<=12;++i){
		if(i==2){
			for(int j=1;j<29;++j){
				string md=mon[i];
				md=md+day[j];
				string ymd="";
				for(int l=3;l>=0;--l){
					ymd=ymd+md[l];
				}
				ymd=ymd+md;
				hw[m++]=ymd;
			}
		}
		else if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
			for(int j=1;j<32;++j){
				string md=mon[i];
				md=md+day[j];
				string ymd="";
				for(int l=3;l>=0;--l){
					ymd=ymd+md[l];
				}
				ymd=ymd+md;
				hw[m++]=ymd;
			}
		}else{
			for(int j=1;j<31;++j){
				string md=mon[i];
				md=md+day[j];
				string ymd="";
				for(int l=3;l>=0;--l){
					ymd=ymd+md[l];
				}
				ymd=ymd+md;
				hw[m++]=ymd;
			}
		}
	} 
	//寻找最近
	sort(hw,hw+365);
	for(int i=0;i<365;++i){
		if(N<hw[i]){
			cout<<hw[i]<<endl;
			break;
		}
	} 
	//baba回文 
	for(int i=0;i<11;++i){
		if(N<ba[i]){
			cout<<ba[i]<<endl;
			break;
		}
	}
	
}
