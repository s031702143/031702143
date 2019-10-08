#include "grid.h"
int grid::bianli(int n)//用递归来解决数独
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
		for (int i = 1; i <= type; i++)   //i从1到9一次尝试
		{
			if (Check(n, i) == true)	//成功则填入i,进行下一次搜索
			{
				arr[n / type][n % type] = i;
				bianli(n + 1);
				if (sign == true) return 1;
				arr[n / type][n % type] = 0;     //不成功还原为零，再次进行bianli(n)
			}
		}
	}
}
bool grid::Check(int n, int key)
{
	/*判断第n宫格所在行是否合法 */
	for (int i = 0; i < type; i++)
	{
		/* j为第n宫格的行 */
		int j = n / type;
		if (arr[j][i] == key) return false;
	}
	/* 判断第n宫格所在列是否合法 */
	for (int i = 0; i < type; i++)
	{
		/* j为第n宫格的列 */
		int j = n % type;
		if (arr[i][j] == key) return false;
	}

	/*x为第n宫格所在小m宫格左上角的行*/
	/*y为第n宫格所在小m宫格左上角的行*/
	int x = 0, y = 0;
	switch (type)   /* 判断n所在的小宫格是否合法，对于四宫格六宫格八宫格九宫格，模式一样但参数不同*/
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
	/* 全部合法，返回正确 */
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