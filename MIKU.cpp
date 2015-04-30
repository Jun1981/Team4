

#include "../DxLib/DxLib.h"

#include "MIKU.h"
#include "map.h"//画面サイズ情報取得のため

#include "Game_Info.h"
#include "key.h"

#include <math.h>


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


	mp_rx=640-24;//マップ内での実際のx座標
	mp_ry=480-32;//マップ内での実際のｙ座標


	dsp_rx=DSP_W/2-real_W/2;//画面内の実際のｘ座標（左から数えて）
	dsp_ry=DSP_H/2-real_H/2;//画面内の実際のy座標（上から数えて）
	
	W=24;//見た目の幅
	H=24;//見た目の高さ

	mp_x=mp_rx-(real_W-W)/2;//マップ内での見た目のｘ座標
	mp_y=mp_ry-(real_H-H)/2;//マップ内での見た目のｙ座標

	dsp_x=DSP_W/2-W/2;//画面内の見た目のｘ座標（左から数えて）
	dsp_y=DSP_H/2-H/2;//画面内の見た目のｙ座標（上から数えて）

	muki=0;//下向き

}

void MIKU::Draw(){


		
	//if (key.c==-1){
	///*	DrawGraph(miku.dsp_rx,miku.dsp_ry, miku.GH_Run[0][1], 1);*/
	//		DrawGraph(300,200, miku.GH[0], 1);
	//	}

	if (key.c==-1)DrawGraph(miku.dsp_rx, miku.dsp_ry, miku.GH[miku.muki], 1);
	else DrawGraph(miku.dsp_rx, miku.dsp_ry, miku.GH_Run[miku.muki][miku.anime], 1);

	DrawFormatString(320, 16,(255,255,255) , "ミクのマップ座標(%d,%d)", miku.mp_rx, miku.mp_ry);

	


}


#define M_PI 3.14159  //円周率

int nokori[2];//残り距離　ｘ、ｙ



void p_move(void){

	dia_chk();//斜めチェック


	if (key.c != -1){
		//左
		if (key.c == 2){
			miku.muki = 2;
			mv_chk(2,nokori);


		//	miku.rx -= nokori[0];自機が動く場合
			miku.mp_rx -= nokori[0];//マップのほうが動く
		
			
		}
		else if (key.c == 6){//右
			miku.muki = 6;
			mv_chk(6, nokori);
			//miku.rx += nokori[0];
				miku.mp_rx += nokori[0];
			
			
			}
		//上
		else if (key.c == 4){
			miku.muki = 4;
			mv_chk(4, nokori);
			//miku.ry -= nokori[1];
			miku.mp_ry -= nokori[1];
			//miku.y -= nokori[1];

			
		}
		else if (key.c == 0){//下
			miku.muki = 0;
			mv_chk(0, nokori);
			//miku.ry += nokori[1];
			miku.mp_ry += nokori[1];
			//miku.y += nokori[1];
			
		}

		//ななめ

		else if (key.c == 3){//左上
			miku.muki = 3;
			mv_chk(3, nokori);

			/*miku.rx -= nokori[0];
			miku.ry -= nokori[1];*/

			miku.mp_rx -= nokori[0];
			miku.mp_ry -= nokori[1];

		

			//miku.x -= nokori[0];
			//miku.y -= nokori[1];
		}


		else if (key.c == 5){
			miku.muki = 5;
			mv_chk(5, nokori);

			//miku.rx += nokori[0];
			//miku.ry -= nokori[1];
			miku.mp_rx += nokori[0];
			miku.mp_ry -= nokori[1];
		}
		//左下
		else if (key.c == 1){

			miku.muki = 1;
			mv_chk(1, nokori);

		/*	miku.rx -= nokori[0];
			miku.ry += nokori[1];*/
			miku.mp_rx -= nokori[0];
			miku.mp_ry += nokori[1];
			
		}
		//右下
		else if (key.c == 7){
			miku.muki = 7;
			mv_chk(7, nokori);

		/*	miku.rx += nokori[0];
			miku.ry += nokori[1];*/

			miku.mp_rx += nokori[0];
			miku.mp_ry += nokori[1];

		}

	}

	//移動モード切替
	if (key.z == 1){
		miku.spd = 10;
		miku.n_spd = miku.spd*cos(45 / 180.0*M_PI) + 0.5;
	}
	else{
		miku.spd = 4;
		miku.n_spd = miku.spd*cos(45 / 180.0*M_PI) + 0.5;//自機スピードななめの初期化
	}



}





//マップ通行チェック
void mv_chk(int k, int *x){ //kキャラの向き x残りの距離

	int i;
	int c=0;
	
	switch (k){
	case 0:
		for (i = 0; i < field.bn; i++){
			if (miku.mp_y + miku.H <= bhit[i].y  && miku.mp_y + miku.H + miku.spd > bhit[i].y   && miku.mp_x  > bhit[i].x && miku.mp_x < bhit[i].x + field.Chip){

				x[1] = bhit[i].y - (miku.mp_y + miku.H);
				return;

			}
		}
		x[1] = miku.spd; x[0] = 0;
		return;
	case 1:
		for (i = map.bn - 1; i >= 0; i--){
			//DrawFormatString(480, 16, 0xffffff, "%d", miku.n_line[i]);

			if (miku.n_line[i][1] == 1){//右上にいる
				if (miku.mp_x - miku.n_spd < bhit[i].x + field.Chip &&  miku.mp_y +miku.H+ miku.n_spd > bhit[i].y ){//移動後にブロックを超えたら
					//DrawFormatString(480, 16, (255, 255, 255), "壁発見");

					mv_chk(0, x);//下
					mv_chk(2, x); return;//左

				}
			}


			/*	}*/
		}x[0] = miku.n_spd;//左
			x[1] = miku.n_spd;//下
		return;


	case 2:
		for (i = 0; i < map.bn; i++){
			if (miku.mp_x >= bhit[i].x + field.Chip && miku.mp_x - miku.spd < bhit[i].x + field.Chip && miku.mp_y + miku.H > bhit[i].y && miku.mp_y < bhit[i].y + field.Chip){

				x[0] = miku.mp_x - (bhit[i].x + field.Chip);
				return;

			}
		}
		x[0] = miku.spd; x[1] = 0;
		return;

	case 3:
		for (i = map.bn-1; i >=0; i--){
			DrawFormatString(480, 16, 0xffffff, "%d", miku.n_line[i]);

			if (miku.n_line[i][3] == 1){
				if (miku.mp_x - miku.n_spd < bhit[i].x + field.Chip &&  miku.mp_y - miku.n_spd < bhit[i].y + field.Chip){
					DrawFormatString(480, 16, (255, 255, 255), "壁発見");

					mv_chk(4, x);
					mv_chk(2, x); return;
					
				}
			}
			

			/*	}*/
		}x[0] = miku.n_spd;
			x[1] = miku.n_spd;
	
			break;

	case 4:

		for (i = 0; i<map.bn; i++){
			if (miku.mp_y >= bhit[i].y+field.Chip  && miku.mp_y - miku.spd < bhit[i].y+field.Chip   && miku.mp_x + miku.W > bhit[i].x && miku.mp_x < bhit[i].x + field.Chip){
				x[1] = miku.mp_y - (bhit[i].y+field.Chip );
				return;
			}
		}
		x[1] = miku.spd; x[0] = 0;
		return;

	case 5:
		for (i = map.bn - 1; i >= 0; i--){
			DrawFormatString(480, 16, (255, 255, 255), "%d", miku.n_line[i]);

			if (miku.n_line[i][2] == 1){//左下にいる
				if (miku.mp_x +miku.W+ miku.n_spd > bhit[i].x  &&  miku.mp_y - miku.n_spd < bhit[i].y + field.Chip){
					DrawFormatString(480, 16, (255, 255, 255), "壁発見");

					mv_chk(4, x);
					mv_chk(6, x); return;

				}
			}
			

			/*	}*/
		}x[0] = miku.n_spd;
			x[1] = miku.n_spd;

		break;


	case 6:

		for (i = 0; i<map.bn; i++){
			if (miku.mp_x+miku.W <= bhit[i].x  && miku.mp_x +miku.W+ miku.spd > bhit[i].x  && miku.mp_y + miku.H > bhit[i].y && miku.mp_y < bhit[i].y + field.Chip){

				x[0] = bhit[i].x-(miku.mp_x+miku.W);
				return;

			}
		}
		x[0] = miku.spd; x[1] = 0;
		return;
	case 7:
		for (i = map.bn - 1; i >= 0; i--){			
			if (miku.n_line[i][0] == 1){//左上にいる
				if (miku.mp_x + miku.W + miku.n_spd > bhit[i].x  &&  miku.mp_y +miku.H+ miku.n_spd > bhit[i].y ){
					DrawFormatString(480, 16, (255, 255, 255), "壁発見");

					mv_chk(0, x);
					mv_chk(6, x); return;

				}
			}
			

			/*	}*/
		}x[0] = miku.n_spd;
			x[1] = miku.n_spd;
		return;


	}//switch終わり
}

//斜めチェック




MHit hb[1200];//
double ang[2];
double kakudo = -45 / 180.0 * M_PI;
double deg135 = 135 / 180.0 * M_PI;

int mx0,mx1,x2, x3, x4,           my0,my1,y2, y3, y4,y5;



void dia_chk(void){//返り値の数字は自機の向いている方向

	int i;
	mx0 = miku.mp_rx, my0 = -1 * (miku.mp_ry);//ミク左下
	mx1 = miku.mp_rx + miku.real_W; my1 = -1 * (miku.mp_ry + miku.real_H);//ミク左下
	for (i = 0; i < field.bn; i++){
		x2 = bhit[i].x , y2 = (-1) * (bhit[i].y);
		x3 = bhit[i].x + field.Chip, y3 = (-1) * (bhit[i].y + field.Chip );
		x4 = bhit[i].x + field.Chip * 2; y4 = (-1) * (bhit[i].y + field.Chip*2);
		y5 = -1*(bhit[i].y - field.Chip);

		
		DrawFormatString(480, 16, 0xffffff, "kakudo%f", kakudo);


		//右下
		if (   my0+mx1>x2+y3 &&   mx1+ my0<x4+y5   &&  (miku.mp_ry >= bhit[i].y+field.Chip || miku.mp_rx >= bhit[i].x+field.Chip)){
			miku.n_line[i][3] = 1;//右下にいる
			//if (miku.n_line[i][3] == 1)DrawFormatString(480, 16 * 5 + i * 16, 0xffffff, "%dの右下ライン", i);
		}
		else miku.n_line[i][3] = 0;


		//左上
		if (my0 + mx1>x2 + y3 &&   mx1 + my0<x4 + y5 && ( miku.mp_ry+miku.real_H <= bhit[i].y  || miku.mp_rx+miku.real_W <= bhit[i].x )  ){
			miku.n_line[i][0] = 1;//左上にいる
		DrawFormatString(480, 16 * 5 + i * 16, 0xffffff, "%dの左上ライン", i);
		}
		else miku.n_line[i][0] = 0;


		//左下
		if (my1 - mx1<y2 - x2 && my1 - mx1 >y4 - x4 && (miku.mp_rx + miku.real_W <= bhit[i].x || miku.mp_ry >= bhit[i].y + field.Chip)){
			miku.n_line[i][2] = 1;//左下
		}
		else 	miku.n_line[i][2] = 0;//

		//右上
		if (my1 - mx1<y2 - x2 && my1 - mx1 >y4 - x4 && (miku.mp_rx >= bhit[i].x+field.Chip || miku.mp_ry+miku.real_H <= bhit[i].y )){
			miku.n_line[i][1] = 1;//右上

			
		}
		else 	miku.n_line[i][1] = 0;//


	}
	DrawFormatString(480, 16 * 6, 0xffffff, "miku.n_line[i]:%d", miku.n_line[i]);

	//DrawFormatString(480, 16 * 7, 0xffffff, "x4+y4:%d", x4 + y4);
	//DrawFormatString(480, 16 * 8, 0xffffff, "x2+y2:%d", x2 + );
	//DrawFormatString(480, 16 * 9, 0xffffff, "x3+y3:%d", x3 + y3);


	//	else miku.n_line[0] = -1;



}


void p_anime(){


	if (key.c != -1){
		miku.anime_c--;//アニメーションカウンタマイナス
		if (miku.anime_c <= 0){

			if (key.z)miku.anime_c = 2;
			else miku.anime_c = 10;
			if (miku.anime >= 5){
				miku.anime = 0;
			}
			else{ miku.anime++; }
		}
	}
	else{
		miku.anime = 0;//アニメリセット


	}
}

