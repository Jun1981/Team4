#pragma once

#include "Menu.h"
#include "Fonts.h"
#include "Object.h"

#define towerSpace 80
class stageSelect{
public:

	int bgGh;//背景画像
	int objGh;//その他の画像ファイル



};



//クラス宣言
extern Menu stgSel;//クラス宣言
extern Fonts fonts;
extern Object bg;//オブジェクトクラス　背景インスタンス
extern Object fairy;//オブジェクトクラス　妖精インスタンス

//////////////////////////////

void stageInit();//初期化
void stageCal();//計算
void stageDraw();//描画



