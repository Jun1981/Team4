#pragma once


class MENU{

public:


	//�摜�ǂݍ��ݗp�ϐ�
	int GH_MAP;//�O���t�B�b�N�n���h��
	int GH_CURSOR;//�J�[�\���摜�����n���h��
	int GH_ITEM;//�A�C�e����ʂ̉摜�ǂݍ��ݗp

	int GH_EQ;//�������j���[��ʓǂݍ��ݗp



	//���j���[�ړ��֌W�̐��l
	int L_List_pos;//���j���[�̍��̃J�[�\���̈ʒu
	int L_List_Num;//���j���[�̐�
	int L_List_Ini_Pos;//���j���[���J�[�\���̏����ʒu
	int L_List_Mv_Amt;//���J�[�\���̈ړ���


	
	int Mode ;//���j���[���[�h�i�@�O�F��{�@�P�F�����@�Q�F�V�X�e�� -1:���j���[����Ȃ��j


};


struct ITEM{
	int ID;			// �A�C�e���ŗL�̎��ʔԍ�
	int kind;		// �A�C�e���ʁA��ޕ����i����A�h��j
	int narabi;		// �A�C�e���ʂŕ\������ꍇ�Ɏg�p�i�A�C�e�����ׂĕ\������ꍇID���g�p�j
	char name[100];		// �A�C�e���̖��O
	int stock;			// �A�C�e���̃X�g�b�N���E��
	int power;		// ���́i����Ȃ�U���́A�h��Ȃ�h��͓��j
	char info[256];		// �������i�L��Ύg�p�j
};

extern enum kind;



extern MENU menu;


//�֐��錾
void menu_init();
void menu_chk();
void menu_draw();
void menu_KeyCal();//�J�[�\���̈ړ��v�Z
