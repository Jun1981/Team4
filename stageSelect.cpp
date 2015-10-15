#include "stageSelect.h"
#include "key.h"

#include "../DxLib/DxLib.h"

#include "Fonts.h"
#include "GameMain.h"
//数学系
#define _USE_MATH_DEFINES // for C++
#include <cmath>

#include "Fonts.h"

#include "Object.h"
//////////////////////////////////////

Menu stgSel;//選択クラス　ステージセレクト用メニュー
Fonts fonts;//フォントクラス　	フォント
Object bg;//オブジェクトクラス　背景
Object fairy;//オブジェクトクラス　妖精インスタンス


void stageInit(){//初期化
	//フォント関係
	fonts.path="..\\Fonts\\uzura.ttf";//うずらフォント
	fonts.loadFont();//フォントの読み込み
	
	//////////////////////////


	stgSel.numOfItems=3;

	//配列作成
	stgSel.setArrayGh(1);//背景画像ハンドラの配列
	stgSel.setArrayGhItem(1);//メニュー背景画像（塔）	
	stgSel.setArrayGhCur(1);

	//画像読み込んで各ハンドラに格納
	//タイトル
	stgSel.setGh(0,"../img/stageSelect/bg1.png");//背景読み込み
	/*stgSel.setGhItem(0,"../img/cursorBg/NewGame.png");
	stgSel.setGhItem(1,"../img/cursorBg/EndGame.png");*/
	stgSel.setGhItem(0,"../img/stageSelect/tower.png");//塔読み込み
	stgSel.setGhCur(0,"../img/cursor/finger1.png");//カーソル読み込み

	//その他オブジェ画像
	bg.setGh("../img/stageSelect/bg1.png");//背景画像
	fairy.setGh("../img/Object/pixy.png");//妖精画像

	//初期位置設定
	stgSel.setItemInitXY(0,200,0);//塔１の初期位置
	stgSel.setItemInitXY(240,200,1);//塔2の初期位置
	stgSel.setItemInitXY(240*2,200,2);//塔3の初期位置

	
	stgSel.setItemXY(stgSel.itemInitX[0],200,0);
	stgSel.setItemXY(stgSel.itemInitX[1],200,1);
	stgSel.setItemXY(stgSel.itemInitX[2],200,2);

	fairy.setXY(100,100);//妖精初期位置設定

	stgSel.curX=stgSel.itemInitX[0]+towerSpace;stgSel.curY=stgSel.itemInitY[0];


}
void stageCal(){//計算
	if(game.fadeMode==0){//フェードモードが０なら
		stgSel.calHori();//計算
		stgSel.curX=stgSel.itemInitX[stgSel.num]+towerSpace;//カーソル位置計算
		
		if(key_Trg==0x100){//エンターキーが押されたら
			if(stgSel.num==0){//カーソルが左端
				//game.fadeMode=2;
				//game.nextMode=2;//ステージセレクトへ
				

			}else if(stgSel.num==1){//カーソルが1なら
				//game.fadeMode=2;//フェードアウト
				//game.nextMode=-1;//終了へ
			}else if(stgSel.num==2){//カーソルが２なら
				//game.fadeMode=2;//フェードアウト
				//game.nextMode=-1;//終了へ
			}
		}
	}
	else if(game.fadeMode==2){//フェードアウトモード

		if(game.fadeOut(10)==100)stgSel.close();//終了処理;
	}

}

//表示系
void stageDraw(){
	//背景画像
	//DrawGraph(0,0,stgSel.bgGh[0],1);
	DrawGraph(0,0,bg.getGh(),1);
	//塔1
	DrawGraph(stgSel.itemX[0],stgSel.itemY[0],stgSel.itemGh[0],1);//画像
	DrawString( stgSel.itemX[0]+towerSpace , 515, "初級", GetColor( 0 , 0 , 0 ) );//文字
	
	//塔2
	DrawGraph(stgSel.itemX[1],stgSel.itemY[1],stgSel.itemGh[0],1);//画像
	DrawString( stgSel.itemX[1]+towerSpace , 515, "中級", GetColor( 0 , 0 , 0 ) );//文字
	//塔３
	DrawGraph(stgSel.itemX[2],stgSel.itemY[2],stgSel.itemGh[0],1);//画像
	DrawString( stgSel.itemX[2]+towerSpace , 515, "上級", GetColor( 0 , 0 , 0 ) );//文字
	

	//その他
	DrawRotaGraph(fairy.x,fairy.y,0.3,0,fairy.getGh(),1);//妖精画像表示(0.2倍)

	//カーソル
	DrawRotaGraph(stgSel.curX,stgSel.curY,0.3,M_PI/2,stgSel.curGh[0],1,0);//カーソル画像（指）描画　0.3倍　90度回転


	//フォント
		SetFontSize(60);	// 見やすさのため、フォントサイズを大きく
		ChangeFont( "うずらフォント", DX_CHARSET_DEFAULT );
		
		
		


}




