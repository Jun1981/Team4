//#include "../DxLib/DxLib.h"

//#include "Title.h"

//Title t;//宣言　タイトル
//Select tSel;//選択用

//初期化

//選択

//
//
////スタート
//void Title::start(){	
//	if(game.fadeMode==0){
//			cal();//計算
//	}
//	if(game.fadeMode==2){//フェードアウトモード
//		game.brightness-=3;
//	
//		if(game.brightness<=0)game.mode=game.nextMode;
//	}
//		draw();//描画
//
//}

//
////描画
//void Title::draw(){
//	DrawGraph(0,0,t.bgGh,1);//背景描画
//
//	if(tSel.num!=0)SetDrawBright(game.brightness/2,game.brightness/2,game.brightness/2);//０が選ばれてなかったら画像を暗くする 
//	DrawRotaGraph(t.balX[L],t.balY[L],1.0,0,t.balGh[L],1,0);//左　風船描画
//	SetDrawBright(game.brightness,game.brightness,game.brightness);//明るさを元に戻す
//	
//	if(tSel.num!=1)SetDrawBright(game.brightness/2,game.brightness/2,game.brightness/2);//０が選ばれてなかったら画像を暗くする
//	DrawRotaGraph(t.balX[R],t.balY[R],1.0,0,t.balGh[R],1,0);//右　風船描画
//	SetDrawBright(game.brightness,game.brightness,game.brightness);//明るさを元に戻す
//	
//	//DrawGraph(t.balX[tSel.num],t.balY[tSel.num],t.curGh,1);//カーソル描画	
//}
//
////計算
//void Title::cal(){	
//	//風船のランダム上下移動
//	int a=rand()%3-1;
//	int b=rand()%3-1;
//	t.balY[L]+=a;
//	t.balY[R]+=b;
//	int z=0;
//
//
//	tSel.cal();
//
//	if(tSel.num==0){//左端だったら
//		if(key_Trg==0x100){//エンターキーが押されたら
//			game.nextMode=2;//ステージセレクト予定
//			game.fadeMode=2;//フェードアウト
//
//		}
//
//	}else if(tSel.num==1){
//		if(key_Trg==0x100){//エンターキーが押されたら
//			exit(0);//終了
//		}
//
//
//	}
//}