#pragma once


#define MAP_BW 100
#define MAP_BH 100


class MAP{
private:
	int* ChipH ;//�O���t�B�b�N�`�b�v�n���h��
	
public:

	int W;//��
	int H;//����

	int BW;//���̃u���b�N��
	int BH;//�c�̃u���b�N��
	

	//const int BN;//�S�u���b�N��

	int Chip;//�}�b�v�`�b�v�̃T�C�Y

	int** bg_array;

	char *ChipName;//�}�b�v�`�b�v�̖��O

	int bn;//������u���b�N�̐�
		


	int GH;
	int ItemWIndowGH;

	void CreateMap();

	


};

class MHit{
public:
	
	int x,y;
	int haba;

	double x_sa[2];//x���W�̍�
	double y_sa[2];


	
};
extern MAP map;
//�֐��G
extern void LoadMap1();//�x�[�X�}�b�v
extern void DrawMap();
extern void DrawMap2();

extern void DrawMapItems();//�}�b�v�A�C�e���`��
extern void DrawMapEvt2();//��Ƃ��{�X�Ƃ��\���֐�





extern MHit bhit[100*100];//�}�b�v�@�c�u���b�N�����u���b�N


//extern int mhit2[30][40];


//�}�b�v�`�b�v�p�O���t�B�b�N�n���h��
extern int map3[16*16];//�}�b�v�`�b�v�p
extern int mapChip_Item[16*16];//�}�b�v�`�b�v�i�A�C�e���j
extern int mapChip_Evt[16*16];//�}�b�v�`�b�v�i�C�x���g�j

extern int map_Evt2_Hit[MAP_BH][MAP_BW];//�}�b�v�C�x���g(�{�X�j�����蔻��


extern int map_base3[MAP_BH][MAP_BW];//�}�b�v�P�`��p

extern int map_Evt2_Draw[MAP_BH][MAP_BW];//�}�b�v�C�x���g�`��p�}�b�v�f�[�^


extern int mhit3[MAP_BH][MAP_BW];//��b�n�`�����蔻��


extern int mhit3_posX[MAP_BH][MAP_BW];//�}�b�v�u���b�N�����蔻��x���W
extern int mhit3_posY[MAP_BH][MAP_BW];//�}�b�v�u���b�N�����蔻��y���W




extern int map_ItemXY[MAP_BH][MAP_BW];//�}�b�v�A�C�e���̏ꏊ
extern int map_ItemHit[MAP_BH][MAP_BW];//�}�b�v�C�x���g�@�q�b�g����

extern int map_ItemHitPos_X[MAP_BH][MAP_BW];//�}�b�v�C�x���g�@�̏ꏊ�̍����X���W
extern int map_ItemHitPos_Y[MAP_BH][MAP_BW];//�}�b�v�C�x���g�@�̏ꏊ�̍����Y���W


extern int map_EvtHitPos_X[MAP_BH][MAP_BW];//�}�b�v�C�x���g�@�̏ꏊ�̍����X���W
extern int map_EvtHitPos_Y[MAP_BH][MAP_BW];//�}�b�v�C�x���g�@�̏ꏊ�̍����Y���W

//extern int map_HitChk[MAP_BH][MAP_BW];//�}�b�v�q�b�g�`�F�b�N�@�ǂ̃u���b�N�Ɍ��������ĐڐG���Ă��邩

extern int ItemWinDrawFlag;//�A�C�e���E�B���h�E��\������f��