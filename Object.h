#pragma once

///<summary>
///いろんな物体全般クラス　
///</summary>
class Object{

protected:
	int gh;//画像ハンドラ
	
public:
	int x,y;//座標（左上）

	Object();//コンストラクタ

	void setGh(const char*);//ghのセッター
	void setXY(int,int);//xとｙのセッター

	int getGh();//ghのゲッター

};