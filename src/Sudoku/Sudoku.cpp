#include <iostream>
#include <stdlib.h>
#include<fstream>
#include <string>
#include <stdio.h>
#include"grid.h"
#pragma warning(disable:4996)
using namespace std;
int main(int argc, char* argv[])
{
	int m, n;		//文件中n个m宫格
	m = atoi(argv[2]);
	n = atoi(argv[4]);
	char itxt[15] = { '\0' };
	char otxt[15] = { '\0' };
	for (int e = 0; argv[6][e] != '\0'; e++)
		itxt[e] = argv[6][e];
	for (int e = 0; argv[8][e] != '\0'; e++)
		otxt[e] = argv[8][e];
	ifstream in;
	ofstream out;
	in.open(itxt, ios::in);
	out.open(otxt, ios::out);
	grid g;
	g._type(m);
	while (n)
	{
		for(int i=0;i<m;i++)
			for (int j = 0; j < m; j++)
			{
				char c = '\0';
				in >> c;
				int l = c - '0';
				g.get_int(i, j, l);
			}
		g.bianli(0);

		for (int i = 0; i < m; i++)
			{for (int j = 0; j < m; j++)
			{
				int k = g.out_int(i, j);
				char c = '\0';
				c = '0' + k;
				out << c;
				out << ' ';
			}
			out << '\n';}
		out << '\n';
		g._false();
		n--;
			
	}
	return 0;
}