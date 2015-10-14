#include "key.h"
#include "../DxLib/DxLib.h"

int key_Trg, key_Info, key_Old, chkKeyAny;

KEY key;//�N���X�F�F�L�[�@�����L�[��{�^��


//�L�[�`�F�b�N
void key_chk(){

	/*---------------------
	*    �L�[���擾    *
	*---------------------
	*
	*    LEFT  = 0000 0001
	*    RIGHT = 0000 0010
	*    UP    = 0000 0100
	*    DOWN  = 0000 1000
	*    key_Trg�͉������u�Ԃ̏��
	*    key_info�͍��̏��
	*
	*/
	key_Trg = key_Info = 0;                                 // �L�[���N���A
	chkKeyAny = false;
	

	if (CheckHitKey(KEY_INPUT_LEFT))   { key_Info |= 0x01; }
	if (CheckHitKey(KEY_INPUT_RIGHT))  { key_Info |= 0x02; }
	if (CheckHitKey(KEY_INPUT_UP))     { key_Info |= 0x04; }
	if (CheckHitKey(KEY_INPUT_DOWN))   { key_Info |= 0x08; }
	if (CheckHitKey(KEY_INPUT_SPACE))  { key_Info |= 0x10; }
	if (CheckHitKey(KEY_INPUT_Z))      { key_Info |= 0x20; }
	if (CheckHitKey(KEY_INPUT_X))      { key_Info |= 0x80; }
	if (CheckHitKey(KEY_INPUT_ESCAPE)) { key_Info |= 0x40; }
	
	if( CheckHitKey( KEY_INPUT_RETURN )){key_Info |= 0x100;}//�G���^�[�L�[


	if (CheckHitKeyAll()) { chkKeyAny = true; }                    // ���Ɂ[

	key_Trg = (key_Info ^ key_Old) & key_Info;          // �L�[�g���K�[���Z�b�g
	key_Old = key_Info;                                     // �L�[���Z�[�u


}

void key_henkan(void){


	//�㉺���E��������

	if (chkKeyAny == TRUE){

		if ((key_Info & 0x0f) == 0x01){ key.c = 2; }//��
		if ((key_Info & 0x0f) == 0x02){ key.c = 6; }//�E
		if ((key_Info & 0x0f) == 0x04){ key.c = 4; }//��
		if (key_Trg  == 0x04){ key.ct = 4; }//��

		if ((key_Info & 0x0f) == 0x08){ key.c = 0; }//��
		if (key_Trg  == 0x08){ key.ct = 0; }//��
						  
						  
		if ((key_Info & 0x0f) == 0x05){ key.c = 3; }//����
						   
		if ((key_Info & 0x0f) == 0x06){ key.c = 5; }//�E��
						   
		if ((key_Info & 0x0f) == 0x09){ key.c = 1; }//����
						   
		if ((key_Info & 0x0f) == 0x0a){ key.c = 7; }//�E��
		/////////////////////////////

		if ((key_Info & 0x0f) == 0x00){
			key.c = -1;//�\���L�[����
		}




		if ((key_Info & 0x20) == 0x20){ key.z = 1; }else{ key.z = 0; }//���L�[
		if ((key_Info & 0x80) == 0x80)key.x = 1; else key.x=0;//���L�[

		

	}
	else{ key.c=-1; key.z = 0;key.x=0; }//�L�[�����ĂȂ�

}