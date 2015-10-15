#include "stageSelect.h"
#include "key.h"

#include "../DxLib/DxLib.h"

#include "Fonts.h"
#include "GameMain.h"
//���w�n
#define _USE_MATH_DEFINES // for C++
#include <cmath>

#include "Fonts.h"

#include "Object.h"
//////////////////////////////////////

Menu stgSel;//�I���N���X�@�X�e�[�W�Z���N�g�p���j���[
Fonts fonts;//�t�H���g�N���X�@	�t�H���g
Object bg;//�I�u�W�F�N�g�N���X�@�w�i
Object fairy;//�I�u�W�F�N�g�N���X�@�d���C���X�^���X


void stageInit(){//������
	//�t�H���g�֌W
	fonts.path="..\\Fonts\\uzura.ttf";//������t�H���g
	fonts.loadFont();//�t�H���g�̓ǂݍ���
	
	//////////////////////////


	stgSel.numOfItems=3;

	//�z��쐬
	stgSel.setArrayGh(1);//�w�i�摜�n���h���̔z��
	stgSel.setArrayGhItem(1);//���j���[�w�i�摜�i���j	
	stgSel.setArrayGhCur(1);

	//�摜�ǂݍ���Ŋe�n���h���Ɋi�[
	//�^�C�g��
	stgSel.setGh(0,"../img/stageSelect/bg1.png");//�w�i�ǂݍ���
	/*stgSel.setGhItem(0,"../img/cursorBg/NewGame.png");
	stgSel.setGhItem(1,"../img/cursorBg/EndGame.png");*/
	stgSel.setGhItem(0,"../img/stageSelect/tower.png");//���ǂݍ���
	stgSel.setGhCur(0,"../img/cursor/finger1.png");//�J�[�\���ǂݍ���

	//���̑��I�u�W�F�摜
	bg.setGh("../img/stageSelect/bg1.png");//�w�i�摜
	fairy.setGh("../img/Object/pixy.png");//�d���摜

	//�����ʒu�ݒ�
	stgSel.setItemInitXY(0,200,0);//���P�̏����ʒu
	stgSel.setItemInitXY(240,200,1);//��2�̏����ʒu
	stgSel.setItemInitXY(240*2,200,2);//��3�̏����ʒu

	
	stgSel.setItemXY(stgSel.itemInitX[0],200,0);
	stgSel.setItemXY(stgSel.itemInitX[1],200,1);
	stgSel.setItemXY(stgSel.itemInitX[2],200,2);

	fairy.setXY(100,100);//�d�������ʒu�ݒ�

	stgSel.curX=stgSel.itemInitX[0]+towerSpace;stgSel.curY=stgSel.itemInitY[0];


}
void stageCal(){//�v�Z
	if(game.fadeMode==0){//�t�F�[�h���[�h���O�Ȃ�
		stgSel.calHori();//�v�Z
		stgSel.curX=stgSel.itemInitX[stgSel.num]+towerSpace;//�J�[�\���ʒu�v�Z
		
		if(key_Trg==0x100){//�G���^�[�L�[�������ꂽ��
			if(stgSel.num==0){//�J�[�\�������[
				//game.fadeMode=2;
				//game.nextMode=2;//�X�e�[�W�Z���N�g��
				

			}else if(stgSel.num==1){//�J�[�\����1�Ȃ�
				//game.fadeMode=2;//�t�F�[�h�A�E�g
				//game.nextMode=-1;//�I����
			}else if(stgSel.num==2){//�J�[�\�����Q�Ȃ�
				//game.fadeMode=2;//�t�F�[�h�A�E�g
				//game.nextMode=-1;//�I����
			}
		}
	}
	else if(game.fadeMode==2){//�t�F�[�h�A�E�g���[�h

		if(game.fadeOut(10)==100)stgSel.close();//�I������;
	}

}

//�\���n
void stageDraw(){
	//�w�i�摜
	//DrawGraph(0,0,stgSel.bgGh[0],1);
	DrawGraph(0,0,bg.getGh(),1);
	//��1
	DrawGraph(stgSel.itemX[0],stgSel.itemY[0],stgSel.itemGh[0],1);//�摜
	DrawString( stgSel.itemX[0]+towerSpace , 515, "����", GetColor( 0 , 0 , 0 ) );//����
	
	//��2
	DrawGraph(stgSel.itemX[1],stgSel.itemY[1],stgSel.itemGh[0],1);//�摜
	DrawString( stgSel.itemX[1]+towerSpace , 515, "����", GetColor( 0 , 0 , 0 ) );//����
	//���R
	DrawGraph(stgSel.itemX[2],stgSel.itemY[2],stgSel.itemGh[0],1);//�摜
	DrawString( stgSel.itemX[2]+towerSpace , 515, "�㋉", GetColor( 0 , 0 , 0 ) );//����
	

	//���̑�
	DrawRotaGraph(fairy.x,fairy.y,0.3,0,fairy.getGh(),1);//�d���摜�\��(0.2�{)

	//�J�[�\��
	DrawRotaGraph(stgSel.curX,stgSel.curY,0.3,M_PI/2,stgSel.curGh[0],1,0);//�J�[�\���摜�i�w�j�`��@0.3�{�@90�x��]


	//�t�H���g
		SetFontSize(60);	// ���₷���̂��߁A�t�H���g�T�C�Y��傫��
		ChangeFont( "������t�H���g", DX_CHARSET_DEFAULT );
		
		
		


}




