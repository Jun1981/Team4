#pragma once 



class Title{
public:
	int bgGh;//�摜�n���h��

	int curGh;//�J�[�\���̉摜�n���h��
	int balGh[2];//���D�̉摜�n���h��

	int balX[2],balY[2];//���D�̍��W
	int balInitX[2],balInitY[2];//�摜�̏����ʒu

	//int curX,curY;//�J�[�\�����W
	
	//�֐�
	//void init();//������
	
	void cal();//�v�Z
	void draw();//�`��

	void start();//�S��
};

extern Title t;
extern void titleInit();//�^�C�g��������

//�����O�E��1
enum titleLR{
L,
R,
};//enum