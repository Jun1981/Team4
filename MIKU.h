#pragma once




//クラス宣言
class MIKU{

private:
	
	//グラフィックハンドラ
	int GH[8];//８方向
	int GH_Run[8][6];//８方向の向きループ画像 ２つ目の配列はアニメーション番号


public:

	//MIKU();//デフォルトコンストラクタ
	//~MIKU();//デストラクタ

	/*座標は左上から

	*/

	//実際の
	int real_W;//実際の幅
	int real_H;//実際の高さ

	int mp_rx;//マップ内での実際のx座標
	int mp_ry;//マップ内での実際のｙ座標

	int dsp_rx;//画面内の実際のｘ座標（左から数えて）
	int dsp_ry;//画面内の実際のy座標（上から数えて）

	int muki;//向き


	//見た目
	int mp_x;//マップ内での見た目のｘ座標
	int mp_y;//マップ内での見た目のｙ座標	
	
	int dsp_x;//画面内の見た目のｘ座標（左から数えて）
	int dsp_y;//画面内の見た目のｙ座標（上から数えて）
	
	int W;//見た目の幅	
	int H;//見た目の高さ

	int spd;//移動スピード
	int n_spd;//斜め移動スピード

	int n_line[1200][4];//斜めラインチェック用

	int anime;//アニメーション
	int anime_c;//アニメーションカウンタ

	//関数
	void Init();//ミク変数初期化
	void LoadImg();//自機画像読み込み
	void Draw();//ミク描画関数
	

};

///ミク
void miku_init();//
extern MIKU miku;//クラス宣言

//
////関数宣言
//void P_LoadImg();//自機画像読み込み



extern void p_move(void);


extern void mv_chk(int,int*);
extern void dia_chk(void);
extern void p_anime(void);

extern int nokori[2];

