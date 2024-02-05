#include"Enemy.h"
#include"player.h"
void Enemy::Initalize()
{
	 enemyposX_ = 600;
	 enemyposY_ = 32;
	 enemyspeed_ = 3;
	 enemytextur_= float(Novice::LoadTexture("./images/enemy.png"));;
	 enemytextur2_ = float(Novice::LoadTexture("./images/enemybad.png"));
	 enemyHP_ = 3;
	 enemytimer_ = 60;
	 r_ = 32;
	 //enemytextur2;
	 enemyHandle_=enemytextur_;
	 isEnemylife_ = true;
}

void Enemy::Update()
{
	if (enemyposX_ > 1210) {
		enemyspeed_ = -3;
	}
	if (enemyposX_ < 0) {
		enemyspeed_ = 3;
	}


	if (isEnemylife_ == true) {
		enemyposX_ = enemyposX_ + enemyspeed_;
	}
	else if (isEnemylife_ == false) {
		enemytimer_--;
	}

	if (enemytimer_ == 0) {
		isEnemylife_ = true;
		enemytimer_ = 60;
	}
	/*f(enemyposY-)*/
}

void Enemy::Draw()
{
	Novice::DrawSprite(int(enemyposX_) - 32, int(enemyposY_) - 32, int(enemyHandle_), 1, 1, 0, WHITE);
	if (isEnemylife_ == true) {
		enemyHandle_ = enemytextur_;
	}
	if (isEnemylife_ == false) {
		enemyHandle_ = enemytextur2_;
	}
}

void Enemy::OnCllision()
{
	enemyHP_ -= 1;
}
