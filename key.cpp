#include "key.h"
#include "../DxLib/DxLib.h"

int key_Trg, key_Info, key_Old, chkKeyAny;

KEY key;//クラス：：キー　方向キーやボタン


//キーチェック
void key_chk(){

	/*---------------------
	*    キー情報取得    *
	*---------------------
	*
	*    LEFT  = 0000 0001
	*    RIGHT = 0000 0010
	*    UP    = 0000 0100
	*    DOWN  = 0000 1000
	*    key_Trgは押した瞬間の情報
	*    key_infoは今の状態
	*
	*/
	key_Trg = key_Info = 0;                                 // キー情報クリア
	chkKeyAny = false;
	

	if (CheckHitKey(KEY_INPUT_LEFT))   { key_Info |= 0x01; }
	if (CheckHitKey(KEY_INPUT_RIGHT))  { key_Info |= 0x02; }
	if (CheckHitKey(KEY_INPUT_UP))     { key_Info |= 0x04; }
	if (CheckHitKey(KEY_INPUT_DOWN))   { key_Info |= 0x08; }
	if (CheckHitKey(KEY_INPUT_SPACE))  { key_Info |= 0x10; }
	if (CheckHitKey(KEY_INPUT_Z))      { key_Info |= 0x20; }
	if (CheckHitKey(KEY_INPUT_X))      { key_Info |= 0x80; }
	if (CheckHitKey(KEY_INPUT_ESCAPE)) { key_Info |= 0x40; }
	
	if( CheckHitKey( KEY_INPUT_RETURN )){key_Info |= 0x100;}//エンターキー


	if (CheckHitKeyAll()) { chkKeyAny = true; }                    // あにー

	key_Trg = (key_Info ^ key_Old) & key_Info;          // キートリガー情報セット
	key_Old = key_Info;                                     // キー情報セーブ


}

void key_henkan(void){


	//上下左右おしっぱ

	if (chkKeyAny == TRUE){

		if ((key_Info & 0x0f) == 0x01){ key.c = 2; }//左
		if ((key_Info & 0x0f) == 0x02){ key.c = 6; }//右
		if ((key_Info & 0x0f) == 0x04){ key.c = 4; }//上
		if (key_Trg  == 0x04){ key.ct = 4; }//上

		if ((key_Info & 0x0f) == 0x08){ key.c = 0; }//下
		if (key_Trg  == 0x08){ key.ct = 0; }//下
						  
						  
		if ((key_Info & 0x0f) == 0x05){ key.c = 3; }//左上
						   
		if ((key_Info & 0x0f) == 0x06){ key.c = 5; }//右上
						   
		if ((key_Info & 0x0f) == 0x09){ key.c = 1; }//左下
						   
		if ((key_Info & 0x0f) == 0x0a){ key.c = 7; }//右下
		/////////////////////////////

		if ((key_Info & 0x0f) == 0x00){
			key.c = -1;//十字キー無効
		}




		if ((key_Info & 0x20) == 0x20){ key.z = 1; }else{ key.z = 0; }//ｚキー
		if ((key_Info & 0x80) == 0x80)key.x = 1; else key.x=0;//ｘキー

		

	}
	else{ key.c=-1; key.z = 0;key.x=0; }//キー押してない

}