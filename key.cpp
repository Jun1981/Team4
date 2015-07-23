#include "key.h"
#include "../DxLib/DxLib.h"

int Key_Trg, Key_Info, Key_Old, ChkKAny;

KEY key;//クラス：：キー　方向キーやボタン

void key_chk(){

	/*---------------------
	*    キー情報取得    *
	*---------------------
	*
	*    LEFT  = 0000 0001
	*    RIGHT = 0000 0010
	*    UP    = 0000 0100
	*    DOWN  = 0000 1000
	*    key_trgは押した瞬間の情報
	*    key_infoは今の状態
	*
	*/
	Key_Trg = Key_Info = 0;                                 // キー情報クリア
	ChkKAny = false;
	

	if (CheckHitKey(KEY_INPUT_LEFT))   { Key_Info |= 0x01; }
	if (CheckHitKey(KEY_INPUT_RIGHT))  { Key_Info |= 0x02; }
	if (CheckHitKey(KEY_INPUT_UP))     { Key_Info |= 0x04; }
	if (CheckHitKey(KEY_INPUT_DOWN))   { Key_Info |= 0x08; }
	if (CheckHitKey(KEY_INPUT_SPACE))  { Key_Info |= 0x10; }
	if (CheckHitKey(KEY_INPUT_Z))      { Key_Info |= 0x20; }
	if (CheckHitKey(KEY_INPUT_X))      { Key_Info |= 0x80; }
	if (CheckHitKey(KEY_INPUT_ESCAPE)) { Key_Info |= 0x40; }
	
	if( CheckHitKey( KEY_INPUT_RETURN )){Key_Info |= 0x100;}//エンターキー


	if (CheckHitKeyAll()) { ChkKAny = true; }                    // あにー

	Key_Trg = (Key_Info ^ Key_Old) & Key_Info;          // キートリガー情報セット
	Key_Old = Key_Info;                                     // キー情報セーブ


}

void key_henkan(void){


	//上下左右おしっぱ

	if (ChkKAny == TRUE){

		if ((Key_Info & 0x0f) == 0x01){ key.c = 2; }//左
		if ((Key_Info & 0x0f) == 0x02){ key.c = 6; }//右
		if ((Key_Info & 0x0f) == 0x04){ key.c = 4; }//上
		if (Key_Trg  == 0x04){ key.ct = 4; }//上

		if ((Key_Info & 0x0f) == 0x08){ key.c = 0; }//下
		if (Key_Trg  == 0x08){ key.ct = 0; }//下
						  
						  
		if ((Key_Info & 0x0f) == 0x05){ key.c = 3; }//左上
						   
		if ((Key_Info & 0x0f) == 0x06){ key.c = 5; }//右上
						   
		if ((Key_Info & 0x0f) == 0x09){ key.c = 1; }//左下
						   
		if ((Key_Info & 0x0f) == 0x0a){ key.c = 7; }//右下
		/////////////////////////////

		if ((Key_Info & 0x0f) == 0x00){
			key.c = -1;//十字キー無効
		}




		if ((Key_Info & 0x20) == 0x20){ key.z = 1; }else{ key.z = 0; }//ｚキー
		if ((Key_Info & 0x80) == 0x80)key.x = 1; else key.x=0;//ｘキー

		

	}
	else{ key.c=-1; key.z = 0;key.x=0; }//キー押してない

}