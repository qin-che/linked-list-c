
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

int realnumber(struct LinkNode* head)
{
	struct LinkNode* t = head;  
	int i;
	for (i = 0; t->next != NULL; i++)
	{
		t = t->next;
	}
	return i;
}

struct LinkNode* add(int place , int x , struct LinkNode* head)
{
	struct LinkNode* nodewant = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	//Ϊ�µĽڵ�����һ���ڴ�ռ�
	struct LinkNode* temp = head;//����ȷ��nodewant��ǰ������̽ڵ�
	int p = place;//�����ж�����λ���Ƿ�Ϸ�

	nodewant->data = x;

	int i ; 
	i = realnumber(head);
	if(place < 0 || i<place)  //�ж�����λ���Ƿ�Ϸ�
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
			if(temp->next != NULL)
				printf(" -> ");
		}
	}
}

void freeList(struct LinkNode* head)
{
	struct LinkNode* temp= head;
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
	List = add(0,10,List);
	List = add(0,20,List);
	print(List);
	freeList(List);
	return 0;
}