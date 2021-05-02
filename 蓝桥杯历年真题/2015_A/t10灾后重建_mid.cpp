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
#include <algorithm>
#include <vector>
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

/*最小树的生成及表示*/
vector<Edge *> mst[MaxN];

void buildMST() {
    int cnt = 0;//已加入边的数量
    for (int i = 0; i < M; ++i) {
        Edge *pEdge = edges[i];
        int from = pEdge->from;
        int to = pEdge->to;
        int cost = pEdge->cost;

        if (find(&ufnodes[from]) == find(&ufnodes[to]))//这两个点已经在一棵树上，这条边不能采纳
            continue;
        else {
            merge(&ufnodes[from], &ufnodes[to]);
            cnt++;
//            将边加入到mst（邻接表）
            mst[from].push_back(pEdge);
            Edge *other = new Edge(to, from, cost);
            mst[to].push_back(other);
            if (cnt == N - 1)//构建完成
            {
                break;
            }
        }
    }
}

int ff[MaxN][17];//ff[i][j]指的是标号为i的节点往根节点的方向移动2^i次达到的节点的标号  ff[i][j]=ff[ff[i][j-1]][j-1]
int mm[MaxN][17];//mm[i][j]指的是标号为i的节点往根节点的方向移动2^i次过程中的最大权
int depth[MaxN];//记录每个点在mst中的深度
int vis[MaxN];//记录某个点是否被访问过
/**
 *
 * @param start 开始的点标号
 * @param parent 父节点标号
 * @param depth 这个点的深度
 */
void dfs(int start, int parent, int d) {
    depth[start] = d + 1;
    vis[start] = 1;
//    先向上走
    for (int i = 1; i < 17; ++i) {
        ff[start][i] = ff[ff[start][i - 1]][i - 1];
        mm[start][i] = max(mm[start][i - 1], mm[ff[start][i - 1]][i - 1]);
    }
//    向下递归，找到所有儿子（所有邻居）
    for (int i = 0; i < mst[start].size(); ++i) {
        Edge *child = mst[start][i];//儿子
        if (vis[child->to])continue;
        ff[child->to][0] = start;
        mm[child->to][0] = child->cost;
        dfs(child->to, start, d + 1);
    }
}

void preLca() {
    ff[1][0] = 1;//定义1号节点为根节点
    mm[1][0] = 0;//定义1号节点为根节点,它向上一步就没了，
    dfs(1, 1, 0);
}
/*倍增法，求lca，顺便求max权重*/
int maxUsingLca(int a, int b) {
    int ans = -1;
//    1.将a深度调到更深(交换)
    if (depth[a] < depth[b]) {
        int t = a;
        a = b;
        b = t;
    }
//2.将a调到和b同一高度
    int k = depth[a] - depth[b];//高度差
    for (int i = 0; (1 << i) <= k; ++i) {//k的二进制101
        if ((1 << i) & k)//k二进制的第i（从右往左）位是1
        {
            ans = max(ans, mm[a][i]);
            a = ff[a][i];
        }
    }
//    至此，a和b已经在同一层上
//从最顶层开始遍历，求ab两点的lca的下一层
    if(a!=b) {//重要更新
        for (int j = 16; j >= 0; --j) {
            if (ff[a][j] == ff[b][j])continue;
                //从最大祖先开始，判断a,b祖先，是否相同，
                // 一开始肯定相同，直到它们都跳j到最近祖先的下一层时，这个else触发
            else {
                ans = max(ans, mm[a][j]);
                ans = max(ans, mm[b][j]);
                a = ff[a][j];
                b = ff[b][j];
//            break;//重要更新
            }
        }
//    至此，a,b离lca还差一步
//再往上走一步就得到了lca
        ans = max(ans, mm[a][0]);
        ans = max(ans, mm[b][0]);
    }
    return ans;
}
void mid(int l, int r, int mod, int c) {
    int ans = -1;
    int left = l - l % mod + c;
    if (left < l)left += mod;
//    遍历关注点，两两在mst中用倍增法求lca顺便求max权重
    for (; left + mod <= r; left += mod) {
        ans = max(ans, maxUsingLca(left, left + mod));
    }
    printf("%d\n", ans);
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
    buildMST();//生成最小树
    preLca();//在最小树为倍增法做预处理
    for (int i = 0; i < Q; ++i) {
        int l, r, mod, c;
        scanf("%d %d %d %d", &l, &r, &mod, &c);
        mid(l, r, mod, c);
    }

    return 0;
}


