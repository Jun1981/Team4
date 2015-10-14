#include "Select.h"
#include "key.h"

#include "../DxLib/DxLib.h"

void Select::calHori(){//横メニューの計算

	//右が押されたら
	if(key_Trg==0x02){
		if(num<numOfItems-1){
			num++;//現在番号＋＋			
		}
		else{
			num=0;//番号リセット		
		}
	}
	
	if(key_Trg==0x01){
		if(num>0){
			num--;
		}else
			num=numOfItems-1;		
	}
	
}
//背景画像
void Select::setArrayGh(int n){

	bgGh=new int[n];

}

void Select::setArrayGhItem(){

	itemGh=new int[numOfItems];
	itemX=new int[numOfItems];
	itemY=new int[numOfItems];
	itemInitX=new int[numOfItems];
	itemInitY=new int[numOfItems];
	
}

void Select::setArrayGhCur(int n){
	curGh=new int[n];
	
}


//アイテムの位置設定
void Select::setItemXY(int x,int y,int n){
	itemX[n]=x;itemY[n]=y;

}
//アイテムの初期位置設定
void Select::setItemInitXY(int x,int y,int n){	
	itemInitX[n]=x;itemInitY[n]=y;
}

void Select::setGh(int n,const char* string){
		bgGh[n]=LoadGraph(string,0);
}

void Select::setGhItem(int n,const char* string){
		itemGh[n]=LoadGraph(string,0);
}

void Select::setGhCur(int n,const char* string){
		curGh[n]=LoadGraph(string,0);
}

//コンストラクタ
Select::Select(){

	bgGh=itemGh=curGh=itemX=itemY=itemInitX=itemInitY=0;



}
//終了処理
void Select::termProc(){
	delete[] bgGh;
	delete[] itemGh;
	delete[] curGh;
	delete[] itemX;
	delete[] itemY;
	delete[] itemInitX;
	delete[] itemInitY;
}