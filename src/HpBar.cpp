#include <iostream>
#include "HpBar.hpp"
#include "Enemy.hpp"

void HpBar::hpSetPosition(int baseWidth, int baseHeight )
{
    hpSprite.setPosition(baseWidth / 2, baseHeight * 1 / 5 );
}

void HpBar::hpBarDraw(){
    window->draw(this->hpSprite);
}


sf::Sprite HpBar::getEnemySprite() {
    return hpSprite;
}

void HpBar::setHpSprite(sf::String filename) {
    //setHpTexture(filename);
    hpTexture.loadFromFile(filePath + filename);
    hpSprite.setTexture(hpTexture);
    hpSprite.setOrigin(hpTexture.getSize().x / 2, hpTexture.getSize().y / 2);
    HpBar::hpSprite = hpSprite;
}

void HpBar::setHpTexture(sf::String filename) {
    hpTexture.loadFromFile(filePath + filename);
}

void HpBar::dropHpOnBar(Enemy enemy){
	static int prevHp = 100;
    int hp = enemy.getHp();
	if (hp != prevHp) {
		if (hp == 100) setHpSprite("HP_bar.png");
		else if (hp < 100 && hp >= 90) setHpSprite("HP_bar_90%.png");
		else if (hp < 90 && hp >= 80) setHpSprite("HP_bar_80%.png");
		else if (hp < 80 && hp >= 70) setHpSprite("HP_bar_75%.png");
		else if (hp < 70 && hp >= 60) setHpSprite("HP_bar_60%.png");
		else if (hp < 60 && hp >= 50) setHpSprite("HP_bar_50%.png");
		else if (hp < 50 && hp >= 40) setHpSprite("HP_bar_40%.png");
		else if (hp < 40 && hp >= 30) setHpSprite("HP_bar_30%.png");
		else if (hp < 30 && hp >= 20) setHpSprite("HP_bar_25%.png");
		else if (hp < 20 && hp >= 10) setHpSprite("HP_bar_15%.png");
		else if (hp < 10 && hp>0)  setHpSprite("HP_bar_5%.png");
		else if (hp >= 0)    setHpSprite("HP_bar_0%.png");
	}

	prevHp = hp;

    //else if(hp==0) setActionSprite("HP_bar_90%.png");


}




