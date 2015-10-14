#pragma once


class Select {
protected:
	

	
public:
	
	int *itemGh;//項目の背景

	int *curGh;//カーソルの画像
	int *bgGh;//背景画像

	int num;//現在の項目番号
	int numOfItems;//項目数

	int *itemX,*itemY;//項目の座標
	int *itemInitX, *itemInitY;//項目の初期座標

	
	
	int curX,curY;//カーソル座標(左上）
	int curInitX,curInitCurY;//カーソルの初期位置
	
	
		
	//セッター
	void setArrayGh(int);//背景画像の配列作成 枚数
	void setArrayGhItem();//項目背景の配列作成
	void setArrayGhCur(int);//カーソルの配列作成
	//void setArrayItemInitXY();//アイテム座標の初期位置
	//void setArrayItemXY();
	void setItemInitXY(int,int,int);//アイテムの初期位置セットｘｙ　何個目のメニューか
	void setItemXY(int,int,int);//
	//void (*fpSetItemInitXY);
	void setGh(int,const char*);//グラフィックハンドラに読み込む関数（何個目の項目、ファイルパス）
	
	void setGhItem(int,const char*);//
	void setGhCur(int ,const char*);//カーソルのハンドラゲット

	
	//計算関係
	void calHori( );//計算 横　メニュー(項目数）　現在の番号を返す
	//void draw();//描画


	Select();//コンストラクタ
	void termProc();//終了処理
	
};

//Lが０　Rが１
enum titleLR{
L,
R,
};//enum

//extern Select titleSel;//タイトル　セレクト

extern Select tSel;