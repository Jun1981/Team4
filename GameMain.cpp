#include "GameMain.h"
#include <time.h>
#include "../DxLib/DxLib.h"
#include "MIKU.h"
#include "key.h"

#include"map.h"
#include "menu.h"

int G_MODE=0;




 int alpha=255;

int fade_mode=0;//フェードモード (０：なし、１：フェードイン　２：フェードアウト）
//static int fade_cnt=2;//フェードカウント用


void GameMain(){
	switch(G_MODE){		

		//オープニング
	case 0:
		break;
		////////////////////////////////////




		//本ゲーム/////////////////////////////////////////
	case 1:



		
		//フェードイン
		if(fade_mode==1){

			if (alpha <= 254){
				alpha += 32;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
				if(alpha>=255){

					fade_mode=0;//フェードインモード
					//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
				}
			}
		}
		//フェードアウト
		if(fade_mode==2){
			//fade_cnt--;
				if (alpha >= 2){
					alpha -= 16;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
					if(alpha<2){
						G_MODE=2;
						fade_mode=1;//フェードインモード
						//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
					}
				}
		}


		//計算
		if(fade_mode==0){
			dia_chk();//斜めチェック
			//キーチェック
			key_chk();//キーチェック
			key_henkan();//キー変換

			p_anime();//自キャラアニメーション



			p_move();//プレイヤー計算

			EvtChk();//イベント計算



			//menu_chk();//メニュー画面に行くか

			if(key.x==1 && fade_mode==0){
				fade_mode=2;

			}//メニューに移行


		}


		//描画
		//DrawMap();

		DrawMap2();//基本ダンジョン描画	
		DrawMapEvt2();//ボスと門表示
		DrawMapItems();//ダンジョンアイテム描画
		miku.Draw();//プレイヤーキャラ描画

		break;
	case 2://メニュー

		if(fade_mode==0){
			//計算
			key_chk();//キーチェック
			key_henkan();//キー変換
			menu_KeyCal();//カーソル計算

		}

		//フェードイン
		if(fade_mode==1){

			if (alpha <= 254){
				alpha += 32;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
				if(alpha>=255){

					fade_mode=0;//フェードインモード
					//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
				}
			}
		}

		//フェードアウト
		if(fade_mode==2){
			//fade_cnt--;
				if (alpha >= 2){
					alpha -= 32;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
					if(alpha<2){
						G_MODE=1;//通常ゲームへ
						fade_mode=1;//フェードインモード
						//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
					}
				}
		}


	


		//描画
		menu_draw();//メニュー画面描画

		break;

		/////////////////////////////////////////////
		//ゲームオーバー
	case 3:
		break;
		//////////////////////////////////////



	case 4://フェードアウト



		break;


	case 5://フェードイン


		break;



	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}




//自機画像データ等の読み込み
void LoadImg(){


	miku.LoadImg();//ミク画像　MIKU.cpp内


}



//終了処理
void Finalize(){

}