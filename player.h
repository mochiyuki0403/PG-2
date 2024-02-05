#pragma once
#include<Novice.h>
class Player {
private:
	float speed_;
	float X_;
	float Y_;
	float playerposX_;
	float playerposY_;
	float bulletposX_;
	float bulletposY_;
	float bulletspeed_;
	float playertextur_;
	float bullettextur_;
	float R_;
	float bulletR_;
	bool isBulletshot_;
	bool isAlive_;
public:
	void Initalize();
	void Update(char*keys,char*preKeys);
	void Draw();
	int GetIsAlive() { return isAlive_; }
	float GetplayerposX() { return playerposX_; };
	float GetplayerposY() { return playerposY_; };
	float GetbulletposX() { return bulletposX_; };
	float GetbulletposY() { return bulletposY_; }; 
	float GetR() { return R_; };
	float GetbulletR() { return bulletR_; };
	int GetBulletShot() { return isBulletshot_; }
	void SetIsBulletShot(int isShot) { isBulletshot_ = isShot; }
	void SetPosX(float posX) { playerposX_ = posX; }
	void SetPosY(float posY) { playerposY_ = posY; }
};