#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>

using namespace geode::prelude;

class $modify(EditLevelLayer) {
	bool init(GJGameLevel* p0) {
		if (!EditLevelLayer::init(p0)) {
			return false;
			}
		// reference
		auto reference = this->getChildByID("level-actions-menu");
		auto refposX = reference->getPositionX();
		auto refposY = reference->getPositionY();

		auto menu = CCMenu::create();
		menu->setID("garage-menu");
		float offset = Mod::get()->getSettingValue<double>("offset");
			menu->setPosition(refposX-55.f+offset, 2*refposY-72.f);
		menu->setContentSize(CCSize(569.f, 320.f));
		this->addChild(menu);

		auto btn = ButtonSprite::createWithSpriteFrameName("garageRope_001.png");
		btn->setPosition(CCPoint(18.875, 35.250));
		auto myButton = CCMenuItemSpriteExtra::create(
			btn,
			this,
			menu_selector(LevelInfoLayer::onGarage));
		myButton->m_animationType = MenuAnimationType::Move;
		myButton->m_startPosition = CCPoint(18.875, 35.25);
		//myButton->m_destPosition = CCPoint(0.f, -8.f);
		myButton->m_offset = CCPoint(0.2, 0.2);
		menu->addChild(myButton);
		if (Mod::get()->getSettingValue<bool>("transparent")){
		this->getChildByID("level-name-background")->setVisible(false);
		this->getChildByID("description-background")->setVisible(false);
		}
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
