#include "Background.h"


Background::Background()
{
	//修改控制台大小及标题
	HWND hwnd=GetForegroundWindow();
	SetWindowTextA(hwnd,"小游戏之贪吃蛇");
	//得到屏幕的长宽  
	int posx=GetSystemMetrics(SM_CXSCREEN), posy=GetSystemMetrics(SM_CYSCREEN);   
	int x=350;
	int y=550;
	//置顶窗口      
	::SetWindowPos(hwnd,HWND_NOTOPMOST,(posx/2-x/2),(posy/2-y/2),x,y,NULL);
	//SendMessage(hwnd,WM_SETICON,ICON_SMALL,( LPARAM )LoadIcon(NULL,IDI_QUESTION));
};

Background::~Background()
{

}


void Background::InitVector(vector<vector<int>> &vt2)
{
	//游戏部分
	vector<int> vt;
	for (int i=0;i<line;i++)//20行
	{
		vt.clear();
		if (0==i||line-1==i)
		{
			for (int j=0;j<column;j++)//40列
			{
				if (0==j||column-1==j)
				{
					if (0==i&&0==j)
					{
						vt.push_back(7);
					}
					else if (0==i&&column-1==j)
					{
						vt.push_back(8);
					}
					else if (line-1==i&&0==j)
					{
						vt.push_back(9);
					}
					else if (line-1==column-1)
					{
						vt.push_back(10);
					}
					else
					{
						vt.push_back(1);
					}
					
				}
				else
				{
					vt.push_back(2);
				}
			}
		}
		else
		{
			for (int j=0;j<column;j++)
			{
				if (0==j||column-1==j)
				{
					vt.push_back(1);
				}
				else
				{
					vt.push_back(0);
				}
			}
		}
		
		vt2.push_back(vt);
	}


	int dline=line/3;
	//说明部分
	for (int i=0;i<dline;i++)
	{
		vt.clear();
		if (0==i||dline-1==i)
		{
			for (int j=0;j<column;j++)//40列
			{
				if (0==j||column-1==j)
				{
					if (0==i&&0==j)
					{
						vt.push_back(7);
					}
					else if (0==i&&column-1==j)
					{
						vt.push_back(8);
					}
					else if (dline-1==i&&0==j)
					{
						vt.push_back(9);
					}
					else if (dline-1==column-1)
					{
						vt.push_back(10);
					}
					else
					{
						vt.push_back(1);
					}

				}
				else
				{
					vt.push_back(2);
				}
			}
		}
		else
		{
			for (int j=0;j<column;j++)
			{
				if (0==j||column-1==j)
				{
					vt.push_back(1);
				}
				else
				{
					vt.push_back(0);
				}
			}
		}
		m_descriptionSection.push_back(vt);
	}
}


void Background::ShowStart(HANDLE hout)//显示按下空格开始的界面
{
	vector<vector<int>> vt12;
	InitVector(vt12);
	InitDisplay(vt12);

	int y=vt12.size();
	int x=(vt12.at(0)).size();
	COORD pos;
	//显示游戏名称
	pos.X=(x/3)*2;
	pos.Y=y/3;
	SetConsoleCursorPosition(hout,pos);
	cout<<"贪吃蛇";

	//提示用户按开始键开始游戏
	pos.X=(x/4)*2;
	pos.Y=y/2;
	SetConsoleCursorPosition(hout,pos);
	cout<<"按下空格键开始游戏";
}

void Background::RefleshFood(vector<vector<int>> &vt2)//刷新食物
{
	srand((unsigned)time(0));
	int x=(rand()%(line-2))+1;
	int y=(rand()%(column-2))+1;
	while ((vt2.at(x)).at(y)==3||((vt2.at(x)).at(y)==4)||((vt2.at(x)).at(y)==6))
	{
		x=(rand()%(line-2))+1;
		y=(rand()%(column-2))+1;
	}
	(vt2.at(x)).at(y)=5;
	m_foodx=x;
	m_foody=y;
}


//使用二维数组来表示
//vector<vector<int>>
//0->" "
//1->|
//2->-
//3->O蛇头
//4->0吃东西的蛇头(数字0)
//5->*食物
//6->#蛇身
//7->
void Background::InitDisplay(vector<vector<int>> &vt2)
{
	//显示游戏界面
	vector<vector<int>>::iterator vt2ItStart;
	vector<vector<int>>::iterator vt2ItEnd;
	
	vector<int>::iterator vtItStart;;
	vector<int>::iterator vtItEnd;


	vt2ItEnd=vt2.end();
	for (vt2ItStart=vt2.begin();vt2ItStart!=vt2ItEnd;++vt2ItStart)
	{
		//cout<<"\t\t";
		vtItStart=(*vt2ItStart).begin();
		vtItEnd=(*vt2ItStart).end();
		for (vtItStart;vtItStart!=vtItEnd;++vtItStart)
		{
			switch(*vtItStart)
			{
			case 0:
				cout<<"  ";
				break;
			case 1:
				cout<<"┆";
				break;
			case 2:
				cout<<"┄";
				break;
			case 3:
				cout<<"○";//大写字母O
				break;
			case 4:
				cout<<"●";//数字0
				break;
			case 5:
				cout<<"★";
				break;
			case 6:
				cout<<"■";
				break;
			case 7:
				cout<<"┌";
				break;
			case 8:
				cout<<"┐";
				break;
			case 9:
				cout<<"└";
				break;
			case 10:
				cout<<"┘";
			default:
				break;

			}
		}
		cout<<endl;
	}

	//显示说明界面
	vt2ItEnd=m_descriptionSection.end();
	for (vt2ItStart=m_descriptionSection.begin();vt2ItStart!=vt2ItEnd;++vt2ItStart)
	{
		//cout<<"\t\t";
		vtItStart=(*vt2ItStart).begin();
		vtItEnd=(*vt2ItStart).end();
		for (vtItStart;vtItStart!=vtItEnd;++vtItStart)
		{
			switch(*vtItStart)
			{
			case 0:
				cout<<"  ";
				break;
			case 1:
				cout<<"┆";
				break;
			case 2:
				cout<<"┄";
				break;
			case 3:
				cout<<"↑";//大写字母O
				break;
			case 4:
				cout<<"↓";//数字0
				break;
			case 5:
				cout<<"←";
				break;
			case 6:
				cout<<"→";
				break;
			default:
				break;

			}
		}
		cout<<endl;
	}
	//显示说明部分

	//■  ┆ ┆ ┌ └ ┐ ┘�→←↑↓♀♂―￣＿︿＼＠＆＃▲■△★○●◎◇◆□℃‰┄

}

void Background::PartChangeDisplay(vector<vector<int>> &vt2,HANDLE hout,COORD pos)
{
	
	vector<vector<int>>::iterator vt2ItStart;
	vector<vector<int>>::iterator vt2ItEnd;

	vector<int>::iterator vtItStart;;
	vector<int>::iterator vtItEnd;
	int x=-1;
	int y=-1;
	

	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.bVisible = FALSE;
	cursor_info.dwSize   = 100;
	SetConsoleCursorInfo(hout, &cursor_info);//隐藏光标

	vt2ItEnd=vt2.end();
	for (vt2ItStart=vt2.begin();vt2ItStart!=vt2ItEnd;++vt2ItStart)
	{
		x++;
		y=-1;
		//cout<<"\t\t";
		vtItStart=(*vt2ItStart).begin();
		vtItEnd=(*vt2ItStart).end();
		for (vtItStart;vtItStart!=vtItEnd;++vtItStart)
		{
			y++;
			pos.X=y*2;
			pos.Y=x;
			SetConsoleCursorPosition(hout,pos);
			switch(*vtItStart)
			{
			case 0:
				cout<<"  ";
				break;
			case 3:
				cout<<"○";//大写字母O
				break;
			case 4:
				cout<<"●";//数字0
				break;
			case 5:
				cout<<"★";
				break;
			case 6:
				cout<<"■";
				break;
			default:
				break;
			}
		}
		cout<<endl;
		//■  ┆ ┆ ┌ └ ┐ ┘�→←↑↓♀♂―￣＿︿＼＠＆＃▲■△★○●◎◇◆□℃‰┄
	}
}

void Background::DisplayGameOver(int score,HANDLE hout)
{
	//背景都清除
	vector<vector<int>> vt2;
	COORD pos1={0,0};
	InitVector(vt2);
	PartChangeDisplay(vt2,hout,pos1);

	COORD pos={15,8};
	SetConsoleCursorPosition(hout,pos);
	cout<<"GameOver!";
	pos.X=15;
	pos.Y=10;
	SetConsoleCursorPosition(hout,pos);
	cout<<"score:"<<score;
}