#include "Select.h"
#include "key.h"

#include "../DxLib/DxLib.h"

void Select::calHori(){//�����j���[�̌v�Z

	//�E�������ꂽ��
	if(key_Trg==0x02){
		if(num<numOfItems-1){
			num++;//���ݔԍ��{�{			
		}
		else{
			num=0;//�ԍ����Z�b�g		
		}
	}
	
	if(key_Trg==0x01){
		if(num>0){
			num--;
		}else
			num=numOfItems-1;		
	}
	
}
//�w�i�摜
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


//�A�C�e���̈ʒu�ݒ�
void Select::setItemXY(int x,int y,int n){
	itemX[n]=x;itemY[n]=y;

}
//�A�C�e���̏����ʒu�ݒ�
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

//�R���X�g���N�^
Select::Select(){

	bgGh=itemGh=curGh=itemX=itemY=itemInitX=itemInitY=0;



}
//�I������
void Select::termProc(){
	delete[] bgGh;
	delete[] itemGh;
	delete[] curGh;
	delete[] itemX;
	delete[] itemY;
	delete[] itemInitX;
	delete[] itemInitY;
}