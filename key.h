#pragma once

extern int key_Trg, key_Info,key_Old, chkKeyAny;// �L�[���N���A



extern void key_chk(void);//�L�[�`�F�b�N
extern void key_henkan(void);//�L�[�ϊ�

class  KEY{

public:

	int c;//�\���L�[�W�����Ł@�����O
	int ct;//�\���L�[�@�������ς���Ȃ�

	int z;//z�L�[�{�^��
	int x;


};

extern KEY key;