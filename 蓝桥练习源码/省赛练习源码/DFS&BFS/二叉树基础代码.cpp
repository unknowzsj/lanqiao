#include<bits/stdc++.h>
using namespace std;

//结点定义
struct node{
	int value;
	node* left;
	node* right;
};
//插入数值
node *insert(node *p,int x){
	//p是指针，为空时为NULL,新节点的初始化 
	if(p==NULL){
		//新创一个结点 
		node *q=new node;
		q->value=x;
		q->left=NULL;
		q->right=NULL;
		//返回根节点指针 
		return q; 
	}else{
		//建一个新节点，连接到根节点不断递归下去 
		if(x<p->value) p->left=insert(p->left,x);
		else p->right=insert(p->right,x);
		//返回根节点 
		return p; 
	}
} 
//查找数值x
bool find(node *p,int x){
	if(p==NULL) return false;
	else if(x==p->value) return true;
	else if(x<p->value) return find(p->left,x);
	else return find(p->right,x);
} 
//删除数值 
node *remove(node *p,int x){
	//无根返回NULL 
	if(p==NULL) return NULL;
	//值小于根的左子树，以左儿子为根节点进行递归 
	else if(x<p->value) p->left=remove(p->left,x);
	//值大于根的右子树，以右儿子为根节点进行递归 
	else if(x>p->value) p->right=remove(p->right,x);
	//经过上面的判定，下面的都是要删除结点的操作
	//删除结点没有左儿子，将右儿子提上去
	//下面都是返回删除位置的更新值，再慢慢递归到根节点 
	else if(p->left==NULL){
		node *q=p->right;
		delete p;//删除p点 
		return q; //提上右子节点 
	}
	//左儿子没有右儿子 
	else if(p->left->right==NULL){
		node *q=p->left;
		//将右儿子加到左儿子的右儿子的位置 
		q->right=p->right;
		delete p;
		return q;//提上左儿子 
		 
	}
	else{
		node *q;
		//寻找最右的儿子，最右儿子的右儿子为空时退出
		//这时已经更新为右子树最大值的父节点 
		for(q=p->left;q->right->right!=NULL;q=q->right);
		node *r=q->right;//r为最大值
		//最大值的父节点的右儿子更新为最大值的左儿子（可以为空） 
		q->right=r->left;
		//将最大值更新到删除的位置 
		r->left=p->left;
		r->right=p->right;
		delete p;
		return r;
	} 
} 
int main(){
	node *root=NULL;
	root=insert(root,1);
	insert(root,3);
	insert(root,5);
	int n=find(root,3);
	int m=find(root,10);
	cout<<n<<" "<<m<<endl; 
} 
