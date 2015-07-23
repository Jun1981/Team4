#include <Windows.h>
#include "../DxLib/DxLib.h"

#include "GameMain.h"
#include "key.h"
#include "MIKU.h"
#include "map.h"

#include "menu.h"

#include "debug.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	ChangeWindowMode(TRUE);                     // ウインドウモードに変更(ただし、２５６色)

	if (DxLib_Init() == -1) {                    // ＤＸライブラリ初期化処理
		return -1;                              // エラーが起きたら直ちに終了
	}


	// ゲームシステム初期化
	Init();

	SetDrawScreen(DX_SCREEN_BACK);              // 描画先を裏画面へ


	




	//------ ゲームループ ------//
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Escキーが押されるまでループ
		ClsDrawScreen();                        // 裏画面クリア
		

		// ゲームコントロールメイン		
		GameMain();//メインゲーム

		debug_msg();//デバッグメッセージ
		


		ScreenFlip();                           // 裏画面を表画面へ
		if (ProcessMessage() == -1) {            // メッセージ処理
			break;                              // エラーが起きたらループから抜ける
		}
	}
	DxLib_End();// ＤＸライブラリ使用の終了処理
	return 0;// アプリケーションの終了

}

void Init(){

	G_MODE=1;//ゲームモード


	miku.Init();//ミク初期化

	menu_init();//メニュー画面初期化

	LoadImg();//画像などの読み込み
	LoadMap1();//マップ関係初期化

}