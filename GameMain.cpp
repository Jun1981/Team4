
#include "GameMain.h"
//#include "Title.h"
//ランダム用
#include <time.h>
#include <iostream>
#include "Menu.h"
//
#include "../DxLib/DxLib.h"

#include "key.h"

//メイン部分
#include "debug.h"

#include "Title.h"

#include "stageSelect.h"

#include "Fonts.h"



//クラス定義
GameMain game;//クラス宣言

//コンストラクタ
GameMain::GameMain(){
	brightness=255;
	fadeMode=0;//通常

}


//Menu stgSel;//ステージセレクト

void GameMain::start(){

	switch(game.mode){

	case -1://終了

		exit(0);

		fonts.deleteFont();//フォントを捨てる

		break;
	case 0://初期化　関係

		titleInit();//タイトル初期化
		stageInit();//ステージ初期化

		game.mode=1;//タイトル画面へ		

		break;

	case 1://タイトル画面

		titleCal();//タイトル計算
		titleDraw();//タイトル描画

		debug();//デバッグ


		//tSel.termProc();//タイトル関係終了処理
		break;


	case 2://ステージセレクトモード

		
		
		if(game.fadeIn(10)==100){

		//	DrawGraph(0,0,stgSel.bgGh[0],1);
		//DrawString(100,400,"ステージセレクト",GetColor(255,255,255),0);

		stageCal();//計算
		stageDraw();//描画
		}
		break;

	}
}
///////////////////////////////////////////////////////////



int GameMain::fadeOut(int n){
	game.brightness-=n;
	SetDrawBright(game.brightness,game.brightness,game.brightness);
		if(game.brightness<=0){
		game.mode=game.nextMode;//次のモードへ
		game.fadeMode=0;//フェードモードを元に戻す
		return 100;
		}

	return 0;
}

int GameMain::fadeIn(int n){
	game.brightness+=n;
	SetDrawBright(game.brightness,game.brightness,game.brightness);
	if(game.brightness>=255){
		game.fadeMode=0;//フェードモードを元に戻す
		return 100;
		}
	return 0;
}

