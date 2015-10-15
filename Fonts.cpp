#include "Fonts.h"
#include "../DxLib/DxLib.h"
void Fonts::loadFont(){
	if (AddFontResourceEx(path, FR_PRIVATE, NULL) > 0) {
	} else {
		// フォント読込エラー処理
		MessageBox(NULL,"フォント読込失敗","",MB_OK);
	}
}

void Fonts::deleteFont(){
	if(RemoveFontResourceEx(path, FR_PRIVATE, NULL)) {
	} else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}
}