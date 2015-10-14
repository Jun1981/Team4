
#include "GameMain.h"
//#include "Title.h"
//ランダム用
#include <time.h>
#include <iostream>
#include "Select.h"
//
#include "../DxLib/DxLib.h"



#include "key.h"

#include "debug.h"



//クラス定義
GameMain game;//クラス宣言

//コンストラクタ
GameMain::GameMain(){
	brightness=255;
	fadeMode=0;//通常

}

Select tSel;//タイトル用メニュー

void GameMain::start(){

	switch(game.mode){

	case -1://終了

		exit(0);

		break;
	case 0://初期化　関係

		titleInit();//初期化	

		game.mode=1;//タイトル画面へ		

		break;

	case 1://タイトル画面

		titleCal();//タイトル計算
		titleDraw();//タイトル描画

		debug();//デバッグ


		//tSel.termProc();//タイトル関係終了処理
		break;


	case 2://ステージセレクトモード
		if(game.fadeIn(10)==100)
		
		DrawString(100,400,"ステージセレクト",GetColor(255,255,255),0);


		break;

	}



}

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


//タイトル関係初期化
void titleInit(){
	srand((unsigned int)time(NULL));//時間でランダム生成


	//選択用
	tSel.num=0;//初期項目
	tSel.numOfItems=2;//項目数２

	//各配列作成
	tSel.setArrayGh(1);//背景画像ハンドラの配列
	tSel.setArrayGhItem();
	
	tSel.setArrayGhCur(1);


	//画像読み込んで各ハンドラに格納
	tSel.setGh(0,"../img/Title/Title.png");
	tSel.setGhItem(0,"../img/cursorBg/NewGame.png");
	tSel.setGhItem(1,"../img/cursorBg/EndGame.png");
	tSel.bgGh[0]=LoadGraph("../img/Title/Title.png",0);

	//tSel.itemInitX[0]=200,tSel.itemInitY[0]=300;//バルーン左の初期位置
	//tSel.itemInitX[0]=200,tSel.itemInitY[0]=300;
	//初期位置設定
	tSel.setItemInitXY(200,300,0);//バルーン左の初期位置
	tSel.setItemInitXY(400,300,1);//バルーン右の初期位置

	tSel.setItemXY(200,200,0);
	tSel.setItemXY(400,300,1);


}

void titleCal(){
	if(game.fadeMode==0){//フェードモードが０なら
		tSel.calHori();//計算

		if(key_Trg==0x100){//エンターキーが押されたら
			if(tSel.num==L){//カーソルが左端
				game.fadeMode=2;
				game.nextMode=2;//ステージセレクトへ

			}else if(tSel.num=R){//カーソルが右端なら
				game.fadeMode=2;//フェードアウト
				game.nextMode=-1;//終了へ
			}
		}
	}
	else if(game.fadeMode==2){//フェードアウトモード
		//game.brightness-=3;

		//if(game.brightness<=0){game.mode=game.nextMode;
		//tSel.termProc();//終了処理
		//}

		if(game.fadeOut(3)==100)tSel.termProc();//終了処理;
	}

}

	void titleDraw(){
		DrawGraph(0,0,tSel.bgGh[0],1);//背景描画

		if(tSel.num!=L)SetDrawBright(game.brightness/2,game.brightness/2,game.brightness/2);//０が選ばれてなかったら画像を暗くする 
		DrawRotaGraph(tSel.itemX[L],tSel.itemY[L],1.0,0,tSel.itemGh[L],1,0);//左　風船描画
		SetDrawBright(game.brightness,game.brightness,game.brightness);//明るさを元に戻す

		if(tSel.num!=R)SetDrawBright(game.brightness/2,game.brightness/2,game.brightness/2);//０が選ばれてなかったら画像を暗くする
		DrawRotaGraph(tSel.itemX[R],tSel.itemY[R],1.0,0,tSel.itemGh[R],1,0);//右　風船描画
		SetDrawBright(game.brightness,game.brightness,game.brightness);//明るさを元に戻す


	}