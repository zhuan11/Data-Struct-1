#define _CRT_SECURE_NO_WARNINGS

//////////////////////////////////////////////////////////////////////////////快速排序-快选
/*#include<iostream>	
#include<cstdio>
using namespace std;
const int N = 5e5;
int arr[N];
int n, m;

void Quiksort(int l, int r)
{
	if (l == r)
		return;

	int left = l - 1;
	int right = r + 1;
	int mid = l + r >> 1;

	while (left < right)
	{
		while (arr[++left] < arr[mid]);
		while (arr[--right] > arr[mid]);

		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}

	if (k <= right)
		return Quiksort(l, right);

	return Quiksort(right + 1, r);

}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	Quiksort(0, n - 1);

	cout << arr[k - 1];

	return 0;

}*/




///////////////////////////////////////////////////////////////////////////一维前缀和
/*#include<iostream>
#include<cstdio>
using namespace std;

const int N = 5;
int pre[N + 1];

int main()
{
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &pre[i]);
		pre[i] = pre[i] + pre[i - 1];
	}

	for (int i = 1; i <= N; i++)
		cout << pre[i] << ' ';

	return 0;

}*/




////////////////////////////////////////////////////////////////////////////一维差分



////////////////////////////////////////////////////////////////////////////二维前缀和算法
/*#include<iostream>
using namespace  std;
int N;
int	sum[N][N];
int arr[N][N];
int maxa = 1e-9;
int pre_f()//储存前缀和数据
{
	sum[0][0] = arr[0][0];//第一个

	for (int i = 1; i < N; i++) sum[0][i] = sum[0][i-1] + arr[0][i];//第一行，定义边界
	for (int i = 1; i < N; i++) sum[i][0] = sum[i-1][0] + arr[i][0];//第一列，定义边界

	for (int i = 1; i < N; i++)    for (int j = 1; j < N; j++)
	sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + arr[i][j] - sum[i - 1][j - 1];//初始化内部成员

	return 0;

}

int get_f(int x1, int y1, int x2, int y2)//x-i y-j
{
	if (x1 == 0 && y1 == 0) return sum[x2][y2];//最简单情况-从0.0到任意位置的前缀和

	if (x1 == 0) return sum[x2][y2] - sum[x2][y1 - 1];//从上边界x=0到任意位置的前缀和

	if (y1 == 0) return sum[x2][y2] - sum[x1 - 1][y2];//从左边界y=0到任意位置的前缀和

	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];//中间元素的二者的前缀和

	return 0;

}*/




/////////////////////////////////////////////////////////////////////链表的实现

/*#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int head, idx;
int point[N], value[N];

int n;

void init()
{
	idx = 0;
	head = -1;
}

void add_head(int x)
{
	value[idx] = x;
	point[idx] = head;
	head = idx++;
}

void add(int k, int x)
{
	value[idx] = x;
	point[idx] = point[k];
	point[k] = idx++;
}

void del(int k)
{
	point[k] = point[point[k]];
}

int main()
{
	cin >> n;

	init();

	while (n--)
	{
		char op;
		int k, x;
		cin >> op;

		if (op == 'H')
		{
			cin >> x;
			add_head(x);
		}
		else if (op == 'D')
		{
			cin >> k;
			if (!k) head = point[head];
			del(k - 1);
		}
		else
		{
			cin >> k >> x;
			add(k - 1, x);
		}
	}

	for (int i = head; ~i; i = point[i])
	{
		cout << value[i] << ' ';
	}

	return 0;

}
*/




/////////////////////堆栈数组模拟
/*#include<iostream>
using namespace std;

typedef struct node {

	int *arr;
	int Top;
	int Maxsize;
}Stack, *Stackpoint;

void Creat(Stackpoint &S,int Maxsize)//建立空堆
{
	S = (Stackpoint)malloc(sizeof(Stack));
	S->arr = (int *)malloc(sizeof(int)*Maxsize);
	S->Maxsize = Maxsize;
	S->Top = -1;

}

int Isempty(Stackpoint S)
{
	return (S->Top == -1);

}

int Isfull(Stackpoint S)
{
	return (S->Top == S->Maxsize-1);
}


void Push(Stackpoint &S, int x)
{

	if (Isfull(S))
	{
		cout << "栈已满";
		return;
	}
	else
	{
		S->arr[++S->Top] = x;

	}

}

int Pop(Stackpoint &S)
{
	if (Isempty(S))
	{
		cout << "栈已空";
		return;
	}

	else
	return S->arr[S->Top--];

}
*/ 



//////////////////////////堆栈链表模拟 
/*#include<iostream>
using namespace std;

typedef struct node {

	int value;
	struct node *next;

}LNcode, *Linklist;


void Creat(Linklist &T)
{
	T = (Linklist)malloc(sizeof(LNcode));
	T->next = NULL;
}

int Isempty(Linklist &T)
{
	return (T->next == NULL);

}

void Push(Linklist &T, int x)
{
	Linklist Temp;
	Temp = (Linklist)malloc(sizeof(LNcode));
	Temp->value = x;

	Temp->next = T->next;//头插法 
	T->next = Temp;

}

void Pop(Linklist &T)
{
	if (Isempty(T))
	{
		cout << "栈已空";
		return;
	}
	else
	{
		Linklist Temp;
		Temp = T->next;
		T->next= Temp->next;
		free(Temp);
	}

}*/ 




///////////////////////循环队列数组模拟 
/*#include<iostream>
using namespace std;

typedef struct node {

	int *arr;
	int front;
	int rear;
	int Maxsize;
}queuecode, *queue;

void Creat(queue &q, int Maxsize)
{
	q = (queue)malloc(sizeof(queuecode));
	q->arr = (int *)malloc(sizeof(int)*Maxsize);
	q->Maxsize = Maxsize;
	q->front = q->rear = 0;

}

bool Isfull(queue q)
{
	return ((q->rear + 1) % q->Maxsize == q->front);
}

bool Isempty(queue q)
{
	return (q->front == q->rear);
}

void AddQ(queue &q, int x)
{
	if (Isfull(q))
	{
		cout << "队列已满";
		return;
	}
	else
	{
		q->rear = (q->rear + 1) % q->Maxsize;
		q->arr[q->rear] = x;
	}

}

int PopQ(queue &q)
{
	if (Isempty(q))
	{
		cout << "队列已空";
		return;
	}

	else
	{
		q->front = (q->front + 1) % q->Maxsize;
		return q->arr[q->front];
	}

}*/ 




/////////////////////队列链表模拟 
/*#include<iostream>
using namespace std;

typedef struct node {//队列节点

	int value;
	struct node* next;
}LNcode, *Linklist;

typedef struct Node {//队列头节点

	Linklist front;
	Linklist rear;
}queuecode, *queue;

void Creat(queue &q)
{
	q = (queue)malloc(sizeof(queuecode));
	q->front = q->rear = NULL;
}

bool Isempty(queue q)
{
	return (q->front == NULL);
}

void Push(queue &q,int x)
{
	Linklist temp;
	temp = (Linklist)malloc(sizeof(LNcode));
	temp->value = x;
	if (Isempty(q))//插入就需要更新尾部rear
	{
		q->rear = q->front = temp;
		temp->next = NULL;
	}
	
	else
	{
		q->rear->next = temp;
		temp->next = NULL;
		q->rear = temp;
	}

}

int Pop(queue &q)
{
	if (Isempty(q))
	{
		cout << "队列已空";
		return 0;
	}
	Linklist Temp = q->front;

	if (q->front == q->rear)//删除就需要更新头部front
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;

	int answer = Temp->value;
	free(Temp);

	return answer;


}*/ 




/////////////////////////双向链表的数组模拟 
/*#include<iostream>
using namespace std;

const int Maxvalue = 100000 + 10;

struct node {

	int left;
	int right;
}arr[Maxvalue];

int Uniquearr[Maxvalue];

int main()
{
	int N;
	cin >> N;
	arr[1].left = 0;
	arr[1].right = Maxvalue;
	arr[0].right = 1;
	arr[arr[1].right].left = 1;

	int a, b;
	for (int i = 2; i <= N; i++)//更新插入元素的左右元素，更新左右的左右
	{
		cin >> a >> b;
		if (b == 0)//左插入
		{
			arr[i].left = arr[a].left;
			arr[i].right = a;
			arr[arr[a].left].right = i;
			arr[a].left = i;
		}
		if (b == 1)//右插入
		{
			arr[i].left = a;
			arr[i].right = arr[a].right;
			arr[arr[a].right].left = i;
			arr[a].right = i;
		}
	}

	int c, f;
	cin >> f;

	while (f--)
	{
		cin >> c;
		if (!Uniquearr[c])//删除元素，更新左右元素
		{
			int s, b;
			s = arr[c].left;
			b = arr[c].right;
			arr[s].right = b;
			arr[b].left = s;
			Uniquearr[c] = 1;
		}

	}
	
	int index = 0;
	while (arr[index].right != Maxvalue)//输出
	{
		cout << arr[index].right << ' ';
		 index = arr[index].right;
	} 

	return 0;

}*/ 
 



//////////////////////////////////////////////////////////////////////////K M P 算法
/*#include<iostream>
#include<string>
using namespace std;

int n, m;
int nexts[100];

int Init_next_arr(string st,int n)
{
	nexts[0] = 0;

	for (int i = 1, j = 0; i < n; i++)
	{

		while (j > 0 && st[i] != st[j])
			j = nexts[j - 1];

		if (st[i] == st[j])
			j++;

		nexts[i] = j;
	}
	return 0;
}

int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	int n = str2.size();
	int m = str1.size();

	Init_next_arr(str2,n);
    
	for (int i = 0, j = 0; i < m; i++)
	{

		while (j > 0 && str1[i] != str2[j])
			j = nexts[j - 1];

		if (str1[i] == str2[j])
			j++;

		if (j == n)
			cout << i - j + 2 << endl;
	}
	for (int i = 0; i < n; i++)
		cout << nexts[i] << ' ';
	return 0;
}
*/




///////////////////////////////////////////////////////////并查集算法  由函数并join() 查find()构成
/*#include<iostream>
#include<cstdio>
using namespace std;
int pre[5];
int a, b;
int find(int x)                            //找到父亲节点
{
	if (pre[x] == x) return x;             // 结束条件，找到并返回教主
	return pre[x] = find(pre[x]);          //找x的父亲节点，若不是教主，继续往上面找，找到后，一层一层返回x作为前一层的父亲节点
}
void join(int x, int y)                    //合并元素，融合教主
{
	if (find(x) == find(y))                //一样，就不用操作啦
		return;
	else
		pre[find(x)] = find(y);            //不一样，玄持大师认灭绝师太为教主，哈哈哈哈

}
int main()
{
	for (int i = 1; i <= 4; i++)          //最开始每个元素都是单一的，都是自己的父亲节点，也只有当i的父亲节点是自己，才能说找到i即为教主
		pre[i] = i;

	int m = 5;
	while (m--)
	{
		char ch[2];
		scanf("%s", &ch);
		scanf("%d %d", &a, &b);

		if (*ch=='M')
			join(a, b);
		
		if (*ch== 'Q')
		{
			if (find(a) == find(b))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}

	return 0;
}*/



/////////////////////////////////////////////////////////单调队列-滑动窗口模板
/*#include<iostream>
#define N 9
using namespace std;

int arr[N];
int index[N];
int k,tail, head = 1;
int main()
{
	scanf("%d", &k);
	for (int i = 1; i <= N-1; i++)//从1开始储存，比较方便，原数组下标与head=1(为了判断队列元素是否存在问题)相对应
		scanf("%d", &arr[i]);     //head<=tail 才有元素(因head本身就加1啦)


	for (int i = 1; i <= N-1; i++)
	{
		while (head <= tail && index[head] <= i - k) head++;//维护窗口范围,防止最值不是该区间情况

		while (head <= tail && arr[index[tail]] >= arr[i]) tail--;//维护队列的单调性,如果不递增,则前面元素(是下标,为了方便处理)出队,直到满足单调性//tail 从后面维护！

			index[++tail] = i;//满足单调性则直接加入,最坏情况tail=0,即加入元素最小(还是要加入)//是下标！

			if (i >= k)//维护窗口范围,输出窗口最小值，头部永远的最值(这就很奇妙)
				cout << arr[index[head]] << ' ';
	}

	return 0;
}*/


////////////树的引子-二分查找
/*
#include<iostream>
#define MAX 50
using namespace std;
typedef struct {

	int arr[MAX];
	int length;
}LNcode;

int	Half_search(LNcode qq,int k)
{
	int left = 1;
	int right =qq.length;

	while (left <= right)//二分模板 left<=right特判不存在
	{
		int mid = left + right >> 1;
		if (qq.arr[mid] < k)
			left = mid + 1;
		else if (qq.arr[mid] > k)
			right = mid - 1;
		else
			return mid;
	}

	return -1;

}

int main()
{    
	int k;
	LNcode QQ;
	cin >> QQ.length >> k;

	for (int i = 1; i <= QQ.length; i++)
		cin >> QQ.arr[i];

	cout<<Half_search(QQ, k);

	return 0;

}
*/

//二叉搜索树
//1.遍历：先序，中序，后序，层序
//二叉树数组储存，深度搜索深度  
//二叉树数组储存，先序在遍历  
//已知先序中序求后序 
//2.查询：搜索特值，最大值，最小值
//3.插入
//4.删除
//5.应用:判断不同的序列是否与标准树相同，即能否构成相同的树
//平衡二叉树


///////////////////////////////////////////////二叉树先序遍历
/*
#include<iostream>
using namespace std;

typedef struct node {
	struct node *left;
	char value;
	struct node *right;
}LNcode, *tree;

void Init(tree &p)//初始化二叉树
{ 
	char ch;
	cin >> ch;
	if (ch == '#')//结束二叉树的输入
		p = NULL;
	else
	{
		p = new LNcode;
		p->value = ch;

		Init(p->left);
		Init(p->right);

	}

}

void PreOrderTraversal(tree p)
{
	if (p)
	{
		printf("%c", p->value);

		PreOrderTraversal(p->left);
		PreOrderTraversal(p->right);
	}
}

int main()
{
	tree T;
	
	Init(T);
	cout << "先序遍历: " << endl;

	PreOrderTraversal(T);

	return 0;

}
*/


////////////////////////////////////////中序遍历
/*
#include<iostream>
using namespace std;

typedef struct node {

	struct node *left;
	char value;
	struct node *right;
}LNcode, *tree;

void Init(tree &q)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		q = NULL;
	else
	{
		q= new LNcode;
		q->value = ch;
		Init(q->left);
		Init(q->right);
	}

}

void MidOrderTraversal(tree p)
{
	if (p)
	{
		MidOrderTraversal(p->left);

		printf("%c", p->value);

		MidOrderTraversal(p->right);

	}
 
}

int main()
{
	tree T;
	Init(T);

	cout<<"中序遍历："<<endl;
	MidOrderTraversal(T);
    
	return 0;

}
*/

///////////////////////////////////后序遍历

/*#include<iostream>
using namespace std;

typedef struct node {

	struct node *left;
	char value;
	struct node *right;

}LNcode, *tree;

void Init(tree &T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = new LNcode;
		T->value = ch;
		Init(T->left);
		Init(T->right);
	}
}

void BehOrderTraversal(tree T)
{
	if (T)
	{
		BehOrderTraversal(T->left);

		BehOrderTraversal(T->right);

		printf("%c", T->value);

	}
}

int main()
{
	tree T;
	Init(T);

	cout << "后序遍历： " << endl;
	BehOrderTraversal(T);

	return 0;
}*/


/////////////////////////////////////层序遍历
/*#include<iostream>
#include<queue>
using namespace std;

typedef struct node {

	struct node *left;
	char value;
	struct node *right;

}LNcode, *tree;

void Init(tree &T)
{
	T = NULL;
	return;
}

void Creat_Ercha_Tree(tree &T)
{
	char ch;
	cin >> ch;

	if (ch == '#')
		T = NULL;
	else
	{
		T = new LNcode;
		T->value = ch;
		Creat_Ercha_Tree(T->left);
		Creat_Ercha_Tree(T->right);

	}

}
void Level_traversal(tree T)
{
	if (T == NULL)
		return;

	queue<tree>p;
	p.push(T);
	while (!p.empty())
	{
		T = p.front();
		p.pop();
		cout << T->value << ' ';
		if (T->left)
			p.push(T->left);
		if (T->right)
			p.push(T->right);

	}

}

int main()
{
	tree T;

	Init(T);
	Creat_Ercha_Tree(T);
	Level_traversal(T);

	return 0;

}*/


/*#include<iostream>
#define NuLL -1;
using namespace std;

const int N = 8;
int check[N];

struct treenode {

	char name;
	int left;
	int right;
}treearr[N];

int Creat_Ercha_Tree(struct treenode treearr[])
{
	char le, ri;
	for (int i = 0; i < N; i++)
	{
		scanf("%c %c %c", &treearr[i].name, &le, &ri);
		if (le != '-')
		{
			treearr[i].left = le - '0';
			check[treearr[i].left] = 1;
		}
		else  
			treearr[i].left = NuLL;

		if (ri != '-')
		{
			treearr[i].right = ri - '0';
			check[treearr[i].right] = 1;
		}
		else
			treearr[i].right = NuLL;

		for (int i = 0; i < N; i++)
			if (check[i] == 0)
				return i;
	}

}
int main()
{
	
	printf("根节点是%d \n", Creat_Ercha_Tree(treearr));
	
	return 0;

}*/




//////////////////////////二叉树数组储存，深度搜索深度 
/*#include<iostream>;
#include<algorithm>;
using namespace std;

const int N = 10e6 + 10;
int ans;

struct node {
	int left;
	int right;
}Node[N];

void dfs(int index, int deepth)
{
	if (index == 0)
		return;

	ans = max(ans, deepth);

	dfs(Node[index].left, deepth + 1);
	dfs(Node[index].right, deepth + 1);

}

int main()
{

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		scanf("%d %d", &Node[i].left, &Node[i].right);

	dfs(1, 1);

	cout << ans;

	return 0;

}*/ 





///////////////////////二叉树数组储存，先序在遍历 
/*#include<iostream>
using namespace std;

struct node {
	char left;
	char right;
}Node[1000];

void Preordertraserval(char c)
{
	if (c == '*') return;

	cout << c;

	Preordertraserval(Node[c].left);
	Preordertraserval(Node[c].right);
}

int main()
{
	char c0,c1,c2,c3;
	int n;
	cin >> n;

	cin >> c0;
	cin >> c2;
	cin >> c3;

	Node[c0].left = c2;
	Node[c0].right = c3;

	for (int i = 2; i <= n; i++)
	{
		cin >> c1;
		cin >> c2;
		cin >> c3;

		Node[c1].left = c2;
		Node[c1].right = c3;
	}

	Preordertraserval(c0);

	return 0;

}*/ 





//////////////////////////已知先序中序求后序 
/*#include<iostream>
#include<cstring>
using namespace std;

void Posttraversal(char *PreStr, char *CenStr, int Length)//前序、中序起始位置、长度
{
	if (Length == 0)//单一节点
		return;

	int Rootindex = 0;//长度

	for (; CenStr[Rootindex] != PreStr[0]; Rootindex++);//通过前序去中序找到左右子树

	Posttraversal(PreStr + 1, CenStr, Rootindex);//左子树递归(左子树前序、中序起始位置、长度)
	Posttraversal(PreStr + Rootindex + 1, CenStr + Rootindex + 1, Length - Rootindex - 1);
	                                             //右子树递归(前序、中序起始位置、长度)                               
	cout << *PreStr;


}


int main()
{
	char PreStr[100];
	char CenStr[100];

	cin >> PreStr;
	cin >> CenStr;

	Posttraversal(PreStr, CenStr, strlen(PreStr));

	return 0;

} */ 




//////////////////////////////////二叉搜索树搜索特值 类似二分法（log2 N）

/*#include<iostream>
using namespace std;
typedef struct node {

	struct node *left;
	int value;
	struct node *right;
}LNcode, *tree;

void Init(tree &T)
{
	int a;
	cin >> a;
    
	if (a == 0)
		T = NULL;
	else
	{
		T = new LNcode;
		T->value = a;

		Init(T->left);
		Init(T->right);
	}

}

int  Ercha_Search_Tree(int x, tree T)
{
	while (T)
	{
		if (x > T->value)
			T= T->right;

		else if (x < T->value)
			T=T->left;
		 
		else           //value==x 
			return x; //返回其地址
	}

	return 0;

}

int main()
{
	tree T;
	int b = 9;

	Init(T);
	printf("%d", Ercha_Search_Tree(b, T));

	return 0;

}*/


////////////////////////////二叉搜索树最大最小值
/*#include<iostream>
using namespace std;

typedef struct node {

	struct node *left;
	int value;
	struct node *right;
}LNcode, *tree;

void Init(tree &T)
{
	int a;
	cin >> a;
	if (a == 0)
		T = NULL;
	else
	{
		T = new LNcode;
		T->value = a;

		Init(T->left);
		Init(T->right);

	}
}

int Ercha_Search_Max_Tree(tree T)
{
	while (T)
	{
		if (T->right->right == NULL)
			return T->right->value;
		else
			T = T->right;
	}
}

int  Ercha_Search_Min_Tree(tree T)
{
	while (T)
	{
		if (T->left->left == NULL)
			return T->left->value;
		else
			T = T->left;
	}
}

int main()
{
	tree T;
	Init(T);

	printf("max=%d", Ercha_Search_Max_Tree(T));
	puts("");
	printf("min=%d", Ercha_Search_Min_Tree(T));

	return 0;

}*/


//////////////////////////二叉搜索树插入操作
/*#include<iostream>
using namespace std;

typedef struct node {
	struct node *left;
	int value;
	struct node *right;
}LNcode, *tree;

void Init(tree &T)
{
	int a;
	cin >> a;

	if (a == 0) T = NULL;
	else
	{
		T = new LNcode;
		T->value = a;

		Init(T->left);
		Init(T->right);
	}
}

tree Ercha_Insert_Tree(int x ,tree &T)
{
	if (!T) //封装节点
	{
		T = new LNcode;
		T->value = x;
		T->left = NULL;
		T->right = NULL;
	}
	else
	{
		if (x > T->value)
			T->right = Ercha_Insert_Tree(x, T->right);//右子树插入，保存地址
		else if (x < T->value)
			T->left = Ercha_Insert_Tree(x, T->left);  //左子树插入，保存地址
	}

	return T; //以便保存地址
}

void PreOrderTraversal(tree T)
{
	if (T)
	{
		printf("%d", T->value);

		PreOrderTraversal(T->left);
		PreOrderTraversal(T->right);
	}

}

int main()
{
	tree T;
	int b;
	cin >> b;

	Init(T);
	Ercha_Insert_Tree(b,T);
	PreOrderTraversal(T);
     
	return 0;

}*/


/////////////////////////////////二叉搜索树删除操作
/*#include<iostream>
using namespace std;

typedef struct node {

	struct node *left;
	int value;
	struct node *right;
}LNcode, *tree;

void Init(tree &T)
{
	int a;
	cin >> a;

	if (a == 0) T = NULL;
	else
	{
		T = new LNcode;
		T->value = a;

		Init(T->left);
		Init(T->right);
	}

}

tree Find_Min(tree T)
{
	int min = T->value;
	while (T->right)
	{
		if (T->right->value < min)
			T = T->right;

	}
	return T;
}

tree Ercha_Search_Delete_Tree(int x, tree &T)
{
	tree tem = T;
	if (!T)
		cout << "Have no element" << endl;

	else if (x > T->value)
		T->right = Ercha_Search_Delete_Tree(x, T->right);//递归右子树删除
	else if (x < T->value)
		T->left = Ercha_Search_Delete_Tree(x, T->left);//递归左子树删除
	else
	{
		if (T->left&&T->right)
		{
			tem = Find_Min(T->right);
			T->value = tem->value;
			T->right = Ercha_Search_Delete_Tree(tem->value, tem);
		}
		else
		{
			if (!T->left)
			{
				T = T->right;
				free(tem);
			}
			else
			{
				T = T->left;
				free(tem);
			}
		}
	}
	return T;
}


void PreOrderTraversal(tree T)
{
	if (T)
	{
		printf("%d ", T->value);

		PreOrderTraversal(T->left);
		PreOrderTraversal(T->right);
	}
}
int main()
{
	tree T;
	int b = 8;

	Init(T);
	Ercha_Search_Delete_Tree(b, T);
	PreOrderTraversal(T);

	return 0;

}*/



///////////////////////////////////总结性程序
/*#include<iostream>
using namespace std;

typedef struct node {

	struct node *left;
	int value;
	struct node *right;
}LNcode, *tree;

void Init(tree &T)//初始化
{
	int a;
	cin >> a;

	if (a == 0)
		T = NULL;
	else
	{
		T = new LNcode;
		T->value = a;

		Init(T->left);
		Init(T->right);
	}
}

tree Find_Min(tree T)//找到右子树中最小的元素 充当删除节点
{
	int min = T->value;

	while (T->right)
	{
		if (T->right->value < min)
			T = T->right;
		else break;
	}

	return T;        //返回最小右子树中元素的地址 给删除节点指针域
}


tree Ercha_Search_Insert_Tree(int x,tree &T)//插入
{
	if (T == NULL)//空树
	{             //封装节点
		T = new LNcode;
		T->value = x;
		T->left = NULL;
		T->right = NULL;
	}

	else if (x > T->value) //找到插入位置，进行插入(最重要的是保存插入节点位置)(赋值)
		T->right = Ercha_Search_Insert_Tree(x, T->right);
	else if (x < T->value)
		T->left = Ercha_Search_Insert_Tree(x, T->left);

	return T;//返回地址以便保存

}

tree Ercha_Search_Delete_Tree(int y, tree &T)//删除
{
	tree tem = T;
	if (T == NULL)//判断元素是否存在
		cout << "Having no element" << endl;

	else if (y > T->value)
		T->right = Ercha_Search_Delete_Tree(y, T->right);//递归右子树删除，递归结束一层一层返回地址，就记住啦所有节点的位置
	else if (y < T->value)
		T->left = Ercha_Search_Delete_Tree(y, T->left);  //递归左子树删除，递归结束一层一层返回地址，就记住啦所有节点的位置
	else //找到啦节点 有三种情况 左右儿子 空或右儿子 空或左儿子
	{
		if (T->left&&T->right)//左右儿子
		{
			tem = Find_Min(T->right);//上述
			T->value = tem->value;//看似删除找到的节点，不如说重新赋值 删除替代节点
			T->right = Ercha_Search_Delete_Tree(tem->value, T->right);//将替代节点删除，转化为后两种情况
		}
		
		else //空或右儿子  空或左儿子
		{
			if (!T->left)
				T = T->right;
			else
				T = T->left;
			delete(tem);//删除节点
		}
	}

		return T;//返回地址，以记住位置

}

void PreOrderTraversal(tree T)//查询
{
	if (T)
	{
		printf("%d ", T->value);

		PreOrderTraversal(T->left);
		PreOrderTraversal(T->right);

	}

}

int main()
{
	int x = 10, y = 13;
	tree T;

	Init(T);
    Ercha_Search_Insert_Tree(y,T);
	Ercha_Search_Delete_Tree(x, T);
	PreOrderTraversal(T);

	return 0;
}*/


//平衡二叉树(也是搜索树)的调整 ： 
//RR旋转：被破坏者A 麻烦者B，B在A的右子树的右边
//若只有一个A，抓住近A 3节点中点 反之 先处理最下面错误，若成功，即可，否则 就处理近A者中点  (左转)

//LL旋转：被破坏者A 麻烦者B，B在A的左子树的左边
//同上(右转)

//LR旋转： 被破坏者A 麻烦者B，B在A左子树的右边
//抓住近A的三个节点 构成二叉型

//RL旋转： 被破坏者A  麻烦者B，B在A右子树的左边
//抓住近A的三个节点 构成二叉型



////////////////////////判断不同的序列是否与标准树相同，即能否构成相同的树（一种序列只能确定唯一一棵二叉树 但一棵二叉树可由不同序列得到）
/*
#include<iostream>
using namespace std;

int counts;

typedef struct node {

	struct node *left;
	int value;
	int flag;
	struct node *right;

}LNcode, *tree;

void Init(tree &T)//初始化
{
	T = NULL; 
	return;
}

tree Ercha_Standard_Tree(int x, tree &T)//建立标准二叉树
{
	if (!T)
	{
		T = new LNcode;
		T->value = x;
		T->flag = 0;
		T->left = NULL;
		T->right = NULL;
	}
	else if (x > T->value)
		T->right = Ercha_Standard_Tree(x, T->right);
	else if (x < T->value)
		T->left = Ercha_Standard_Tree(x, T->left);

	return T;

}

int check(int x, tree T)//序列匹配标准二叉树
{
	if (T->flag) //表示已查询过
	{
		if (x > T->value)
			return check(x, T->right);
		else if (x < T->value)
			return check(x, T->left);

		else return 0; //出现重复 即错误

	}

	else //开始查询
	{
		if (x == T->value)//找到
		{
			T->flag = 1;//找到就标记该节点
			return 1;
		}

		else return 0;//没找到

	}

}

void Reset(tree &T)//清除所有的flag标记
{
	
	tree temp1 = T, temp2 = T;
	T->flag = 0;

	while (temp1->left)//左子树清除
	{
		temp1 = temp1->left;
		temp1->flag = 0;
	}

	while (temp2->right)//右子树清除
	{
		temp2 = temp2->right;
		temp2->flag = 0;
	}
	

	//tree temp=T;
	//temp->flag = 0;
	//if (temp->left) Reset(temp->left);
	//if (temp->right) Reset(temp->right);
}



int main()
{   
	tree T;
	Init(T);
	int Ge_num = 4;//元素个数
	int Xu_num = 2;//序列个数

	for (int i = 0; i < Ge_num; i++)//建立标准树
	{
		int a;
		cin >> a;
		Ercha_Standard_Tree(a, T);
	}

	for (int i = 0; i < Xu_num; i++)
	{
		for (int j = 0; j < Ge_num; j++)
		{
			int b;
			cin >> b;

			if (check(b, T)) counts++;//必须查询完 正常的话一个数就会记录一次 不正常即不相同

		}
		if (counts == Ge_num) cout << "Yes" << endl;
		else cout << "No" << endl;
		Reset(T);

	}

}
*/

//堆
//1.最大最小堆的插入(建立)
//2.最大最小堆的删除
//3.遍历
//4.并查集算法
//5.堆的应用-打印路径权值
//6.并查集的应用-File Transfer


/*#include<iostream>
using namespace std;

const int Maxdata = 10000;//哨兵节点


typedef struct stack {

	int *arr;         //储存元素数组
	int size;         //当前元素个数
	int max_capacity;//最大容量

}LNcode, *stack_tree;

void Init_Maxheap(stack_tree &T,int Maxsize)
{
	T = new LNcode;
	T->arr = (int *)malloc( (Maxsize+1) * sizeof(int) );
	T->arr[0] = Maxdata;
	T->size = 0;
	T->max_capacity = Maxsize;

}

void Creat_Maxheap_tree(stack_tree &T)//初始化最大堆数组
{
	int a;
	for (int i = 1; ; i++)
	{
		
		cin >> a;
		if (a != 0 && T->size <= T->max_capacity)
		{
			T->arr[i] = a;
			T->size++;
		}
		else
			break;
	}
}

void Insert_Maxheap_tree(stack_tree &T, int item)
{
	int i =T->size+1;

	for (; T->arr[i / 2] < item; i /= 2)
		T->arr[i] = T->arr[i / 2];
	T->arr[i] = item;
	T->size++;
}

void Display(stack_tree T)
{
	for (int i = 1; i <= T->size; i++)
		cout << T->arr[i] << ' ';

}

int main()
{
	stack_tree T;
	int item = 41;
	int Maxsize;
	cin >> Maxsize;

	Init_Maxheap(T, Maxsize);
	Creat_Maxheap_tree(T);
	Insert_Maxheap_tree(T, item);
	Display(T);

	return 0;

}*/


///////////////////////////////////////////最大堆插入操作(也即建立)
/*#include<iostream>
using namespace std;

const int start = 1000;

typedef struct node {

	int *arr;
	int Size;//当前数组元素个数
	int Max_Capacity;//数组最大容量

}LNcode, *stack_tree;

void Init_MaxHeap(stack_tree &T,int Max_Capacity)//初始化结构体
{
	T = new LNcode;
	T->arr = (int *)malloc((Max_Capacity + 1) * sizeof(int));//下标从1开始
	T->arr[0] = start;//哨兵结点
	T->Size = 0;
	T->Max_Capacity = Max_Capacity;
}

void Creat_MaxHeap(stack_tree &T)  //初始化最大堆-数组
{
	int a;
	for (int i = 1; i <= T->Max_Capacity; i++)
	{
		cin >> a;
		if (a != 0 && T->Size <= T->Max_Capacity)
		{
			T->arr[i] = a;
			T->Size++;
		}
	}
}

void Insert_MaxHeap(stack_tree &T, int item) //插入算法
{
	int b = T->Size + 1;

	for (; item > T->arr[b / 2] ; b/=2)//上下层访问
		T->arr[b] = T->arr[b / 2];

	T->arr[b] = item;//哨兵节点起作用
	T->Size++;
}

void Display(stack_tree T) //遍历
{
	for (int i = 1; i <= T->Size; i++)
		cout << T->arr[i] << ' ';
}

int main()
{
	stack_tree T;
	int Max_Capacity, item;
	cin >> Max_Capacity, item = 41;

	Init_MaxHeap(T,Max_Capacity);
	Creat_MaxHeap(T);
	Insert_MaxHeap(T, item);
	Display(T);

	return 0;

}*/





//////////////////////////////////////最大堆删除操作
/*#include<iostream>
using namespace std;

const int start = 1000;

typedef struct node {

	int *arr;
	int Size;
	int Max_Capacity;

}LNcode, *stack_tree;

void Init_MaxHeap(stack_tree &T, int Max_Capacity)
{
	T = new LNcode;
	T->arr = (int *)malloc((Max_Capacity + 1) * sizeof(int));
	T->arr[0] = start;
	T->Size = 0;
	T->Max_Capacity = Max_Capacity;
}

void Creat_MaxHeap(stack_tree &T)  
{
	int a;
	for (int i = 1; i <= T->Max_Capacity; i++)
	{
		cin >> a;
		if (a != 0 && T->Size <= T->Max_Capacity)
		{
			T->arr[i] = a;
			T->Size++;
		}
	}
}

void Delete_Stacktree_Maxelement(stack_tree &T)//删除算法
{
	int temp = T->arr[T->Size];//数组最后一个元素
	T->Size--;
	int parent, child;

	for (parent = 1; parent * 2 <= T->Size; parent=child)//删除
	{
		child = parent * 2;//假定左儿子为最大下层儿子
		if (child != T->Size//若等于则无右儿子
		&&T->arr[child] < T->arr[child + 1])//找出最大儿子
			child++;//则为右儿子

		if (temp >= T->arr[child]) break;//单调性正常，没必要继续下去，即为结束条件
		else
			T->arr[parent]=T->arr[child];//单调性不正常，维护最大堆

	}
	T->arr[parent] = temp;//维护单调性

}

void Traversal(stack_tree T)//遍历
{
	for (int i = 1; i <= T->Size; i++)
		cout << T->arr[i] << ' ';

}

int main()
{
	stack_tree T;
	int Max_Capacity = 9;

	Init_MaxHeap(T, Max_Capacity);
	Creat_MaxHeap(T);
	Delete_Stacktree_Maxelement(T);
	Traversal(T);

	return 0;

}*/




//////////////////////////////////////并查集算法
/*#include<iostream>
using namespace std;

int Parent_arr[1000];

void Init(int Maxsize)//建立父亲数组，数组元素即为父亲节点权值
{
	for (int i = 1; i <= Maxsize; i++)
		cin >> Parent_arr[i];
}

int find(int x)//查找算法
{

	if (Parent_arr[x] < 0)//x的父亲节点
		return Parent_arr[x];//返回父亲节点的权值
	else
		return Parent_arr[x]=find(Parent_arr[x]);//返回时依次记录祖先节点的权值,提高效率(巨牛!)

}


void Join(int x, int y)//合并算法
{
	if (find(x) == find(y))
		return;
	else
		Parent_arr[x] = find(y);//节点相同即在同一集合
}


int main()
{
	int Maxsize = 8;
	
	Init(Maxsize);
	int a = 1, b = 4;
	if (find(a) == find(b))
		cout<<"已在同一集合"<<' ';
	else
		Join(a, b);
     
	if (find(a) == find(b))
		cout << "合并后才在一个集合中" << ' ';

	return 0;

}*/






///////////////////////////堆的应用-打印路径权值
/*#include<iostream>
using namespace std;

int Smallest_stacktree[1001];
int Size;

void Insert(int x)//建立最小堆(标准建立)
{

	int i;
	for (i = ++Size; x < Smallest_stacktree[i / 2]; i /= 2)
		Smallest_stacktree[i] = Smallest_stacktree[i / 2];
	     
	Smallest_stacktree[i] = x;
}

void Creat(int Maxsize)//建立最小堆(也即插入操作)
{
	int element;
	for (int i = 1; i <= Maxsize; i++)//传进元素，初始化
	{
		cin >> element;
		Insert(element);
	}
}

int main()
{
	Smallest_stacktree[0] = -1000;//哨兵节点
	int Maxsize, num;
	cin >> Maxsize >> num;

	Creat(Maxsize);

	for (int i = 0; i < num; i++)//查询次数
	{
		int j;
		cin >> j;
		while (Smallest_stacktree[j] >= 0)//底部至根部输出权值
		{
			cout << Smallest_stacktree[j] << ' ';
			j /= 2;
		}
		puts("");

	}

	return 0;

}*/





///////////////////////////////并查集应用-File Transfer
/*#include<iostream>
#define Maxsize 5
using namespace std;


int Parent[Maxsize+1];

void Init_Parent_arr()
{ 
	for (int i = 1; i <= Maxsize; i++)
		cin >> Parent[i];
}

int find(int x)
{
	if (Parent[x] == x)
		return x;
	else
		return Parent[x] = find(Parent[x]);

}

void Join(int x, int y)
{
	if (find(x) == find(y))
		return;
	else
		Parent[x] = find(y);

	return;
}

int main()
{
	Init_Parent_arr();

	char ch;
	int a, b;
	while (1)
	{
		cin >> ch;
		if (ch == 'S')
			break;
		else
		{
			cin >> a >> b;
			if (ch == 'C')
			{
				if (find(a) == find(b))
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}

			else if (ch == 'I')
				Join(a, b);
		}

	}

	return 0;

}*/





//排序:
//冒泡 插入 都是交换相邻元素  //稳定
//选择排序 希尔排序(选取恰当的间隔量的插入排序) //不稳定
//堆排序(选择排序的改进，用最大堆模拟，相当于最大堆的插入删除总结性程序)//不稳定
//归并排序(核心:两个有序子序列归并)(递归 循环)//稳定
//快速排序//不稳定
//基数排序(桶排序的升级版本)(按基数分配桶，先分配在收集，躺数由关键字个数决定) 线性复杂度


//冒泡排序最优O(N) 最差O(N^2) 优点：省空间 稳定(元素相同不会交换）； 缺点：耗时间

/*#include<iostream>
using namespace std;

const int N = 10;

void  Bubble_sort(int arr[], int N)
{
	for (int p = N - 1; p >= 0; p--)//多趟冒泡
	{
		int flag = 0;

		for (int i = 0; i < p; i++)//一趟冒泡
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				flag = 1;//观察是否已排好序
			}
		}

		if (flag == 0)
			break;
	}

}

int main()
{
	int arr[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	Bubble_sort(arr, N);

	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';

	return 0;

}*/



//插入排序最优O(N) 最差O(N^2) 优点：省空间 稳定； 缺点：耗时间
/*#include<iostream>
using namespace std;

const int N = 10;

void Insertion_sort(int arr[], int N)
{
	int i;
	for (int p = 1;p<N;p++)//arr[0]这张牌已在手上，马上摸后面的牌
	{
		int temp = arr[p];//用来保存，防止覆盖要摸的牌
		for (i = p; i > 0 && temp < arr[i - 1]; i--)
			arr[i] = arr[i - 1];//向后移动位置，腾出位置

		arr[i] = temp;//添加新牌
		
	}

}

int main()
{
	int arr[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	Insertion_sort(arr, N);

	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';

	return 0;

}*/


///////////////////////归并排序 O(稳定Nlog2N) 稳定
/*#include<iostream>
using namespace std;
const int N =4;
typedef int Elementtype;

void Merge(Elementtype arr[], Elementtype Temp[], int Left, int Middle, int Right)
{
	int Leftend = Middle - 1;//记录左边终点
	int NumElement = Right - Left + 1;//元素个数
	int start = Left;//记录起始位置

	while (Left <= Leftend && Middle <= Right)//合并两个有序序列
	{
		if (arr[start] <=arr[Middle])
			Temp[start++] = arr[Left++];
		else
			Temp[start++] = arr[Middle++];

	}

	while (Left <= Leftend)//处理左边剩下元素
		Temp[start++] = arr[Left++];

	while (Right >= Middle)//或者处理右边剩下元素
		Temp[start++] = arr[Middle++];

	for (int i = 0; i < NumElement; i++, Right--)//将排好序的元素放进原数组
		arr[Right] = Temp[Right];


}


void Msort(Elementtype arr[], Elementtype Temp[], int Left, int Right)
{
	int Center = Left + Right >> 1;//取中点

	if (Left < Right)
	{
		Msort(arr, Temp, Left, Center);   //左递归解决
		Msort(arr, Temp, Center+1, Right);//右递归解决
		Merge(arr, Temp,Left, Center + 1, Right);//合并两段有序序列
	}

}


void Merge_sort(Elementtype arr[], int N)//函数接口
{
	Elementtype	*Temp;
	Temp = (int*)malloc(N * sizeof(Elementtype));
	if (Temp != NULL)
	{
		Msort(arr, Temp, 0, N - 1);
		free(Temp);//好习惯
	}
	else
		cout << "空间不足" << endl;

}

int main()
{
	Elementtype arr[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	Merge_sort(arr, N);

	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';

	return 0;

}*/


///////////快速排序: 最优:O(Nlog2N) 最差O(N^2) 不稳定
/*#include<iostream>
using namespace std;
const int N = 10;
typedef int ElementType;

void Quicksort(ElementType arr[], int Left, int Right)//Left数组起始位置 Right末端位置
{


	int left = Left - 1;
	int right = Right + 1;
	int Center = Left + Right >> 1;

	if (Left >= Right)
		return;

	while (left < right)
	{
		while (arr[++left] < arr[Center]);
		while (arr[--right] > arr[Center]);
		if(left<right)
		{
				int temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
		}

		 
	}

	 Quicksort(arr, Left,right);

	 Quicksort(arr,right + 1, Right);

}

void Quick_sort(ElementType arr[], int N)//函数接口
{
	Quicksort(arr, 0, N - 1);
}

int main()
{
	ElementType arr[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	Quick_sort(arr, N);

	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';

	return 0;

}*/





//堆排序:平均复杂度(略小于Nlog2N) 不稳定
/*#include<iostream>
using namespace std;

typedef struct node {

	int *arr;
	int Size;
	int Maxsize;
}LNcode, *tree;


void Init_Max_Stacktree(tree &T,int N)//初始化最大堆
{
	T = (tree)malloc(sizeof(LNcode));
	T->arr = (int *)malloc( (N + 1) * sizeof(int));
	T->Maxsize = N;
	T->Size = 0;
	T->arr[0] = 1000;
}

void Insert_Smallest_Stacktree(tree &T, int Temp)//最大堆插入操作
{
	int i = T->Size;

	for (; Temp > T->arr[i / 2]; i/=2)
		T->arr[i] = T->arr[i / 2];

	T->arr[i] = Temp;

}


void Creat_Max_Stacktree(tree &T ,int N)//建立最大堆
{

	int a;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		if (a != 0)
		{
			T->Size++;
			Insert_Smallest_Stacktree(T,a);
		
		}
		else break;
	}

}

void DeleteMax_Smallest_Stacktree(tree &T)//最大堆删除操作
{
	int Parent = 1;
	int Child = 0;
	int Temp = T->arr[T->Size];
	int TEmp = T->arr[Parent];

	for (; Parent * 2 <= T->Size; Parent = Child)
	{
		Child = Parent * 2;
		if (Child != T->Size&&T->arr[Child] < T->arr[Child + 1])
			Child++;
		if (T->arr[Child] > Temp)
		{
			T->arr[Parent] = T->arr[Child];
		}
		else break;
	}
	    T->arr[T->Size] = TEmp;//将最大元素，即根节点放入数组最末尾，实现排序
		T->arr[Parent] = Temp;
		T->Size--;

}

void Stack_sort(tree &T,int N)//堆排序
{
	for (int i = 1; i <= N; i++)//一个一个排
		DeleteMax_Smallest_Stacktree(T);

}

int main()
{
	tree T;
	int N;
	cin >> N;

	Init_Max_Stacktree(T, N);

	Creat_Max_Stacktree(T, N);

	Stack_sort(T, N);

	for (int i = 1; i <= N; i++)
		cout << T->arr[i] << ' ';

	return 0;
}*/


