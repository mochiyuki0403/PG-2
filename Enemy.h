#pragma once
#include<Novice.h>
class Enemy
{
private:
	float enemyposX_ ;
	float enemyposY_ ;
	float enemyspeed_ ;
	float enemytextur_;
	int enemyHP_ ;
	float enemytimer_;
	float enemytextur2_;
	float enemyHandle_;
	float r_;
	bool isEnemylife_ ;
public:
	void Initalize();
	void Update();
	void Draw();
	void OnCllision();

	float GetenemyposX() { return enemyposX_; };
	float GetenemyposY() { return enemyposY_; };
	float Getr() { return r_; };
	void SetIsAlive(bool isFlag) { isEnemylife_ = isFlag; }
	int  GetHP() { return enemyHP_; }
};