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
	void DisplayTetris();//��ӡ�м䲿��
private:
	vector<vector<int>> m_Tetris;//����˹�����м��λ��
	int m_TetrisLine;//�м����
	int m_TetrisColumn;//�м����

	HANDLE m_hout;
	COORD m_scoreCoord;
	COORD m_lifeCoord;
	COORD m_nextCoord;
	COORD m_authorCoord;
	COORD m_startDrawCoord;//����˹�����п�ʼ��ͼ��λ��
};



#endif

