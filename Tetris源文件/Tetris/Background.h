#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "stdafx.h"


class Background
{
public:
	Background();
	~Background();
	void InitTetris();
	void SetScore(int score);
	void SetLife(int lifeValue);
	void SetNext();
	void MoveOneStep();
	void DisplayTetris();//打印中间部分
private:
	vector<vector<int>> m_Tetris;//俄罗斯方块中间的位置
	int m_TetrisLine;//中间的行
	int m_TetrisColumn;//中间的列

	HANDLE m_hout;
	COORD m_scoreCoord;
	COORD m_lifeCoord;
	COORD m_nextCoord;
	COORD m_authorCoord;
	COORD m_startDrawCoord;//俄罗斯方块中开始画图的位置
};



#endif

