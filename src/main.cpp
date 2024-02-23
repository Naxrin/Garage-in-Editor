#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(MyLayer, EditLevelLayer) {
	bool init(GJGameLevel* p0) {
		if (!EditLevelLayer::init(p0)) {
			return false;
			}
		
		auto menu = CCMenu::create();
		menu->setID("garage-menu");
		menu->setPosition(492.f, 295.f);
		if (Mod::get()->getSettingValue<bool>("left"))
			menu->setPosition(484.f, 295.f);
		menu->setContentSize(CCSize(569.f, 320.f));
		this->addChild(menu);

		auto btn = ButtonSprite::createWithSpriteFrameName("garageRope_001.png");
		btn->setPosition(CCPoint(18.875, 35.520));
		auto myButton = CCMenuItemSpriteExtra::create(
			btn,
			this,
			menu_selector(LevelInfoLayer::onGarage));
		myButton->m_animationType = MenuAnimationType::Move;
		myButton->m_startPosition = CCPoint(18.875, 35.25);
		myButton->m_destPosition = CCPoint(0.f, -8.f);
		myButton->m_offset = CCPoint(0.2, 0.2);
		menu->addChild(myButton);
		this->updateLayout();
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