#pragma once

extern int key_Trg, key_Info,key_Old, chkKeyAny;// キー情報クリア



extern void key_chk(void);//キーチェック
extern void key_henkan(void);//キー変換

class  KEY{

public:

	int c;//十字キー８方向で　下が０
	int ct;//十字キー　おしっぱじゃない

	int z;//zキーボタン
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