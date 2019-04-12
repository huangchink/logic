#include<iostream>
#include<string>
#include <vector>  
#include <fstream>
#include<math.h>
using namespace std;
void twogetmap(int two[2][2])//2變數的輸出
{
	cout << "=====Kmap=====" << endl;
	cout << "  \\ A|       |" << endl;
	cout << " B \\ |  0  1 |" << endl;
	cout << "-----+---+---+\n";
	cout << "  0  | "; if (two[0][0] == 4) { cout << 'x'; }
	else { cout << two[0][0]; }; cout << " | "; if (two[0][1] == 4) { cout << 'x'; }
	else { cout << two[0][1]; }cout << " | " << endl;
	cout << "-----+---+---+\n";
	cout << "  1  | "; if (two[1][0] == 4) { cout << 'x'; }
	else { cout << two[1][0]; }cout << " | "; if (two[1][1] == 4) { cout << 'x'; }
	else {
		cout << two[1][1];
	}cout << " | " << endl;
	cout << "-----+---+---+\n";
}
void threegetmap(int three[2][4])//3變數的輸出
{
	cout << "=========Kmap=========" << endl;
	cout << "  \\AB|               |" << endl;
	cout << " C \\ | 00  01  11  10|" << endl;
	cout << "-----+---+---+---+---+\n";
	cout << " 0   |"; if (three[0][0] == 8) { cout << 'x'; }
	else { cout << three[0][0]; } cout << "  | "; if (three[0][1] == 8) { cout << 'x'; }
	else { cout << three[0][1]; } cout << " | "; if (three[0][2] == 8) { cout << 'x'; }
	else {
		cout << three[0][2];
	} cout << " | "; if (three[0][3] == 8) { cout << 'x'; }
		else {
			cout << three[0][3];
		} cout<< " | " << endl;

	cout << "-----+---+---+---+---+\n";
	cout << " 1   |"; if (three[1][0] == 8) { cout << 'x'; }
	else { cout << three[1][0]; }cout << "  | "; if (three[1][1] == 8) { cout << 'x'; }
	else { cout << three[1][1]; } cout << " | "; if (three[1][2] == 8) { cout << 'x'; }
	else { cout << three[1][2]; }  cout << " | ";  if (three[1][3] == 8) { cout << 'x'; }
	else { cout << three[1][3]; } cout<< " | " << endl;
	cout << "-----+---+---+---+---+\n";
}

void fourgetmap(int four[4][4])//四變數的輸出
{
	cout << "=========Kmap=========" << endl;
	cout << "  \\AB|               |" << endl;
	cout << "CD \\ | 00  01  11  10|" << endl;
	cout << "-----+---+---+---+---+\n";
	cout << " 00  | "; if (four[0][0] == 16) { cout << 'x'; }
	else { cout << four[0][0]; } cout << " | "; if (four[0][1] == 16) { cout << 'x'; }
	else { cout << four[0][1]; }cout << " | ";  if (four[0][2] == 16) { cout << 'x'; }
	else {
		cout << four[0][2];
	} cout << " | "; if (four[0][3] == 16) { cout << 'x'; }
	else {
		cout << four[0][3];
	} cout<< " |" << endl;
	cout << "-----+---+---+---+---+\n";
	cout << " 01  | "; if (four[1][0] == 16) { cout << 'x'; }
	else { cout << four[1][0]; } cout << " | "; if (four[1][1] == 16) { cout << 'x'; }
	else { cout << four[1][1]; }cout << " | "; if (four[1][2] == 16) { cout << four[1][2]; }
	else { cout << four[1][2]; }cout << " | "; if (four[1][3] == 16) { cout << 'x'; }
	else {
		cout << four[1][3];
	} cout<< " |" << endl;
	cout << "-----+---+---+---+---+\n";
	cout << " 11  | ";  if (four[2][0] == 16) { cout << 'x'; }
	else { cout << four[2][0]; } cout << " | "; if (four[2][1] == 16) { cout << 'x'; }
	else { cout << four[2][1]; }cout << " | "; if (four[2][2] == 16) { cout << 'x'; }
	else { cout << four[2][2]; }cout << " | "; if (four[2][3] == 16) { cout << 'x'; }
	else {
		cout << four[2][3];
	} cout<< " |" << endl;
	cout << "-----+---+---+---+---+\n";
	cout << " 10  | "; if (four[3][0] == 16) { cout << 'x'; }
	else { cout << four[3][0]; } cout << " | "; if (four[3][1] == 16) { cout << 'x'; }
	else { cout << four[3][1]; }cout << " | "; if (four[3][2] == 16) { cout << 'x'; }
	else { cout << four[3][2]; }cout << " | "; if (four[3][3] == 16) { cout << 'x'; }
	else { cout << four[3][3]; } cout<< " |" << endl;
	cout << "-----+---+---+---+---+\n";



}
void twoterm(int two[2][2])//處理二變數
{
	int sum = 0;
	int count[2][2] = { { 0,0 },{ 0,0 } };//存 圈到幾次
	int casetwo[4] = { 0,0,0,0 }; //圈兩個的
	for (int i = 0; i <2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if ((two[i][j] == 1) || two[i][j] == 4)//我把dont care設4
			{
				sum++;
			}
		}
	}
	//如果全部都是1或dontcare，則直接output 1
	if (sum == 4)
	{
		cout << endl;
		cout << "F(A,B)=1" << endl;
	}
	else
	{
		//橫的兩個相連
		if ((two[0][0] == 1 || two[0][0] == 4) && (two[0][1] == 1 || two[0][1] == 4))//上
		{
			count[0][0]++; count[0][1]++;
			casetwo[0]++;
		}
		if ((two[1][0] == 1 || two[1][0] == 4) && (two[1][1] == 1 || two[1][1] == 4))//下
		{
			count[1][0]++; count[1][1]++;
			casetwo[1]++;
		}
		//直的兩個相連
		if ((two[0][0] == 1 || two[0][0] == 4) && (two[1][0] == 1 || two[1][0] == 4))//左
		{
			count[0][0]++; count[1][0]++;
			casetwo[2]++;
		}
		if ((two[0][1] == 1 || two[0][1] == 4) && (two[1][1] == 1 || two[1][1] == 4))//右
		{
			count[0][1]++; count[1][1]++;
			casetwo[3]++;
		}


		cout << endl;
		cout << "prime implicant :";
		for (int i = 0; i < 3; i++)
		{
			if (casetwo[i] == 1)
			{
				switch (i)
				{
				case 0:
					cout << "b',";
					break;
				case 1:
					cout << "b,"; break;
				case 2:
					cout << "a',"; break;
				case 3:
					cout << "a,"; break;

				}
			}
		}
		if ((two[0][0] == 1) && (casetwo[0] == 0) && (casetwo[2] == 0))//只圈到一次且只有自己
		{
			cout << "a'b',";
		}


		if ((two[0][1] == 1) && (casetwo[0] == 0) && (casetwo[3] == 0))//只圈到一次且只有自己
		{
			cout << "ab',";
		}


		if ((two[1][0] == 1) && casetwo[1] == 0 && casetwo[2] == 0)//只圈到一次且只有自己
		{
			cout << "a'b,";
		}
		if ((two[1][1] == 1)&& casetwo[3] == 0 && casetwo[1] == 0)//只圈到一次且只有自己
		{
			cout << "ab";
		}
		
		cout << endl;
		cout << "essential prime implicant :";

		for (int i = 0; i < 3; i++)
		{
			if (casetwo[i] == 1)
			{
				switch (i)
				{
				case 0:
					cout << "b',";
					break;
				case 1:
					cout << "b,"; break;
				case 2:
					cout << "a',"; break;
				case 3:
					cout << "a,"; break;

				}
			}
		}
		if ((two[0][0] == 1) && (casetwo[0] == 0) && (casetwo[2] == 0))//只圈到一次且只有自己
		{
			cout << "a'b',";
		}


		if ((two[0][1] == 1) && (casetwo[0] == 0) && (casetwo[3] == 0))//只圈到一次且只有自己
		{
			cout << "ab',";
		}


		if ((two[1][0] == 1) && casetwo[1] == 0 && casetwo[2] == 0)//只圈到一次且只有自己
		{
			cout << "a'b,";
		}
		if ((two[1][1] == 1) && casetwo[3] == 0 && casetwo[1] == 0)//只圈到一次且只有自己
		{
			cout << "ab";
		}
		cout << endl;
		cout << "F(A,B):";

		for (int i = 0; i < 3; i++)
		{
			if (casetwo[i] == 1)
			{
				switch (i)
				{
				case 0:
					cout << "b'+";
					break;
				case 1:
					cout << "b+"; break;
				case 2:
					cout << "a'+"; break;
				case 3:
					cout << "a+"; break;

				}
			}
		}
		if ((two[0][0] == 1) && (casetwo[0] == 0) && (casetwo[2] == 0))//只圈到一次且只有自己
		{
			cout << "a'b'+";
		}


		if ((two[0][1] == 1) && (casetwo[0] == 0) && (casetwo[3] == 0))//只圈到一次且只有自己
		{
			cout << "ab'+";
		}


		if ((two[1][0] == 1) && casetwo[1] == 0 && casetwo[2] == 0)//只圈到一次且只有自己
		{
			cout << "a'b+";
		}
		if ((two[1][1] == 1) && casetwo[3] == 0 && casetwo[1] == 0)//只圈到一次且只有自己
		{
			cout << "ab";
		}
	}

}

void threeterm(int three[2][4])
{

	int sum = 0;
	int count[2][4] = { { 0,0,0,0 },{ 0,0,0,0 } };//存圈到幾次，essential要用的
	int casefour_rod[2] = { 0,0 }; //圈四個的bar
	int casefour_square[4] = { 0 };//圈四個的井字
	int casetwo_ho[8] = { 0 };//圈兩個的 水平
	int casetwo_ver[4] = { 0 };//圈兩個的 垂直
	for (int i = 0; i <2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if ((three[i][j] == 1) || three[i][j] == 8)//我把dont care設8
			{
				sum++;
			}
		}
	}
	//如果全部都是1或dontcare，則直接output 1
	if (sum == 8)
	{
		cout << endl;
		cout << "F(A,B,c)=1" << endl;
	}
	else
	{
		for (int i = 0; i < 2; i++)//上下兩個長條
		{
			if ((three[i][0] == 1 || three[i][0] == 8) && (three[i][1] == 1 || three[i][1] == 8) &&
				(three[i][2] == 1 || three[i][2] == 8) && (three[i][3] == 1 || three[i][3] == 8))
			{
				casefour_rod[i] = 1;
				count[i][0]++; count[i][1]++; count[i][2]++; count[i][3]++;
			}
		}
		for (int i = 0; i < 3; i++)//田型四格
		{
			if ((three[0][i] == 1 || three[0][i] == 8) && (three[0][i + 1] == 1 || three[0][i + 1] == 8) &&
				(three[1][i] == 1 || three[1][i] == 8) && (three[1][i + 1] == 1 || three[1][i + 1] == 8))
			{
				casefour_square[i] = 1;
				count[0][i]++; count[0][i + 1]++; count[1][i]++; count[1][i + 1]++;
			}
		}

		if ((three[0][0] == 1 || three[0][0] == 8) && (three[0][3] == 1 || three[0][3] == 8) &&
			(three[1][0] == 1 || three[1][0] == 8) && (three[1][3] == 1 || three[1][3] == 8))
		{
			casefour_square[3] = 1;
			count[0][0]++; count[0][3]++; count[1][0]++; count[1][3]++;
		}


		//-------兩格(左右)共8個
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((three[i][j] == 1 ||three[i][j]==8)&&( three[i][j + 1] == 1||three[i][j+1]==8) && casefour_square[j] != 1 && casefour_rod[i] != 1)
				{
					casetwo_ho[j]++; count[i][j]++; count[i][j + 1]++;
				}
			}
		}
		if ((three[0][0] == 1 ||three[0][0]==8)&& (three[0][3] == 1||three[0][3]==8) && casefour_square[3] != 1 &&casefour_rod[0]!=1)
		{
			casetwo_ho[3]++; count[0][0]++; count[0][3]++;

		}


		for (int i = 1; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((three[i][j] == 1||three[i][j]==8) && (three[i][j + 1] == 1||three[i][j+1]==8 )&& casefour_square[j] != 1 && casefour_rod[i] != 1)
				{
					casetwo_ho[j + 4]++; count[i][j]++; count[i][j + 1]++;
				}
			}
		}
		if ((three[1][0] == 1||three[1][0]==8 )&& (three[1][3] == 1||three[1][3]==8) && casefour_square[3] != 1&&casefour_rod[1]!=1)
		{
			casetwo_ho[7]++; count[0][0]++; count[0][3]++;

		}

		//兩格 上下的

		
			

				if ((three[0][0] == 1||three[0][0]==8) && (three[1][0] == 1||three[1][0]==8) && casefour_square[0] != 1 &&casefour_square[3]!=1)
				{
					casetwo_ver[0]++; count[0][0]++; count[1][0]++;
				}
				if ((three[0][1] == 1 || three[0][1] == 8) && (three[1][1] == 1 || three[1][1] == 8) && casefour_square[0] != 1 &&casefour_square[1]!=1)
				{
					casetwo_ver[1]++; count[0][1]++; count[1][1]++;
				}
				if ((three[0][2] == 1 || three[0][2] == 8) && (three[1][2] == 1 || three[1][2] == 8) && casefour_square[1] != 1&&casefour_square[2]!=1)
				{
					casetwo_ver[2]++; count[0][2]++; count[1][2]++;
				}
			
			if ((three[0][3] == 1 ||three[0][3]==8)&& (three[1][3] == 1||three[1][3]==8) && casefour_square[3] != 1 &&casefour_square[2]!=1)
			{
				casetwo_ver[3]++; count[0][3]++; count[1][3]++;
			}
		cout << endl;
		cout << "prime implicant :";
		//OUTPUT 圈四個的PRIME
		for (int i = 0; i < 2; i++)
		{
			if (casefour_rod[i] == 1)
			{
				switch (i)
				{
				case 0:
					cout << "c',";
					break;
				case 1:
					cout << "c,";
					break;


				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (casefour_square[i] == 1)
			{
				switch (i)
				{
				case 0:
					cout << "a',";
					break;
				case 1:
					cout << "b,";
					break;
				case 2:
					cout << "a,";
					break;
				case 3:
					cout << "b',";
					break;



				}
			}


		}
		//output 圈兩個的prime
		for (int j = 0; j < 8; j++)
		{

			if (casetwo_ho[j] == 1)
			{
				switch (j)
				{
				case 0:
					cout << "a'c',";
					break;
				case 1:
					cout << "bc',";
					break;
				case 2:
					cout << "ac',";
					break;
				case 3:
					cout << "b'c',";
					break;
				case 4:
					cout << "a'c,";
					break;
				case 5:
					cout << "bc,";
					break;
				case 6:
					cout << "ac,";
					break;

				case 7:

					cout << "b'c,";


				}

			}

		}

		
		for (int j = 0; j < 4; j++)
		{
			if (casetwo_ver[j] == 1)
			{
				switch (j)
				{
				case 0:
					cout << "a'b',";
					break;
				case 1:
					cout << "a'b,";
					break;
				case 2:
					cout << "ab,";
					break;
				case 3:
					cout << "ab'";
					break;
				}
			}
		}
	
				if (three[0][0] == 1 &&casefour_rod[0]==0&&casefour_square[0]==0&&casefour_square[3]==0&&casetwo_ho[0]==0&&casetwo_ver[0]==0&&casetwo_ho[3]==0)
				{
					cout << "a'b'c'";
				}
				if (three[0][1] == 1 && casefour_rod[0] == 0 && casefour_square[0] == 0 &&casefour_square[1]==0&& casetwo_ho[0] == 0 && casetwo_ver[1]==0 && casetwo_ho[1] == 0)
				{
					cout << "a'b c'";
				}
				if (three[0][2] == 1 && casefour_rod[0] == 0 && casefour_square[1] == 0 && casefour_square[2] == 0 && casetwo_ho[1] == 0 && casetwo_ver[2]==0 && casetwo_ho[2] == 0)
				{
					cout << "a b c'";
				}
				if (three[0][3] == 1 && casefour_rod[0] == 0 && casefour_square[2] == 0 && casefour_square[3] == 0 && casetwo_ho[2] == 0 && casetwo_ver[3]==0 && casetwo_ho[3] == 0)
				{
					cout << "a b'c'";
				}
				if (three[1][0] == 1 && casefour_rod[1] == 0 && casefour_square[0] == 0 && casefour_square[3] == 0 && casetwo_ho[4] == 0 && casetwo_ver[0]==0 && casetwo_ho[7] == 0)
				{
					cout << "a b'c'";
				}
				if (three[1][1] == 1 && casefour_rod[1] == 0 && casefour_square[0] == 0 && casefour_square[1] == 0 && casetwo_ho[4] == 0 && casetwo_ver[1]==0 && casetwo_ho[5] == 0)
				{
					cout << "a'b c'";
				}

				if (three[1][2] == 1 && casefour_rod[1] == 0 && casefour_square[1] == 0 && casefour_square[2] == 0 && casetwo_ho[5] == 0 && casetwo_ver[2]==0 && casetwo_ho[6] == 0)
				{
					cout << "a b c ";
				}
				if (three[1][3] == 1 && casefour_rod[1] == 0 && casefour_square[2] == 0 && casefour_square[3] == 0 && casetwo_ho[6] == 0 && casetwo_ver[3]==0 && casetwo_ho[7] == 0)
				{
					cout << "a b'c";
				}






		cout << endl;
		cout << "essential prime implicant :";           //3變數的prime implicant 跟essential一樣，Output同上
		//OUTPUT 圈四個的PRIME
		for (int i = 0; i < 2; i++)
		{
			if (casefour_rod[i] == 1)
			{
				switch (i)
				{
				case 0:
					cout << "c',";
					break;
				case 1:
					cout << "c,";
					break;


				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (casefour_square[i] == 1)
			{
				switch (i)
				{
				case 0:
					cout << "a',";
					break;
				case 1:
					cout << "b,";
					break;
				case 2:
					cout << "a,";
					break;
				case 3:
					cout << "b',";
					break;



				}
			}


		}
		//output 圈兩個的prime
		for (int j = 0; j < 8; j++)
		{

			if (casetwo_ho[j] == 1)
			{
				switch (j)
				{
				case 0:
					cout << "a'c',";
					break;
				case 1:
					cout << "bc',";
					break;
				case 2:
					cout << "ac',";
					break;
				case 3:
					cout << "b'c',";
					break;
				case 4:
					cout << "a'c,";
					break;
				case 5:
					cout << "bc,";
					break;
				case 6:
					cout << "ac,";
					break;

				case 7:

					cout << "b'c,";


				}

			}

		}


		for (int j = 0; j < 4; j++)
		{
			if (casetwo_ver[j] == 1)
			{
				switch (j)
				{
				case 0:
					cout << "a'b',";
					break;
				case 1:
					cout << "a'b,";
					break;
				case 2:
					cout << "ab,";
					break;
				case 3:
					cout << "ab'";
					break;
				}
			}
		}
		if (three[0][0] == 1 && casefour_rod[0] == 0 && casefour_square[0] == 0 && casefour_square[3] == 0 && casetwo_ho[0] == 0 && casetwo_ver[0] == 0 && casetwo_ho[3] == 0)
		{
			cout << "a'b'c'";
		}
		if (three[0][1] == 1 && casefour_rod[0] == 0 && casefour_square[0] == 0 && casefour_square[1] == 0 && casetwo_ho[0] == 0 && casetwo_ver[1] == 0 && casetwo_ho[1] == 0)
		{
			cout << "a'b c'";
		}
		if (three[0][2] == 1 && casefour_rod[0] == 0 && casefour_square[1] == 0 && casefour_square[2] == 0 && casetwo_ho[1] == 0 && casetwo_ver[2] == 0 && casetwo_ho[2] == 0)
		{
			cout << "a b c'";
		}
		if (three[0][3] == 1 && casefour_rod[0] == 0 && casefour_square[2] == 0 && casefour_square[3] == 0 && casetwo_ho[2] == 0 && casetwo_ver[3] == 0 && casetwo_ho[3] == 0)
		{
			cout << "a b'c'";
		}
		if (three[1][0] == 1 && casefour_rod[1] == 0 && casefour_square[0] == 0 && casefour_square[3] == 0 && casetwo_ho[4] == 0 && casetwo_ver[0] == 0 && casetwo_ho[7] == 0)
		{
			cout << "a b'c'";
		}
		if (three[1][1] == 1 && casefour_rod[1] == 0 && casefour_square[0] == 0 && casefour_square[1] == 0 && casetwo_ho[4] == 0 && casetwo_ver[1] == 0 && casetwo_ho[5] == 0)
		{
			cout << "a'b c'";
		}

		if (three[1][2] == 1 && casefour_rod[1] == 0 && casefour_square[1] == 0 && casefour_square[2] == 0 && casetwo_ho[5] == 0 && casetwo_ver[2] == 0 && casetwo_ho[6] == 0)
		{
			cout << "a b c ";
		}
		if (three[1][3] == 1 && casefour_rod[1] == 0 && casefour_square[2] == 0 && casefour_square[3] == 0 && casetwo_ho[6] == 0 && casetwo_ver[3] == 0 && casetwo_ho[7] == 0)
		{
			cout << "a b'c";
		}
		cout << endl;
		cout << "F(A,B,C)=";
		for (int i = 0; i < 2; i++)
		{
			if (casefour_rod[i] == 1)
			{
				switch (i)
				{
				case 0:
					cout << "c'+";
					break;
				case 1:
					cout << "c+";
					break;


				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (casefour_square[i] == 1)
			{
				switch (i)
				{
				case 0:
					cout << "a'+";
					break;
				case 1:
					cout << "b+";
					break;
				case 2:
					cout << "a+";
					break;
				case 3:
					cout << "b'+";
					break;



				}
			}


		}
		//output 圈兩個的prime
		for (int j = 0; j < 8; j++)
		{

			if (casetwo_ho[j] == 1)
			{
				switch (j)
				{
				case 0:
					cout << "a'c'+";
					break;
				case 1:
					cout << "bc'+";
					break;
				case 2:
					cout << "ac'+";
					break;
				case 3:
					cout << "b'c'+";
					break;
				case 4:
					cout << "a'c+";
					break;
				case 5:
					cout << "bc+";
					break;
				case 6:
					cout << "ac+";
					break;

				case 7:

					cout << "b'c+";


				}

			}

		}


		for (int j = 0; j < 4; j++)
		{
			if (casetwo_ver[j] == 1)
			{
				switch (j)
				{
				case 0:
					cout << "a'b'+";
					break;
				case 1:
					cout << "a'b+";
					break;
				case 2:
					cout << "ab+";
					break;
				case 3:
					cout << "ab'+";
					break;
				}
			}
		}
		if (three[0][0] == 1 && casefour_rod[0] == 0 && casefour_square[0] == 0 && casefour_square[3] == 0 && casetwo_ho[0] == 0 && casetwo_ver[0] == 0 && casetwo_ho[3] == 0)
		{
			cout << "a'b'c'+";
		}
		if (three[0][1] == 1 && casefour_rod[0] == 0 && casefour_square[0] == 0 && casefour_square[1] == 0 && casetwo_ho[0] == 0 && casetwo_ver[1] == 0 && casetwo_ho[1] == 0)
		{
			cout << "a'b c'+";
		}
		if (three[0][2] == 1 && casefour_rod[0] == 0 && casefour_square[1] == 0 && casefour_square[2] == 0 && casetwo_ho[1] == 0 && casetwo_ver[2] == 0 && casetwo_ho[2] == 0)
		{
			cout << "a b c'+";
		}
		if (three[0][3] == 1 && casefour_rod[0] == 0 && casefour_square[2] == 0 && casefour_square[3] == 0 && casetwo_ho[2] == 0 && casetwo_ver[3] == 0 && casetwo_ho[3] == 0)
		{
			cout << "a b'c'+";
		}
		if (three[1][0] == 1 && casefour_rod[1] == 0 && casefour_square[0] == 0 && casefour_square[3] == 0 && casetwo_ho[4] == 0 && casetwo_ver[0] == 0 && casetwo_ho[7] == 0)
		{
			cout << "a b'c'+";
		}
		if (three[1][1] == 1 && casefour_rod[1] == 0 && casefour_square[0] == 0 && casefour_square[1] == 0 && casetwo_ho[4] == 0 && casetwo_ver[1] == 0 && casetwo_ho[5] == 0)
		{
			cout << "a'b c'+";
		}

		if (three[1][2] == 1 && casefour_rod[1] == 0 && casefour_square[1] == 0 && casefour_square[2] == 0 && casetwo_ho[5] == 0 && casetwo_ver[2] == 0 && casetwo_ho[6] == 0)
		{
			cout << "a b c+ ";
		}
		if (three[1][3] == 1 && casefour_rod[1] == 0 && casefour_square[2] == 0 && casefour_square[3] == 0 && casetwo_ho[6] == 0 && casetwo_ver[3] == 0 && casetwo_ho[7] == 0)
		{
			cout << "a b'c";
		}

	}

}







void fourterm(int four[4][4])
{
	int sum = 0;
	int count[4][4] = { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
	int caseeight[8] = { 0,0,0,0,0,0,0,0 };
	int casefour_bar[8] = { 0,0,0,0,0,0,0,0 };
	int casetwo[32] = {0};
	int casefour_square[16] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (four[i][j] == 1)
			{
				sum++;
			}
		}
	}
	if (sum == 16)
	{
		cout << "F(A,B,C)=1";
	}
	else   //橫條 長條 (1*4)
	{
		for (int i = 0; i<4; i++)
		{
			if ((four[i][0] == 1 || four[i][0] == 16) && (four[i][1] == 1 || four[i][1] == 16) &&
				(four[i][2] == 1 || four[i][2] == 16) && (four[i][3] == 1 || four[i][3] == 16))
			{
				casefour_bar[i] = 1;
				count[i][0]++; count[i][1]++; count[i][2]++; count[i][3]++;
			}
			if ((four[0][i] == 1 || four[0][i] == 16) && (four[1][i] == 1 || four[1][i] == 16) &&
				(four[2][i] == 1 || four[2][i] == 16) && (four[3][i] == 1 || four[3][i] == 16))
			{
				casefour_bar[i + 4] = 1;
				count[0][i]++; count[1][i]++; count[2][i]++; count[3][i]++;
			}
		}
		//8 case prime implicant
		for (int i = 0; i<4; i++)
		{
			//horizontal
			if (casefour_bar[i] == 1 && casefour_bar[(i + 1 == 4) ? 0 : i + 1] == 1)
			{
				caseeight[i] = 1;
				casefour_bar[i]--; casefour_bar[(i + 1 == 4 ? 0 : i + 1)]--;
				
			}
			//vertical
			if (casefour_bar[i + 4] == 1 && casefour_bar[(i + 5 == 8) ? 4 : i + 5] == 1)
			{
				caseeight[i + 4] = 1;
				casefour_bar[i + 4]--; casefour_bar[(i + 5 == 8 ? 4 : i + 5)]--;
				cout << "fuck";
			}
		}

		//square
		int k = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((four[i][j] == 1 || four[i][j] == 16) && (four[i][j + 1] == 1 || four[i][j + 1] == 16) && (four[i + 1][j] == 1 || four[i + 1][j] == 16) && (four[i + 1][j + 1] == 1 || four[i + 1][j + 1] == 16))
				{
					casefour_square[k]= 1;
					

				}
				k++;
			}
		}
		if ((four[0][0] == 1 || four[0][0] == 16) && (four[0][3] == 1 || four[0][3] == 16) && (four[1][3] == 1 || four[1][3] == 16) && (four[1][0] == 1 || four[1][0] == 16))
		{
		
			casefour_square[9] = 1;
		
		}
		if ((four[1][0] == 1 || four[1][0] == 16) && (four[1][3] == 1 || four[1][3] == 16) && (four[2][3] == 1 || four[2][3] == 16) && (four[2][0] == 1 || four[2][0] == 16))
		{

			casefour_square[10] = 1;

		}
		if ((four[2][0] == 1 || four[2][0] == 16) && (four[2][3] == 1 || four[2][3] == 16) && (four[3][3] == 1 || four[3][3] == 16) && (four[3][0] == 1 || four[3][0] == 16))
		{

			casefour_square[11] = 1;

		}
		
	
	if ((four[0][0] == 1 || four[0][0] == 16) && (four[0][1] == 1 || four[0][1] == 16) && (four[3][0] == 1 || four[3][0] == 16) && (four[3][1] == 1 || four[3][1] == 16))
	{

		casefour_square[12] = 1;

	}
	if ((four[0][1] == 1 || four[0][1] == 16) && (four[0][2] == 1 || four[0][2] == 16) && (four[3][1] == 1 || four[3][1] == 16) && (four[3][2] == 1 || four[3][2] == 16))
	{

		casefour_square[13] = 1;

	}
	if ((four[0][2] == 1 || four[0][2] == 16) && (four[0][3] == 1 || four[0][3] == 16) && (four[3][2] == 1 || four[3][2] == 16) && (four[3][3] == 1 || four[3][3] == 16))
	{

		casefour_square[14] = 1;

	}
	if ((four[0][0] == 1 || four[0][0] == 16) && (four[3][0] == 1 || four[3][0] == 16) && (four[3][3] == 1 || four[3][3] == 16) && (four[0][3] == 1 || four[0][3] == 16))
	{

		casefour_square[15] = 1;

	}
	
			if (casefour_square[0] != 1 && casefour_square[12]!=1&&casefour_bar[0] != 1&&(four[0][0]==1||four[0][0]==16)&&(four[0][1]==1||four[0][1]==16)&&caseeight[0]!=1&&caseeight[3]!=1)
			{
				casetwo[0]++;
				
			}
			if (casefour_square[1] != 1 && casefour_square[13] != 1 && casefour_bar[0] != 1 && (four[0][1] == 1||four[0][1]==16) && (four[0][2] == 1||four[0][2]==16) && caseeight[0] != 1 && caseeight[3] != 1)
			{
				casetwo[1]++;

			}
			if (casefour_square[2] != 1 && casefour_square[14] != 1 && casefour_bar[0] != 1 &&( four[0][2] == 1||four[0][2]==16) && (four[0][3] == 1||four[0][3]==16) && caseeight[0] != 1 && caseeight[3] != 1)
			{
				casetwo[2]++;

			}
			if (casefour_square[0] != 1 && casefour_square[3] != 1 && casefour_bar[1] != 1 && (four[1][0] == 1||four[1][0]==16) && (four[1][1] == 1||four[1][1]==16) && caseeight[0] != 1 && caseeight[1] != 1)
			{
				casetwo[3]++;

			}
			if (casefour_square[1] != 1 && casefour_square[4] != 1 && casefour_bar[1] != 1 &&( four[1][1] == 1||four[1][1]==16) && (four[1][2] == 1||four[1][2]==16) && caseeight[0] != 1 && caseeight[1] != 1)
			{
				casetwo[4]++;

			}
			if (casefour_square[2] != 1 && casefour_square[5] != 1 && casefour_bar[1] != 1 && (four[1][2] == 1||four[1][2]==16) && (four[1][3] == 1 ||four[1][3]==16)&& caseeight[0] != 1 && caseeight[1] != 1)
			{
				casetwo[5]++;

			}
			if (casefour_square[3] != 1 && casefour_square[6] != 1 && casefour_bar[2] != 1 &&( four[2][0] == 1 ||four[2][0]==16)&& (four[2][1] == 1||four[2][1]==16) && caseeight[1] != 1 && caseeight[2] != 1)
			{
				casetwo[6]++;

			}
			if (casefour_square[4] != 1 && casefour_square[7] != 1 && casefour_bar[2] != 1 &&( four[2][1] == 1||four[2][1]==16) &&( four[2][2] == 1||four[2][2]==16) && caseeight[1] != 1 && caseeight[2] != 1)
			{
				casetwo[7]++;

			}
			if (casefour_square[5] != 1 && casefour_square[8] != 1 && casefour_bar[2] != 1 && (four[2][2] == 1||four[2][2]==16) && (four[2][3] == 1||four[2][3]==16) && caseeight[1] != 1 && caseeight[2] != 1)
			{
				casetwo[8]++;

			}

			if (casefour_square[6] != 1 && casefour_square[12] != 1 && casefour_bar[3] != 1 &&( four[3][0] == 1 ||four[3][0]==16)&&( four[3][1] == 1||four[3][1]==16) && caseeight[2] != 1 && caseeight[3] != 1)
			{
				casetwo[9]++;

			}
			if (casefour_square[7] != 1 && casefour_square[13] != 1 && casefour_bar[3] != 1 &&( four[3][1] == 1 ||four[3][1]==16)&& (four[3][2] == 1||four[3][2]==16) && caseeight[2] != 1 && caseeight[3] != 1)
			{
				casetwo[10]++;

			}
			if (casefour_square[8] != 1 && casefour_square[14] != 1 && casefour_bar[3] != 1 && (four[3][2] == 1||four[3][2]==16) &&( four[3][3] == 1||four[3][3]==16) && caseeight[2] != 1 && caseeight[3] != 1)
			{
				casetwo[11]++;

			}


			if (casefour_square[11] != 1 && casefour_square[9] != 1 && casefour_bar[0] != 1 &&( four[0][0] == 1||four[0][0]==16) &&( four[0][3] == 1||four[0][3]==16) && caseeight[0] != 1 && caseeight[3] != 1)
			{
				casetwo[12]++;

			}
			if (casefour_square[10] != 1 && casefour_square[9] != 1 && casefour_bar[1] != 1 &&( four[1][0] == 1||four[1][0]==16) &&( four[1][3] == 1||four[1][3]==16) && caseeight[0] != 1 && caseeight[1] != 1)
			{
				casetwo[13]++;

			}
			if (casefour_square[11] != 1 && casefour_square[10] != 1 && casefour_bar[2] != 1 && (four[2][0] == 1||four[2][0]==16) &&( four[2][3] == 1||four[2][3]==16) && caseeight[1] != 1 && caseeight[2] != 1)
			{
				casetwo[14]++;

			}
			if (casefour_square[11] != 1 && casefour_square[15]!=1 && casefour_bar[3] != 1 && (four[3][0] == 1||four[3][0]==16) &&( four[3][3] == 1||four[3][3]==16) && caseeight[2] != 1 && caseeight[3] != 1)
			{
				casetwo[15]++;

			}
			if (casefour_bar[4]!=1&&casefour_square[0] != 1 && casefour_square[9]!=1 &&  (four[0][0] == 1 ||four[0][0]==16)&& (four[1][0] == 1||four[1][0]==16) && caseeight[0] != 1 )
			{
				casetwo[16]++;

			}

			if (casefour_bar[5] != 1&&casefour_square[0] != 1 && casefour_square[1]!=1 && (four[0][1] == 1||four[0][1]==16) &&( four[1][1] == 1||four[1][1]==16) && caseeight[0] != 1)
			{
				casetwo[17]++;

			}
			if (casefour_bar[6] != 1&&casefour_square[1] != 1 && casefour_square[2] != 1 && (four[0][2] == 1 ||four[0][2]==16)&&( four[1][2] == 1||four[1][2]==16) && caseeight[0] != 1)
			{
				casetwo[18]++;

			}
			if (casefour_bar[7] != 1&&casefour_square[2] != 1 && casefour_square[9] != 1 && (four[0][3] == 1||four[0][3]==16) && (four[1][3] == 1||four[1][3]==16) && caseeight[0] != 1)
			{
				casetwo[19]++;

			}
			if (casefour_bar[4] != 1&&casefour_square[3] != 1 && casefour_square[10] != 1 &&( four[1][0] == 1||four[1][0]==16) && (four[2][0] == 1||four[2][0]==16) && caseeight[1] != 1)
			{
				casetwo[20]++;

			}
			if (casefour_bar[5] != 1&&casefour_square[3] != 1 && casefour_square[4] != 1 &&( four[1][1] == 1||four[1][1]==16) && (four[2][1] == 1||four[2][1]==16) && caseeight[1] != 1)
			{
				casetwo[21]++;

			}
			if (casefour_bar[6] != 1 && casefour_square[4] != 1 && casefour_square[5] != 1 && (four[1][2] == 1||four[1][2]==16) && (four[2][2] == 1||four[2][2]==16) && caseeight[1] != 1)
			{
				casetwo[22]++;

			}
			if (casefour_bar[7] != 1 && casefour_square[5] != 1 && casefour_square[10] != 1 && (four[1][3] == 1||four[1][3]==16) && (four[2][3] == 1||four[2][3]==16) && caseeight[1] != 1)
			{
				casetwo[23]++;

			}
			if (casefour_bar[4] != 1 && casefour_square[6] != 1 && casefour_square[11] != 1 && (four[2][0] == 1||four[2][0]==16) && (four[3][0] == 1||four[3][0]==16) && caseeight[2] != 1)
			{
				casetwo[24]++;

			}
			if (casefour_bar[5] != 1 && casefour_square[6] != 1 && casefour_square[7] != 1 && (four[2][1] == 1||four[2][1]==16) &&( four[3][1] == 1||four[3][1]==16) && caseeight[2] != 1)
			{
				casetwo[25]++;

			}
			if (casefour_bar[6] != 1 && casefour_square[7] != 1 && casefour_square[8] != 1 && (four[2][2] == 1 ||four[2][2]==16)&& (four[3][2] == 1||four[3][2]==16) && caseeight[2] != 1)
			{
				casetwo[26]++;

			}
			if (casefour_bar[7] != 1 && casefour_square[8] != 1 && casefour_square[11] != 1 && (four[2][3] == 1||four[2][3]==16) && (four[3][3] == 1 ||four[3][3]==16)&& caseeight[2] != 1)
			{
				casetwo[27]++;

			}
			if (casefour_bar[4] != 1 && (four[0][0] == 1||four[0][0]==16 )&& (four[3][0] == 1||four[3][0]==16) && casefour_square[12] != 1 && casefour_square[15] != 1 && caseeight[3] != 1)
			{
				casetwo[28]++;
			}
			if (casefour_bar[5] != 1 && (four[0][1] == 1 ||four[0][1]==16)&& (four[3][1] == 1||four[3][1]==16) && casefour_square[12] != 1 && casefour_square[13] != 1 && caseeight[3] != 1)
			{
				casetwo[29]++;
			}
			if (casefour_bar[6] != 1 && (four[0][2] == 1||four[0][2]==16 )&&( four[3][2] == 1||four[3][2]==16) && casefour_square[13] != 1 && casefour_square[14] != 1 && caseeight[3] != 1)
			{
				casetwo[30]++;
			}
			if (casefour_bar[7] != 1 && (four[0][3] == 1||four[0][3]==16) && (four[3][3] == 1||four[3][3]==16) && casefour_square[15] != 1 && casefour_square[14] != 1 && caseeight[3] != 1)
			{
				casetwo[31]++;
			}
			//test
			for (int i = 0; i<8; i++)
			{
				cout << casefour_bar[i] << " ";
			}
			cout << endl;
			for (int i = 0; i<16; i++)
			{
				cout << casefour_square[i] << " ";
			}
			cout << endl;
			for (int i = 0; i<4; i++)
			{
				cout << caseeight[i] << " ";
			}
			cout << endl;
			for (int i = 0; i<32; i++)
			{
				cout << casetwo[i]<<" ";
			
			}
				//endtest
	//輸出prime implicant
			cout << "prime implicant:";
			for (int i = 0; i < 4; i++)
			{
				if (caseeight[i]==1)
				{
					switch (i)
					{
					case 0:
						cout << "c', ";
						break;
					case 1:
						cout << "d,";
						break;
					case 2:
						cout << "c,";
						break;
					case 3:
						cout << "d',";
						break;
					}
				}
			
			
			
			}
			for (int i = 0; i < 8; i++)
			{
				if (casefour_bar[i] == 1)
				{
					switch (i)
					{
					case 0:
						cout << "c'd',";
						break;
					case 1:
						cout << "c'd,";
						break;
					case 2:
						cout << "cd,";
							break;
					case 3:
						cout << "cd',";
						break;
					case 4:
						cout << "a'b',";
						break;
					case 5:
						cout << "a'b,";
						break;
					case 6:
						cout << "ab,";
						break;
					case 7:
						cout << "ab',";
						break;



					}
				}
			}
			for (int i = 0; i < 16; i++)
			{
				if (casefour_square[i] == 1)
				{

					switch (i)
					{
					case 0:
						cout << "a'c',";
						break;
					case 1:
						cout << "bc',";
						break;
					case 2:
						cout << "ac',";
						break;
					case 3:
						cout << "a'd,";
						break;
					case 4:
						cout << "bd,";
						break;
					case 5:
						cout << "ad,";
						break;
					case 6:
						cout << "a'c,";
						break;
					case 7:
						cout << "bc,";
					case 8:
						cout << "ac,";
						break;
					case 9:
						cout << "b'c',";
						break;
					case 10:
						cout << "b'd,";
						break;
					case 11:
						cout << "b'c,";
						break;
					case 12:
						cout << "a'd',";
						break;
					case 13:
						cout << "bd',";
						break;
					case 14:
						cout << "ad',";
						break;
					case 15:
						cout << "b'd',";
						break;


					}

				}





			}

			for (int i = 0; i < 32; i++)
			{
				if (casetwo[i] == 1)
				{
					switch (i)
					{
					case 0:
						cout << "a'c'd',";
						break;
					case 1:
						cout << "bc'd',";
						break;
					case 2:
						cout << "ac'd',";
						break;
					case 3:
						cout << "a'c'd,";
						break;
					case 4:
						cout << "bc'd,";
						break;
					case 5:
						cout << "ac'd";
						break;
					case 6:
						cout << "a'cd,";
						break;
					case 7:
						cout << "bcd";
						break;
					case 8:
						cout << "acd,";
						break;
					case 9:
						cout << "a'cd',";
						break;
					case 10:
						cout << "bcd',";
						break;
					case 11:
						cout << "acd',";
						break;
					case 12:
						cout << "b'c'd',";
						break;
					case 13:
						cout << "b'c'd,";
						break;
					case 14:
						cout << "b'cd,";
						break;
					case 15:
						cout << "b'cd',";
						break;
					case 16:
						cout << "a'b'c',";
						break;
					case 17:
						cout << "a'bc',";
						break;
					case 18:
						cout << "abc',";
						break;
					case 19:
						cout << "ab'c',";
						break;
					case 20:
						cout << "a'b'd,";
						break;
					case 21:
						cout << "a'bd,";
						break;
					case 22:
						cout << "abd,";
						break;
					case 23:
						cout << "ab'd,";
						break;
					case 24:
						cout << "a'b'c,";
						break;
					case 25:
						cout << "a'bc,";
						break;
					case 26:
						cout << "abc,";
						break;
					case 27:
						cout << "ab'c,";
						break;
					case 28:
						cout << "a'b'd',";
						break;
					case 29:
						cout << "a'bd',";
						break;
					case 30:
						cout << "abd',";
						break;
					case 31:
						cout << "ab'd',";
						break;



					}
				}
			}

			if (casefour_bar[4]!=1&& four[0][0] == 1 && casetwo[0] != 1 && casetwo[12] != 1 && casetwo[16] != 1 && casetwo[28] != 1 && casefour_bar[0] != 1 && casefour_square[0] != 1 && casefour_square[9] != 1 && casefour_square[15] != 1 && casefour_square[12] != 1 && caseeight[0] != 1 && caseeight[3] != 1)
			{
				cout << "a'b'c'd',";
			}
			if (casefour_bar[5] != 1&&four[0][1] == 1 && casetwo[0] != 1 && casetwo[1] != 1 && casetwo[17] != 1 && casetwo[29] != 1 && casefour_bar[0] != 1 && casefour_square[12] != 1 && casefour_square[13] != 1&&casefour_square[1]!=1 && casefour_square[0] != 1 && caseeight[0] != 1 && caseeight[3] != 1)
			{
				cout << "a'b c'd',";
			}
			if (casefour_bar[6] != 1 && four[0][2] == 1 && casetwo[1] != 1 && casetwo[2] != 1 && casetwo[30] != 1 && casetwo[18] != 1 && casefour_bar[0] != 1 && casefour_square[13] != 1 && casefour_square[14] != 1 && casefour_square[1] != 1 && casefour_square[2] != 1 && caseeight[0] != 1 && caseeight[3] != 1)
			{
				cout << "abc'd',";
			}
			if (casefour_bar[7] != 1 && four[0][3] == 1 && casetwo[2] != 1 && casetwo[12] != 1 && casetwo[31] != 1 && casetwo[19] != 1 && casefour_bar[0] != 1 && casefour_square[9] != 1 && casefour_square[15] != 1 && casefour_square[14] != 1 && casefour_square[2] != 1 && caseeight[0] != 1 && caseeight[3] != 1)
			{
				cout << "ab'c'd',";
			}

			if (casefour_bar[4] != 1 && four[1][0] == 1 && casetwo[3] != 1 && casetwo[13] != 1 && casetwo[16] != 1 && casetwo[20] != 1 && casefour_bar[1] != 1 && casefour_square[0] != 1 && casefour_square[3] != 1 && casefour_square[9] != 1 && casefour_square[10] != 1 && caseeight[0] != 1 && caseeight[1] != 1)
			{
				cout << "a'b'c'd,";
			}
			if (casefour_bar[5] != 1 && four[1][1] == 1 && casetwo[3] != 1 && casetwo[4] != 1 && casetwo[17] != 1 && casetwo[21] != 1 && casefour_bar[1] != 1 && casefour_square[0] != 1 && casefour_square[1] != 1 && casefour_square[3] != 1 && casefour_square[4] != 1 && caseeight[0] != 1 && caseeight[1] != 1)
			{
				cout << "a'bc'd,";
			}
			if (casefour_bar[6] != 1 && four[1][2] == 1 && casetwo[4] != 1 && casetwo[5] != 1 && casetwo[18] != 1 && casetwo[22] != 1 && casefour_bar[1] != 1 && casefour_square[1] != 1 && casefour_square[2] != 1 && casefour_square[4] != 1 && casefour_square[5] != 1 && caseeight[0] != 1 && caseeight[1] != 1)
			{
				cout << "abc'd,";
			}
			if (casefour_bar[7] != 1 && four[1][3] == 1 && casetwo[5] != 1 && casetwo[13] != 1 && casetwo[19] != 1 && casetwo[23] != 1 && casefour_bar[1] != 1 && casefour_square[10] != 1 && casefour_square[2] != 1 && casefour_square[5] != 1 && casefour_square[9] != 1 && caseeight[0] != 1 && caseeight[1] != 1)
			{
				cout << "ab'c'd,";
			}


			if (casefour_bar[4] != 1 && four[2][0] == 1 && casetwo[6] != 1 && casetwo[14] != 1 && casetwo[20] != 1 && casetwo[24] != 1 && casefour_bar[2] != 1 && casefour_square[3] != 1 && casefour_square[6] != 1 && casefour_square[10] != 1 && casefour_square[11] != 1 && caseeight[1] != 1 && caseeight[2] != 1)
			{
				cout << "a'b'cd,";
			}
			if (casefour_bar[5] != 1 && four[2][1] == 1 && casetwo[6] != 1 && casetwo[7] != 1 && casetwo[21] != 1 && casetwo[25] != 1 && casefour_bar[2] != 1 && casefour_square[3] != 1 && casefour_square[4] != 1 && casefour_square[6] != 1 && casefour_square[7] != 1 && caseeight[1] != 1 && caseeight[2] != 1)
			{
				cout << "a'bcd,";
			}
			if (casefour_bar[6] != 1 && four[2][2] == 1 && casetwo[7] != 1 && casetwo[8] != 1 && casetwo[22] != 1 && casetwo[26] != 1 && casefour_bar[2] != 1 && casefour_square[4] != 1 && casefour_square[5] != 1 && casefour_square[7] != 1 && casefour_square[8] != 1 && caseeight[1] != 1 && caseeight[2] != 1)
			{
				cout << "abcd,";
			}
			if (casefour_bar[7] != 1 && four[2][3] == 1 && casetwo[8] != 1 && casetwo[14] != 1 && casetwo[23] != 1 && casetwo[27] != 1 && casefour_bar[2] != 1 && casefour_square[8] != 1 && casefour_square[5] != 1 && casefour_square[10] != 1 && casefour_square[11] != 1 && caseeight[1] != 1 && caseeight[2] != 1)
			{
				cout << "ab'cd,";
			}


			if (casefour_bar[4] != 1 && four[3][0] == 1 && casetwo[9] != 1 && casetwo[15] != 1 && casetwo[24] != 1 && casetwo[28] != 1 && casefour_bar[3] != 1 && casefour_square[11] != 1 && casefour_square[6] != 1 && casefour_square[12] != 1 && casefour_square[15] != 1 && caseeight[2] != 1 && caseeight[3] != 1)
			{
				cout << "a'b'cd',";
			}

			if (casefour_bar[5] != 1 && four[3][1] == 1 && casetwo[9] != 1 && casetwo[10] != 1 && casetwo[25] != 1 && casetwo[29] != 1 && casefour_bar[3] != 1 && casefour_square[6] != 1 && casefour_square[7] != 1 && casefour_square[12] != 1 && casefour_square[13] != 1 && caseeight[2] != 1 && caseeight[3] != 1)
			{
				cout << "a'bcd',";
			}

			if (casefour_bar[6] != 1 && four[3][2] == 1 && casetwo[10] != 1 && casetwo[11] != 1 && casetwo[26] != 1 && casetwo[30] != 1 && casefour_bar[3] != 1 && casefour_square[7] != 1 && casefour_square[8] != 1 && casefour_square[13] != 1 && casefour_square[14] != 1 && caseeight[2] != 1 && caseeight[3] != 1)
			{
				cout << "abcd',";
			}

			if (casefour_bar[7] != 1 && four[3][3] == 1 && casetwo[11] != 1 && casetwo[15] != 1 && casetwo[22] != 1 && casetwo[31] != 1 && casefour_bar[3] != 1 && casefour_square[8] != 1 && casefour_square[15] != 1 && casefour_square[11] != 1 && casefour_square[14] != 1 && caseeight[2] != 1 && caseeight[3] != 1)
			{
				cout << "ab'cd',";
			}


			//輸出essential 
			cout << endl;
			cout << "essential prime implicant:";




	}


}






int main()
{
	// 讀檔跟設值
	ifstream readfile("input.txt", ios::in);
	if (!readfile) {
		cerr << "Failed opening" << endl;
		exit(1);

	}
	int v = 0;
	int m[16] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int d[16] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	char buffer;
	readfile >> buffer;// -
	for (int i = 0; i < 3; i++)
	{
		readfile >> buffer;
		if (buffer == 'v')
		{
			readfile >> v >> buffer;
		}
		else if (buffer == 'm')
		{
			int x = 0;
			while (readfile >> m[x])
			{

				readfile >> buffer;
				if (buffer == '-')//過濾-
				{
					break;
				}
				x++;
			}
		}
		else if (buffer == 'd')
		{
			int ii = 0;
			while (readfile >> d[ii])
			{
				readfile >> buffer;
				if (buffer == '-')
				{
					break;
				}
				ii++;
			}
		}
	}
	cout << v << endl;

	readfile.close();
	//-------------------------Initialize the terms in the K-map----------------
	int two[2][2] = { { 0,1 } ,{ 2,3 } };
	int three[2][4] = { { 0,2,6,4 } ,{ 1,3,7,5 } };
	int four[4][4] = { { 0,4,12,8 },{ 1,5,13,9 },{ 3,7,15,11 },{ 2,6,14,10 } };
	if (v == 4)//如果讀到4變數 就進入
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 16; k++)
				{
					if (four[i][j] == d[k])
					{
						four[i][j] = 16;

					}
				}
			}
		}


		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 16; k++)
				{
					if (four[i][j] == m[k])
					{
						four[i][j] = 1;

					}
				}
			}
		}



		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 16; k++)
				{
					if (four[i][j] != 1 && four[i][j] != 16)
					{
						four[i][j] = 0;

					}
				}
			}
		}
		cout << endl;
		int num = 0;
		int num2 = 0;
		//debug
		for (int i = 0; i < 16; i++)
		{
			if (m[i] != 1)
			{
				num++;
			}
			if (d[i] != 1)
			{
				num2++;
			}
		}
		if (num == 16 && num2 == 16)
		{
			four[1][0] = 0;
		}
		//確認
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << four[i][j] << " ";
			}
			cout << endl;
		}
		fourgetmap(four);
		fourterm(four);
	}
	else if (v == 3)//如果讀到3變數，就進入
	{


		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					if (three[i][j] == d[k])
					{

						three[i][j] = 8;  //我把dontcare設成整數8

					}
				}
			}
		}


		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					if (three[i][j] == m[k])
					{
						three[i][j] = 1;

					}
				}
			}
		}

		cout << endl;
		/*
		for (int i = 0; i < 2; i++)
		{
		for (int j = 0; j < 4; j++)
		{
		cout << three[i][j]<<" ";
		}
		cout << endl;
		}*/

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					if (three[i][j] != 1 && three[i][j] != 8)
					{
						three[i][j] = 0;

					}
				}
			}
		}

		/*
		cout << "d:";
		for (int i = 0; i < 8; i++)
		{
		cout << d[i]<<" ";
		}
		cout << endl;
		cout << "m:";
		for (int i = 0; i < 8; i++)
		{
		cout << m[i] << " ";
		}

		cout << endl;

		for (int i = 0; i < 2; i++)
		{
		for (int j = 0; j < 4; j++)
		{
		cout << three[i][j] << " ";
		}
		cout << endl;
		}
		*/


		//debug
		int num = 0;
		int num2 = 0;
		for (int i = 0; i < 8; i++)
		{
			if (m[i] != 1)
			{
				num++;
			}
			if (d[i] != 1)
			{
				num2++;
			}
		}
		if (num == 8 && num2 == 8)
		{
			three[1][0] = 0;
		}
		threegetmap(three);

		threeterm(three);






	}
	else if (v == 2) //如果讀到2變數就進入
	{
		int num = 0;
		int num2 = 0;


		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					if (two[i][j] == d[k])
					{
						two[i][j] = 4;  //我把dontcare設成整數4

					}
				}
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					if (two[i][j] == m[k])
					{
						two[i][j] = 1;

					}
				}
			}
		}




		cout << endl;


		//debug
		for (int i = 0; i < 4; i++)
		{
			if (m[i] != 1)
			{
				num++;
			}
			if (d[i] != 1)
			{
				num2++;
			}
		}
		if (num == 4 && num2 == 4)
		{
			two[0][1] = 0;
		}


		cout << endl;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					if (two[i][j] != 1 && two[i][j] != 4)
					{
						two[i][j] = 0;

					}
				}
			}
		}

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << two[i][j] << " ";
			}
			cout << endl;
		}
		twogetmap(two);
		twoterm(two);
	}


	system("pause");


}