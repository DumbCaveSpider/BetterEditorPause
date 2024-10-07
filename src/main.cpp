#include "util/EditorEnum.hpp"
#include "popups/CustomPopupLayer.hpp"

#include <Geode/Geode.hpp>
#include <Geode/Loader.hpp>

#include <Geode/modify/EditorPauseLayer.hpp>

#include <Geode/binding/EditorPauseLayer.hpp>

using namespace geode::prelude;

auto getThisMod = geode::getMod();
auto gm = GameManager::get();
auto winSize = CCDirector::sharedDirector()->getWinSize();

class $modify(EditorPause, EditorPauseLayer)
{
	bool init(LevelEditorLayer * p0)
	{
		if (EditorPauseLayer::init(p0))
		{

			// For all of the people reading this code, I'm sorry. I'm sorry for the mess I've created.
			// Be sure you have a good day, and remember to drink water and eat food.


			auto actionsMenu = this->getChildByID("actions-menu");
			auto smallActionsMenu = this->getChildByID("small-actions-menu");
			auto togglesMenu = this->getChildByID("options-menu");
			auto settingsMenu = this->getChildByID("settings-menu");
			auto infoMenu = this->getChildByID("info-menu");
			auto resumeMenu = this->getChildByID("resume-menu");

			actionsMenu->removeMeAndCleanup();
			smallActionsMenu->removeMeAndCleanup();
			togglesMenu->removeMeAndCleanup();
			settingsMenu->removeMeAndCleanup();
			//resumeMenu->removeMeAndCleanup();

			// newTogglesMenu menu
			auto newTogglesMenu = CCMenu::create();
			newTogglesMenu->setID("options-menu"_spr);
			newTogglesMenu->ignoreAnchorPointForPosition(false);
			newTogglesMenu->setScaledContentSize({150.f, 300.f});
			newTogglesMenu->setPosition({this->getContentWidth() + 90.f, 160.f});

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

			// newResumeMenu menu
			auto newResumeMenu = CCMenu::create();
			newResumeMenu->setID("resume_menu"_spr);
			newResumeMenu->ignoreAnchorPointForPosition(false);
			newResumeMenu->setScaledContentSize({200.f, 220.f});
			newResumeMenu->setPosition({this->getContentWidth() / 2.f, 160.f});

			// infoMenu background
			CCScale9Sprite *infoMenuSprite = CCScale9Sprite::create("square02b_001.png");
			infoMenuSprite->ignoreAnchorPointForPosition(false);
			infoMenuSprite->setScaledContentSize(infoMenu->getScaledContentSize());
			infoMenuSprite->setAnchorPoint({0.0, 0.0});
			infoMenuSprite->setOpacity(150);
			infoMenuSprite->setColor(ccColor3B(0, 0, 0));

			// ACTION TAB //////////////////////////////////////////////////////////////////////////////////////

			// Action Title
			auto ActionTitle = CCLabelBMFont::create("Actions", "goldFont.fnt");
			ActionTitle->setScale(0.8);
			ActionTitle->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 15.f});
			ActionTitle->ignoreAnchorPointForPosition(false);

			// Quick Action Title
			auto QuickActionTitle = CCLabelBMFont::create("Quick Actions", "goldFont.fnt");
			QuickActionTitle->setScale(0.65);
			QuickActionTitle->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 155.f});
			QuickActionTitle->ignoreAnchorPointForPosition(false);

			// Action Buttons //////////////////////////////////////////////////////////////////////////////////////

			// Build Helper Button
			auto BuildHelper_ButtonSprite = CCSprite::create("GJ_button_04.png");
			BuildHelper_ButtonSprite->setScale(0.8);

			auto BuildHelper_Sprite = CCSprite::create("a_buildHelper.png"_spr);
			auto BuildHelper = CCMenuItemSpriteExtra::create(
				BuildHelper_ButtonSprite,
				this,
				menu_selector(EditorPause::onBuildHelper)); // Change this to function
			BuildHelper->setID(EditorEnum::editorActionNode[EditorEnum::EditorAction::BuildHelper]);

			BuildHelper_ButtonSprite->addChild(BuildHelper_Sprite);

			BuildHelper_Sprite->setAnchorPoint({0.0, 0.0});
			BuildHelper_Sprite->setScale(0.8);

			BuildHelper->setZOrder(1);
			BuildHelper->setPosition({newActionsMenu->getContentWidth() / 2.f - 50.f, newActionsMenu->getContentHeight() - 50.f});

			// Copy Color Plus Button
			auto CopyColorPlus_ButtonSprite = CCSprite::create("GJ_button_04.png");
			CopyColorPlus_ButtonSprite->setScale(0.8);

			auto CopyColorPlus_Sprite = CCSprite::create("a_copyColor+.png"_spr);
			auto CopyColorPlus = CCMenuItemSpriteExtra::create(
				CopyColorPlus_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function
			CopyColorPlus->setID(EditorEnum::editorActionNode[EditorEnum::EditorAction::CopyColorPlus]);

			CopyColorPlus_ButtonSprite->addChild(CopyColorPlus_Sprite);

			CopyColorPlus_Sprite->setAnchorPoint({0.0, 0.0});
			CopyColorPlus_Sprite->setScale(0.8);

			CopyColorPlus->setZOrder(1);
			CopyColorPlus->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 50.f});

			// Paste Color Plus Button
			auto PasteColorPlus_ButtonSprite = CCSprite::create("GJ_button_04.png");
			PasteColorPlus_ButtonSprite->setScale(0.8);

			auto PasteColorPlus_Sprite = CCSprite::create("a_pasteColor+.png"_spr);
			auto PasteColorPlus = CCMenuItemSpriteExtra::create(
				PasteColorPlus_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function
			PasteColorPlus->setID(EditorEnum::editorActionNode[EditorEnum::EditorAction::PasteColorPlus]);

			PasteColorPlus_ButtonSprite->addChild(PasteColorPlus_Sprite);

			PasteColorPlus_Sprite->setAnchorPoint({0.0, 0.0});
			PasteColorPlus_Sprite->setScale(0.8);

			PasteColorPlus->setZOrder(1);
			PasteColorPlus->setPosition({newActionsMenu->getContentWidth() / 2.f + 50.f, newActionsMenu->getContentHeight() - 50.f});

			// Create Extra Button
			auto CreateExtra_ButtonSprite = CCSprite::create("GJ_button_04.png");
			CreateExtra_ButtonSprite->setScale(0.8);

			auto CreateExtra_Sprite = CCSprite::create("a_createExtras.png"_spr);
			auto CreateExtra = CCMenuItemSpriteExtra::create(
				CreateExtra_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function
			CreateExtra->setID(EditorEnum::editorActionNode[EditorEnum::EditorAction::CreateExtras]);

			CreateExtra_ButtonSprite->addChild(CreateExtra_Sprite);

			CreateExtra_Sprite->setAnchorPoint({0.0, 0.0});
			CreateExtra_Sprite->setScale(0.8);

			CreateExtra->setZOrder(1);
			CreateExtra->setPosition({newActionsMenu->getContentWidth() / 2.f - 50.f, newActionsMenu->getContentHeight() - 90.f});

			// Unlock Layers Button
			auto UnlockLayers_ButtonSprite = CCSprite::create("GJ_button_04.png");
			UnlockLayers_ButtonSprite->setScale(0.8);

			auto UnlockLayers_Sprite = CCSprite::create("a_unlockLayers.png"_spr);
			auto UnlockLayers = CCMenuItemSpriteExtra::create(
				UnlockLayers_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function
			UnlockLayers->setID(EditorEnum::editorActionNode[EditorEnum::EditorAction::UnlockLayers]);

			UnlockLayers_ButtonSprite->addChild(UnlockLayers_Sprite);

			UnlockLayers_Sprite->setAnchorPoint({0.0, 0.0});
			UnlockLayers_Sprite->setScale(0.8);

			UnlockLayers->setZOrder(1);
			UnlockLayers->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 90.f});

			// Reset Unused Button
			auto ResetUnused_ButtonSprite = CCSprite::create("GJ_button_04.png");
			ResetUnused_ButtonSprite->setScale(0.8);

			auto ResetUnused_Sprite = CCSprite::create("a_resetUnused.png"_spr);
			auto ResetUnused = CCMenuItemSpriteExtra::create(
				ResetUnused_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function
			ResetUnused->setID(EditorEnum::editorActionNode[EditorEnum::EditorAction::ResetUnused]);

			ResetUnused_ButtonSprite->addChild(ResetUnused_Sprite);

			ResetUnused_Sprite->setAnchorPoint({0.0, 0.0});
			ResetUnused_Sprite->setScale(0.8);

			ResetUnused->setZOrder(1);
			ResetUnused->setPosition({newActionsMenu->getContentWidth() / 2.f + 50.f, newActionsMenu->getContentHeight() - 90.f});

			// Create Loop Button
			auto CreateLoop_ButtonSprite = CCSprite::create("GJ_button_04.png");
			CreateLoop_ButtonSprite->setScale(0.8);

			auto CreateLoop_Sprite = CCSprite::create("a_createLoop.png"_spr);
			auto CreateLoop = CCMenuItemSpriteExtra::create(
				CreateLoop_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function
			CreateLoop->setID(EditorEnum::editorActionNode[EditorEnum::EditorAction::CreateLoop]);

			CreateLoop_ButtonSprite->addChild(CreateLoop_Sprite);

			CreateLoop_Sprite->setAnchorPoint({0.0, 0.0});
			CreateLoop_Sprite->setPosition({4.0, 4.0});
			CreateLoop_Sprite->setScale(0.65);

			CreateLoop->setZOrder(1);
			CreateLoop->setPosition({newActionsMenu->getContentWidth() / 2.f - 50.f, newActionsMenu->getContentHeight() - 130.f});

			// Uncheck Portals Button
			auto UncheckPortals_ButtonSprite = CCSprite::create("GJ_button_04.png");
			UncheckPortals_ButtonSprite->setScale(0.8);

			auto UncheckPortals_Sprite = CCSprite::create("a_uncheckPortals.png"_spr);
			auto UncheckPortals = CCMenuItemSpriteExtra::create(
				UncheckPortals_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function
			UncheckPortals->setID(EditorEnum::editorActionNode[EditorEnum::EditorAction::UncheckPortals]);

			UncheckPortals_ButtonSprite->addChild(UncheckPortals_Sprite);

			UncheckPortals_Sprite->setAnchorPoint({0.0, 0.0});
			UncheckPortals_Sprite->setScale(0.8);

			UncheckPortals->setZOrder(1);
			UncheckPortals->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 130.f});

			// Keys Button
			auto Keys_ButtonSprite = CCSprite::create("GJ_button_04.png");
			Keys_ButtonSprite->setScale(0.8);

			auto Keys_Sprite = CCSprite::create("a_keys.png"_spr);
			auto Keys = CCMenuItemSpriteExtra::create(
				Keys_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function

			Keys_ButtonSprite->addChild(Keys_Sprite);

			Keys_Sprite->setAnchorPoint({0.0, 0.0});
			Keys_Sprite->setScale(0.8);

			Keys->setZOrder(1);
			Keys->setPosition({newActionsMenu->getContentWidth() / 2.f + 50.f, newActionsMenu->getContentHeight() - 130.f});

			// Quick Actions //////////////////////////////////////////////////////////////////////////////////////

			// Regroup Button
			auto Regroup_ButtonSprite = CCSprite::create("GJ_button_05.png");
			Regroup_ButtonSprite->setScale(0.8);

			auto Regroup_Sprite = CCSprite::create("as_regroup.png"_spr);
			auto Regroup = CCMenuItemSpriteExtra::create(
				Regroup_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function

			Regroup_ButtonSprite->addChild(Regroup_Sprite);

			Regroup_Sprite->setAnchorPoint({0.0, 0.0});
			Regroup_Sprite->setPosition({4.0, 4.0});
			Regroup_Sprite->setScale(0.65);

			Regroup->setZOrder(1);
			Regroup->setPosition({newActionsMenu->getContentWidth() / 2.f - 50.f, newActionsMenu->getContentHeight() - 185.f});

			// Reset Scroll Button
			auto ResetScroll_ButtonSprite = CCSprite::create("GJ_button_05.png");
			ResetScroll_ButtonSprite->setScale(0.8);

			auto ResetScroll_Sprite = CCSprite::create("as_resetScroll.png"_spr);
			auto ResetScroll = CCMenuItemSpriteExtra::create(
				ResetScroll_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function

			ResetScroll_ButtonSprite->addChild(ResetScroll_Sprite);

			ResetScroll_Sprite->setAnchorPoint({0.0, 0.0});
			ResetScroll_Sprite->setPosition({4.0, 4.0});
			ResetScroll_Sprite->setScale(0.65);

			ResetScroll->setZOrder(1);
			ResetScroll->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 185.f});

			// Select All Button
			auto SelectAll_ButtonSprite = CCSprite::create("GJ_button_05.png");
			SelectAll_ButtonSprite->setScale(0.8);

			auto SelectAll_Sprite = CCSprite::create("as_selectAll.png"_spr);
			auto SelectAll = CCMenuItemSpriteExtra::create(
				SelectAll_ButtonSprite,
				this,
				menu_selector(EditorPauseLayer::onSelectAll)); // Change this to function

			SelectAll_ButtonSprite->addChild(SelectAll_Sprite);

			SelectAll_Sprite->setAnchorPoint({0.0, 0.0});
			SelectAll_Sprite->setPosition({4.0, 4.0});
			SelectAll_Sprite->setScale(0.65);

			SelectAll->setZOrder(1);
			SelectAll->setPosition({newActionsMenu->getContentWidth() / 2.f + 50.f, newActionsMenu->getContentHeight() - 185.f});

			// Align X Button
			auto AlignX_ButtonSprite = CCSprite::create("GJ_button_05.png");
			AlignX_ButtonSprite->setScale(0.8);

			auto AlignX_Sprite = CCSprite::create("as_alignX.png"_spr);
			auto AlignX = CCMenuItemSpriteExtra::create(
				AlignX_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function

			AlignX_ButtonSprite->addChild(AlignX_Sprite);

			AlignX_Sprite->setAnchorPoint({0.0, 0.0});
			AlignX_Sprite->setPosition({4.0, 4.0});
			AlignX_Sprite->setScale(0.65);

			AlignX->setZOrder(1);
			AlignX->setPosition({newActionsMenu->getContentWidth() / 2.f - 50.f, newActionsMenu->getContentHeight() - 225.f});

			// New Group X Button
			auto NewGroupX_ButtonSprite = CCSprite::create("GJ_button_05.png");
			NewGroupX_ButtonSprite->setScale(0.8);

			auto NewGroupX_Sprite = CCSprite::create("as_newGroupX.png"_spr);
			auto NewGroupX = CCMenuItemSpriteExtra::create(
				NewGroupX_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function

			NewGroupX_ButtonSprite->addChild(NewGroupX_Sprite);

			NewGroupX_Sprite->setAnchorPoint({0.0, 0.0});
			NewGroupX_Sprite->setPosition({4.0, 4.0});
			NewGroupX_Sprite->setScale(0.65);

			NewGroupX->setZOrder(1);
			NewGroupX->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 225.f});

			// Select All Left Button
			auto SelectAllLeft_ButtonSprite = CCSprite::create("GJ_button_05.png");
			SelectAllLeft_ButtonSprite->setScale(0.8);

			auto SelectAllLeft_Sprite = CCSprite::create("as_selectAllLeft.png"_spr);
			auto SelectAllLeft = CCMenuItemSpriteExtra::create(
				SelectAllLeft_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function

			SelectAllLeft_ButtonSprite->addChild(SelectAllLeft_Sprite);

			SelectAllLeft_Sprite->setAnchorPoint({0.0, 0.0});
			SelectAllLeft_Sprite->setPosition({4.0, 4.0});
			SelectAllLeft_Sprite->setScale(0.65);

			SelectAllLeft->setZOrder(1);
			SelectAllLeft->setPosition({newActionsMenu->getContentWidth() / 2.f + 50.f, newActionsMenu->getContentHeight() - 225.f});

			// Align Y Button
			auto AlignY_ButtonSprite = CCSprite::create("GJ_button_05.png");
			AlignY_ButtonSprite->setScale(0.8);

			auto AlignY_Sprite = CCSprite::create("as_alignY.png"_spr);
			auto AlignY = CCMenuItemSpriteExtra::create(
				AlignY_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function

			AlignY_ButtonSprite->addChild(AlignY_Sprite);

			AlignY_Sprite->setAnchorPoint({0.0, 0.0});
			AlignY_Sprite->setPosition({4.0, 4.0});
			AlignY_Sprite->setScale(0.65);

			AlignY->setZOrder(1);
			AlignY->setPosition({newActionsMenu->getContentWidth() / 2.f - 50.f, newActionsMenu->getContentHeight() - 265.f});

			// New Group Y Button
			auto NewGroupY_ButtonSprite = CCSprite::create("GJ_button_05.png");
			NewGroupY_ButtonSprite->setScale(0.8);

			auto NewGroupY_Sprite = CCSprite::create("as_newGroupY.png"_spr);
			auto NewGroupY = CCMenuItemSpriteExtra::create(
				NewGroupY_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function

			NewGroupY_ButtonSprite->addChild(NewGroupY_Sprite);

			NewGroupY_Sprite->setAnchorPoint({0.0, 0.0});
			NewGroupY_Sprite->setPosition({4.0, 4.0});
			NewGroupY_Sprite->setScale(0.65);

			NewGroupY->setZOrder(1);
			NewGroupY->setPosition({newActionsMenu->getContentWidth() / 2.f, newActionsMenu->getContentHeight() - 265.f});

			// Select All Right Button
			auto SelectAllRight_ButtonSprite = CCSprite::create("GJ_button_05.png");
			SelectAllRight_ButtonSprite->setScale(0.8);

			auto SelectAllRight_Sprite = CCSprite::create("as_selectAllRight.png"_spr);
			auto SelectAllRight = CCMenuItemSpriteExtra::create(
				SelectAllRight_ButtonSprite,
				this,
				menu_selector(EditorPause::onAction)); // Change this to function

			SelectAllRight_ButtonSprite->addChild(SelectAllRight_Sprite);

			SelectAllRight_Sprite->setAnchorPoint({0.0, 0.0});
			SelectAllRight_Sprite->setPosition({4.0, 4.0});
			SelectAllRight_Sprite->setScale(0.65);

			SelectAllRight->setZOrder(1);
			SelectAllRight->setPosition({newActionsMenu->getContentWidth() / 2.f + 50.f, newActionsMenu->getContentHeight() - 265.f});

			// TOGGLE TAB //////////////////////////////////////////////////////////////////////////////////////

			// Options Title
			auto OptionTitle = CCLabelBMFont::create("Togglable Options", "goldFont.fnt");
			OptionTitle->setScale(0.5);
			OptionTitle->setPosition({newTogglesMenu->getContentWidth() / 2.f, newTogglesMenu->getContentHeight() - 15.f});
			OptionTitle->ignoreAnchorPointForPosition(false);

			// Preview Mode Button

			auto togglePreviewMode = CCMenuItemToggler::create(
				CCSprite::create("t_previewModeOff.png"_spr), CCSprite::create("t_previewModeOn.png"_spr),
				this,
				menu_selector(EditorPause::onOption)); // this isnt right btw // well this is :]
			togglePreviewMode->setID(EditorEnum::editorOptionNode[EditorEnum::EditorOption::PreviewMode]);

			bool isPreviewMode = gm->getGameVariable(EditorEnum::editorOptionVar[togglePreviewMode->getID()].c_str());

			togglePreviewMode->setZOrder(1);
			togglePreviewMode->setScale(0.6);
			togglePreviewMode->setPosition({newTogglesMenu->getContentWidth() / 2.f, newTogglesMenu->getContentHeight() - 40.f});
			togglePreviewMode->ignoreAnchorPointForPosition(false);
			togglePreviewMode->toggle(isPreviewMode);

			// RESUME BUTTON //////////////////////////////////////////////////////////////////////////////////////

			// Resume Button (pls fix this, it kept crashing the game and it does no logs)
			/*
			auto resumeButton_Sprite = CCSprite::create("r_resumeToEditor.png"_spr);
			resumeButton_Sprite->setScale(0.8);

			auto resumeButton = CCMenuItemSpriteExtra::create(
				resumeButton_Sprite,
				this,
				menu_selector(EditorPause::onNewToggles));

			resumeButton_Sprite->addChild(resumeButton);
			
			resumeButton->setZOrder(1);
			resumeButton->setPosition({newResumeMenu->getContentWidth() / 2.f, newResumeMenu->getContentHeight()});
			resumeButton->ignoreAnchorPointForPosition(false);

			// Add Buttons to Resume Menu
			newResumeMenu->addChild(resumeButton);
			*/
			// Add Toggles to Toggles Menu
			newTogglesMenu->addChild(togglePreviewMode);

			// Add Button to Action menu
			newActionsMenu->addChild(BuildHelper);
			newActionsMenu->addChild(CopyColorPlus);
			newActionsMenu->addChild(PasteColorPlus);
			newActionsMenu->addChild(CreateExtra);
			newActionsMenu->addChild(UnlockLayers);
			newActionsMenu->addChild(ResetUnused);
			newActionsMenu->addChild(CreateLoop);
			newActionsMenu->addChild(UncheckPortals);
			newActionsMenu->addChild(Keys);

			newActionsMenu->addChild(Regroup);
			newActionsMenu->addChild(ResetScroll);
			newActionsMenu->addChild(SelectAll);
			newActionsMenu->addChild(AlignX);
			newActionsMenu->addChild(NewGroupX);
			newActionsMenu->addChild(SelectAllLeft);
			newActionsMenu->addChild(AlignY);
			newActionsMenu->addChild(NewGroupY);
			newActionsMenu->addChild(SelectAllRight);

			// Add Menu into the Editor Pause Layer
			this->addChild(newActionsMenu);
			this->addChild(newTogglesMenu);
			this->addChild(newResumeMenu);

			newActionsMenu->addChild(ActionMenuSprite);
			newTogglesMenu->addChild(TogglesMenuSprite);
			infoMenu->addChild(infoMenuSprite);

			// Add Title to the Action Menu
			newActionsMenu->addChild(ActionTitle);
			newActionsMenu->addChild(QuickActionTitle);

			// Add Title to the Toggles Menu
			newTogglesMenu->addChild(OptionTitle);

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

	void onAction(CCObject * sender)
	{
		CCNode *nodeObject = as<CCNode *>(sender);
		auto nodeID = nodeObject->getID();

		log::debug("Processing editor action of ID {}...", nodeID.c_str());

		auto validation = EditorEnum::editorActionName[nodeID];

		if (validation.empty())
		{
			log::error("Editor action '{}' invalid", nodeID.c_str());
		}
		else
		{
			log::debug("Editor action {} valid", nodeID.c_str());

			if (getThisMod->getSettingValue<bool>("confirm-use"))
			{
				geode::createQuickPopup(
					validation.c_str(),
					fmt::format("Would you like to use <cy>{}</c>?", validation.c_str()),
					"Cancel", "Yes",
					[this, sender, nodeID](auto, bool btn2)
					{
						if (btn2)
						{
							log::debug("Initiating editor action with ID {}", nodeID.c_str());
							EditorPause::initiateAction(nodeID, sender);
						};
					});
			}
			else
			{
				EditorPause::initiateAction(nodeID, sender);
			};
		};
	};

	void onOption(CCObject * sender)
	{
		CCNode *nodeObject = as<CCNode *>(sender);
		auto nodeID = nodeObject->getID();

		log::debug("Processing editor option of ID {}...", nodeID.c_str());

		auto validation = EditorEnum::editorOptionName[nodeID];

		if (validation.empty())
		{
			log::error("Editor option '{}' invalid", nodeID.c_str());
		}
		else
		{
			log::error("Editor option {} valid", nodeID.c_str());

			EditorPause::initiateOption(nodeID, sender);
		};
	};

	void initiateAction(std::string actionID, CCObject * sender)
	{
		auto validate = EditorEnum::editorActionName[actionID];

		if (validate.empty())
		{
			log::error("Cannot initiate editor action of invalid ID '{}'", actionID);
		}
		else
		{
			log::debug("Initiating editor action of ID {}...", actionID);

			if (actionID == EditorEnum::editorActionNode[EditorEnum::EditorAction::BuildHelper])
			{
				EditorPauseLayer::onBuildHelper(sender);
				// }
				// else if (actionID == EditorEnum::editorActionNode[EditorEnum::EditorAction::CopyColorPlus])
				// {
				// 	EditorPauseLayer::onCopyWColor(sender);
				// }
				// else if (actionID == EditorEnum::editorActionNode[EditorEnum::EditorAction::PasteColorPlus])
				// {
				// 	EditorPauseLayer::onPasteWColor(sender);
			}
			else if (actionID == EditorEnum::editorActionNode[EditorEnum::EditorAction::CreateExtras])
			{
				EditorPauseLayer::onCreateExtras(sender);
				// }
				// else if (actionID == EditorEnum::editorActionNode[EditorEnum::EditorAction::UnlockLayers])
				// {
				// 	EditorPauseLayer::onUnlockAllLayers(sender);
				// }
				// else if (actionID == EditorEnum::editorActionNode[EditorEnum::EditorAction::ResetUnused])
				// {
				// 	EditorPauseLayer::doResetUnused(sender);
				// }
				// else if (actionID == EditorEnum::editorActionNode[EditorEnum::EditorAction::CreateLoop])
				// {
				// 	EditorPauseLayer::onCreateLoop(sender);
				// }
				// else if (actionID == EditorEnum::editorActionNode[EditorEnum::EditorAction::UncheckPortals])
				// {
				// 	EditorPauseLayer::uncheckAllPortals(sender);
				// }
				// else if (actionID == EditorEnum::editorActionNode[EditorEnum::EditorAction::Keys])
				// {
				// 	EditorPauseLayer::onKeybindings(sender);
			};
		};
	};

	void initiateOption(std::string optionID, CCObject * sender)
	{
		auto nodeObject = as<CCNode *>(sender);
		auto togglerObject = as<CCMenuItemToggler *>(nodeObject);

		auto validate = EditorEnum::editorActionName[optionID];

		if (validate.empty())
		{
			log::error("Cannot initiate editor action of invalid ID '{}'", optionID);
		}
		else
		{
			log::debug("Toggling editor option of ID {}...", optionID);

			m_editorLayer->updateEditorMode();
			togglerObject->toggle(gm->getGameVariable(EditorEnum::editorOptionVar[nodeObject->getID()].c_str()));
		};
	};
};