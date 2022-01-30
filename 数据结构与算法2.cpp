#define _CRT_SECURE_NO_WARNINGS

//ɢ�в���

//ɢ�к�������
//�ַ���

/*int Hash_Char(const char *Str, int TableSize)
{
	int h = 0;
	while (*str)
	h = h << 5 + *str++;//����

	return h / TableSize;

}*/

//������

/*int Hash_Count(int Count, int TableSize)
{
	return Count / TableSize;
}*/


//�򵥲���
/*#include<iostream>
using namespace std;

typedef struct node {//������

	int data;
	struct node  *next;

}LNcode, *Linklist;

typedef struct Node {//Hash��
	int TableSize;
	Linklist arr; //�洢���������
}Hashcode, *Hashtable;

int Prime(int x)
{
	if (x % 2 == 0)
		return x + 1;
	else
		return x;

}

int HASH(int value, int TableSize)//��ϣ����
{
	return value % TableSize;
}

void Creat_Hashtable(Hashtable &T,int TableSize)//�����յ�hash��
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

Linklist find(Hashtable  T, int value)//���ҹؼ���λ��
{
	int Position;
	Position = HASH(value, T->TableSize);
	Linklist p = T->arr[Position].next;
	while (p&&p->data!=value)
	p = p->next;

	return p;

}

void Insert(Hashtable &T, int value)//����Ԫ��
{
	Linklist Tmp;//ָ���ݽ���ָ���븱��ָ��
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

	if (find(T, 9)) cout << "����";
	else cout << "������";

	return 0;

}*/


//ɢ�б�Ӧ��-�绰����
/*#include<iostream>
using namespace std;

#define Maxtablesize 100000
#define Keylength 11
#define Inputlength 5
char arr[Keylength + 1];

int max;

//���嵥����
typedef struct node {

	char* Key_arr;
	struct node *next;
	int count = 0;

}LNcode, *Linklist;

//�����ϣ��
typedef struct Tnode {

	int TableSize;
	Linklist Heads_arr;

}HashTcode,*HashTable;

//�ҵ�>N <=Maxtablesize ����һ������
int NextPrime(int N)
{
	int i;
    int p = (N % 2) ? (N + 2) : (N + 1);//��2���� ������������ ������������
	while (p <= Maxtablesize)
	{
		for (i = sqrt(p); i > 2; i--)
			if (!(p%i)) break;//p��������

		if (i == 2) return p;//p������
		else p += 2;

	}

}

//��ϣ����
int HASH(int value, int TableSize)
{
	return value % TableSize;
}

//�����յĹ�ϣ��
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

//���Һ���
Linklist find(HashTable T, char *str)
{
	Linklist p;
	int Position;
	Position = HASH(atoi(str + Keylength - Inputlength), T->TableSize);//�ַ���ת����
	p = T->Heads_arr[Position].next;

	while (p&&strcmp(p->Key_arr, str))
	{
		p = p->next;
	}

	return p;
}

//���뺯��
void Insert(HashTable &T, char *str)
{
	Linklist Tmp,Tmp1;
	Linklist P = find(T, str);
	if (!P)//ͷ�巨
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

//���뺯��
void Input_Message(HashTable &T, int Num_input)
{
	for (int i = 0; i < Num_input; i++)
	{
		scanf("%s", &arr); Insert(T, arr);
		scanf("%s", &arr); Insert(T, arr);
	}

}

//��ӡ����
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

//�ֶ��ͷ��ڴ�
void Destroy_HashTable(HashTable &T)
{
	Linklist p, Tmp;
	for (int i = 0; i < T->TableSize; i++)//�ͷ�����
	{
		p = T->Heads_arr[i].next;
		while (p)
		{
			Tmp = p->next;
			free(p);
			p = Tmp;
		}

	}
	free(T->Heads_arr);//�ͷ�ͷ�ڵ�����

}


int main()
{
	HashTable T;
	int N;//��¼��
	cin >> N;

	Creat_HashTable(T,N * 2);
	Input_Message(T,N);
	Output_Answer(T);
	Destroy_HashTable(T);

	return 0;
}*/


