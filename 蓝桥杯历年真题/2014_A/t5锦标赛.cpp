//
// Created by zhengwei.
//
/*
标题：锦标赛

   如果要在n个数据中挑选出第一大和第二大的数据（要求输出数据所在位置和值），使用什么方法比较的次数最少？
   我们可以从体育锦标赛中受到启发。

   如图【1.png】所示，8个选手的锦标赛，先两两捉对比拼，淘汰一半。优胜者再两两比拼...直到决出第一名。

   第一名输出后，只要对黄色标示的位置重新比赛即可。

   下面的代码实现了这个算法（假设数据中没有相同值）。

   代码中需要用一个数组来表示图中的树（注意，这是个满二叉树，不足需要补齐）。
   它不是存储数据本身，而是存储了数据的下标。

   第一个数据输出后，它所在的位置被标识为-1

//重新决出k号位置，v为已输出值
void pk(int* a, int* b, int n, int k, int v)
{
	int k1 = k*2 + 1;
	int k2 = k1 + 1;

	if(k1>=n || k2>=n){
		b[k] = -1;
		return;
	}

	if(b[k1]==v)
		pk(a,b,n,k1,v);
	else
		pk(a,b,n,k2,v);

	//重新比较
	if(b[k1]<0){
		if(b[k2]>=0)
			b[k] = b[k2];
		else
			b[k] = -1;
		return;
	}

	if(b[k2]<0){
		if(b[k1]>=0)
			b[k] = b[k1];
		else
			b[k] = -1;
		return;
	}

	if(______________________) //填空
		b[k] = b[k1];
	else
		b[k] = b[k2];
}

//对a中数据，输出最大，次大元素位置和值
void f(int* a, int len)
{
	int n = 1;
	while(n<len) n *= 2;

	int* b = (int*)malloc(sizeof(int*) * (2*n-1));
	int i;
	for(i=0; i<n; i++){
		if(i<len)
			b[n-1+i] = i;
		else
			b[n-1+i] = -1;
	}

	//从最后一个向前处理
	for(i=2*n-1-1; i>0; i-=2){
		if(b[i]<0){
			if(b[i-1]>=0)
				b[(i-1)/2] = b[i-1];
			else
				b[(i-1)/2] = -1;
		}
		else{
			if(a[b[i]]>a[b[i-1]])
				b[(i-1)/2] = b[i];
			else
				b[(i-1)/2] = b[i-1];
		}
	}

	//输出树根
	printf("%d : %d\n", b[0], a[b[0]]);

	//值等于根元素的需要重新pk
	pk(a,b,2*n-1,0,b[0]);

	//再次输出树根
	printf("%d : %d\n", b[0], a[b[0]]);

	free(b);
}


int main()
{
	int a[] = {54,55,18,16,122,17,30,9,58};
	dfs(a,9);
}

    请仔细分析流程，填写缺失的代码。

    通过浏览器提交答案，只填写缺失的代码，不要填写已有代码或其它说明语句等。



*/
#include <iostream>
using namespace std;

//重新决出k号位置，v为已输出值
//a原始数据，b是树，n=31，k=0是下标，v是第一大的值的下标
void pk(int* a, int* b, int n, int k, int v)
{
    int k1 = k*2 + 1;//k的左子下标
    int k2 = k1 + 1;//右子下标

    if(k1>=n || k2>=n){//超出树的边界，k一定是叶子，b[k]-1
        b[k] = -1;
        return;
    }

    //沿着冠军的路，一直追溯到第一次比赛
    if(b[k1]==v)
        pk(a,b,n,k1,v);
    else
        pk(a,b,n,k2,v);

//到此，k就是冠军一开始的下标,此时b[k]=-1
    //重新比较
    if(b[k1]<0){//
        if(b[k2]>=0)
            b[k] = b[k2];//左子<0，右子>0,选右子
        else
            b[k] = -1;//都小于0 标记为-1
        return;
    }

    if(b[k2]<0){
        if(b[k1]>=0)
            b[k] = b[k1];
        else
            b[k] = -1;
        return;
    }

    if(a[b[k1]]>a[b[k2]]) //填空
        b[k] = b[k1];
    else
        b[k] = b[k2];
}

//对a中数据，输出最大，次大元素位置和值
void f(int* a, int len)
{
    int n = 1;
    while(n<len) n *= 2;
//    n=16 2n-1=31
//开辟树的空间 ll=31 树数组的长度
    int* b = (int*)malloc(sizeof(int*) * (2*n-1));
    int i;
//    初始化树的最下层
    for(i=0; i<n; i++){
        if(i<len)
            b[n-1+i] = i;
        else
            b[n-1+i] = -1;
    }

    //从最后一个向前处理 2*n-1-1是b数组的最大小标
    for(i=2*n-1-1; i>0; i-=2){
        if(b[i]<0){//i一开始一定指向右孩子，每次-2还是右孩子
            if(b[i-1]>=0)//兄弟大于0，父节点的值就是兄弟节点的值，父节点b[(i-1)/2]
                b[(i-1)/2] = b[i-1];
            else //两个孩子都是-1
                b[(i-1)/2] = -1;
        }
        else{//自身不是-1，左兄弟也一定不是-1
            if(a[b[i]]>a[b[i-1]])//pk，谁代表的原始数据更大，谁上
                b[(i-1)/2] = b[i];
            else
                b[(i-1)/2] = b[i-1];
        }
    }
//    第一轮pk结束

    //输出树根
    printf("%d : %d\n", b[0], a[b[0]]);

    //值等于根元素的需要重新pk 2*n-1=31
    pk(a,b,2*n-1,0,b[0]);

    //再次输出树根
    printf("%d : %d\n", b[0], a[b[0]]);

    free(b);
}


int main()
{
    int a[] = {154,55,18,16,122,17,130,9,58};//原始数据
    f(a,9);
}
