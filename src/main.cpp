#include "popups/CustomPopupLayer.hpp"

#include <Geode/Geode.hpp>
#include <Geode/Loader.hpp>

#include <Geode/modify/EditorPauseLayer.hpp>

using namespace geode::prelude;

class $modify(EditorPause, EditorPauseLayer)
{
	bool init(LevelEditorLayer * p0)
	{
		if (EditorPauseLayer::init(p0))
		{
			auto actionsMenu = this->getChildByID("actions-menu");
			auto smallActionsMenu = this->getChildByID("small-actions-menu");
			auto togglesMenu = this->getChildByID("options-menu");

			actionsMenu->removeMeAndCleanup();
			smallActionsMenu->removeMeAndCleanup();

			togglesMenu->removeAllChildrenWithCleanup(true);

			auto newTogglesBtnSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
			newTogglesBtnSprite->setScale(0.875);

			auto newTogglesBtn = CCMenuItemSpriteExtra::create(
				newTogglesBtnSprite,
				this,
				menu_selector(EditorPause::onNewToggles));

			togglesMenu->addChild(newTogglesBtn);

			return true;
		}
		else
		{
			return false;
		};
	};

	void onNewToggles(CCObject * sender)
	{
		CustomPopupLayer::create()->show();
	};
};