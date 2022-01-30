#define _CRT_SECURE_NO_WARNINGS

//散列查找

//散列函数构造
//字符型

/*int Hash_Char(const char *Str, int TableSize)
{
	int h = 0;
	while (*str)
	h = h << 5 + *str++;//级数

	return h / TableSize;

}*/

//数字型

/*int Hash_Count(int Count, int TableSize)
{
	return Count / TableSize;
}*/


//简单查找
/*#include<iostream>
using namespace std;

typedef struct node {//链表结点

	int data;
	struct node  *next;

}LNcode, *Linklist;

typedef struct Node {//Hash表
	int TableSize;
	Linklist arr; //存储链表的数组
}Hashcode, *Hashtable;

int Prime(int x)
{
	if (x % 2 == 0)
		return x + 1;
	else
		return x;

}

int HASH(int value, int TableSize)//哈希函数
{
	return value % TableSize;
}

void Creat_Hashtable(Hashtable &T,int TableSize)//建立空的hash表
{
	T = (Hashtable)malloc(sizeof(Hashcode));
	T->TableSize = Prime(TableSize);
	T->arr = (Linklist)malloc(T->TableSize * sizeof(LNcode));

	for (int i = 0; i < T->TableSize; i++)
	{
		T->arr[i].data = 0;
		T->arr[i].next = NULL;
	}
}

Linklist find(Hashtable  T, int value)//查找关键字位置
{
	int Position;
	Position = HASH(value, T->TableSize);
	Linklist p = T->arr[Position].next;
	while (p&&p->data!=value)
	p = p->next;

	return p;

}

void Insert(Hashtable &T, int value)//插入元素
{
	Linklist Tmp;//指针陷进，指针与副本指针
	int Position;
	Linklist P = find(T, value);
	if (!P)
	{
		Tmp = (Linklist)malloc(sizeof(LNcode));
		Tmp->data = value;
		Tmp->next = NULL;
		Position = HASH(value, T->TableSize);
		T->arr[Position].next = Tmp;

	}
}

int main()
{
	Hashtable T;
	Creat_Hashtable(T, 5);

	for (int i = 0; i < 5; i++)
	{
		int a;
		cin >> a;
		Insert(T, a);
	}
	for (int i = 0; i < 5; i++)
	{
		Linklist q = T->arr[i].next;
		cout << q->data << ' ';
	}

	if (find(T, 9)) cout << "存在";
	else cout << "不存在";

	return 0;

}*/


//散列表应用-电话狂人
/*#include<iostream>
using namespace std;

#define Maxtablesize 100000
#define Keylength 11
#define Inputlength 5
char arr[Keylength + 1];

int max;

//定义单链表
typedef struct node {

	char* Key_arr;
	struct node *next;
	int count = 0;

}LNcode, *Linklist;

//定义哈希表
typedef struct Tnode {

	int TableSize;
	Linklist Heads_arr;

}HashTcode,*HashTable;

//找到>N <=Maxtablesize 的下一个素数
int NextPrime(int N)
{
	int i;
    int p = (N % 2) ? (N + 2) : (N + 1);//除2以外 素数必是奇数 奇数包括素数
	while (p <= Maxtablesize)
	{
		for (i = sqrt(p); i > 2; i--)
			if (!(p%i)) break;//p不是素数

		if (i == 2) return p;//p是素数
		else p += 2;

	}

}

//哈希函数
int HASH(int value, int TableSize)
{
	return value % TableSize;
}

//创建空的哈希表
void Creat_HashTable(HashTable &T,int N)
{
	T = (HashTable)malloc(sizeof(HashTcode));
	T->TableSize = NextPrime(N);
	T->Heads_arr = (Linklist)malloc(T->TableSize * sizeof(LNcode));

	for (int i = 0; i < T->TableSize; i++)
	{
		T->Heads_arr[i].Key_arr = (char *)malloc((Keylength+1)*sizeof(char));
		T->Heads_arr[i].Key_arr[0] = '\0';
		T->Heads_arr[i].next = NULL;
		T->Heads_arr[i].count = 0;

	}
}

//查找函数
Linklist find(HashTable T, char *str)
{
	Linklist p;
	int Position;
	Position = HASH(atoi(str + Keylength - Inputlength), T->TableSize);//字符串转数字
	p = T->Heads_arr[Position].next;

	while (p&&strcmp(p->Key_arr, str))
	{
		p = p->next;
	}

	return p;
}

//插入函数
void Insert(HashTable &T, char *str)
{
	Linklist Tmp,Tmp1;
	Linklist P = find(T, str);
	if (!P)//头插法
	{
		Tmp = (Linklist)malloc(sizeof(LNcode));
		Tmp->Key_arr = (char *)malloc((Keylength + 1) * sizeof(char));
		strcpy(Tmp->Key_arr, str);
		Tmp->count = 1;
		int Position = HASH(atoi(str + Keylength - Inputlength), T->TableSize);
		Tmp1 = T->Heads_arr[Position].next;
		T->Heads_arr[Position].next = Tmp;
		Tmp->next = Tmp1;
		//Tmp->next = NULL;
		//P = Tmp;
	}
	else
	{
		P->count++;
	}
	
}

//输入函数
void Input_Message(HashTable &T, int Num_input)
{
	for (int i = 0; i < Num_input; i++)
	{
		scanf("%s", &arr); Insert(T, arr);
		scanf("%s", &arr); Insert(T, arr);
	}

}

//打印函数
void Output_Answer(HashTable T)
{
	char Answer_arr[Keylength + 1];
	Linklist p;

	for (int i = 0; i < T->TableSize; i++)
	{
		p = T->Heads_arr[i].next;
		while (p)
		{  

			if (p->count > max)
			{
				max = p->count;
				strcpy(Answer_arr, p->Key_arr);
			}
			p = p->next;

		}

	}
	printf("%d\n", max);
	printf("%s", Answer_arr);

}

//手动释放内存
void Destroy_HashTable(HashTable &T)
{
	Linklist p, Tmp;
	for (int i = 0; i < T->TableSize; i++)//释放链表
	{
		p = T->Heads_arr[i].next;
		while (p)
		{
			Tmp = p->next;
			free(p);
			p = Tmp;
		}

	}
	free(T->Heads_arr);//释放头节点数组

}


int main()
{
	HashTable T;
	int N;//记录数
	cin >> N;

	Creat_HashTable(T,N * 2);
	Input_Message(T,N);
	Output_Answer(T);
	Destroy_HashTable(T);

	return 0;
}*/


