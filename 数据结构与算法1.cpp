#define _CRT_SECURE_NO_WARNINGS

//////////////////////////////////////////////////////////////////////////////��������-��ѡ
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




///////////////////////////////////////////////////////////////////////////һάǰ׺��
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




////////////////////////////////////////////////////////////////////////////һά���



////////////////////////////////////////////////////////////////////////////��άǰ׺���㷨
/*#include<iostream>
using namespace  std;
int N;
int	sum[N][N];
int arr[N][N];
int maxa = 1e-9;
int pre_f()//����ǰ׺������
{
	sum[0][0] = arr[0][0];//��һ��

	for (int i = 1; i < N; i++) sum[0][i] = sum[0][i-1] + arr[0][i];//��һ�У�����߽�
	for (int i = 1; i < N; i++) sum[i][0] = sum[i-1][0] + arr[i][0];//��һ�У�����߽�

	for (int i = 1; i < N; i++)    for (int j = 1; j < N; j++)
	sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + arr[i][j] - sum[i - 1][j - 1];//��ʼ���ڲ���Ա

	return 0;

}

int get_f(int x1, int y1, int x2, int y2)//x-i y-j
{
	if (x1 == 0 && y1 == 0) return sum[x2][y2];//������-��0.0������λ�õ�ǰ׺��

	if (x1 == 0) return sum[x2][y2] - sum[x2][y1 - 1];//���ϱ߽�x=0������λ�õ�ǰ׺��

	if (y1 == 0) return sum[x2][y2] - sum[x1 - 1][y2];//����߽�y=0������λ�õ�ǰ׺��

	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];//�м�Ԫ�صĶ��ߵ�ǰ׺��

	return 0;

}*/




/////////////////////////////////////////////////////////////////////�����ʵ��

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




/////////////////////��ջ����ģ��
/*#include<iostream>
using namespace std;

typedef struct node {

	int *arr;
	int Top;
	int Maxsize;
}Stack, *Stackpoint;

void Creat(Stackpoint &S,int Maxsize)//�����ն�
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
		cout << "ջ����";
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
		cout << "ջ�ѿ�";
		return;
	}

	else
	return S->arr[S->Top--];

}
*/ 



//////////////////////////��ջ����ģ�� 
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

	Temp->next = T->next;//ͷ�巨 
	T->next = Temp;

}

void Pop(Linklist &T)
{
	if (Isempty(T))
	{
		cout << "ջ�ѿ�";
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




///////////////////////ѭ����������ģ�� 
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
		cout << "��������";
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
		cout << "�����ѿ�";
		return;
	}

	else
	{
		q->front = (q->front + 1) % q->Maxsize;
		return q->arr[q->front];
	}

}*/ 




/////////////////////��������ģ�� 
/*#include<iostream>
using namespace std;

typedef struct node {//���нڵ�

	int value;
	struct node* next;
}LNcode, *Linklist;

typedef struct Node {//����ͷ�ڵ�

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
	if (Isempty(q))//�������Ҫ����β��rear
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
		cout << "�����ѿ�";
		return 0;
	}
	Linklist Temp = q->front;

	if (q->front == q->rear)//ɾ������Ҫ����ͷ��front
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;

	int answer = Temp->value;
	free(Temp);

	return answer;


}*/ 




/////////////////////////˫�����������ģ�� 
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
	for (int i = 2; i <= N; i++)//���²���Ԫ�ص�����Ԫ�أ��������ҵ�����
	{
		cin >> a >> b;
		if (b == 0)//�����
		{
			arr[i].left = arr[a].left;
			arr[i].right = a;
			arr[arr[a].left].right = i;
			arr[a].left = i;
		}
		if (b == 1)//�Ҳ���
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
		if (!Uniquearr[c])//ɾ��Ԫ�أ���������Ԫ��
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
	while (arr[index].right != Maxvalue)//���
	{
		cout << arr[index].right << ' ';
		 index = arr[index].right;
	} 

	return 0;

}*/ 
 



//////////////////////////////////////////////////////////////////////////K M P �㷨
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




///////////////////////////////////////////////////////////���鼯�㷨  �ɺ�����join() ��find()����
/*#include<iostream>
#include<cstdio>
using namespace std;
int pre[5];
int a, b;
int find(int x)                            //�ҵ����׽ڵ�
{
	if (pre[x] == x) return x;             // �����������ҵ������ؽ���
	return pre[x] = find(pre[x]);          //��x�ĸ��׽ڵ㣬�����ǽ����������������ң��ҵ���һ��һ�㷵��x��Ϊǰһ��ĸ��׽ڵ�
}
void join(int x, int y)                    //�ϲ�Ԫ�أ��ںϽ���
{
	if (find(x) == find(y))                //һ�����Ͳ��ò�����
		return;
	else
		pre[find(x)] = find(y);            //��һ�������ִ�ʦ�����ʦ̫Ϊ��������������

}
int main()
{
	for (int i = 1; i <= 4; i++)          //�ʼÿ��Ԫ�ض��ǵ�һ�ģ������Լ��ĸ��׽ڵ㣬Ҳֻ�е�i�ĸ��׽ڵ����Լ�������˵�ҵ�i��Ϊ����
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



/////////////////////////////////////////////////////////��������-��������ģ��
/*#include<iostream>
#define N 9
using namespace std;

int arr[N];
int index[N];
int k,tail, head = 1;
int main()
{
	scanf("%d", &k);
	for (int i = 1; i <= N-1; i++)//��1��ʼ���棬�ȽϷ��㣬ԭ�����±���head=1(Ϊ���ж϶���Ԫ���Ƿ��������)���Ӧ
		scanf("%d", &arr[i]);     //head<=tail ����Ԫ��(��head����ͼ�1��)


	for (int i = 1; i <= N-1; i++)
	{
		while (head <= tail && index[head] <= i - k) head++;//ά�����ڷ�Χ,��ֹ��ֵ���Ǹ��������

		while (head <= tail && arr[index[tail]] >= arr[i]) tail--;//ά�����еĵ�����,���������,��ǰ��Ԫ��(���±�,Ϊ�˷��㴦��)����,ֱ�����㵥����//tail �Ӻ���ά����

			index[++tail] = i;//���㵥������ֱ�Ӽ���,����tail=0,������Ԫ����С(����Ҫ����)//���±꣡

			if (i >= k)//ά�����ڷ�Χ,���������Сֵ��ͷ����Զ����ֵ(��ͺ�����)
				cout << arr[index[head]] << ' ';
	}

	return 0;
}*/


////////////��������-���ֲ���
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

	while (left <= right)//����ģ�� left<=right���в�����
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

//����������
//1.�������������򣬺��򣬲���
//���������鴢�棬����������  
//���������鴢�棬�����ڱ���  
//��֪������������� 
//2.��ѯ��������ֵ�����ֵ����Сֵ
//3.����
//4.ɾ��
//5.Ӧ��:�жϲ�ͬ�������Ƿ����׼����ͬ�����ܷ񹹳���ͬ����
//ƽ�������


///////////////////////////////////////////////�������������
/*
#include<iostream>
using namespace std;

typedef struct node {
	struct node *left;
	char value;
	struct node *right;
}LNcode, *tree;

void Init(tree &p)//��ʼ��������
{ 
	char ch;
	cin >> ch;
	if (ch == '#')//����������������
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
	cout << "�������: " << endl;

	PreOrderTraversal(T);

	return 0;

}
*/


////////////////////////////////////////�������
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

	cout<<"���������"<<endl;
	MidOrderTraversal(T);
    
	return 0;

}
*/

///////////////////////////////////�������

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

	cout << "��������� " << endl;
	BehOrderTraversal(T);

	return 0;
}*/


/////////////////////////////////////�������
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
	
	printf("���ڵ���%d \n", Creat_Ercha_Tree(treearr));
	
	return 0;

}*/




//////////////////////////���������鴢�棬���������� 
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





///////////////////////���������鴢�棬�����ڱ��� 
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





//////////////////////////��֪������������� 
/*#include<iostream>
#include<cstring>
using namespace std;

void Posttraversal(char *PreStr, char *CenStr, int Length)//ǰ��������ʼλ�á�����
{
	if (Length == 0)//��һ�ڵ�
		return;

	int Rootindex = 0;//����

	for (; CenStr[Rootindex] != PreStr[0]; Rootindex++);//ͨ��ǰ��ȥ�����ҵ���������

	Posttraversal(PreStr + 1, CenStr, Rootindex);//�������ݹ�(������ǰ��������ʼλ�á�����)
	Posttraversal(PreStr + Rootindex + 1, CenStr + Rootindex + 1, Length - Rootindex - 1);
	                                             //�������ݹ�(ǰ��������ʼλ�á�����)                               
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




//////////////////////////////////����������������ֵ ���ƶ��ַ���log2 N��

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
			return x; //�������ַ
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


////////////////////////////���������������Сֵ
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


//////////////////////////�����������������
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
	if (!T) //��װ�ڵ�
	{
		T = new LNcode;
		T->value = x;
		T->left = NULL;
		T->right = NULL;
	}
	else
	{
		if (x > T->value)
			T->right = Ercha_Insert_Tree(x, T->right);//���������룬�����ַ
		else if (x < T->value)
			T->left = Ercha_Insert_Tree(x, T->left);  //���������룬�����ַ
	}

	return T; //�Ա㱣���ַ
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


/////////////////////////////////����������ɾ������
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
		T->right = Ercha_Search_Delete_Tree(x, T->right);//�ݹ�������ɾ��
	else if (x < T->value)
		T->left = Ercha_Search_Delete_Tree(x, T->left);//�ݹ�������ɾ��
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



///////////////////////////////////�ܽ��Գ���
/*#include<iostream>
using namespace std;

typedef struct node {

	struct node *left;
	int value;
	struct node *right;
}LNcode, *tree;

void Init(tree &T)//��ʼ��
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

tree Find_Min(tree T)//�ҵ�����������С��Ԫ�� �䵱ɾ���ڵ�
{
	int min = T->value;

	while (T->right)
	{
		if (T->right->value < min)
			T = T->right;
		else break;
	}

	return T;        //������С��������Ԫ�صĵ�ַ ��ɾ���ڵ�ָ����
}


tree Ercha_Search_Insert_Tree(int x,tree &T)//����
{
	if (T == NULL)//����
	{             //��װ�ڵ�
		T = new LNcode;
		T->value = x;
		T->left = NULL;
		T->right = NULL;
	}

	else if (x > T->value) //�ҵ�����λ�ã����в���(����Ҫ���Ǳ������ڵ�λ��)(��ֵ)
		T->right = Ercha_Search_Insert_Tree(x, T->right);
	else if (x < T->value)
		T->left = Ercha_Search_Insert_Tree(x, T->left);

	return T;//���ص�ַ�Ա㱣��

}

tree Ercha_Search_Delete_Tree(int y, tree &T)//ɾ��
{
	tree tem = T;
	if (T == NULL)//�ж�Ԫ���Ƿ����
		cout << "Having no element" << endl;

	else if (y > T->value)
		T->right = Ercha_Search_Delete_Tree(y, T->right);//�ݹ�������ɾ�����ݹ����һ��һ�㷵�ص�ַ���ͼ�ס�����нڵ��λ��
	else if (y < T->value)
		T->left = Ercha_Search_Delete_Tree(y, T->left);  //�ݹ�������ɾ�����ݹ����һ��һ�㷵�ص�ַ���ͼ�ס�����нڵ��λ��
	else //�ҵ����ڵ� ��������� ���Ҷ��� �ջ��Ҷ��� �ջ������
	{
		if (T->left&&T->right)//���Ҷ���
		{
			tem = Find_Min(T->right);//����
			T->value = tem->value;//����ɾ���ҵ��Ľڵ㣬����˵���¸�ֵ ɾ������ڵ�
			T->right = Ercha_Search_Delete_Tree(tem->value, T->right);//������ڵ�ɾ����ת��Ϊ���������
		}
		
		else //�ջ��Ҷ���  �ջ������
		{
			if (!T->left)
				T = T->right;
			else
				T = T->left;
			delete(tem);//ɾ���ڵ�
		}
	}

		return T;//���ص�ַ���Լ�סλ��

}

void PreOrderTraversal(tree T)//��ѯ
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


//ƽ�������(Ҳ��������)�ĵ��� �� 
//RR��ת�����ƻ���A �鷳��B��B��A�����������ұ�
//��ֻ��һ��A��ץס��A 3�ڵ��е� ��֮ �ȴ���������������ɹ������ɣ����� �ʹ����A���е�  (��ת)

//LL��ת�����ƻ���A �鷳��B��B��A�������������
//ͬ��(��ת)

//LR��ת�� ���ƻ���A �鷳��B��B��A���������ұ�
//ץס��A�������ڵ� ���ɶ�����

//RL��ת�� ���ƻ���A  �鷳��B��B��A�����������
//ץס��A�������ڵ� ���ɶ�����



////////////////////////�жϲ�ͬ�������Ƿ����׼����ͬ�����ܷ񹹳���ͬ������һ������ֻ��ȷ��Ψһһ�ö����� ��һ�ö��������ɲ�ͬ���еõ���
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

void Init(tree &T)//��ʼ��
{
	T = NULL; 
	return;
}

tree Ercha_Standard_Tree(int x, tree &T)//������׼������
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

int check(int x, tree T)//����ƥ���׼������
{
	if (T->flag) //��ʾ�Ѳ�ѯ��
	{
		if (x > T->value)
			return check(x, T->right);
		else if (x < T->value)
			return check(x, T->left);

		else return 0; //�����ظ� ������

	}

	else //��ʼ��ѯ
	{
		if (x == T->value)//�ҵ�
		{
			T->flag = 1;//�ҵ��ͱ�Ǹýڵ�
			return 1;
		}

		else return 0;//û�ҵ�

	}

}

void Reset(tree &T)//������е�flag���
{
	
	tree temp1 = T, temp2 = T;
	T->flag = 0;

	while (temp1->left)//���������
	{
		temp1 = temp1->left;
		temp1->flag = 0;
	}

	while (temp2->right)//���������
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
	int Ge_num = 4;//Ԫ�ظ���
	int Xu_num = 2;//���и���

	for (int i = 0; i < Ge_num; i++)//������׼��
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

			if (check(b, T)) counts++;//�����ѯ�� �����Ļ�һ�����ͻ��¼һ�� ������������ͬ

		}
		if (counts == Ge_num) cout << "Yes" << endl;
		else cout << "No" << endl;
		Reset(T);

	}

}
*/

//��
//1.�����С�ѵĲ���(����)
//2.�����С�ѵ�ɾ��
//3.����
//4.���鼯�㷨
//5.�ѵ�Ӧ��-��ӡ·��Ȩֵ
//6.���鼯��Ӧ��-File Transfer


/*#include<iostream>
using namespace std;

const int Maxdata = 10000;//�ڱ��ڵ�


typedef struct stack {

	int *arr;         //����Ԫ������
	int size;         //��ǰԪ�ظ���
	int max_capacity;//�������

}LNcode, *stack_tree;

void Init_Maxheap(stack_tree &T,int Maxsize)
{
	T = new LNcode;
	T->arr = (int *)malloc( (Maxsize+1) * sizeof(int) );
	T->arr[0] = Maxdata;
	T->size = 0;
	T->max_capacity = Maxsize;

}

void Creat_Maxheap_tree(stack_tree &T)//��ʼ����������
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


///////////////////////////////////////////���Ѳ������(Ҳ������)
/*#include<iostream>
using namespace std;

const int start = 1000;

typedef struct node {

	int *arr;
	int Size;//��ǰ����Ԫ�ظ���
	int Max_Capacity;//�����������

}LNcode, *stack_tree;

void Init_MaxHeap(stack_tree &T,int Max_Capacity)//��ʼ���ṹ��
{
	T = new LNcode;
	T->arr = (int *)malloc((Max_Capacity + 1) * sizeof(int));//�±��1��ʼ
	T->arr[0] = start;//�ڱ����
	T->Size = 0;
	T->Max_Capacity = Max_Capacity;
}

void Creat_MaxHeap(stack_tree &T)  //��ʼ������-����
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

void Insert_MaxHeap(stack_tree &T, int item) //�����㷨
{
	int b = T->Size + 1;

	for (; item > T->arr[b / 2] ; b/=2)//���²����
		T->arr[b] = T->arr[b / 2];

	T->arr[b] = item;//�ڱ��ڵ�������
	T->Size++;
}

void Display(stack_tree T) //����
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





//////////////////////////////////////����ɾ������
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

void Delete_Stacktree_Maxelement(stack_tree &T)//ɾ���㷨
{
	int temp = T->arr[T->Size];//�������һ��Ԫ��
	T->Size--;
	int parent, child;

	for (parent = 1; parent * 2 <= T->Size; parent=child)//ɾ��
	{
		child = parent * 2;//�ٶ������Ϊ����²����
		if (child != T->Size//�����������Ҷ���
		&&T->arr[child] < T->arr[child + 1])//�ҳ�������
			child++;//��Ϊ�Ҷ���

		if (temp >= T->arr[child]) break;//������������û��Ҫ������ȥ����Ϊ��������
		else
			T->arr[parent]=T->arr[child];//�����Բ�������ά������

	}
	T->arr[parent] = temp;//ά��������

}

void Traversal(stack_tree T)//����
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




//////////////////////////////////////���鼯�㷨
/*#include<iostream>
using namespace std;

int Parent_arr[1000];

void Init(int Maxsize)//�����������飬����Ԫ�ؼ�Ϊ���׽ڵ�Ȩֵ
{
	for (int i = 1; i <= Maxsize; i++)
		cin >> Parent_arr[i];
}

int find(int x)//�����㷨
{

	if (Parent_arr[x] < 0)//x�ĸ��׽ڵ�
		return Parent_arr[x];//���ظ��׽ڵ��Ȩֵ
	else
		return Parent_arr[x]=find(Parent_arr[x]);//����ʱ���μ�¼���Ƚڵ��Ȩֵ,���Ч��(��ţ!)

}


void Join(int x, int y)//�ϲ��㷨
{
	if (find(x) == find(y))
		return;
	else
		Parent_arr[x] = find(y);//�ڵ���ͬ����ͬһ����
}


int main()
{
	int Maxsize = 8;
	
	Init(Maxsize);
	int a = 1, b = 4;
	if (find(a) == find(b))
		cout<<"����ͬһ����"<<' ';
	else
		Join(a, b);
     
	if (find(a) == find(b))
		cout << "�ϲ������һ��������" << ' ';

	return 0;

}*/






///////////////////////////�ѵ�Ӧ��-��ӡ·��Ȩֵ
/*#include<iostream>
using namespace std;

int Smallest_stacktree[1001];
int Size;

void Insert(int x)//������С��(��׼����)
{

	int i;
	for (i = ++Size; x < Smallest_stacktree[i / 2]; i /= 2)
		Smallest_stacktree[i] = Smallest_stacktree[i / 2];
	     
	Smallest_stacktree[i] = x;
}

void Creat(int Maxsize)//������С��(Ҳ���������)
{
	int element;
	for (int i = 1; i <= Maxsize; i++)//����Ԫ�أ���ʼ��
	{
		cin >> element;
		Insert(element);
	}
}

int main()
{
	Smallest_stacktree[0] = -1000;//�ڱ��ڵ�
	int Maxsize, num;
	cin >> Maxsize >> num;

	Creat(Maxsize);

	for (int i = 0; i < num; i++)//��ѯ����
	{
		int j;
		cin >> j;
		while (Smallest_stacktree[j] >= 0)//�ײ����������Ȩֵ
		{
			cout << Smallest_stacktree[j] << ' ';
			j /= 2;
		}
		puts("");

	}

	return 0;

}*/





///////////////////////////////���鼯Ӧ��-File Transfer
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





//����:
//ð�� ���� ���ǽ�������Ԫ��  //�ȶ�
//ѡ������ ϣ������(ѡȡǡ���ļ�����Ĳ�������) //���ȶ�
//������(ѡ������ĸĽ���������ģ�⣬�൱�����ѵĲ���ɾ���ܽ��Գ���)//���ȶ�
//�鲢����(����:�������������й鲢)(�ݹ� ѭ��)//�ȶ�
//��������//���ȶ�
//��������(Ͱ����������汾)(����������Ͱ���ȷ������ռ��������ɹؼ��ָ�������) ���Ը��Ӷ�


//ð����������O(N) ���O(N^2) �ŵ㣺ʡ�ռ� �ȶ�(Ԫ����ͬ���ύ������ ȱ�㣺��ʱ��

/*#include<iostream>
using namespace std;

const int N = 10;

void  Bubble_sort(int arr[], int N)
{
	for (int p = N - 1; p >= 0; p--)//����ð��
	{
		int flag = 0;

		for (int i = 0; i < p; i++)//һ��ð��
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				flag = 1;//�۲��Ƿ����ź���
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



//������������O(N) ���O(N^2) �ŵ㣺ʡ�ռ� �ȶ��� ȱ�㣺��ʱ��
/*#include<iostream>
using namespace std;

const int N = 10;

void Insertion_sort(int arr[], int N)
{
	int i;
	for (int p = 1;p<N;p++)//arr[0]�������������ϣ��������������
	{
		int temp = arr[p];//�������棬��ֹ����Ҫ������
		for (i = p; i > 0 && temp < arr[i - 1]; i--)
			arr[i] = arr[i - 1];//����ƶ�λ�ã��ڳ�λ��

		arr[i] = temp;//�������
		
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


///////////////////////�鲢���� O(�ȶ�Nlog2N) �ȶ�
/*#include<iostream>
using namespace std;
const int N =4;
typedef int Elementtype;

void Merge(Elementtype arr[], Elementtype Temp[], int Left, int Middle, int Right)
{
	int Leftend = Middle - 1;//��¼����յ�
	int NumElement = Right - Left + 1;//Ԫ�ظ���
	int start = Left;//��¼��ʼλ��

	while (Left <= Leftend && Middle <= Right)//�ϲ�������������
	{
		if (arr[start] <=arr[Middle])
			Temp[start++] = arr[Left++];
		else
			Temp[start++] = arr[Middle++];

	}

	while (Left <= Leftend)//�������ʣ��Ԫ��
		Temp[start++] = arr[Left++];

	while (Right >= Middle)//���ߴ����ұ�ʣ��Ԫ��
		Temp[start++] = arr[Middle++];

	for (int i = 0; i < NumElement; i++, Right--)//���ź����Ԫ�طŽ�ԭ����
		arr[Right] = Temp[Right];


}


void Msort(Elementtype arr[], Elementtype Temp[], int Left, int Right)
{
	int Center = Left + Right >> 1;//ȡ�е�

	if (Left < Right)
	{
		Msort(arr, Temp, Left, Center);   //��ݹ���
		Msort(arr, Temp, Center+1, Right);//�ҵݹ���
		Merge(arr, Temp,Left, Center + 1, Right);//�ϲ�������������
	}

}


void Merge_sort(Elementtype arr[], int N)//�����ӿ�
{
	Elementtype	*Temp;
	Temp = (int*)malloc(N * sizeof(Elementtype));
	if (Temp != NULL)
	{
		Msort(arr, Temp, 0, N - 1);
		free(Temp);//��ϰ��
	}
	else
		cout << "�ռ䲻��" << endl;

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


///////////��������: ����:O(Nlog2N) ���O(N^2) ���ȶ�
/*#include<iostream>
using namespace std;
const int N = 10;
typedef int ElementType;

void Quicksort(ElementType arr[], int Left, int Right)//Left������ʼλ�� Rightĩ��λ��
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

void Quick_sort(ElementType arr[], int N)//�����ӿ�
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





//������:ƽ�����Ӷ�(��С��Nlog2N) ���ȶ�
/*#include<iostream>
using namespace std;

typedef struct node {

	int *arr;
	int Size;
	int Maxsize;
}LNcode, *tree;


void Init_Max_Stacktree(tree &T,int N)//��ʼ������
{
	T = (tree)malloc(sizeof(LNcode));
	T->arr = (int *)malloc( (N + 1) * sizeof(int));
	T->Maxsize = N;
	T->Size = 0;
	T->arr[0] = 1000;
}

void Insert_Smallest_Stacktree(tree &T, int Temp)//���Ѳ������
{
	int i = T->Size;

	for (; Temp > T->arr[i / 2]; i/=2)
		T->arr[i] = T->arr[i / 2];

	T->arr[i] = Temp;

}


void Creat_Max_Stacktree(tree &T ,int N)//��������
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

void DeleteMax_Smallest_Stacktree(tree &T)//����ɾ������
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
	    T->arr[T->Size] = TEmp;//�����Ԫ�أ������ڵ����������ĩβ��ʵ������
		T->arr[Parent] = Temp;
		T->Size--;

}

void Stack_sort(tree &T,int N)//������
{
	for (int i = 1; i <= N; i++)//һ��һ����
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


