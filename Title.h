#pragma once 



class Title{
public:
	int bgGh;//画像ハンドラ

	int curGh;//カーソルの画像ハンドラ
	int balGh[2];//風船の画像ハンドラ

	int balX[2],balY[2];//風船の座標
	int balInitX[2],balInitY[2];//画像の初期位置

	//int curX,curY;//カーソル座標
	
	//関数
	//void init();//初期化
	
	void cal();//計算
	void draw();//描画

	void start();//全部
};

extern Title t;
extern void titleInit();//タイトル初期化

//左が０右が1
enum titleLR{
L,
R,
};//enum