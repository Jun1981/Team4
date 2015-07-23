
#include "DxLib\DxLib.h"
#include "menu.h"
#include "key.h"

#include "GameMain.h"//G_MODE�p


//
MENU menu;//�N���X�錾


int menu_type=0;//���j���[��ʂ̃^�C�v�@�A�C�e���Ƃ� 0:��{�@�P�F�A�C�e���@�Q�F

//����̎�ނ�enum
enum kind {Buki=0,Bougu=1,Syoumouhin=2};

int i;//���[�v
//���j���[������
void menu_init(){

	//menu.GH_MAP=LoadGraph("menu/menu1.png",0);//���j���[��{�ǂݍ���
	//menu.GH_CURSOR=LoadGraph("menu/cusor1.png",0);//�J�[�\���ǂݍ���

	menu.GH_MAP=LoadGraph("menu/menu.png",0);//���j���[��{�ǂݍ���
	menu.GH_CURSOR=LoadGraph("menu/cusor1.png",0);//�J�[�\���ǂݍ���

	menu.GH_EQ=LoadGraph("menu/eq.png",0);//������ʓǂݍ���










	//���j���[��{���
	menu.L_List_pos=0;//�����j���[���X�g�̃J�[�\���ʒu�̔ԍ�
	menu.L_List_Num=3;//���̍��ڐ�
	menu.L_List_Ini_Pos=50;//�J�[�\���̂x���W�����ʒu
	menu.L_List_Mv_Amt=60;//���J�[�\���̈ړ���
	menu.Mode=0;//��{���






	//�����A�C�e�����X�g

	struct ITEM Ivt[400] = {
		/*{ID, kind, narabi, name, stock, power, info} ���͂̏���*/
		{0, Buki, 0, "�G�X�g�b�N", 1, 5, "�W���I�ȏ��S�җp�̑匕�B"},
		{1, Buki, 1, "�c���@�C�n���_�\", 1, 15, "�匕�̒��ł���^�ŁA���̑匕�ɔ�ׂē��g���d������Ă���B"},
		{2, Buki, 2, "�t�����x���W��", 1, 13, "�g�̂悤�ȓ��g�������B���g�͌y������Ă��邪����������З͂��Ⴂ"},
		{3, Buki, 3, "�t���K���b�n", 1, 24, "�Z��@������قǂ̍����B�����A���̕��d���@�����ɗ��B"},
		{4, Buki, 4, "�T�C�X", 1, 6, "�����₷�����S�җp�̑劙"},
		{5, Buki, 5, "�n���p�[", 1, 16, "��������̂�������劙�B�ƂĂ��d�����݂̗͂ł͈������Ƃ��o���Ȃ��B"},
		{6, Buki, 6, "�~�J�n���q", 1, 10, "�n���}�[�̒��ł͌Q�𔲂��Čy���A���S�҂ł������₷���d�l�ƂȂ��Ă���B"},
		{7, Buki, 7, "�N�O�m�`", 1, 25, "�R�̂悤�ɑ傫���ƂĂ��d���B�������A���̈З͂��܂莆���B"},
		{8, Buki, 8, "�g�}�z�[�N", 1, 7, "���S�җp�̕��B�ƂĂ��y���A�������邱�Ƃ��ł���B"},
		{9, Buki, 9, "�o���f�B�b�V��", 1, 17, "�����̂悤�Ȍʂ�`���傫�ȕ��B���Ƃ��Ă����ł͂Ȃ����Ƃ��Ă��g����B"},
		{10, Buki, 10, "�p���`�U��", 1, 3, "���S�җp�̑��B�����Ƃ��Ă��g����B"},
		{11, Buki, 11, "�X�s�A", 1, 8, "�ƂĂ������A����ȊZ�Ȃ�Έꌂ�œ˂��ʂ����̒��̑��B"},
		{12, Buki, 12, "�n���J�[", 1, 13, "�s�v�c�ȍa�����܂�Ă���A������p���������ꌂ���J��o�����Ƃ��ł���B"},
		{13, Buki, 13, "�A�Y�T", 1, 3, "���S�җp�̈����₷���|�B"},
		{14, Buki, 14, "�g���X�^��", 1, 8, "��x��3���̖������Ƃ̂ł��鋐��ȋ|�B"},
		{15, Buki, 15, "�A���m�J�S���~", 1, 13, "�������Ɍ��܂Œǋ������|�B�ˑ������������錄��^���Ȃ��B"},
		{16, Buki, 16, "�뎮�˝��C�@�h�ދ�y�i�J�O�c�`�j�h", 1, 5, "���}�g�^�P���Ђ��J���������P�b�g�����`���[�B�ˑ����x�����A���j�͂������B"},
		{17, Buki, 17, "�s�b-�P", 1, 8, "���萫���d�������݌v�ŁA���������������P�b�g�����`���[�B"},
		{18, Buki, 18, "�e1 burne", 1, 12, "FURIT�Ђ��J�������ˑ��d���̃��P�b�g�����`���[�B�����������A�З͂������B"},
		{19, Buki, 19, "�N���X�^�[�X�g�[��", 1, 18, "�N���X�^�[���e��p�������P�b�g�����`���[�B���e�n�_�͏œy�Ɖ����A������ǂ𕲍ӂ���B"},
		{20, Buki, 20, "�s�l-1�q", 1, 5, "the,Terminal Corporation�ЊJ���̋@�֏e�Ŕ��Q�̖������ƈ��萫���ւ�B�e�g�͏��������߂ŁA�����^�т₷���݌v����Ă���B"},
		{21, Buki, 21, "�s�l-1�e", 1, 13, "TC�ЊJ����TM�V���[�Y�̏d�@�֖C�B�����ˑ��Ɣj��͂������A�������傫���d���B"},
		{22, Buki, 22, "Recaeme", 1, 15, "FURIT�ЊJ���̏d�@�֏e�B��^�ň��萫�ɕx�݉Η͂����Q�̈�i�B�y���b�Ȃ�Ηe�ՂɊт��B"},
		{23, Buki, 23, "�뎮�����@�e�C���@�h���C�q�i�I���`�j�h", 1, 20, "���}�g�^�P���Ђ̍ō�����ŁA�E�r���ɏd�@�֏e�A���r���ɋ@�֖C�𑕒�����\���ƂȂ��Ă���B�d���ǂł���u�ŖI�̑���ɂ���Η͂����B"},

		{100, Bougu, 0, "�A�C�A���M�A", 3, 1, "������"},
		{101, Bougu, 1, "�V���t�L���b�v", 3, 3, "������"},
		{102, Bougu, 2, "������", 3, 3, "������"},
		{103, Bougu, 3, "�O���[�g�w����", 3, 5, "������"},
		{104, Bougu, 4, "�A�C�A���O���[�u", 3, 2, "������"},
		{105, Bougu, 5, "�V���t�K���g���b�g", 3, 4, "������"},
		{106, Bougu, 6, "�����Ď�", 3, 5, "������"},
		{107, Bougu, 7, "�O���[�g�O���[�u", 3, 7, "������"},
		{108, Bougu, 8, "�A�C�A���A�[�}�[", 3, 3, "������"},
		{109, Bougu, 9, "�V���t�v���[�g", 3, 7, "������"},
		{110, Bougu, 10, "��������", 3, 7, "������"},
		{111, Bougu, 11, "�O���[�g�v���[�g", 3, 9, "������"},
		{112, Bougu, 12, "�A�C�A�����b�O", 3, 2, "������"},
		{113, Bougu, 13, "�V���t���M���X", 3, 4, "������"},
		{114, Bougu, 14, "��������", 3, 5, "������"},
		{115, Bougu, 15, "�O���[�g���M���X", 3, 7, "������"},
		{116, Bougu, 16, "�A�C�A���u�[�c", 3, 1, "������"},
		{117, Bougu, 17, "�V���t�u�[�c", 3, 3, "������"},
		{118, Bougu, 18, "�����", 3, 3, "������"},
		{119, Bougu, 19, "�O���[�g�u�[�c", 3, 5, "������"},
		{119, Bougu, 20, "�M�A�������[", 3, 2, "������"},
		{119, Bougu, 21, "�J�I�X�������[", 3, 6, "������"},
		{119, Bougu, 22, "�G�������g�������[", 3, 10, "������"},
		{119, Bougu, 23, "�A�[�X�`�b�v", 3, 2, "������"},
		{119, Bougu, 24, "�����I�X�`�b�v", 3, 5, "������"},
		{119, Bougu, 25, "�t�F�A���[�`�b�v", 3, 8, "������"},

		{200, Syoumouhin, 0, "�w�C���T�v��", 99, 30, "������"},
		{201, Syoumouhin, 1, "�n�C�w�C���T�v��", 99, 50, "������"},
		{202, Syoumouhin, 2, "���K�w�C���T�v��", 99, 70, "������"},
		{203, Syoumouhin, 3, "�J�E�X�T�v��", 99, 30, "������"},
		{204, Syoumouhin, 4, "�n�C�J�E�X�T�v��", 99, 50, "������"},
		{205, Syoumouhin, 5, "���K�J�E�X�T�v��", 99, 70, "������"},
		{206, Syoumouhin, 6, "O�L�b�g", 99, 1, "������"},
		{207, Syoumouhin, 7, "H�L�b�g", 99, 20, "������"},
		{208, Syoumouhin, 8, "M�L�b�g", 99, 50, "������"},
	};



}


//�ʏ��ʂŃ��j���[�ɍs�����ǂ�������
void menu_chk(){
	if(key.x==1 && G_MODE==1 ){
		G_MODE=2;//�Q�[�����[�h�i���j���[�j

		menu.Mode=0;//���j���[���[�h�@��{���

		menu_type=0;

		//�t�F�[�h�A�E�g
		for(i=0;i<255;i++){
			SetDrawBright( 255-i , 255-i , 255-i );
		}

	}//���j���[�Ɉڍs

	//���j���[��{�ɂ��鎞
	if(menu.Mode==0){
		if(key.x==1 && G_MODE==2 ){

			menu_type=1;
			for(i=0;i<255;i++){
				SetDrawBright( 255-i , 255-i , 255-i );
			}

		}





	}

	//	if(key.x==1)DrawGraph(0,0,menu.GH,0);

}

//���j���[�Ăяo���֐�
void menu_draw(){



	SetDrawBright( 255 , 255 , 255 );


	switch(menu.Mode){

	case 0:

		//���j���[��{��ʕ`��
		DrawGraph(0,0,menu.GH_MAP,0);
		//DrawGraph(30,+26+64*menu.L_List_pos,menu.GH_CURSOR,1);	


		//�J�[�\���摜�`��
		DrawGraph(10/*�J�[�\���̂����W*/,menu.L_List_Ini_Pos+menu.L_List_Mv_Amt*menu.L_List_pos,menu.GH_CURSOR,1);	
		break;

	case 1:


		//���j���[�̑�����ʕ`��
		DrawGraph(0,0,menu.GH_EQ,0);




	}


}

//�e�X�g���j���[�p
//void menu_KeyCal(){
//	//������������
//	if(Key_Trg==0x08){
//
//		if(menu.L_List_pos<menu.L_List_Num)menu.L_List_pos++;
//		else menu.L_List_pos=1;
//
//	}
//	//�����������
//	if(Key_Trg==0x04){
//
//		if(menu.L_List_pos>1)menu.L_List_pos--;
//		else menu.L_List_pos=menu.L_List_Num;
//
//	}
//
//
//
//
//
//
//
//}



//���j���[�̃L�[�v�Z�֌W
void menu_KeyCal(){


	//��{��ʂɂ��鎞
	if(menu.Mode==0){
		//������������
		if(Key_Trg==0x08){

			if(menu.L_List_pos<menu.L_List_Num-1)menu.L_List_pos++;
			else menu.L_List_pos=0;

		}
		//�����������
		if(Key_Trg==0x04){

			if(menu.L_List_pos>0)menu.L_List_pos--;
			else menu.L_List_pos=menu.L_List_Num-1;

		}

		//�Q�[���I���ɃJ�[�\��������Ƃ��ɂd���������������ƏI��
		if(menu.L_List_pos==2){
			if( CheckHitKey( KEY_INPUT_RETURN ) ==1)exit(0);
		}

		//���j���[��{��ʏI��
		if(fade_mode==0){//�t�F�[�h������Ȃ�������
			if(Key_Trg==0x80){
				fade_mode=2;menu.L_List_pos=0;}//�t�F�[�h�A�E�g���Ēʏ�Q�[���� �J�[�\���ʒu������

		}

		//������ŃG���^�[
		if(menu.L_List_pos==0){//���j���[�J�[�\���������̏�ɂ���Ƃ�Enter�L�[�ő������j���[�imenu.Mode=1)�ɂƂԁj

			if( CheckHitKey( KEY_INPUT_RETURN ) ==1){				
				menu.Mode=1;
				
			}		
		}

	}


	//������ʂɂ���Ƃ�
	else if(menu.Mode==1){			
			
			if(menu.Mode==1)if(Key_Trg==0x80)menu.Mode=0;//���L�[�Ń��j���[��{��ʂɖ߂�
					
	}
	///////////////////////////////////////////////////////



}


