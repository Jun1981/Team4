#include "GameMain.h"
#include <time.h>
#include "../DxLib/DxLib.h"
#include "MIKU.h"
#include "key.h"

#include"map.h"
#include "menu.h"

int G_MODE=0;




 int alpha=255;

int fade_mode=0;//�t�F�[�h���[�h (�O�F�Ȃ��A�P�F�t�F�[�h�C���@�Q�F�t�F�[�h�A�E�g�j
//static int fade_cnt=2;//�t�F�[�h�J�E���g�p


void GameMain(){
	switch(G_MODE){		

		//�I�[�v�j���O
	case 0:
		break;
		////////////////////////////////////




		//�{�Q�[��/////////////////////////////////////////
	case 1:



		
		//�t�F�[�h�C��
		if(fade_mode==1){

			if (alpha <= 254){
				alpha += 32;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
				if(alpha>=255){

					fade_mode=0;//�t�F�[�h�C�����[�h
					//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
				}
			}
		}
		//�t�F�[�h�A�E�g
		if(fade_mode==2){
			//fade_cnt--;
				if (alpha >= 2){
					alpha -= 16;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
					if(alpha<2){
						G_MODE=2;
						fade_mode=1;//�t�F�[�h�C�����[�h
						//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
					}
				}
		}


		//�v�Z
		if(fade_mode==0){
			dia_chk();//�΂߃`�F�b�N
			//�L�[�`�F�b�N
			key_chk();//�L�[�`�F�b�N
			key_henkan();//�L�[�ϊ�

			p_anime();//���L�����A�j���[�V����



			p_move();//�v���C���[�v�Z

			EvtChk();//�C�x���g�v�Z



			//menu_chk();//���j���[��ʂɍs����

			if(key.x==1 && fade_mode==0){
				fade_mode=2;

			}//���j���[�Ɉڍs


		}


		//�`��
		//DrawMap();

		DrawMap2();//��{�_���W�����`��	
		DrawMapEvt2();//�{�X�Ɩ�\��
		DrawMapItems();//�_���W�����A�C�e���`��
		miku.Draw();//�v���C���[�L�����`��

		break;
	case 2://���j���[

		if(fade_mode==0){
			//�v�Z
			key_chk();//�L�[�`�F�b�N
			key_henkan();//�L�[�ϊ�
			menu_KeyCal();//�J�[�\���v�Z

		}

		//�t�F�[�h�C��
		if(fade_mode==1){

			if (alpha <= 254){
				alpha += 32;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
				if(alpha>=255){

					fade_mode=0;//�t�F�[�h�C�����[�h
					//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
				}
			}
		}

		//�t�F�[�h�A�E�g
		if(fade_mode==2){
			//fade_cnt--;
				if (alpha >= 2){
					alpha -= 32;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
					if(alpha<2){
						G_MODE=1;//�ʏ�Q�[����
						fade_mode=1;//�t�F�[�h�C�����[�h
						//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
					}
				}
		}


	


		//�`��
		menu_draw();//���j���[��ʕ`��

		break;

		/////////////////////////////////////////////
		//�Q�[���I�[�o�[
	case 3:
		break;
		//////////////////////////////////////



	case 4://�t�F�[�h�A�E�g



		break;


	case 5://�t�F�[�h�C��


		break;



	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}




//���@�摜�f�[�^���̓ǂݍ���
void LoadImg(){


	miku.LoadImg();//�~�N�摜�@MIKU.cpp��


}



//�I������
void Finalize(){

}