#include "debug.h"

#include "../DxLib/DxLib.h"

#include "MIKU.h"

#include "key.h"

#include "map.h"

#include "GameMain.h"

#include "menu.h"


void debug_msg(){

	/*DrawFormatString(320, 16,(255,255,255) , "�~�N�̃A�j���ԍ�(%d,)",miku.anime);
		DrawFormatString(320, 16*2,(255,255,255) , "�A�j���J�E���g,%d)",miku.anime_c);
		DrawFormatString(320, 16*3,(255,255,255) , "�\���L�[,%d)",key.c);

		DrawFormatString(320, 16*4,(255,255,255) , "�ꎞ�\���L�[,%d)",Key_Trg);


		DrawFormatString(320, 16*5,(255,255,255) , "�}�b�v���܂�,%d)",miku.mp_rx%32);
		DrawFormatString(320, 16*6,(255,255,255) , "�u�����h���[�h,%d)",alpha);*/


	DrawFormatString(400, 16*4,(255,255,255) , "�L�[,%d)",Key_Info);
		DrawFormatString( 400, 16*6,(255,255,255), "�}�b�v�`�b�v�A�C�e��%d",mapChip_Item);
			DrawFormatString( 400, 16*7,(255,255,255), "�A�C�e������������(0,0)%d",EvtBlockTouch[0][0]);




}

