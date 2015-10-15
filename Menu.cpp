#include "Menu.h"
#include "key.h"

#include "../DxLib/DxLib.h"

void Menu::calHori(){//�����j���[�̌v�Z

	//�E�������ꂽ��
	if(key_Trg==keyRight){
		if(num<numOfItems-1){
			num++;//���ݔԍ��{�{			
		}
		else{
			num=0;//�ԍ����Z�b�g		
		}
	}
	//������������
	if(key_Trg==0x01){
		if(num>0){
			num--;
		}else
			num=numOfItems-1;		
	}
	
}
//�w�i�摜
void Menu::setArrayGh(int n){

	bgGh=new int[n];

}

void Menu::setArrayGhItem(int n){

	itemGh=new int[n];
	itemX=new int[n];
	itemY=new int[n];
	itemInitX=new int[n];
	itemInitY=new int[n];
	
}
void Menu::setArrayGhItem(){

	itemGh=new int[numOfItems];
	itemX=new int[numOfItems];
	itemY=new int[numOfItems];
	itemInitX=new int[numOfItems];
	itemInitY=new int[numOfItems];
	
}

void Menu::setArrayGhCur(int n){
	curGh=new int[n];
	
}


//�A�C�e���̈ʒu�ݒ�
void Menu::setItemXY(int x,int y,int n){
	itemX[n]=x;itemY[n]=y;

}
//�A�C�e���̏����ʒu�ݒ�
void Menu::setItemInitXY(int x,int y,int n){	
	itemInitX[n]=x;itemInitY[n]=y;
}

void Menu::setGh(int n,const char* string){
		bgGh[n]=LoadGraph(string,0);
}

void Menu::setGhItem(int n,const char* string){
		itemGh[n]=LoadGraph(string,0);
}

void Menu::setGhCur(int n,const char* string){
		curGh[n]=LoadGraph(string,0);
}

//�R���X�g���N�^
Menu::Menu(){

	bgGh=itemGh=curGh=itemX=itemY=itemInitX=itemInitY=0;



}
//�I������
void Menu::close(){
	delete[] bgGh;
	delete[] itemGh;
	delete[] curGh;
	delete[] itemX;
	delete[] itemY;
	delete[] itemInitX;
	delete[] itemInitY;
}