//#include "../DxLib/DxLib.h"

//#include "Title.h"

//Title t;//�錾�@�^�C�g��
//Select tSel;//�I��p

//������

//�I��

//
//
////�X�^�[�g
//void Title::start(){	
//	if(game.fadeMode==0){
//			cal();//�v�Z
//	}
//	if(game.fadeMode==2){//�t�F�[�h�A�E�g���[�h
//		game.brightness-=3;
//	
//		if(game.brightness<=0)game.mode=game.nextMode;
//	}
//		draw();//�`��
//
//}

//
////�`��
//void Title::draw(){
//	DrawGraph(0,0,t.bgGh,1);//�w�i�`��
//
//	if(tSel.num!=0)SetDrawBright(game.brightness/2,game.brightness/2,game.brightness/2);//�O���I�΂�ĂȂ�������摜���Â����� 
//	DrawRotaGraph(t.balX[L],t.balY[L],1.0,0,t.balGh[L],1,0);//���@���D�`��
//	SetDrawBright(game.brightness,game.brightness,game.brightness);//���邳�����ɖ߂�
//	
//	if(tSel.num!=1)SetDrawBright(game.brightness/2,game.brightness/2,game.brightness/2);//�O���I�΂�ĂȂ�������摜���Â�����
//	DrawRotaGraph(t.balX[R],t.balY[R],1.0,0,t.balGh[R],1,0);//�E�@���D�`��
//	SetDrawBright(game.brightness,game.brightness,game.brightness);//���邳�����ɖ߂�
//	
//	//DrawGraph(t.balX[tSel.num],t.balY[tSel.num],t.curGh,1);//�J�[�\���`��	
//}
//
////�v�Z
//void Title::cal(){	
//	//���D�̃����_���㉺�ړ�
//	int a=rand()%3-1;
//	int b=rand()%3-1;
//	t.balY[L]+=a;
//	t.balY[R]+=b;
//	int z=0;
//
//
//	tSel.cal();
//
//	if(tSel.num==0){//���[��������
//		if(key_Trg==0x100){//�G���^�[�L�[�������ꂽ��
//			game.nextMode=2;//�X�e�[�W�Z���N�g�\��
//			game.fadeMode=2;//�t�F�[�h�A�E�g
//
//		}
//
//	}else if(tSel.num==1){
//		if(key_Trg==0x100){//�G���^�[�L�[�������ꂽ��
//			exit(0);//�I��
//		}
//
//
//	}
//}