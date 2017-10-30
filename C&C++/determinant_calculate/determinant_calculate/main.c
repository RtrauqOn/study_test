//Copyright 2016 Fyf All rights reserved.

/*
˵������������ʽ������������ʽ��ֵ������ָ���
*
create_date:2016/05/22
*
last_edit_date:2016/06/04
*/

//======================================================/
#include <stdio.h>
#include <stdlib.h>
//======================================================/
typedef int Number;
typedef int RCNum;
typedef int COUNTER;
typedef int FLAG;
//======================================================/
RCNum Input2mem(Number ***p);
void Print_det(RCNum n, Number *det);
Number Calc_det_dictionary(RCNum n, Number *det);
Number Calc_det_recursion(RCNum n, Number *det);
void recursion_proc(RCNum n, Number *det, Number *mul_ptr, RCNum *list, RCNum deep);
//======================================================/
int main()
{
	Number *det, result, **poi = NULL;//poiΪ����ָ�����,��ָ��ָ��(ָ��ָ������ڴ��׵�ַ��ָ�����det)�ĵ�ַ,�Ҹ�ָ������ĵ�ַ��Input2mem()�ľֲ�ָ�����p��ָ��ָ��.
	RCNum n;
	n = Input2mem(&poi);//ȡָ�����poi�ĵ�ַ���ݸ��β�
	det = *poi;//�˴�ָ�����poi��ȡֵ�����ΪInput2mem()�е�ָ�����det,���ʽ��(Input2mem()�е�ָ�����det)��ָ��ָ���ַ����(main()�е�ָ�����det)��ָ��ָ���ַ,����detָ�������ָ���ָ�������ڴ�,����������ָ������ĵ�ַ��ͬ,Ϊ������ͬ�ı���.
	printf("\n");
	Print_det(n, det);
	result = Calc_det_recursion(n, det);
	printf("\nresult=%d\n", result);
	free(det);
	system("pause");
	return 0;
}

//*p��poi, *poi��det(Input2mem()�����е�), det(main()�����е�) == det(Input2mem()�����е�), but,&det(main()�����е�) != &det(Input2mem()�����е�),���������det��ͬ��ַ����ͬһ��ָ�����
//p->poi(�ڴ��е�����)->det(Input2mem()�����е�),p == &poi, poi == &det(Input2mem()�����е�)

RCNum Input2mem(Number ***p)//pΪ����ָ�����,��ָ��ָ��main()�оֲ�ָ�����poi�ĵ�ַ(ʵ��)
{
	RCNum n, i, r, c;
	printf("input n\n");
	scanf_s("%d", &n);
	Number *det = calloc(n*n, sizeof(Number));
	*p = &det;//�˴�ָ�����p��ȡֵ�����Ϊָ�����poi,�ñ��ʽ��ָ�����poi��ָ��ָ����ָ�����det�ĵ�ַ
	printf("please input\n");
	for (i = 0, r = 0, c = 0; i < n*n; i++)
	{
		r = i / n;
		c = i - r * n;
		printf("input r[%d]c[%d]=", r + 1, c + 1);
		scanf_s("%d", det + i);
	}
	return n;
}

void Print_det(RCNum n, Number *det)
{
	RCNum i;
	printf("Print_determinant:\n");
	for (i = 0; i < n*n; i++)
	{
		printf("%d", det[i]);
		if ((i + 1) % n == 0) printf("\n");
		else printf(" ");
	}
}

Number Calc_det_dictionary(RCNum n, Number *det)
{
	RCNum r, c, bit, set;
	RCNum *list = (RCNum *)calloc(n, sizeof(RCNum));
	Number add = 0, inv_num = 0, mul = 1;
	COUNTER ctr;
	FLAG cbflag = 0, addflag = 0, sign = 1;//��λ
	for (bit = 0; bit < n; bit++) list[bit] = n - bit;
	//printf("\nfor debug\n");//for debug
	//for (int i = 0; i < n; i++) printf("%d", list[i]);//for debug
	for (ctr = 0;; ctr++)
	{
	//=================================================================/	
		if (ctr != 0)
		{
			bit = 0;//����
			list[bit]++;
		}
		if (list[bit] > n)//�����λ
		{
			list[bit] -= n;
			for (bit = 1, cbflag = 1; bit < n; bit++)
			{
				if (cbflag)
				{
					cbflag = 0;
					list[bit]++;
				}
				if (list[bit] > n)
				{
					list[bit] -= n;
					cbflag = 1;
				}
			}
			if (cbflag) break;//
		}//end
	//=================================================================/
		for (bit = 0, addflag = 1; bit < n; bit++)//�ۼ������ж�
		{
			for (set = 0; set < n; set++)
			{
				if (bit == set) continue;
				if (list[bit] == list[set])
				{
					addflag = 0;
					break;
				}
			}
			if (addflag == 0) break;
		}//end
	//=================================================================/
		if (addflag)//�ۼ�
		{
			for (bit = 0, inv_num = 0; bit < n; bit++)//���������÷���
			{
				for (set = bit + 1; set < n; set++)
				{
					if (list[bit] > list[set]) inv_num++;
				}
			}
			if (inv_num % 2 == 1) sign = -1;
			else sign = 1;//end
			//printf("\nfor debug\n");//for debug
			//for (int i = 0; i < n; i++) printf("%d", list[i]);//for debug
			//printf("\n");//for debug
			for (r = 0, mul = sign; r < n; r++)//��ͬ�����۳�
			{
				c = list[r] - 1;
				mul *= det[r * n + c];
				//printf("for debug r=%dc=%d,det=%d\n", r, c, det[r * 3 + c]);//for debug
			}
			add += mul;//end
			//printf("add+=%d\n", mul);//for debug
		}//end
	}
	free(list);
	return add;
}

Number Calc_det_recursion(RCNum n, Number *det)
{
	Number add = 0;
	RCNum cursor;
	RCNum *record = (RCNum *)calloc(n*n, sizeof(RCNum));
	for (cursor = 0; cursor < n; cursor++)
	{
		*(record + n*cursor) = cursor + 1;
		recursion_proc(n, det, &add, record + n*cursor, 0);
	}
	free(record);
	return add;
}

void recursion_proc(RCNum n, Number *det, Number *add_ptr, RCNum *list, RCNum deep)
{
	RCNum num, cursor, set, r, c;
	Number inv_num, mul = 1;
	FLAG jmp_flag = 0, add_flag = 0, sign = 1;
	//============================================================================/
	for (num = 1; num <= n; num++)//����ȡֵȫ����
	{
		for (cursor = 0; cursor <= deep; cursor++)
		{
			if (list[cursor] == num)
			{
				jmp_flag = 1;
				break;
			}
		}
		if (jmp_flag)
		{
			jmp_flag = 0;
			continue;
		}
		list[deep + 1] = num;
		if (deep + 1 == n - 1)
		{
			add_flag = 1;
			break;
		}
		recursion_proc(n, det, add_ptr, list, deep + 1);
	}//end
	//============================================================================/
	if (add_flag)
	{
		add_flag = 0;
		for (cursor = 0, inv_num = 0; cursor < n; cursor++)//���������÷���
		{
			for (set = cursor + 1; set < n; set++)
			{
				if (list[cursor] > list[set]) inv_num++;
			}
		}
		if (inv_num % 2 == 1) sign = -1;
		else sign = 1;//end
		for (r = 0, mul = sign; r < n; r++)//��ͬ�����۳�
		{
			c = list[r] - 1;
			mul *= det[r * n + c];
		}
		*add_ptr += mul;//end
	}
}
