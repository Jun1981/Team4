
class MAP{
private:
	int* ChipH ;//グラフィックチップハンドラ
	
public:

	int W;//幅
	int H;//高さ

	int BW;//横のブロック数
	int BH;//縦のブロック数

	int Chip;//マップチップのサイズ

	int** bg_array;

	char *ChipName;//マップチップの名前

	int bn;//当たりブロックの数

	


	int GH;

	void CreateMap();


};

class MHit{
public:

	 //int mchip[15][20];//マップチップ
	 //int mhit[15][20];//通行設定

	int x,y;
	int haba;

	double x_sa[2];//x座標の差
	double y_sa[2];


	
};
extern MAP field;
extern MAP map;

extern void LoadMap1();//ベースマップ
extern void DrawMap();

extern MHit bhit[1200];


extern int mhit2[40][30];