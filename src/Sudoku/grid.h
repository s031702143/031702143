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
		type = x;					//д�빬���ʽ
	}
	void get_int(int, int, int);   //һ�δζ�ȡ��д������
	int out_int(int, int);
	void _false()
	{
		sign = false;
	}
};

