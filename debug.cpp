#include "debug.h"

#include "../DxLib/DxLib.h"

#include "MIKU.h"

#include "key.h"

#include "map.h"

#include "GameMain.h"

#include "menu.h"


void debug_msg(){

	/*DrawFormatString(320, 16,(255,255,255) , "ミクのアニメ番号(%d,)",miku.anime);
		DrawFormatString(320, 16*2,(255,255,255) , "アニメカウント,%d)",miku.anime_c);
		DrawFormatString(320, 16*3,(255,255,255) , "十字キー,%d)",key.c);

		DrawFormatString(320, 16*4,(255,255,255) , "一時十字キー,%d)",Key_Trg);


		DrawFormatString(320, 16*5,(255,255,255) , "マップあまり,%d)",miku.mp_rx%32);
		DrawFormatString(320, 16*6,(255,255,255) , "ブレンドモード,%d)",alpha);*/


	DrawFormatString(400, 16*4,(255,255,255) , "キー,%d)",Key_Info);
		DrawFormatString( 400, 16*6,(255,255,255), "マップチップアイテム%d",mapChip_Item);
			DrawFormatString( 400, 16*7,(255,255,255), "アイテム向かい合い(0,0)%d",EvtBlockTouch[0][0]);




}

