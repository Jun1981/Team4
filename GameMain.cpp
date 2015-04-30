#include "GameMain.h"
#include <time.h>
#include "../DxLib/DxLib.h"
#include "MIKU.h"
#include "key.h"

int G_MODE=0;


void GameMain(){
	switch(G_MODE){		

		//オープニング
	case 0:
		break;
		////////////////////////////////////




		//本ゲーム/////////////////////////////////////////
	case 1:

		key_chk();//キーチェック
		key_henkan();//キー変換
		// WaitKey();

		Calc();//計算全体
		Draw();//描画全体			


		break;
		/////////////////////////////////////////////
		//ゲームオーバー
	case 2:
		break;
		//////////////////////////////////////

	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}


void Init(){

	G_MODE=1;//ゲームモード


	miku.Init();//ミク初期化

	LoadImg();//画像などの読み込み

}

//自機画像データ等の読み込み
void LoadImg(){


	miku.LoadImg();//ミク画像　MIKU.cpp内


}

//計算メイン
void Calc(){

}


//描画
void Draw(){
	miku.Draw();


}

//終了処理
void Finalize(){

}