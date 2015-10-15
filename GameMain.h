#pragma once
#include "Menu.h"
class GameMain{

public:
	int mode;//ゲームモード	
	int fadeMode;//フェードイン・アウトモード
	int nextMode;//次のモード予定
	int brightness;//輝度
	
	
	
	void start();//ゲーム本編スタート

	GameMain();//コンストラクタ
	
	int fadeOut(int);//フェードアウト関数　終了時に　１００を返す
	int fadeIn(int);//フェードイン関数	終了時に　１００を返す
};

//クラス外部宣言
extern GameMain game;//クラス宣言
//extern Menu stgSel;
