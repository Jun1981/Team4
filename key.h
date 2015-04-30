#pragma once

extern int Key_Trg, Key_Info,Key_Old, ChkKAny;// キー情報クリア



extern void key_chk(void);//キーチェック
extern void key_henkan(void);//キー変換

class  KEY{

public:

	int c;//十字キー８方向で　下が０
	int z;//zキーボタン
	int x;


};

extern KEY key;