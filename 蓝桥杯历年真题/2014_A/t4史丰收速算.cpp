//
// Created by zhengwei.
//

/*
标题：史丰收速算

    史丰收速算法的革命性贡献是：从高位算起，预测进位。不需要九九表，彻底颠覆了传统手算!

    速算的核心基础是：1位数乘以多位数的乘法。

    其中，乘以7是最复杂的，就以它为例。

    因为，1/7 是个循环小数：0.142857...，如果多位数超过 142857...，就要进1

    同理，2/7, 3/7, ... 6/7 也都是类似的循环小数，多位数超过 n/7，就要进n

    下面的程序模拟了史丰收速算法中乘以7的运算过程。

    乘以 7 的个位规律是：偶数乘以2，奇数乘以2再加5，都只取个位。

    乘以 7 的进位规律是：
	满 142857... 进1,
	满 285714... 进2,
	满 428571... 进3,
	满 571428... 进4,
	满 714285... 进5,
	满 857142... 进6

    请分析程序流程，填写划线部分缺少的代码。


//计算个位
int ge_wei(int a)
{
	if(a % 2 == 0)
		return (a * 2) % 10;
	else
		return (a * 2 + 5) % 10;
}

//计算进位
int jin_wei(char* mod)
{
	char* level[] = {
		"142857",
		"285714",
		"428571",
		"571428",
		"714285",
		"857142"
	};

	char buf[7];
	buf[6] = '\0';
	strncpy(buf,mod,6);

	int i;
	for(i=5; i>=0; i--){
		int tr = strcmp(level[i], buf);
		if(tr<0) return i+1;
		while(tr==0){
			mod += 6;
			strncpy(buf,mod,6);
			tr = strcmp(level[i], buf);
			if(tr<0) return i+1;
			______________________________;  //填空
		}
	}

	return 0;
}

//多位数乘以7
void f(char* s)
{
	int head = jin_wei(s);
	if(head > 0) printf("%d", head);

	char* mod = s;
	while(*mod){
		int a = (*mod-'0');
		int x = (ge_wei(a) + jin_wei(mod+1)) % 10;
		printf("%d",x);
		mod++;
	}

	printf("\n");
}

int main()
{
	f("428571428571");
	dfs("34553834937543");
	return 0;
}


注意：通过浏览器提交答案。只填写缺少的内容，不要填写任何多余的内容（例如：说明性文字）

*/
#include <iostream>
using namespace std;
//计算个位
int ge_wei(int a)
{
    if(a % 2 == 0)//偶数
        return (a * 2) % 10;//乘以2保留个位
    else
        return (a * 2 + 5) % 10;//奇数，乘以2加上5，保留个位
}

//计算进位
int jin_wei(char* mod)
{
    char* level[] = {
            "142857",
            "285714",
            "428571",
            "571428",
            "714285",
            "857142"
    };//多位数超过 n/7，就要进n

    char buf[7];
    buf[6] = '\0';
    strncpy(buf,mod,6);//将mod这个字符串的前6个字符，拷贝到buff中

    int i;
    for(i=5; i>=0; i--){
        int tr = strcmp(level[i], buf);//从后往前，依次level中的串和buff比较
        if(tr<0)//buff更大 ，得出了进位数=i+1
            return i+1;
        while(tr==0){//buff和level[i]相同了
            mod += 6;//往后偏移6位
            strncpy(buf,mod,6);//再拷贝6个字符到buff中
            tr = strcmp(level[i], buf);//再比较
            if(tr<0) return i+1;//buf更大
//            ______________________________;  //填空
//            //?//buff更小
            if(tr>0)  return i;

        }
    }

    return 0;
}

//多位数乘以7
void f(char* s)//s代表多位数
{
    int head = jin_wei(s);//head是s的进位
    if(head > 0) printf("%d", head);//输出进位

    char* mod = s;//拷贝字符串指针
    while(*mod){//没有到末尾
        int a = (*mod-'0');//依次字符转数字
        int ge = ge_wei(a);//算出个位
        int jin = jin_wei(mod + 1);//后续字符串的进位
        int x = (ge + jin) % 10;//两者相加取个位
        printf("%d",x);//打印
        mod++;//指针后移
    }

    printf("\n");
}

int main()
{
    f("4285711");
    f("34553834937543");
    return 0;
}
