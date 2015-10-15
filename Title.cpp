#include "Title.h"
#include "../DxLib/DxLib.h"
#include "Menu.h"
#include <time.h>
#include <iostream>
#include "key.h"
#include "GameMain.h"

Menu tSel;//�^�C�g���p���j���[

//�^�C�g���֌W������
void titleInit(){
	srand((unsigned int)time(NULL));//���ԂŃ����_������


	//�I��p
	tSel.num=0;//��������
	tSel.numOfItems=2;//���ڐ��Q

	//�e�z��쐬
	tSel.setArrayGh(1);//�w�i�摜�n���h���̔z��
	tSel.setArrayGhItem();
	
	tSel.setArrayGhCur(1);


	//�摜�ǂݍ���Ŋe�n���h���Ɋi�[
	//�^�C�g��
	tSel.setGh(0,"../img/Title/Title.png");
	tSel.setGhItem(0,"../img/cursorBg/NewGame.png");
	tSel.setGhItem(1,"../img/cursorBg/EndGame.png");
	
	//stgSel.setGh(0,"../img/stageSelect/bg.png");


	//tSel.itemInitX[0]=200,tSel.itemInitY[0]=300;//�o���[�����̏����ʒu
	//tSel.itemInitX[0]=200,tSel.itemInitY[0]=300;
	//�����ʒu�ݒ�
	tSel.setItemInitXY(200,300,0);//�o���[�����̏����ʒu
	tSel.setItemInitXY(400,300,1);//�o���[���E�̏����ʒu

	tSel.setItemXY(200,200,0);
	tSel.setItemXY(400,300,1);


}

void titleCal(){
	if(game.fadeMode==0){//�t�F�[�h���[�h���O�Ȃ�
		tSel.calHori();//�v�Z

		if(key_Trg==0x100){//�G���^�[�L�[�������ꂽ��
			if(tSel.num==L){//�J�[�\�������[
				game.fadeMode=2;
				game.nextMode=2;//�X�e�[�W�Z���N�g��

			}else if(tSel.num=R){//�J�[�\�����E�[�Ȃ�
				game.fadeMode=2;//�t�F�[�h�A�E�g
				game.nextMode=-1;//�I����
			}
		}
	}
	else if(game.fadeMode==2){//�t�F�[�h�A�E�g���[�h
		//game.brightness-=3;

		//if(game.brightness<=0){game.mode=game.nextMode;
		//tSel.termProc();//�I������
		//}

		if(game.fadeOut(10)==100)tSel.close();//�I������;
	}

}

	void titleDraw(){
		DrawGraph(0,0,tSel.bgGh[0],1);//�w�i�`��

		if(tSel.num!=L)SetDrawBright(game.brightness/2,game.brightness/2,game.brightness/2);//�O���I�΂�ĂȂ�������摜���Â����� 
		DrawRotaGraph(tSel.itemX[L],tSel.itemY[L],1.0,0,tSel.itemGh[L],1,0);//���@���D�`��
		SetDrawBright(game.brightness,game.brightness,game.brightness);//���邳�����ɖ߂�

		if(tSel.num!=R)SetDrawBright(game.brightness/2,game.brightness/2,game.brightness/2);//�O���I�΂�ĂȂ�������摜���Â�����
		DrawRotaGraph(tSel.itemX[R],tSel.itemY[R],1.0,0,tSel.itemGh[R],1,0);//�E�@���D�`��
		SetDrawBright(game.brightness,game.brightness,game.brightness);//���邳�����ɖ߂�


	}