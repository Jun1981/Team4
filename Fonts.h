#pragma once
#include "../DxLib/DxLib.h"

class Fonts{

public:


	LPSTR path;//フォントのパス名
	void loadFont();//フォントを読み込む
	void deleteFont();//読み込んだフォントを消す

};