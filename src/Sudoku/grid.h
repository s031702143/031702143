#pragma once
class grid
{
private:
	int arr[9][9] = { 0 };
	bool sign = false;
	int type;
public:
	bool Check(int,int);
	int bianli(int);
	void _type(int x)
	{
		type = x;					//写入宫格格式
	}
	void get_int(int, int, int);   //一次次读取，写入数组
	int out_int(int, int);
	void _false()
	{
		sign = false;
	}
};

