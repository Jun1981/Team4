#pragma once

#include "Menu.h"
#include "Fonts.h"
#include "Object.h"

#define towerSpace 80
class stageSelect{
public:

	int bgGh;//�w�i�摜
	int objGh;//���̑��̉摜�t�@�C��



};



//�N���X�錾
extern Menu stgSel;//�N���X�錾
extern Fonts fonts;
extern Object bg;//�I�u�W�F�N�g�N���X�@�w�i�C���X�^���X
extern Object fairy;//�I�u�W�F�N�g�N���X�@�d���C���X�^���X

//////////////////////////////

void stageInit();//������
void stageCal();//�v�Z
void stageDraw();//�`��



