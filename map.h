#pragma once


#define MAP_BW 100
#define MAP_BH 100


class MAP{
private:
	int* ChipH ;//グラフィックチップハンドラ
	
public:

	int W;//幅
	int H;//高さ

	int BW;//横のブロック数
	int BH;//縦のブロック数
	

	//const int BN;//全ブロック数

	int Chip;//マップチップのサイズ

	int** bg_array;

	char *ChipName;//マップチップの名前

	int bn;//当たりブロックの数
		


	int GH;
	int ItemWIndowGH;

	void CreateMap();

	


};

class MHit{
public:
	
	int x,y;
	int haba;

	double x_sa[2];//x座標の差
	double y_sa[2];


	
};
extern MAP map;
//関数；
extern void LoadMap1();//ベースマップ
extern void DrawMap();
extern void DrawMap2();

extern void DrawMapItems();//マップアイテム描画
extern void DrawMapEvt2();//門とかボスとか表示関数





extern MHit bhit[100*100];//マップ　縦ブロックｘ横ブロック


//extern int mhit2[30][40];


//マップチップ用グラフィックハンドラ
extern int map3[16*16];//マップチップ用
extern int mapChip_Item[16*16];//マップチップ（アイテム）
extern int mapChip_Evt[16*16];//マップチップ（イベント）

extern int map_Evt2_Hit[MAP_BH][MAP_BW];//マップイベント(ボス）当たり判定


extern int map_base3[MAP_BH][MAP_BW];//マップ１描画用

extern int map_Evt2_Draw[MAP_BH][MAP_BW];//マップイベント描画用マップデータ


extern int mhit3[MAP_BH][MAP_BW];//基礎地形当たり判定


extern int mhit3_posX[MAP_BH][MAP_BW];//マップブロック当たり判定x座標
extern int mhit3_posY[MAP_BH][MAP_BW];//マップブロック当たり判定y座標




extern int map_ItemXY[MAP_BH][MAP_BW];//マップアイテムの場所
extern int map_ItemHit[MAP_BH][MAP_BW];//マップイベント　ヒット判定

extern int map_ItemHitPos_X[MAP_BH][MAP_BW];//マップイベント　の場所の左上のX座標
extern int map_ItemHitPos_Y[MAP_BH][MAP_BW];//マップイベント　の場所の左上のY座標


extern int map_EvtHitPos_X[MAP_BH][MAP_BW];//マップイベント　の場所の左上のX座標
extern int map_EvtHitPos_Y[MAP_BH][MAP_BW];//マップイベント　の場所の左上のY座標

//extern int map_HitChk[MAP_BH][MAP_BW];//マップヒットチェック　どのブロックに向き合って接触しているか

extern int ItemWinDrawFlag;//アイテムウィンドウを表示するfか