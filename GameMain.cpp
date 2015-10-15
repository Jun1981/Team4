
#include "GameMain.h"
//#include "Title.h"
//�����_���p
#include <time.h>
#include <iostream>
#include "Menu.h"
//
#include "../DxLib/DxLib.h"

#include "key.h"

//���C������
#include "debug.h"

#include "Title.h"

#include "stageSelect.h"

#include "Fonts.h"



//�N���X��`
GameMain game;//�N���X�錾

//�R���X�g���N�^
GameMain::GameMain(){
	brightness=255;
	fadeMode=0;//�ʏ�

}


//Menu stgSel;//�X�e�[�W�Z���N�g

void GameMain::start(){

	switch(game.mode){

	case -1://�I��

		exit(0);

		fonts.deleteFont();//�t�H���g���̂Ă�

		break;
	case 0://�������@�֌W

		titleInit();//�^�C�g��������
		stageInit();//�X�e�[�W������

		game.mode=1;//�^�C�g����ʂ�		

		break;

	case 1://�^�C�g�����

		titleCal();//�^�C�g���v�Z
		titleDraw();//�^�C�g���`��

		debug();//�f�o�b�O


		//tSel.termProc();//�^�C�g���֌W�I������
		break;


	case 2://�X�e�[�W�Z���N�g���[�h

		
		
		if(game.fadeIn(10)==100){

		//	DrawGraph(0,0,stgSel.bgGh[0],1);
		//DrawString(100,400,"�X�e�[�W�Z���N�g",GetColor(255,255,255),0);

		stageCal();//�v�Z
		stageDraw();//�`��
		}
		break;

	}
}
///////////////////////////////////////////////////////////



int GameMain::fadeOut(int n){
	game.brightness-=n;
	SetDrawBright(game.brightness,game.brightness,game.brightness);
		if(game.brightness<=0){
		game.mode=game.nextMode;//���̃��[�h��
		game.fadeMode=0;//�t�F�[�h���[�h�����ɖ߂�
		return 100;
		}

	return 0;
}

int GameMain::fadeIn(int n){
	game.brightness+=n;
	SetDrawBright(game.brightness,game.brightness,game.brightness);
	if(game.brightness>=255){
		game.fadeMode=0;//�t�F�[�h���[�h�����ɖ߂�
		return 100;
		}
	return 0;
}

