#include <Novice.h>
#include"player.h"
#include"Enemy.h"
#include<math.h>
enum seen {
	start,
	play,
	end,
	clear,
};
seen currentseen = start;
const char kWindowTitle[] = "GC1D_11_モチダユキヤ_title";
bool collision(float obj1_x, float obj1_y, float obj1_r, float obj2_x, float obj2_y, float obj2_r)
{
	float a = obj2_x - obj1_x;
	float b = obj2_y - obj1_y;
	float distance = sqrtf(a * a + b * b);
	if (distance <= obj1_r + obj2_r) {
		return true;
	}
	else {
		return false;
	}
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	Player* player = new Player();
	Enemy* enemy = new Enemy();
	enemy->Initalize();
	player->Initalize();

	int bgtextur6 = Novice::LoadTexture("./images/dead.png");
	int bgtextur7 = Novice::LoadTexture("./images/gameclear.png");
	int bgtextur8 = Novice::LoadTexture("./images/start.png");
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (currentseen) {
		case start:
			if (keys[DIK_RETURN] && preKeys[DIK_RETURN]) {
				currentseen = play;
				player->Initalize();
				enemy->Initalize();
			}
		case play:
			enemy->Update();
			player->Update(keys,preKeys);
			if (player->GetIsAlive() == 1)
			{

				if (collision(player->GetplayerposX(), player->GetplayerposY(), player->GetR(), enemy->GetenemyposX(), enemy->GetenemyposY(), enemy->Getr())) {
					currentseen = end;
					player->SetPosX(-100);
					player->SetPosY(-100);
				}
			}
			if (player->GetBulletShot() == 1)
			{
				if (collision(player->GetbulletposX(), player->GetbulletposY(), player->GetbulletR(), enemy->GetenemyposX(), enemy->GetenemyposY(), enemy->Getr())) {
					enemy->SetIsAlive(false);
					player->SetIsBulletShot(false);
					enemy->OnCllision();
					if (enemy->GetHP() == 0) {
						currentseen = clear;
					}
				}
			}
			break;
		case end:
			if (keys[DIK_F])
			{
				currentseen = start;
			}
			break;
		case clear:
			if (keys[DIK_N])
			{
				currentseen = start;
			}
			break;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (currentseen) {
		case start:
			Novice::DrawSprite(0, 0, bgtextur8, 1, 1, 0.0f, WHITE);
			break;
		case play:
			enemy->Draw();
			player->Draw();
			break;
		case end:
			Novice::DrawSprite(0, 0, bgtextur6, 1, 1, 0.0f, WHITE);
			break;
		case clear:
			Novice::DrawSprite(0, 0, bgtextur7, 1, 1, 0.0f, WHITE);
			break;
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
