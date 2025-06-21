# 链表实现（C语言）

这是一个简单的带头节点的单链表实现，包含以下功能：

- 创建链表头节点
- 在指定位置添加节点
- 打印链表内容
- 释放链表内存

## 使用示例

```c
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
	//为新的节点申请一份内存空间
	struct LinkNode* temp = head;//用于确定nodewant的前驱、后继节点
	int p = place;//用于判断输入位置是否合法

	nodewant->data = x;

	int i ; 
	i = realnumber(head);
	if(place < 0 || i<place)  //判断输入位置是否合法
	{
		printf("***输入位置不合法***");
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
		printf("链表中没有元素");
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

int main() {
    struct LinkNode* list = creatList();
    list = add(0, 10, list);
    list = add(0, 20, list);
    print(list); // 输出: 20 -> 10
    freeList(list);
    return 0;
}