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
			auto settingsMenu = this->getChildByID("settings-menu");

			actionsMenu->removeMeAndCleanup();
			smallActionsMenu->removeMeAndCleanup();
			togglesMenu->removeMeAndCleanup();
			settingsMenu->removeMeAndCleanup();

			// newTogglesMenu menu
			auto newTogglesMenu = CCMenu::create();
			newTogglesMenu->setID("options-menu"_spr);
			newTogglesMenu->ignoreAnchorPointForPosition(false);
			newTogglesMenu->setScaledContentSize({150.f, 300.f});
			newTogglesMenu->setPosition({115.f, 160.f});

			CCScale9Sprite *TogglesMenuSprite = CCScale9Sprite::create("square02b_001.png");
			TogglesMenuSprite->ignoreAnchorPointForPosition(false);
			TogglesMenuSprite->setScaledContentSize(newTogglesMenu->getScaledContentSize());
			TogglesMenuSprite->setAnchorPoint({0.0, 0.0});
			TogglesMenuSprite->setOpacity(150);
			TogglesMenuSprite->setColor(ccColor3B(0, 0, 0));

			// newActionsMenu menu
			auto newActionsMenu = CCMenu::create();
			newActionsMenu->setID("all-actions-menu"_spr);
			newActionsMenu->ignoreAnchorPointForPosition(false);
			newActionsMenu->setScaledContentSize({150.f, 300.f});
			newActionsMenu->setPosition({this->getContentWidth() - 90.f, 160.f});

			CCScale9Sprite *ActionMenuSprite = CCScale9Sprite::create("square02b_001.png");
			ActionMenuSprite->ignoreAnchorPointForPosition(false);
			ActionMenuSprite->setScaledContentSize(newActionsMenu->getScaledContentSize());
			ActionMenuSprite->setAnchorPoint({0.0, 0.0});
			ActionMenuSprite->setOpacity(150);
			ActionMenuSprite->setColor(ccColor3B(0, 0, 0));

			// ACTION TAB //////////////////////////////////////////////////////////////////////////////////////

			// Action Title
			auto ActionTitle = CCLabelBMFont::create("Actions", "goldFont.fnt");
			ActionTitle->setScale(0.8);
			ActionTitle->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 15.f});
			ActionTitle->ignoreAnchorPointForPosition(false);
			
			// Quick Action Title
			auto QuickActionTitle = CCLabelBMFont::create("Quick Actions", "goldFont.fnt");
			QuickActionTitle->setScale(0.65);
			QuickActionTitle->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 175.f});
			QuickActionTitle->ignoreAnchorPointForPosition(false);

			// Action Buttons //////////////////////////////////////////////////////////////////////////////////////

			// Build Helper Button
			auto BuildHelper_ButtonSprite = CCSprite::create("GJ_button_04.png");
			BuildHelper_ButtonSprite->setScale(0.9);

			auto BuildHelper_Sprite = CCSprite::create("a_buildHelper.png"_spr);
			auto BuildHelper = CCMenuItemSpriteExtra::create(
				BuildHelper_ButtonSprite,
				this,
				menu_selector(EditorPause::onNewToggles)); // Change this to function
			
			BuildHelper_ButtonSprite->addChild(BuildHelper_Sprite);

			BuildHelper_Sprite->setAnchorPoint({0.0, 0.0});
			BuildHelper_Sprite->setScale(0.8);

			BuildHelper->setZOrder(1);
			BuildHelper->setPosition({newActionsMenu->getContentWidth() / 2.f - 50.f, newActionsMenu->getContentHeight() - 50.f});

			// Copy Color Plus Button
			auto CopyColorPlus_ButtonSprite = CCSprite::create("GJ_button_04.png");
			CopyColorPlus_ButtonSprite->setScale(0.9);

			auto CopyColorPlus_Sprite = CCSprite::create("a_copyColor+.png"_spr);
			auto CopyColorPlus = CCMenuItemSpriteExtra::create(
				CopyColorPlus_ButtonSprite,
				this,
				menu_selector(EditorPause::onNewToggles)); // Change this to function
			
			CopyColorPlus_ButtonSprite->addChild(CopyColorPlus_Sprite);

			CopyColorPlus_Sprite->setAnchorPoint({0.0, 0.0});
			CopyColorPlus_Sprite->setScale(0.8);

			CopyColorPlus->setZOrder(1);
			CopyColorPlus->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 50.f});

			// Paste Color Plus Button
			auto PasteColorPlus_ButtonSprite = CCSprite::create("GJ_button_04.png");
			PasteColorPlus_ButtonSprite->setScale(0.9);

			auto PasteColorPlus_Sprite = CCSprite::create("a_pasteColor+.png"_spr);
			auto PasteColor = CCMenuItemSpriteExtra::create(
				PasteColorPlus_ButtonSprite,
				this,
				menu_selector(EditorPause::onNewToggles)); // Change this to function
			
			PasteColorPlus_ButtonSprite->addChild(PasteColorPlus_Sprite);

			PasteColorPlus_Sprite->setAnchorPoint({0.0, 0.0});
			PasteColorPlus_Sprite->setScale(0.8);

			PasteColor->setZOrder(1);
			PasteColor->setPosition({newActionsMenu->getContentWidth() / 2.f + 50.f, newActionsMenu->getContentHeight() - 50.f});

			// Create Extra Button
			auto CreateExtra_ButtonSprite = CCSprite::create("GJ_button_04.png");
			CreateExtra_ButtonSprite->setScale(0.9);

			auto CreateExtra_Sprite = CCSprite::create("a_createExtras.png"_spr);
			auto CreateExtra = CCMenuItemSpriteExtra::create(
				CreateExtra_ButtonSprite,
				this,
				menu_selector(EditorPause::onNewToggles)); // Change this to function
			
			CreateExtra_ButtonSprite->addChild(CreateExtra_Sprite);

			CreateExtra_Sprite->setAnchorPoint({0.0, 0.0});
			CreateExtra_Sprite->setScale(0.8);

			CreateExtra->setZOrder(1);
			CreateExtra->setPosition({newActionsMenu->getContentWidth() / 2.f - 50.f, newActionsMenu->getContentHeight() - 95.f});

			// Unlock Layers Button
			auto UnlockLayers_ButtonSprite = CCSprite::create("GJ_button_04.png");
			UnlockLayers_ButtonSprite->setScale(0.9);

			auto UnlockLayers_Sprite = CCSprite::create("a_unlockLayers.png"_spr);
			auto UnlockLayers = CCMenuItemSpriteExtra::create(
				UnlockLayers_ButtonSprite,
				this,
				menu_selector(EditorPause::onNewToggles)); // Change this to function
			
			UnlockLayers_ButtonSprite->addChild(UnlockLayers_Sprite);

			UnlockLayers_Sprite->setAnchorPoint({0.0, 0.0});
			UnlockLayers_Sprite->setScale(0.8);

			UnlockLayers->setZOrder(1);
			UnlockLayers->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 95.f});

			// Reset Unused Button
			auto ResetUnused_ButtonSprite = CCSprite::create("GJ_button_04.png");
			ResetUnused_ButtonSprite->setScale(0.9);

			auto ResetUnused_Sprite = CCSprite::create("a_resetUnused.png"_spr);
			auto ResetUnused = CCMenuItemSpriteExtra::create(
				ResetUnused_ButtonSprite,
				this,
				menu_selector(EditorPause::onNewToggles)); // Change this to function
			
			ResetUnused_ButtonSprite->addChild(ResetUnused_Sprite);

			ResetUnused_Sprite->setAnchorPoint({0.0, 0.0});
			ResetUnused_Sprite->setScale(0.8);

			ResetUnused->setZOrder(1);
			ResetUnused->setPosition({newActionsMenu->getContentWidth() / 2.f + 50.f, newActionsMenu->getContentHeight() - 95.f});

			// Uncheck Portals Button
			auto UncheckPortals_ButtonSprite = CCSprite::create("GJ_button_04.png");
			UncheckPortals_ButtonSprite->setScale(0.9);

			auto UncheckPortals_Sprite = CCSprite::create("a_uncheckPortals.png"_spr);
			auto UncheckPortals = CCMenuItemSpriteExtra::create(
				UncheckPortals_ButtonSprite,
				this,
				menu_selector(EditorPause::onNewToggles)); // Change this to function
			
			UncheckPortals_ButtonSprite->addChild(UncheckPortals_Sprite);

			UncheckPortals_Sprite->setAnchorPoint({0.0, 0.0});
			UncheckPortals_Sprite->setScale(0.8);

			UncheckPortals->setZOrder(1);
			UncheckPortals->setPosition({newActionsMenu->getContentWidth() / 2.f - 25.f, newActionsMenu->getContentHeight() - 145.f});

			// Keys Button
			auto Keys_ButtonSprite = CCSprite::create("GJ_button_04.png");
			Keys_ButtonSprite->setScale(0.9);

			auto Keys_Sprite = CCSprite::create("a_keys.png"_spr);
			auto Keys = CCMenuItemSpriteExtra::create(
				Keys_ButtonSprite,
				this,
				menu_selector(EditorPause::onNewToggles)); // Change this to function
			
			Keys_ButtonSprite->addChild(Keys_Sprite);

			Keys_Sprite->setAnchorPoint({0.0, 0.0});
			Keys_Sprite->setScale(0.8);

			Keys->setZOrder(1);
			Keys->setPosition({newActionsMenu->getContentWidth() / 2.f + 25.f, newActionsMenu->getContentHeight() - 145.f});

			// Quick Actions //////////////////////////////////////////////////////////////////////////////////////

			// Add Button to Action menu
			newActionsMenu->addChild(BuildHelper);
			newActionsMenu->addChild(CopyColorPlus);
			newActionsMenu->addChild(PasteColor);
			newActionsMenu->addChild(CreateExtra);
			newActionsMenu->addChild(UnlockLayers);
			newActionsMenu->addChild(ResetUnused);
			newActionsMenu->addChild(UncheckPortals);
			newActionsMenu->addChild(Keys);

			// Add Menu into the Editor Pause Layer
			this->addChild(newActionsMenu);
			this->addChild(newTogglesMenu);

			newActionsMenu->addChild(ActionMenuSprite);
			newTogglesMenu->addChild(TogglesMenuSprite);
			
			// Add Title to the Action Menu
			newActionsMenu->addChild(ActionTitle);
			newActionsMenu->addChild(QuickActionTitle);

			return true;
		}
		else
		{
			return false;
		};
	};

	void onNewToggles(CCObject * sender)
	{
		Notification::create("Button yes", NotificationIcon::Success, 2.f)->show();
	};
};