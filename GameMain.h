#pragma once

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

void titleInit();//初期化
void titleCal();//計算
void titleDraw();
extern GameMain game;//クラス宣言