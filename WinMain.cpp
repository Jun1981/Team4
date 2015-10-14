
#include "../DxLib/dxlib.h"


#include "GameMain.h"
////#include "Title.h"

#include "key.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
		
	//

	//解像度とウィンドウモード
	ChangeWindowMode(TRUE);                     // ウインドウモードに変更(ただし、２５６色)
	SetGraphMode(800,600,16);//画面解像度とカラービット数設定
	

	if (DxLib_Init() == -1) {                    // ＤＸライブラリ初期化処理
		return -1;                              // エラーが起きたら直ちに終了
	}
	
	//キーチェック

	/* key_chk();
*/
	 ////////////////////////
	
	
	
	SetDrawScreen(DX_SCREEN_BACK);              // 描画先を裏画面へ


	
	

	//------ ゲームループ ------//
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Escキーが押されるまでループ
		ClsDrawScreen();                        // 裏画面クリア


		// こっから書く
		key_chk();//
		//
		game.start();//ゲームメイン





	
		///////////////////////

		ScreenFlip();                           // 裏画面を表画面へ
		if (ProcessMessage() == -1) {            // メッセージ処理
			break;                              // エラーが起きたらループから抜ける
		}
	}
	DxLib_End();// ＤＸライブラリ使用の終了処理
	return 0;// アプリケーションの終了

}