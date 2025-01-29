#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/EditLevelLayer.hpp>
class $modify(EditLevelLayer) {
	bool init(GJGameLevel* p) {
		if (!EditLevelLayer::init(p))
			return false;

		// win size reference
		auto winSize = CCDirector::sharedDirector()->getWinSize();

		// menu
		auto menu = CCMenu::create();
		menu->setID("garage-menu");
		float offset = Mod::get()->getSettingValue<double>("offset");
			menu->setPosition(winSize.width - 85.f + offset, winSize.height - 25.f);
		this->addChild(menu);

		// button
		auto spr = ButtonSprite::createWithSpriteFrameName("garageRope_001.png");
		spr->setPosition(CCPoint(18.875, 35.250));
		auto btn = CCMenuItemSpriteExtra::create(
			spr,
			this,
			menu_selector(LevelInfoLayer::onGarage));
		btn->m_animationType = MenuAnimationType::Move;
		btn->m_startPosition = CCPoint(18.875, 35.25);
		btn->m_offset = CCPoint(0.f, -8.f);
		menu->addChild(btn);

		// transparent
		if (Mod::get()->getSettingValue<bool>("transparent")){
			this->getChildByID("level-name-background")->setVisible(false);
			this->getChildByID("description-background")->setVisible(false);
		}

		return true;
	}
};

#include <Geode/modify/LevelSelectLayer.hpp>
class $modify(LevelSelectLayer) {
	bool init(int page) {
		if (!LevelSelectLayer::init(page))
			return false;
		if (!Mod::get()->getSettingValue<bool>("official"))
			return true;

		// win size reference
		auto winSize = CCDirector::sharedDirector()->getWinSize();

		// menu
		auto menu = CCMenu::create();
		menu->setID("garage-menu");
		float offset = Mod::get()->getSettingValue<double>("offset");
			menu->setPosition(winSize.width - 85.f + offset, winSize.height - 25.f);
		this->addChild(menu);

		// button
		auto spr = ButtonSprite::createWithSpriteFrameName("garageRope_001.png");
		spr->setPosition(CCPoint(18.875, 35.250));
		auto btn = CCMenuItemSpriteExtra::create(
			spr,
			this,
			menu_selector(LevelInfoLayer::onGarage));
		btn->m_animationType = MenuAnimationType::Move;
		btn->m_startPosition = CCPoint(18.875, 35.25);
		btn->m_offset = CCPoint(0.f, -8.f);
		menu->addChild(btn);
		
		return true;
	}
};

/*
class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1)) {
			return false;
			}

		auto menu = static_cast<CCMenuItemSpriteExtra* >(this->getChildByID("garage-menu")->getChildByID("garage-button"));
		auto num1 = menu->m_destPosition.x;
		auto num2 = menu->m_destPosition.y;
		auto num3 = menu->m_startPosition.x;
		auto num4 = menu->m_startPosition.y;
		auto num5 = menu->m_offset.x;
		auto num6 = menu->m_offset.y;
	fstream myFile;
	myFile.open("D:/Alvorika my waifu.txt", ios::out);
	if (myFile.is_open())
	{
		myFile << num1 << '\n' << num2 << '\n' << num3 << '\n' << num4 << '\n' << num5 << '\n' << num6 << '\n' << '\n';
		myFile.close();
	}return true;
	}
};*/
