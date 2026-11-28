#include <Geode/Geode.hpp>

using namespace geode::prelude;

// animation instead of replacing the scene with MenuLayer
static void pushGarageScene() {
	auto scene = GJGarageLayer::scene();
	auto effect = CCTransitionMoveInT::create(0.4, scene);
	CCDirector::sharedDirector()->pushScene(effect);
	GameManager::get()->m_ropeGarageEnter = true;
}

// ridiculous feature
#include <Geode/modify/LevelInfoLayer.hpp>
class $modify(MyLevelInfoLayer, LevelInfoLayer) {
	bool init(GJGameLevel* p, bool challenge) {
		if (!LevelInfoLayer::init(p, challenge))
			return false;

		if (!Mod::get()->getSettingValue<bool>("hide-vanilla"))
			return true;
		// hide the original garage button
		if (auto menu = this->getChildByID("garage-menu"))
			menu->setVisible(false);
		
		return true;
	}
};

#include <Geode/modify/EditLevelLayer.hpp>
class $modify(MyEditLevelLayer, EditLevelLayer) {
	bool init(GJGameLevel* p) {
		if (!EditLevelLayer::init(p))
			return false;

		if (!Mod::get()->getSettingValue<bool>("editor"))
			return true;

		// win size reference
		auto winSize = CCDirector::sharedDirector()->getWinSize();

		// menu
		auto menu = CCMenu::create();
		menu->setID("garage-menu"_spr);
		float offset = Mod::get()->getSettingValue<double>("offset");
		menu->setPosition(ccp(winSize.width - 85.f + offset, winSize.height - 25.f));
		this->addChild(menu);

		// button
		auto spr = ButtonSprite::createWithSpriteFrameName("garageRope_001.png");
		spr->setPosition(ccp(18.875, 35.250));
		auto btn = CCMenuItemSpriteExtra::create(
			spr,
			this,
			menu_selector(MyEditLevelLayer::onGarage));
		btn->m_animationType = MenuAnimationType::Move;
		btn->m_startPosition = ccp(18.875, 35.25);
		btn->m_offset = ccp(0.f, -8.f);
		menu->addChild(btn);

		return true;
	}

	void onGarage(CCObject* sender) {
		pushGarageScene();
	}
};

#include <Geode/modify/LevelSelectLayer.hpp>
class $modify(OfficialBrowser, LevelSelectLayer) {
	bool init(int page) {
		if (!LevelSelectLayer::init(page))
			return false;
		if (!Mod::get()->getSettingValue<bool>("official"))
			return true;

		// win size reference
		auto winSize = CCDirector::sharedDirector()->getWinSize();

		// menu
		auto menu = CCMenu::create();
		menu->setID("garage-menu"_spr);
		float offset = Mod::get()->getSettingValue<double>("offset");
			menu->setPosition(winSize.width - 85.f + offset, winSize.height - 25.f);
		this->addChild(menu);

		// button
		auto spr = ButtonSprite::createWithSpriteFrameName("garageRope_001.png");
		spr->setPosition(ccp(18.875, 35.250));
		auto btn = CCMenuItemSpriteExtra::create(
			spr,
			this,
			menu_selector(OfficialBrowser::onGarage));
		btn->m_animationType = MenuAnimationType::Move;
		btn->m_startPosition = ccp(18.875, 35.25);
		btn->m_offset = ccp(0.f, -8.f);
		menu->addChild(btn);

		return true;
	}

	void onGarage(CCObject* sender) {
		pushGarageScene();
	}
};
