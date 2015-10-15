#include "Object.h"
#include "../DxLib/DxLib.h"


//コンストラクタ
Object::Object(){
	x=y=gh=0;
}
//セッター
void Object::setGh(const char* str){

 gh=LoadGraph(str,0);

}
void Object::setXY(int a, int b){
	x=a;y=b;

}

//ゲッター

int Object::getGh(){

	return gh;


}