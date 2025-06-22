
#include <stdio.h>
#include <stdlib.h>

struct LinkNode
{
	int data;
	struct LinkNode* next;
};

struct LinkNode* creatList()
{
	struct LinkNode* nodehead = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	nodehead->data = -1;
	nodehead->next = NULL;
	return nodehead;
}

int vaildnumber(struct LinkNode* head)
{
	struct LinkNode* t = head;
	int i;
	for (i = 0; t->next != NULL; i++)
	{
		t = t->next;
	}
	return i;
}

struct LinkNode* add(int place, int x, struct LinkNode* head)
{
	struct LinkNode* nodewant = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	//Ϊ�µĽڵ�����һ���ڴ�ռ�
	struct LinkNode* temp = head;//����ȷ��nodewant��ǰ������̽ڵ�
	int p = place;//�����ж�����λ���Ƿ�Ϸ�

	nodewant->data = x;

	int i;
	i = vaildnumber(head);
	if (place < 0 || i < place)  //�ж�����λ���Ƿ�Ϸ�
	{
		printf("***����λ�ò��Ϸ�***");
		return head;
	}

	while (p)
	{
		temp = temp->next;
		p--;
	}
	nodewant->next = temp->next;
	temp->next = nodewant;

	return head;
}

struct LinkNode* changenode(int place, int x, struct LinkNode* head)
{
	struct LinkNode* changenode = head->next;
	int i = vaildnumber(head);
	int p = place;
	if (head->next == NULL)
	{
		printf("����Ϊ�գ��޷��޸ģ��������Ԫ��");
		return head;
	}
	else
	{
		if (place<0 || place>i - 1)
		{
			printf("***�޸�λ�ò��Ϸ�***");
			return head;
		}
		else
		{
			while (p)
			{
				changenode = changenode->next;
				p--;
			}
			changenode->data = x;
			return head;
		}
	}
}

struct LinkNode* del(int place, struct LinkNode* head)
{
	int i = vaildnumber(head);
	if (place > i - 1 || place < 0)
	{
		if (i == 0)
		{
			printf("��������Ԫ�ؿ�ɾ��");
			return head;
		}
		else
		{
			printf("***ɾ��λ�ò��Ϸ�***");
			return head;
		}
	}
	else
	{
		struct LinkNode* temp = head;
		while (place)
		{
			temp = temp->next;
			place--;
		}
		struct LinkNode* deletenode = temp->next;
		temp->next = deletenode->next;
		free(deletenode);
		return head;
	}
}

void print(struct LinkNode* head)
{
	struct LinkNode* temp = head;
	if (temp->next == NULL)
	{
		printf("������û��Ԫ��");
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
			printf("%d", temp->data);
			if (temp->next != NULL)
				printf(" -> ");
		}
	}
}

void freeList(struct LinkNode* head)
{
	struct LinkNode* temp = head;
	while (temp != NULL)
	{
		head = temp->next;
		free(temp);
		temp = head;
	}
}

int main()
{
	struct LinkNode* List = NULL;
	List = creatList();
	List = add(0, 10, List);
	List = add(0, 20, List);
	List = add(0, 30, List);
	List = add(0, 40, List);
	List = del(2, List);
	List = changenode(1, 100, List);
	print(List);
	freeList(List);
	return 0;
}