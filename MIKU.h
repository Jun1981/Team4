#pragma once

#include "map.h"

#define MAP_W 100
#define MAP_H 100

//�N���X�錾
class MIKU{

private:
	
	//�O���t�B�b�N�n���h��
	int GH[8];//�W����
	int GH_Run[8][6];//�W�����̌������[�v�摜 �Q�ڂ̔z��̓A�j���[�V�����ԍ�


public:

	//MIKU();//�f�t�H���g�R���X�g���N�^
	//~MIKU();//�f�X�g���N�^

	/*���W�͍��ォ��

	*/

	//���ۂ�
	int real_W;//���ۂ̕�
	int real_H;//���ۂ̍���

	int mp_rx;//�}�b�v���ł̎��ۂ�x���W
	int mp_ry;//�}�b�v���ł̎��ۂ̂����W

	int dsp_rx;//��ʓ��̎��ۂ̂����W�i�����琔���āj
	int dsp_ry;//��ʓ��̎��ۂ�y���W�i�ォ�琔���āj

	int muki;//����


	//������
	int mp_x;//�}�b�v���ł̌����ڂ̂����W
	int mp_y;//�}�b�v���ł̌����ڂ̂����W	
	
	int dsp_x;//��ʓ��̌����ڂ̂����W�i�����琔���āj
	int dsp_y;//��ʓ��̌����ڂ̂����W�i�ォ�琔���āj
	
	int W;//�����ڂ̕�	
	int H;//�����ڂ̍���

	int spd;//�ړ��X�s�[�h
	int n_spd;//�΂߈ړ��X�s�[�h

	int n_line[MAP_BH][MAP_BW][4];//�΂߃��C���`�F�b�N�p ���J�b�R�̓}�b�v�̏c�u���b�N�����u���b�N��

	int anime;//�A�j���[�V����
	int anime_c;//�A�j���[�V�����J�E���^

	void real_adj();//���A�����W����


	//�֐�
	void Init();//�~�N�ϐ�������
	void LoadImg();//���@�摜�ǂݍ���
	void Draw();//�~�N�`��֐�
	
	

};

///�~�N
void miku_init();//
extern MIKU miku;//�N���X�錾

//
////�֐��錾
//void P_LoadImg();//���@�摜�ǂݍ���



extern void p_move(void);


extern void mv_chk(int,int*);
extern void dia_chk(void);
extern void p_anime(void);
extern void EvtChk();//�C�x���g�֌W

extern void EvtBlockChk();//�C�x���g�u���b�N�`�F�b�N
extern int EvtBlockTouch[MAP_BH][MAP_BW];

extern int nokori[2];



