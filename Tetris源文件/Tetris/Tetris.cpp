// Tetris.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Background.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Background bk;
	bk.InitTetris();
	bk.MoveOneStep();
	while (1)
	{
		bk.MoveOneStep();
		Sleep(1000);
	}
	system("pause");
	return 0;
}

