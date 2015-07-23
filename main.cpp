#include <Windows.h>
#include "../DxLib/DxLib.h"

#include "GameMain.h"
#include "key.h"
#include "MIKU.h"
#include "map.h"

#include "menu.h"

#include "debug.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	ChangeWindowMode(TRUE);                     // �E�C���h�E���[�h�ɕύX(�������A�Q�T�U�F)

	if (DxLib_Init() == -1) {                    // �c�w���C�u��������������
		return -1;                              // �G���[���N�����璼���ɏI��
	}


	// �Q�[���V�X�e��������
	Init();

	SetDrawScreen(DX_SCREEN_BACK);              // �`���𗠉�ʂ�


	




	//------ �Q�[�����[�v ------//
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Esc�L�[���������܂Ń��[�v
		ClsDrawScreen();                        // ����ʃN���A
		

		// �Q�[���R���g���[�����C��		
		GameMain();//���C���Q�[��

		debug_msg();//�f�o�b�O���b�Z�[�W
		


		ScreenFlip();                           // ����ʂ�\��ʂ�
		if (ProcessMessage() == -1) {            // ���b�Z�[�W����
			break;                              // �G���[���N�����烋�[�v���甲����
		}
	}
	DxLib_End();// �c�w���C�u�����g�p�̏I������
	return 0;// �A�v���P�[�V�����̏I��

}

void Init(){

	G_MODE=1;//�Q�[�����[�h


	miku.Init();//�~�N������

	menu_init();//���j���[��ʏ�����

	LoadImg();//�摜�Ȃǂ̓ǂݍ���
	LoadMap1();//�}�b�v�֌W������

}