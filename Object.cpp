#include "Object.h"
#include "../DxLib/DxLib.h"


//�R���X�g���N�^
Object::Object(){
	x=y=gh=0;
}
//�Z�b�^�[
void Object::setGh(const char* str){

 gh=LoadGraph(str,0);

}
void Object::setXY(int a, int b){
	x=a;y=b;

}

//�Q�b�^�[

int Object::getGh(){

	return gh;


}