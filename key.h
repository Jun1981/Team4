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
enum KeyName{
	keyLeft=0x01,
	keyRight=0x02,
	keyUp=0x04,
	keyDown=0x08,
	keyEnter=0x100,

};

extern KEY key;