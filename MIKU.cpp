

#include "../DxLib/DxLib.h"

#include "MIKU.h"
#include "map.h"//��ʃT�C�Y���擾�̂���

#include "Game_Info.h"
#include "key.h"

#include <math.h>


MIKU miku;//���@�N���X�錾

//�C�x���g�u���b�N�ɐG��Ă邩�ǂ���
int EvtBlockTouch[MAP_BH][MAP_BW]={0};


//�~�N�摜�ǂݍ���
void MIKU::LoadImg(){

	LoadDivGraph("Img/miku/mikusan.png", 8, 8, 1, 48, 64, GH, 1);//���@�摜

	LoadDivGraph("Img/miku/loop1000/loop0.png", 6, 6, 1, 48, 64, GH_Run[0], 1);//���@�摜
	LoadDivGraph("Img/miku/loop1001/loop1.png", 6, 6, 1, 48, 64, GH_Run[1], 1);//���@�摜
	LoadDivGraph("Img/miku/loop1002/loop2.png", 6, 6, 1, 48, 64, GH_Run[2], 1);//���@�摜

	LoadDivGraph("Img/miku/loop1003/loop3.png", 6, 6, 1, 48, 64, GH_Run[3], 1);//���@�摜

	LoadDivGraph("Img/miku/loop1004/loop4.png", 6, 6, 1, 48, 64, GH_Run[4], 1);//���@�摜
	LoadDivGraph("Img/miku/loop1005/loop5.png", 6, 6, 1, 48, 64, GH_Run[5], 1);//���@�摜

	LoadDivGraph("Img/miku/loop1006/loop6.png", 6, 6, 1, 48, 64, GH_Run[6], 1);//���@�摜
	LoadDivGraph("Img/miku/loop1007/loop7.png", 6, 6, 1, 48, 64, GH_Run[7], 1);//���@�摜
	

}

void MIKU::Init(){

	real_W=48;//���ۂ̕�
	real_H=64;//���ۂ̍���
	
	W=20;//�����蔻��̕�
	H=20;//�����蔻��̍����i������j

	//mp_rx=640-real_W/2;//�}�b�v���ł̎��ۂ�x���W
	//mp_ry=480-real_H/2;//�}�b�v���ł̎��ۂ̂����W


	//�����ʒu
	mp_rx=32;//�}�b�v���ł̎��ۂ̏����ʒu
	mp_ry=32;//�}�b�v���ł̎��ۂ̏����ʒu


	dsp_rx=DSP_W/2-real_W/2;//��ʓ��̎��ۂ̂����W�i�����琔���āj
	dsp_ry=DSP_H/2-real_H/2;//��ʓ��̎��ۂ�y���W�i�ォ�琔���āj
	
	

	mp_x=mp_rx+(real_W-W)/2;//�}�b�v���ł̃A�^���̂����W
	mp_y=mp_ry+(real_H-H);//�}�b�v���ł̃A�^���̂����W

	dsp_x=dsp_rx+(real_W-W)/2;//��ʓ��̂�����̂����W�i�����琔���āj
	dsp_y=dsp_ry+(real_H-H);//��ʓ��̂�����̂����W�i�ォ�琔���āj

	muki=0;//������

}

void MIKU::Draw(){

	if (key.c==-1)DrawGraph(miku.dsp_rx,miku.dsp_ry , miku.GH[miku.muki], 1);
	else DrawGraph(miku.dsp_rx, miku.dsp_ry, miku.GH_Run[miku.muki][miku.anime], 1);
	
}


#define M_PI 3.14159  //�~����

int nokori[2];//�c�苗���@���A��



void p_move(void){
	if (key.c != -1){		
		//��
		if (key.c == 2){
			miku.muki = 2;
			mv_chk(2,nokori);

		//	miku.rx -= nokori[0];���@�������ꍇ
			miku.mp_rx -= nokori[0];//�}�b�v�̂ق�������
			miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W		
			
		}
		else if (key.c == 6){//�E
			miku.muki = 6;
			mv_chk(6, nokori);
			//miku.rx += nokori[0];
				miku.mp_rx += nokori[0];

				miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
						
			}
		//��
		else if (key.c == 4){
			miku.muki = 4;
			mv_chk(4, nokori);
			//miku.ry -= nokori[1];
			miku.mp_ry -= nokori[1];
			//miku.y -= nokori[1];

			miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W
						
		}

		//��
		else if (key.c == 0){//��
			miku.muki = 0;
			mv_chk(0, nokori);
			//miku.ry += nokori[1];
			miku.mp_ry += nokori[1];
			//miku.y += nokori[1];
			miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W
			
		}

		//�ȂȂ�

		else if (key.c == 3){//����
			miku.muki = 3;
			mv_chk(3, nokori);

			/*miku.rx -= nokori[0];
			miku.ry -= nokori[1];*/

			miku.mp_rx -= nokori[0];
			miku.mp_ry -= nokori[1];

			miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
				miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W
			//miku.x -= nokori[0];
			//miku.y -= nokori[1];
		}


		else if (key.c == 5){
			miku.muki = 5;
			mv_chk(5, nokori);

			
			miku.mp_rx += nokori[0];
			miku.mp_ry -= nokori[1];

				miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
					miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W
		}
		//����
		else if (key.c == 1){

			miku.muki = 1;
			mv_chk(1, nokori);

		/*	miku.rx -= nokori[0];
			miku.ry += nokori[1];*/
			miku.mp_rx -= nokori[0];
			miku.mp_ry += nokori[1];

				miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
					miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W
			
		}
		//�E��
		else if (key.c == 7){
			miku.muki = 7;
			mv_chk(7, nokori);

		/*	miku.rx += nokori[0];
			miku.ry += nokori[1];*/

			miku.mp_rx += nokori[0];
			miku.mp_ry += nokori[1];

				miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
				miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W

		}

	}

	//�ړ����[�h�ؑ�
	if (key.z == 1){
		miku.spd = 10;
		miku.n_spd = miku.spd*cos(45 / 180.0*M_PI) + 0.5;
	}
	else{
		miku.spd = 4;
		miku.n_spd = miku.spd*cos(45 / 180.0*M_PI) + 0.5;//���@�X�s�[�h�ȂȂ߂̏�����
	}



}





void mv_chk(int k, int *x){ //k�L�����̌��� x�c��̋���

	int i,j;
	int c=0;
	
	switch (k){
	case 0:		
		for(i=0;i<MAP_BH;i++){
			for(j=0;j<MAP_BW;j++){

				if (miku.mp_y + miku.H <= mhit3_posY[i][j]  && miku.mp_y + miku.H + miku.spd > mhit3_posY[i][j]   && miku.mp_x+miku.W  > mhit3_posX[i][j] && miku.mp_x < mhit3_posX[i][j] + map.Chip){

					x[1] = mhit3_posY[i][j] - (miku.mp_y + miku.H);


					

					return;
				}
			}
		}
		
	
		x[1] = miku.spd; x[0] = 0;//�u���b�N�ɐڐG���Ă���t���O
		return;
	case 1:
	//	for (i = map.bn - 1; i >= 0; i--){


		for(i=MAP_BH-1;i>=0;i--){
			for(j=MAP_BW-1;j>=0;j--){
				//DrawFormatString(480, 16, 0xffffff, "%d", miku.n_line[i]);

				if (miku.n_line[i][j][1] == 1){//�E��ɂ���
					if (miku.mp_x - miku.n_spd < mhit3_posX[i][j] + map.Chip &&  miku.mp_y +miku.H+ miku.n_spd > mhit3_posY[i][j] ){//�ړ���Ƀu���b�N�𒴂�����
						//DrawFormatString(480, 16, (255, 255, 255), "�ǔ���");

						mv_chk(0, x);//��
						mv_chk(2, x); return;//��

					}
				}


				/*	}*/
			}			
		}
		
		
		x[0] = miku.n_spd;//��	
			x[1] = miku.n_spd;//��
			return;


	case 2:
		for(i=0;i<MAP_BH;i++){
			for(j=0;j<MAP_BW;j++){
				if (miku.mp_x >= mhit3_posX[i][j] + map.Chip && miku.mp_x - miku.spd < mhit3_posX[i][j] + map.Chip && miku.mp_y + miku.H > mhit3_posY[i][j] && miku.mp_y < mhit3_posY[i][j] + map.Chip){

					x[0] = miku.mp_x - (mhit3_posX[i][j] + map.Chip);
					return;

				}
			}
		}
		x[0] = miku.spd; x[1] = 0;
		return;

	case 3:
		//for (i = map.bn-1; i >=0; i--){

		for(i=MAP_BH-1;i>=0;i--){
			for(j=MAP_BW-1;j>=0;j--){

				//DrawFormatString(480, 16, 0xffffff, "%d", miku.n_line[i]);

				if (miku.n_line[i][j][3] == 1){
					if (miku.mp_x - miku.n_spd < mhit3_posX[i][j] + map.Chip &&  miku.mp_y - miku.n_spd < mhit3_posY[i][j] + map.Chip){
						//DrawFormatString(480, 16, (255, 255, 255), "�ǔ���");

						mv_chk(4, x);
						mv_chk(2, x); return;

					}
				}


				/*	}*/
			}
		}

		x[0] = miku.n_spd;
			x[1] = miku.n_spd;
	
			break;

	case 4:

		//for (i = 0; i<map.bn; i++){

		for(i=0;i<MAP_BH;i++){
			for(j=0;j<MAP_BW;j++){
				if (miku.mp_y >= mhit3_posY[i][j]+map.Chip  && miku.mp_y - miku.spd < mhit3_posY[i][j]+map.Chip   && miku.mp_x + miku.W > mhit3_posX[i][j] && miku.mp_x < mhit3_posX[i][j] + map.Chip){
					x[1] = miku.mp_y - (mhit3_posY[i][j]+map.Chip );
					return;
				}
			}
		}
		x[1] = miku.spd; x[0] = 0;
		return;

	case 5:
		//for (i = map.bn - 1; i >= 0; i--){

		for(i=MAP_BH-1;i>=0;i--){
			for(j=MAP_BW-1;j>=0;j--){

				//DrawFormatString(480, 16, (255, 255, 255), "%d", miku.n_line[i]);

				if (miku.n_line[i][j][2] == 1){//�����ɂ���
					if (miku.mp_x +miku.W+ miku.n_spd > mhit3_posX[i][j]  &&  miku.mp_y - miku.n_spd < mhit3_posY[i][j] + map.Chip){
						//	DrawFormatString(480, 16, (255, 255, 255), "�ǔ���");


						mv_chk(6, x);
						mv_chk(4, x);
						return;

					}
				}


				/*	}*/
			}
		}x[0] = miku.n_spd;
		x[1] = miku.n_spd;

		break;


	case 6:

		//for (i = 0; i<map.bn; i++){

		for(i=0;i<MAP_BH;i++){
			for(j=0;j<MAP_BW;j++){
			if (miku.mp_x+miku.W <= mhit3_posX[i][j]  && miku.mp_x +miku.W+ miku.spd > mhit3_posX[i][j]  && miku.mp_y + miku.H > mhit3_posY[i][j] && miku.mp_y < mhit3_posY[i][j] + map.Chip){

				x[0] = mhit3_posX[i][j]-(miku.mp_x+miku.W);
				return;

			}
		}
		}
		x[0] = miku.spd; x[1] = 0;
		return;
	case 7:
	//	for (i = map.bn - 1; i >= 0; i--){			
		for(i=MAP_BH-1;i>=0;i--){
			for(j=MAP_BW-1;j>=0;j--){

			if (miku.n_line[i][j][0] == 1){//����ɂ���
				if (miku.mp_x + miku.W + miku.n_spd > mhit3_posX[i][j]  &&  miku.mp_y +miku.H+ miku.n_spd > mhit3_posY[i][j] ){
															
					mv_chk(6, x);
					mv_chk(0, x);
					return;

				}
			}
			

			/*	}*/
		}
			
		}
		
		x[0] = miku.n_spd;
			x[1] = miku.n_spd;
		return;

	}//switch�I���
}

//�C�x���g�`�F�b�N
void EvtChk(){
	EvtBlockChk();

	int i,j;

	if(ItemWinDrawFlag==0){
		for(i=0;i<MAP_BH;i++){
			for(j=0;j<MAP_BW;j++){


				if(EvtBlockTouch[i][j]==1){//�C�x���g�u���b�N�Ɍ��������Ă���
					if(Key_Trg==0x100){//�G���^�[�L�[

						map_EvtHitPos_X[i][j]=-100;//�����蔻�����
						map_EvtHitPos_Y[i][j]=-100;//�����蔻�����
				
						map_ItemXY[i][j]=0;//�}�b�v�A�C�e������


						mhit3[i][j]=0;//�����蔻��
						mhit3_posX[i][j]=-100;//�}�b�v�u���b�N�����蔻��x���W
						mhit3_posY[i][j]=-100;//�}�b�v�u���b�N�����蔻��y���W


						ItemWinDrawFlag=1;
						break;
					}

				}

			}
		}
	}else {
		if(Key_Trg==0x01 || Key_Trg==0x02 || Key_Trg==0x04 || Key_Trg==0x08 || Key_Trg==0x10 || Key_Trg==0x20 || Key_Trg==0x40 || 
			Key_Trg==0x80 || Key_Trg==0x100){
			ItemWinDrawFlag=0;
		}
	}
}

//�C�x���g�u���b�N�ɂԂ����Ă邩�ǂ����`�F�b�N
void EvtBlockChk(){
	int i,j;
	for(i=0;i<MAP_BH;i++){
		for(j=0;j<MAP_BW;j++){

			switch(miku.muki){

				//������
			case 0:
				if(miku.mp_y+miku.H==map_ItemHitPos_Y[i][j] && miku.mp_rx+miku.real_W>=map_ItemHitPos_X[i][j] && miku.mp_rx<=map_ItemHitPos_X[i][j]+map.Chip){
						EvtBlockTouch[i][j]=1;				
				}else
					EvtBlockTouch[i][j]=0;		
				break;
			case 2://������

				if(miku.mp_x==map_ItemHitPos_X[i][j]+map.Chip && miku.mp_ry+miku.real_H>=map_ItemHitPos_Y[i][j] && miku.mp_ry<=map_ItemHitPos_Y[i][j]+map.Chip){
						EvtBlockTouch[i][j]=1;				
				}else
					EvtBlockTouch[i][j]=0;		
				break;
			case 4://�����

					if(miku.mp_y==map_ItemHitPos_Y[i][j]+map.Chip && miku.mp_rx+miku.real_W>=map_ItemHitPos_X[i][j] && miku.mp_rx<=map_ItemHitPos_X[i][j]+map.Chip){
						EvtBlockTouch[i][j]=1;		
					}else
						EvtBlockTouch[i][j]=0;	
				break;
			case 6://�E����				

				if(miku.mp_x+miku.W==map_ItemHitPos_X[i][j] && miku.mp_ry+miku.real_H>=map_ItemHitPos_Y[i][j] && miku.mp_ry<=map_ItemHitPos_Y[i][j]+map.Chip){
						EvtBlockTouch[i][j]=1;				
				}else
					EvtBlockTouch[i][j]=0;		
				break;
				
			}
		}
	}
}



//�΂ߓ�����u���b�N�`�F�b�N

MHit hb[100*100];//�}�b�v�̏c�u���b�N�����u���b�N
double ang[2];
double kakudo = -45 / 180.0 * M_PI;
double deg135 = 135 / 180.0 * M_PI;

int mx0,mx1,x2, x3, x4,           my0,my1,y2, y3, y4,y5;


void dia_chk(void){//�Ԃ�l�̐����͎��@�̌����Ă������

	int i,j;
	mx0 = miku.mp_x, my0 = -1 * (miku.mp_y);//�~�N����
	mx1 = miku.mp_x + miku.W; my1 = -1 * (miku.mp_y + miku.H);//�~�N����
	//for (i = 0; i < map.bn; i++){


	for(i=0;i<MAP_BH;i++){
		for(j=0;j<MAP_BW;j++){

			x2 =mhit3_posX[i][j] , y2 = (-1) * (mhit3_posY[i][j]);
			x3 = mhit3_posX[i][j] + map.Chip, y3 = (-1) * (mhit3_posY[i][j] + map.Chip );
			x4 = mhit3_posX[i][j] + map.Chip * 2; y4 = (-1) * (mhit3_posY[i][j] + map.Chip*2);
			y5 = -1*(mhit3_posY[i][j] - map.Chip);


			//DrawFormatString(480, 16, 0xffffff, "kakudo%f", kakudo);


			//�E��
			if (   my0+mx1>x2+y3 &&   mx1+ my0<x4+y5   &&  (miku.mp_y >= mhit3_posY[i][j]+map.Chip || miku.mp_x >= mhit3_posX[i][j]+map.Chip)){
				miku.n_line[i][j][3] = 1;//�E���ɂ���
				//if (miku.n_line[i][3] == 1)DrawFormatString(480, 16 * 5 + i * 16, 0xffffff, "%d�̉E�����C��", i);
			}
			else miku.n_line[i][j][3] = 0;


			//����
			if (my0 + mx1>x2 + y3 &&   mx1 + my0<x4 + y5 && ( miku.mp_y+miku.H <= mhit3_posY[i][j]  || miku.mp_x+miku.W <= mhit3_posX[i][j] )  ){
				miku.n_line[i][j][0] = 1;//����ɂ���
				//DrawFormatString(480, 16 * 5 + i * 16, 0xffffff, "%d�̍��ド�C��", i);
			}
			else miku.n_line[i][j][0] = 0;


			//����
			if (my1 - mx1<y2 - x2 && my1 - mx1 >y4 - x4 && (miku.mp_x + miku.W <= mhit3_posX[i][j] || miku.mp_y >= mhit3_posY[i][j] + map.Chip)){
				miku.n_line[i][j][2] = 1;//����
			}
			else 	miku.n_line[i][j][2] = 0;//

			//�E��
			if (my1 - mx1<y2 - x2 && my1 - mx1 >y4 - x4 && (miku.mp_x >= mhit3_posX[i][j]+map.Chip || miku.mp_y+miku.H <= mhit3_posY[i][j] )){
				miku.n_line[i][j][1] = 1;//�E��


			}
			else 	miku.n_line[i][j][1] = 0;//


		}
	}
	
}

void p_anime(){
	
	if (key.c!=-1){//�L�[��������Ă�����
		miku.anime_c--;//�A�j���[�V�����J�E���^�}�C�i�X		
		if (miku.anime_c <= 0){

			if (key.z){
				miku.anime_c = 2;
			}//�_�b�V�����[�h
			else {
				miku.anime_c = 10;
			}			
			
			if (miku.anime >= 5){
				miku.anime = 0;
			}
			else 
				{
					miku.anime++; 
			}
		}
	}

	//if (key.z)miku.anime_c = 2;//�_�b�V�����[�h
	//		else miku.anime_c = 10;

}