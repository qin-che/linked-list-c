#include <stdio.h>
#include <stdlib.h>
struct vector  //动态数组相关参数
{
	int* data;
	int capacity;
};

struct vector* creat_arry()  //初始化动态数组容量，并手动初始化数组元素
{
	int n;
	lable1:
	printf("请输入动态数组初始容量");
	scanf_s("%d", &n);
	if (n > 0)
	{
		struct vector* arry = (struct vector*)malloc(sizeof(struct vector));
		arry->data = (int*)malloc(n * sizeof(int));
		arry->capacity = n;
		for (int i = 0; i <= arry->capacity - 1; i++)
		{
			arry->data[i] = 0;
		}
		return arry;
	}
	else
	{
		printf("错误！初始容量必须大于0，请重新输入");
		goto lable1;
	}
}

struct vector* expansion_capacity(struct vector* arry)
{
	int n;
	lable1:
	printf("请输入想要增加的容量个数");
	scanf_s("%d", &n);
	if (n >= 0)
	{
		int* temp_arry = (int*)malloc((arry->capacity + n) * sizeof(int));
		for (int i = 0; i <= arry->capacity - 1; i++)
		{
			temp_arry[i] = arry->data[i];
		}
		for (int i = arry->capacity; i <= arry->capacity + n - 1; i++)
		{
			temp_arry[i] = 0;
		}
		free(arry->data);
		arry->capacity = arry->capacity + n;
		arry->data = (int*)malloc((arry->capacity) * sizeof(int));
		for (int i = 0; i < arry->capacity; i++)
		{
			arry->data[i] = temp_arry[i];
		}
		free(temp_arry);
		return arry;
	}
	else
	{
		int n0;
		if (n <= -(arry->capacity))
		{
			printf("缩容数据不合法");
			printf("\n");
			return arry;
		}
		printf("输入的数据小于零可能会丢失数据，确定请输入1，重新输入请输入2");
		scanf_s("%d", &n0);
		switch(n0)
		{
		case 1:
		{
			int* temp_arry = (int*)malloc((arry->capacity + n) * sizeof(int));
			for (int i = 0; i <= arry->capacity + n - 1; i++)
			{
				temp_arry[i] = arry->data[i];
			}
			free(arry->data);
			arry->capacity = arry->capacity + n;
			arry->data = (int*)malloc((arry->capacity) * sizeof(int));
			for (int i = 0; i < arry->capacity; i++)
			{
				arry->data[i] = temp_arry[i];
			}
			free(temp_arry);
		}
		break;

		case 2:
		{
			goto lable1;
		}
		break;
		}
		return arry;
	}
}

struct vector* change_data(struct vector* arry , int place ,int x)
{
	if (place > 0 || place < arry->capacity)
	{
		arry->data[place] = x;
		return arry;
	}
	else
	{
		printf("更改位置不存在");
		printf("\n");
		return arry;
	}
}

void print_arry(struct vector* arry)
{
	for (int i = 0; i < arry->capacity; i++)
	{
		printf("%d", arry->data[i]);
		printf("\t");
	}
}

int main()
{
	struct vector* arry = creat_arry();
	for (int i = 0; i < arry->capacity; i++)
	{
		arry->data[i] = i * i - 1;
	}
	arry = expansion_capacity(arry);
	print_arry(arry);
	printf("\n");
	arry = change_data(arry, 4, 71);
	print_arry(arry);
	printf("\n");
	return 0;
}