#include "grid.h"
int grid::bianli(int n)//�õݹ����������
{
	if (sign)  return 1;
	if (n >= type * type)
	{
		sign = true;
		return 1;
	}
	if (arr[n / type][n % type] != 0)
	{
		bianli(n + 1);
	}
	else
	{
		for (int i = 1; i <= type; i++)   //i��1��9һ�γ���
		{
			if (Check(n, i) == true)	//�ɹ�������i,������һ������
			{
				arr[n / type][n % type] = i;
				bianli(n + 1);
				if (sign == true) return 1;
				arr[n / type][n % type] = 0;     //���ɹ���ԭΪ�㣬�ٴν���bianli(n)
			}
		}
	}
}
bool grid::Check(int n, int key)
{
	/*�жϵ�n�����������Ƿ�Ϸ� */
	for (int i = 0; i < type; i++)
	{
		/* jΪ��n������� */
		int j = n / type;
		if (arr[j][i] == key) return false;
	}
	/* �жϵ�n�����������Ƿ�Ϸ� */
	for (int i = 0; i < type; i++)
	{
		/* jΪ��n������� */
		int j = n % type;
		if (arr[i][j] == key) return false;
	}

	/*xΪ��n��������Сm�������Ͻǵ���*/
	/*yΪ��n��������Сm�������Ͻǵ���*/
	int x = 0, y = 0;
	switch (type)   /* �ж�n���ڵ�С�����Ƿ�Ϸ��������Ĺ���������˹���Ź���ģʽһ����������ͬ*/
	{
	case'4': {
		x = n / 4 / 2 * 2;
		y = n % 4 / 2 * 2;
		for (int i = x; i < x + 2; i++)
			for (int j = y; j < y + 2; j++)
				if (arr[i][j] == key) return false;
	}; break;
	case'6': {
		x = n / 6 / 2 * 2;
		y = n % 6 / 3 * 3;
		for (int i = x; i < x + 2; i++)
			for (int j = y; j < y + 3; j++)
				if (arr[i][j] == key) return false;
	}; break;
	case'8': {
		x = n / 8 / 4 * 4;
		y = n % 8 / 2 * 2;
		for (int i = x; i < x + 4; i++)
			for (int j = y; j < y + 2; j++)
				if (arr[i][j] == key) return false;
	}; break;
	case'9': {
		x = n / 9 / 3 * 3;
		y = n % 9 / 3 * 3;
		for (int i = x; i < x + 3; i++)
			for (int j = y; j < y + 3; j++)
				if (arr[i][j] == key) return false;
	}; break;
	default:
		break;
	}
	/* ȫ���Ϸ���������ȷ */
	return true;
}
void grid::get_int(int x, int y, int num)
{
	arr[x][y] = num;
}
int grid::out_int(int i, int j)
{
	return arr[i][j];
}