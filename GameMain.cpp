#include "GameMain.h"
#include <time.h>
#include "../DxLib/DxLib.h"
#include "MIKU.h"
#include "key.h"

#include"map.h"

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




//自機画像データ等の読み込み
void LoadImg(){


	miku.LoadImg();//ミク画像　MIKU.cpp内


}

//計算メイン
void Calc(){
	p_move();//プレイヤー計算
	p_anime();//自キャラアニメーション	


}


//描画
void Draw(){
	DrawMap();
	miku.Draw();
	


}

//終了処理
void Finalize(){

}