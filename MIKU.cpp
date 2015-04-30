

#include "../DxLib/DxLib.h"

#include "MIKU.h"
#include "map.h"//画面サイズ情報取得のため

#include "Game_Info.h"
#include "key.h"


MIKU miku;//自機クラス宣言



//ミク画像読み込み
void MIKU::LoadImg(){

	LoadDivGraph("Img/miku/mikusan.png", 8, 8, 1, 48, 64, GH, 1);//自機画像

	LoadDivGraph("Img/miku/loop1000/loop0.png", 6, 6, 1, 48, 64, GH_Run[0], 1);//自機画像
	LoadDivGraph("Img/miku/loop1001/loop1.png", 6, 6, 1, 48, 64, GH_Run[1], 1);//自機画像
	LoadDivGraph("Img/miku/loop1002/loop2.png", 6, 6, 1, 48, 64, GH_Run[2], 1);//自機画像

	LoadDivGraph("Img/miku/loop1003/loop3.png", 6, 6, 1, 48, 64, GH_Run[3], 1);//自機画像

	LoadDivGraph("Img/miku/loop1004/loop4.png", 6, 6, 1, 48, 64, GH_Run[4], 1);//自機画像
	LoadDivGraph("Img/miku/loop1005/loop5.png", 6, 6, 1, 48, 64, GH_Run[5], 1);//自機画像

	LoadDivGraph("Img/miku/loop1006/loop6.png", 6, 6, 1, 48, 64, GH_Run[6], 1);//自機画像
	LoadDivGraph("Img/miku/loop1007/loop7.png", 6, 6, 1, 48, 64, GH_Run[7], 1);//自機画像
	

}

void MIKU::Init(){

	real_W=48;//実際の幅


	real_H=64;//実際の高さ


	mp_rx=0;//マップ内での実際のx座標
	mp_ry=0;//マップ内での実際のｙ座標


	dsp_rx=DSP_W/2-real_W/2;//画面内の実際のｘ座標（左から数えて）
	dsp_ry=DSP_H/2-real_H/2;//画面内の実際のy座標（上から数えて）
	
	W=24;//見た目の幅
	H=24;//見た目の高さ

	mp_x=mp_rx-(real_W-W)/2;//マップ内での見た目のｘ座標
	mp_y=mp_ry-(real_H-H)/2;//マップ内での見た目のｙ座標

	dsp_x=DSP_W/2-W/2;//画面内の見た目のｘ座標（左から数えて）
	dsp_y=DSP_H/2-H/2;//画面内の見た目のｙ座標（上から数えて）

}

void MIKU::Draw(){


		
	if (key.c==-1){
	/*	DrawGraph(miku.dsp_rx,miku.dsp_ry, miku.GH_Run[0][1], 1);*/
			DrawGraph(300,200, miku.GH[0], 1);
		}

	DrawFormatString(320, 16,(255,255,255) , "座標(%d,%d)", miku.dsp_rx, miku.dsp_ry);

	


}