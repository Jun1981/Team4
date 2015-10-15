#include "Title.h"
#include "../DxLib/DxLib.h"
#include "Menu.h"
#include <time.h>
#include <iostream>
#include "key.h"
#include "GameMain.h"

Menu tSel;//タイトル用メニュー

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
	//タイトル
	tSel.setGh(0,"../img/Title/Title.png");
	tSel.setGhItem(0,"../img/cursorBg/NewGame.png");
	tSel.setGhItem(1,"../img/cursorBg/EndGame.png");
	
	//stgSel.setGh(0,"../img/stageSelect/bg.png");


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

		if(game.fadeOut(10)==100)tSel.close();//終了処理;
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