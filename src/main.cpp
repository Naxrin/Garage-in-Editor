#include <Geode/Geode.hpp>

using namespace geode::prelude;

static bool special = false;

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
		if (Mod::get()->getSettingValue<bool>("transparent")) {
			this->getChildByID("level-name-background")->setVisible(false);
			this->getChildByID("description-background")->setVisible(false);
		}
		return true;
	}
};

#include <Geode/modify/GJGarageLayer.hpp>
class $modify(MyGarageLayer, GJGarageLayer) {
public:
	void onBack(CCObject* sender) {
		if (special)
			CCDirector::get()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
		else
			GJGarageLayer::onBack(sender);
		special = false;
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
			menu_selector(OfficialBrowser::onGarage));
		btn->m_animationType = MenuAnimationType::Move;
		btn->m_startPosition = CCPoint(18.875, 35.25);
		btn->m_offset = CCPoint(0.f, -8.f);
		menu->addChild(btn);
		
		return true;
	}

	void onGarage(CCObject* sender) {
		special = true;
		auto scene = MyGarageLayer::scene();
		auto effect = CCTransitionMoveInT::create(0.4, scene);
		CCDirector::sharedDirector()->pushScene(effect);
	}
};
