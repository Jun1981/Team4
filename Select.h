#pragma once


class Select {
protected:
	

	
public:
	
	int *itemGh;//���ڂ̔w�i

	int *curGh;//�J�[�\���̉摜
	int *bgGh;//�w�i�摜

	int num;//���݂̍��ڔԍ�
	int numOfItems;//���ڐ�

	int *itemX,*itemY;//���ڂ̍��W
	int *itemInitX, *itemInitY;//���ڂ̏������W

	
	
	int curX,curY;//�J�[�\�����W(����j
	int curInitX,curInitCurY;//�J�[�\���̏����ʒu
	
	
		
	//�Z�b�^�[
	void setArrayGh(int);//�w�i�摜�̔z��쐬 ����
	void setArrayGhItem();//���ڔw�i�̔z��쐬
	void setArrayGhCur(int);//�J�[�\���̔z��쐬
	//void setArrayItemInitXY();//�A�C�e�����W�̏����ʒu
	//void setArrayItemXY();
	void setItemInitXY(int,int,int);//�A�C�e���̏����ʒu�Z�b�g�����@���ڂ̃��j���[��
	void setItemXY(int,int,int);//
	//void (*fpSetItemInitXY);
	void setGh(int,const char*);//�O���t�B�b�N�n���h���ɓǂݍ��ފ֐��i���ڂ̍��ځA�t�@�C���p�X�j
	
	void setGhItem(int,const char*);//
	void setGhCur(int ,const char*);//�J�[�\���̃n���h���Q�b�g

	
	//�v�Z�֌W
	void calHori( );//�v�Z ���@���j���[(���ڐ��j�@���݂̔ԍ���Ԃ�
	//void draw();//�`��


	Select();//�R���X�g���N�^
	void termProc();//�I������
	
};

//L���O�@R���P
enum titleLR{
L,
R,
};//enum

//extern Select titleSel;//�^�C�g���@�Z���N�g

extern Select tSel;