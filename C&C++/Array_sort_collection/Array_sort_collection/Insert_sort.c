//Copyright 2016 Fyf and Xjw. All Rights Reserved.

#include "custom.h"
#include <stdio.h>
#include <stdlib.h>

void Insert_sort_1(Number *array, BitNum n)//Fyf ����Ԫ�������������ȷλ��
{
	Number temp;
	BitNum i, j;//iָ�������Ԫ��
	for (i = 1; i < n; i++)
	{
		for (j = i; j > 0 && array[j] < array[j - 1]; j--)
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
		}
		//printf("\nfor debug i=%d\n", i);
		//PrintArray(array, n, 1);
		//system("pause");
	}
}

void Insert_sort_2(Number *array, BitNum n)//Fyf �ȱ����ҵ�����λ���ٲ���
{
	Number temp;
	BitNum i, j, cursor;//iָ�������Ԫ��,j����Ѱ�Ҳ�ָ����������һ��ֵ���ڴ�����Ԫ�ص�Ԫ��,cursor���򽫰���jָ���Ԫ�ص�������Ԫ�������1����λ������iָ��Ĵ���������λ����չ������1����λ
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i && array[j] <= array[i]; j++);
		temp = array[i];
		cursor = i;
		for (cursor; cursor > j; cursor--)
		{
			array[cursor] = array[cursor - 1];
		}
		array[j] = temp;
	}
}