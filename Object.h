#pragma once

///<summary>
///�����ȕ��̑S�ʃN���X�@
///</summary>
class Object{

protected:
	int gh;//�摜�n���h��
	
public:
	int x,y;//���W�i����j

	Object();//�R���X�g���N�^

	void setGh(const char*);//gh�̃Z�b�^�[
	void setXY(int,int);//x�Ƃ��̃Z�b�^�[

	int getGh();//gh�̃Q�b�^�[

};