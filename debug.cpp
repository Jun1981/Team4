#include "debug.h"
#include "GameMain.h"
#include "Select.h"
#include <iostream>
#include "key.h"

#include "../DxLib/DxLib.h"
void debug(){

	
	DrawFormatString(100,200,GetColor(255,255,255),"カーソルナンバー%d",tSel.num);
	DrawFormatString(100,200+16,GetColor(255,255,255),"キー0x%03x",key_Trg);
	DrawFormatString(100,200+16*2,GetColor(255,255,255),"キーおしっぱ0x%03x",key_Info);



}


