#pragma once

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

void titleInit();//������
void titleCal();//�v�Z
void titleDraw();
extern GameMain game;//�N���X�錾