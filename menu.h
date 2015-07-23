#pragma once


class MENU{

public:


	//画像読み込み用変数
	int GH_MAP;//グラフィックハンドラ
	int GH_CURSOR;//カーソル画像入れるハンドら
	int GH_ITEM;//アイテム画面の画像読み込み用

	int GH_EQ;//装備メニュー画面読み込み用



	//メニュー移動関係の数値
	int L_List_pos;//メニューの左のカーソルの位置
	int L_List_Num;//メニューの数
	int L_List_Ini_Pos;//メニュー左カーソルの初期位置
	int L_List_Mv_Amt;//左カーソルの移動量


	
	int Mode ;//メニューモード（　０：基本　１：装備　２：システム -1:メニューじゃない）


};


struct ITEM{
	int ID;			// アイテム固有の識別番号
	int kind;		// アイテム別、種類分け（武器、防具等）
	int narabi;		// アイテム別で表示する場合に使用（アイテムすべて表示する場合IDを使用）
	char name[100];		// アイテムの名前
	int stock;			// アイテムのストック限界数
	int power;		// 効力（武器なら攻撃力、防具なら防御力等）
	char info[256];		// 説明文（有れば使用）
};

extern enum kind;



extern MENU menu;


//関数宣言
void menu_init();
void menu_chk();
void menu_draw();
void menu_KeyCal();//カーソルの移動計算
