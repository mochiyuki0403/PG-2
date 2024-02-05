#include "player.h"
#include"Enemy.h"
void Player::Initalize()
{
	speed_ = 5;
	playerposX_=600;
	playerposY_=600;
	bulletposX_=playerposX_;
	bulletposY_=playerposY_;
	bulletspeed_=20;
	R_ = 64;
	bulletR_ = 16;
	isAlive_ = true;
	isBulletshot_=false;
	playertextur_ =float(Novice::LoadTexture("./images/player.png"));
	bullettextur_=float( Novice::LoadTexture("./images/playerbullet.png"));
}

void Player::Update(char* keys, char* preKeys)
{
	if (keys[DIK_W]) {
		playerposY_ -= speed_;
	}
	if (keys[DIK_A]) {
		playerposX_ -= speed_;
	}
	if (keys[DIK_S]) {
		playerposY_ += speed_;
	}
	if (keys[DIK_D]) {
		playerposX_ += speed_;
	}
	if (playerposY_ <= 64) {
		playerposY_ = 200;
	}
	if (playerposX_ <= 64) {
		playerposX_ = 0;
	}
	if (playerposY_ >= 590) {
		playerposY_ = 590;
	}
	if (playerposX_ >= 1150) {
		playerposX_ = 1150;
	}
	if (isBulletshot_ == false && !keys[DIK_SPACE] && preKeys[DIK_SPACE]) {
		isBulletshot_ = true;
	}
	if (isBulletshot_ == true) {
		bulletposY_ -= bulletspeed_;
	}
	else if (isBulletshot_ == false) {
		bulletposX_ = playerposX_ + 47;
		bulletposY_ = playerposY_;
	}
	if (bulletposY_ <= -10) {
		isBulletshot_ = false;
	}
}

void Player::Draw()
{
	Novice::DrawSprite(int(bulletposX_), int(bulletposY_), int(bullettextur_), 1, 1, 0, WHITE);
	Novice::DrawSprite(int(playerposX_), int(playerposY_), int(playertextur_), 1, 1, 0, WHITE);
}
