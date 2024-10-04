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
			togglesMenu->removeMeAndCleanup();

			// new options menu
			auto newTogglesMenu = CCMenu::create();
			newTogglesMenu->setID("options-menu"_spr);
			newTogglesMenu->ignoreAnchorPointForPosition(false);
			newTogglesMenu->setScaledContentSize({185.f, 250.f});
			newTogglesMenu->setPosition({115.f, 135.f});

			this->addChild(newTogglesMenu);

			// new options menu
			auto newActionsMenu = CCMenu::create();
			newActionsMenu->setID("all-actions-menu"_spr);
			newActionsMenu->ignoreAnchorPointForPosition(false);
			newActionsMenu->setScaledContentSize({185.f, 250.f});
			newActionsMenu->setPosition({this->getContentWidth() - 115.f, 135.f});

			this->addChild(newActionsMenu);

			auto toggle_PreviewModeSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
			toggle_PreviewModeSprite->setScale(0.875);

			auto toggle_PreviewMode = CCMenuItemSpriteExtra::create(
				toggle_PreviewModeSprite,
				this,
				menu_selector(EditorPause::onNewToggles));

			newTogglesMenu->addChild(toggle_PreviewMode);

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