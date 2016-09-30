#include "stdafx.h"
#include "Background.h"
const int line=20;
const int column=20;

int nextX=(column*2/3)*2;
int nextY=1;

int lifeX=nextX;
int lifeY=line/2-2;

int scoreX=nextX;
int scoreY=line-6;

int authorX=nextX;
int authorY=line-2;

Background::Background()
{
	m_hout=GetStdHandle(STD_OUTPUT_HANDLE);

	m_startDrawCoord.X=2;
	m_startDrawCoord.Y=1;

	m_nextCoord.X=nextX;
	m_nextCoord.Y=nextY;

	m_lifeCoord.X=lifeX;
	m_lifeCoord.Y=lifeY;

	m_scoreCoord.X=scoreX;
	m_scoreCoord.Y=scoreY;

	m_authorCoord.X=authorX;
	m_authorCoord.Y=authorY;

	m_TetrisLine=line-2;
	m_TetrisColumn=column*2/3-3;

	vector<int> vt;
	for (int i=0;i<m_TetrisLine;i++)
	{
		vt.clear();
		for (int j=0;j<m_TetrisColumn;j++)
		{
			if ((0==i)&&(3==j||4==j||5==j||6==j))
			{
				vt.push_back(2);
			}
			else
			{
				vt.push_back(0);
			}
			
		}
		m_Tetris.push_back(vt);
	}
}

Background::~Background()
{

}

//┚┖┒┎┆┄
void Background::InitTetris()
{
	for (int i=0;i<line;i++)
	{
		for (int j=0;j<column;j++)
		{
			if ((0==i&&0==j)||(0==i&&column*2/3-1==j))
			{
				cout<<"┎";
			}
			else if ((0==i&&column*2/3-2==j)||(0==i&&column-1==j))
			{
				cout<<"┒";
			}
			else if ((line-1==i&&0==j)||(line-1==i&&column*2/3-1==j))
			{
				cout<<"┖";
			}
			else if ((line-1==i&&column-1==j)||(line-1==i&&column*2/3-2==j))
			{
				cout<<"┚";
			}
			else if (0==j||column*2/3-2==j||column*2/3-1==j||column-1==j)
			{
				cout<<"┆";
			}
			else if (0==i||line-1==i)
			{
				cout<<"┄";
			}
			else
			{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	SetNext();
	SetLife(4);
	SetScore(0);

	COORD pos={authorX,authorY};
	SetConsoleCursorPosition(m_hout,m_authorCoord);
	cout<<"作者：TZY";
}

void Background::SetScore(int score)
{
	//HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={scoreX,scoreY};
	SetConsoleCursorPosition(m_hout,pos);
	cout<<"得分：";
	pos.X+=3;
	pos.Y+=2;
	SetConsoleCursorPosition(m_hout,pos);
	cout<<score;
}

void Background::SetLife(int lifeValue)
{
	//HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={lifeX,lifeY};
	SetConsoleCursorPosition(m_hout,pos);
	cout<<"生命值：";
	pos.X+=3;
	pos.Y+=3;
	SetConsoleCursorPosition(m_hout,pos);
	for (int i=0;i<lifeValue;i++)
	{
		cout<<"■";
	}
}

void Background::SetNext()
{
	//HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={nextX,nextY};
	SetConsoleCursorPosition(m_hout,pos);
	cout<<"下一个：";
	pos.X+=2;
	pos.Y+=3;
	SetConsoleCursorPosition(m_hout,pos);
	cout<<"■■■■";
}

void Background::MoveOneStep()
{
	//有值的向下加1，即移动一步
	//先判断是否左右移动和旋转
	//再把中心坐标向下加1
	//然后设置到中心坐标上
	//
	for (int i=m_TetrisLine-1;i>=0;i--)
	{
		for (int j=0;j<m_TetrisColumn;j++)
		{
			switch(m_Tetris.at(i).at(j))
			{
			case 2:
				if (i<m_TetrisLine-1)
				{
					m_Tetris.at(i).at(j)=3;
					m_Tetris.at(i+1).at(j)=2;
				}
				else
				{

				}
				
				break;
			}
		}
	}
	//然后打印到屏幕上
	DisplayTetris();
}

void Background::DisplayTetris()
{
	COORD pos=m_startDrawCoord;
	SetConsoleCursorPosition(m_hout,pos);
	for (int i=0;i<m_TetrisLine;i++)
	{
		for (int j=0;j<m_TetrisColumn;j++)
		{
			switch(m_Tetris.at(i).at(j))
			{
			case 1://代表已经停止的方块
				pos.X=j*2+m_startDrawCoord.X;
				pos.Y=i+m_startDrawCoord.Y;
				SetConsoleCursorPosition(m_hout,pos);
				cout<<"■";
				break;
			case 2://代表正在移动的方块
				pos.X=j*2+m_startDrawCoord.X;
				pos.Y=i+m_startDrawCoord.Y;
				SetConsoleCursorPosition(m_hout,pos);
				cout<<"■";
				break;
			case 3://代表已经移动或已经消除的方块，需要输出空格，并把该数清零
				pos.X=j*2+m_startDrawCoord.X;
				pos.Y=i+m_startDrawCoord.Y;
				SetConsoleCursorPosition(m_hout,pos);
				cout<<"　";
				m_Tetris.at(i).at(j)=0;
				break;
			}
		}
	}

}