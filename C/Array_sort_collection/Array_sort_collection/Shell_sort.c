//Copyright 2016 Fyf and Xjw. All Rights Reserved.

#include "custom.h"
#include <stdio.h>
#include <stdlib.h>

void Shell_sort_1(Number *array, BitNum n)//Fyf
{
	Number temp;
	BitNum d, head, group, cursor;//dΪ����,��d����,headָ��ÿ��ͷλԪ��,group����ָ���ͷλԪ�ص�ÿ���Ԫ��,cursorָ��������ÿ�ε���λԪ��
	Counter ctr = 0;
	for (d = n / 2; d > 0; d /= 2)//ѡȡ����d
	{
		for (head = 0; head < d; head++)//��d����,headָ��ÿ��ͷλԪ��,ÿ����head��1,����[0-(d-1)]
		{
			for (group = head + d; group < n; group += d)//ÿ����group��d,�˺�ʼ����direct Insert sort
			{
				for (cursor = group; cursor > head && array[cursor] < array[cursor - d]; cursor -= d)//����ֱ����ȷλ��
				{
					temp = array[cursor];
					array[cursor] = array[cursor - d];
					array[cursor - d] = temp;
					ctr++;
				}
			}
			//printf("\nfor debug d=%d,head=%d\n", d, head);
			//PrintArray(array, n, 1);
			//system("pause");
		}
	}
	printf("\nCounter=%d\n", ctr);
}

void Shell_sort_2(Number *array, BitNum n)//���ϵ�,�����㷨������
{
	Number temp;
	BitNum d, i, j;
	Counter ctr = 0;
	for (d = n / 2; d > 0; d /= 2)
	{
		for (i = d; i < n; i++)
		{
			for (j = i - d; j >= 0 && array[j] > array[j + d]; j -= d)
			{
				temp = array[j];
				array[j] = array[j + d];
				array[j + d] = temp;
				ctr++;
			}
			//printf("\nfor debug d=%d,i=%d\n", d, i);
			//PrintArray(array, n, 1);
			//system("pause");
		}
	}
	printf("\nCounter=%d\n", ctr);
}

