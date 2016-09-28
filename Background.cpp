#include "Background.h"


Background::Background()
{
	//�޸Ŀ���̨��С������
	HWND hwnd=GetForegroundWindow();
	SetWindowTextA(hwnd,"С��Ϸ̰֮����");
	//�õ���Ļ�ĳ���  
	int posx=GetSystemMetrics(SM_CXSCREEN), posy=GetSystemMetrics(SM_CYSCREEN);   
	int x=350;
	int y=550;
	//�ö�����      
	::SetWindowPos(hwnd,HWND_NOTOPMOST,(posx/2-x/2),(posy/2-y/2),x,y,NULL);
	//SendMessage(hwnd,WM_SETICON,ICON_SMALL,( LPARAM )LoadIcon(NULL,IDI_QUESTION));
};

Background::~Background()
{

}


void Background::InitVector(vector<vector<int>> &vt2)
{
	//��Ϸ����
	vector<int> vt;
	for (int i=0;i<line;i++)//20��
	{
		vt.clear();
		if (0==i||line-1==i)
		{
			for (int j=0;j<column;j++)//40��
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
	//˵������
	for (int i=0;i<dline;i++)
	{
		vt.clear();
		if (0==i||dline-1==i)
		{
			for (int j=0;j<column;j++)//40��
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


void Background::ShowStart(HANDLE hout)//��ʾ���¿ո�ʼ�Ľ���
{
	vector<vector<int>> vt12;
	InitVector(vt12);
	InitDisplay(vt12);

	int y=vt12.size();
	int x=(vt12.at(0)).size();
	COORD pos;
	//��ʾ��Ϸ����
	pos.X=(x/3)*2;
	pos.Y=y/3;
	SetConsoleCursorPosition(hout,pos);
	cout<<"̰����";

	//��ʾ�û�����ʼ����ʼ��Ϸ
	pos.X=(x/4)*2;
	pos.Y=y/2;
	SetConsoleCursorPosition(hout,pos);
	cout<<"���¿ո����ʼ��Ϸ";
}

void Background::RefleshFood(vector<vector<int>> &vt2)//ˢ��ʳ��
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


//ʹ�ö�ά��������ʾ
//vector<vector<int>>
//0->" "
//1->|
//2->-
//3->O��ͷ
//4->0�Զ�������ͷ(����0)
//5->*ʳ��
//6->#����
//7->
void Background::InitDisplay(vector<vector<int>> &vt2)
{
	//��ʾ��Ϸ����
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
				cout<<"��";
				break;
			case 2:
				cout<<"��";
				break;
			case 3:
				cout<<"��";//��д��ĸO
				break;
			case 4:
				cout<<"��";//����0
				break;
			case 5:
				cout<<"��";
				break;
			case 6:
				cout<<"��";
				break;
			case 7:
				cout<<"��";
				break;
			case 8:
				cout<<"��";
				break;
			case 9:
				cout<<"��";
				break;
			case 10:
				cout<<"��";
			default:
				break;

			}
		}
		cout<<endl;
	}

	//��ʾ˵������
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
				cout<<"��";
				break;
			case 2:
				cout<<"��";
				break;
			case 3:
				cout<<"��";//��д��ĸO
				break;
			case 4:
				cout<<"��";//����0
				break;
			case 5:
				cout<<"��";
				break;
			case 6:
				cout<<"��";
				break;
			default:
				break;

			}
		}
		cout<<endl;
	}
	//��ʾ˵������

	//��  �� �� �� �� �� ��������������D���ߦ�ܣ����������������������멨

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
	SetConsoleCursorInfo(hout, &cursor_info);//���ع��

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
				cout<<"��";//��д��ĸO
				break;
			case 4:
				cout<<"��";//����0
				break;
			case 5:
				cout<<"��";
				break;
			case 6:
				cout<<"��";
				break;
			default:
				break;
			}
		}
		cout<<endl;
		//��  �� �� �� �� �� ��������������D���ߦ�ܣ����������������������멨
	}
}

void Background::DisplayGameOver(int score,HANDLE hout)
{
	//���������
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