#pragma once

extern int G_MODE;//ゲームモード切替用変数　オープニング　ゲームオーバーなど 0-オープニング　1-メイン　２ゲームオーバー　３ーフェイド・アウト　４－フェードイン


void GameMain();//ゲームメイン
void Init();//初期化


void LoadImg();//画像データ等の読み込み


void Calc();//計算メイン


void Draw();//描画


void Finalize();//終了処理

