#pragma once
#include "Menu.h"
class GameMain{

public:
	int mode;//�Q�[�����[�h	
	int fadeMode;//�t�F�[�h�C���E�A�E�g���[�h
	int nextMode;//���̃��[�h�\��
	int brightness;//�P�x
	
	
	
	void start();//�Q�[���{�҃X�^�[�g

	GameMain();//�R���X�g���N�^
	
	int fadeOut(int);//�t�F�[�h�A�E�g�֐��@�I�����Ɂ@�P�O�O��Ԃ�
	int fadeIn(int);//�t�F�[�h�C���֐�	�I�����Ɂ@�P�O�O��Ԃ�
};

//�N���X�O���錾
extern GameMain game;//�N���X�錾
//extern Menu stgSel;
