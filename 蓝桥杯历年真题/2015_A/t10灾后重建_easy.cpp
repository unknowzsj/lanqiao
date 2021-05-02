//
// Created by zhengwei.
//
/*
灾后重建

Pear市一共有N（<=50000）个居民点，居民点之间有M（<=200000）条双向道路相连。这些居民点两两之间都可以通过双向道路到达。
 这种情况一直持续到最近，一次严重的地震毁坏了全部M条道路。
震后，Pear打算修复其中一些道路，修理第i条道路需要Pi的时间。不过，Pear并不打算让全部的点连通，而是选择一些标号特殊的点让他们连通。
Pear有Q（<=50000）次询问，每次询问，他会选择所有编号在[tl,tr]之间，并且 编号 mod K  = C 的点，修理一些路使得它们连通。
 由于所有道路的修理可以同时开工，所以完成修理的时间取决于花费时间最长的一条路，即涉及到的道路中Pi的最大值。

你能帮助Pear计算出每次询问时需要花费的最少时间么？这里询问是独立的，也就是上一个询问里的修理计划并没有付诸行动。

【输入格式】
第一行三个正整数N、M、Q，含义如题面所述。
接下来M行，每行三个正整数Xi、Yi、Pi，表示一条连接Xi和Yi的双向道路，修复需要Pi的时间。可能有自环，可能有重边。1<=Pi<=1000000。

接下来Q行，每行四个正整数Li、Ri、Ki、Ci，表示这次询问的点是[Li,Ri]区间中所有编号Mod Ki=Ci的点。保证参与询问的点至少有两个。

【输出格式】
输出Q行，每行一个正整数表示对应询问的答案。

【样例输入】
7 10 4
1 3 10
2 6 9
4 1 5
3 7 4
3 6 9
1 5 8
2 7 4
3 2 10
1 7 6
7 6 9
1 7 1 0
1 7 3 1
2 5 1 0
3 7 2 1

【样例输出】
9
6
8
8

【数据范围】
对于20%的数据，N,M,Q<=30
对于40%的数据，N,M,Q<=2000
对于100%的数据，N<=50000,M<=2*10^5,Q<=50000. Pi<=10^6. Li,Ri,Ki均在[1,N]范围内，Ci在[0,对应询问的Ki)范围内。




资源约定：
峰值内存消耗 < 256M
CPU消耗  < 5000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/
#include <iostream>
#include <set>

using namespace std;
int N, M, Q;
const int MaxM = 2e5;//修正4：不能用10^5
const int MaxN = 50001;

/*边的抽象*/
struct Edge {
    int from, to, cost;//起点，终点，代价
    Edge(int from, int to, int cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};

bool cmp(Edge *e1, Edge *e2) {
    return e1->cost < e2->cost;
}

Edge *edges[MaxM];


/*并查集*/
struct UFNode {
    UFNode *parent;

    UFNode() : parent(NULL) {}
};

UFNode *find(UFNode *p) {
    if (p->parent == NULL)return p;
    set<UFNode *> path;
    while (p->parent != NULL) {
        path.insert(p);
        p = p->parent;
    }
//路径压缩，让每个节点都能直接到达集团老大
    set<UFNode *>::iterator iter = path.begin();
    while (iter != path.end()) {
        (*iter)->parent = p;
        iter++;//修正1.指针后移
    }
    return p;
}

void merge(UFNode *p1, UFNode *p2) {
    find(p2)->parent = find(p1);
}

UFNode ufnodes[MaxN];//并查集的节点，一开始各自独立

void easy(int l, int r, int mod, int c) {
    for (int j = 0; j <=N ; ++j) {
        ufnodes[j].parent=NULL;//修正2：重新初始化
    }
    //    逐步加入边到最小生成树中
    for (int i = 0; i < M; ++i) {
        Edge *pEdge = edges[i];
        int from = pEdge->from;
        int to = pEdge->to;
        int cost = pEdge->cost;

        if (find(&ufnodes[from]) == find(&ufnodes[to]))//这两个点已经在一棵树上，这条边不能采纳
            continue;
        else
            merge(&ufnodes[from], &ufnodes[to]);

//      如果这里求最小生成树，if cnt==N-1 最小树已经生成
        UFNode *parent = NULL;
        bool isOk=true;
        for (int i = l; i <= r; ++i) {
            if (i % mod == c)//i是关注点的编号
            {
                if (parent == NULL)
                    parent = find(&ufnodes[i]);//第一个关注点的老大
                else
                if(parent!=find(&ufnodes[i]))//没有联通
                {
                    isOk=false;
                    break;
                }
            }
        }
        if(isOk)//关注点都联通了
        {
            printf("%d\n",cost);
            break;
        }
    }
}

int main(int argc, const char *argv[]) {
//    freopen("/Users/zhengwei/CLionProjects/lanqiao2018/2015_c_a/in/in5.txt", "r", stdin);
    scanf("%d %d %d", &N, &M, &Q);
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        Edge *e = new Edge(a, b, c);
        edges[i] = e;
    }
//    排序
    sort(edges, edges + M, cmp);//修正3.排序边界
    for (int i = 0; i < Q; ++i) {
        int l, r, mod, c;
        scanf("%d %d %d %d", &l, &r, &mod, &c);
        easy(l, r, mod, c);
    }

    return 0;
}
