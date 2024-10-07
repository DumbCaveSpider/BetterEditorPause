#include "util/EditorEnum.hpp"
#include "popups/CustomPopupLayer.hpp"

#include <Geode/Geode.hpp>
#include <Geode/Loader.hpp>

#include <Geode/modify/EditorPauseLayer.hpp>

#include <Geode/binding/EditorPauseLayer.hpp>

using namespace geode::prelude;

auto getThisMod = geode::getMod();
auto getThisLoader = geode::Loader::get();

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

			// ok fixed it
			//
			// love,
			// chris

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
			// resumeMenu->removeMeAndCleanup();

			// newActionsMenu menu
			auto newActionsMenu = CCMenu::create();
			newActionsMenu->setID("all-actions-menu"_spr);
			newActionsMenu->ignoreAnchorPointForPosition(false);
			newActionsMenu->setZOrder(1);

			CCScale9Sprite *newActionsMenu_sprite = CCScale9Sprite::create("square02b_001.png");
			newActionsMenu_sprite->setID("panel-actions"_spr);
			newActionsMenu_sprite->ignoreAnchorPointForPosition(false);
			newActionsMenu_sprite->setScaledContentSize({150.f, 300.f});
			newActionsMenu_sprite->setPosition({this->getContentWidth() - 90.f, 160.f});
			newActionsMenu_sprite->setOpacity(150);
			newActionsMenu_sprite->setColor(ccColor3B(0, 0, 0));
			newActionsMenu_sprite->setZOrder(0);

			AxisLayout *newActionsMenu_layout = AxisLayout::create(Axis::Row);
			newActionsMenu_layout->setGap(30.f);
			newActionsMenu_layout->setAutoScale(true);
			newActionsMenu_layout->setGrowCrossAxis(true);
			newActionsMenu_layout->setCrossAxisOverflow(true);
			newActionsMenu_layout->setAxisAlignment(AxisAlignment::Even);
			newActionsMenu_layout->setCrossAxisAlignment(AxisAlignment::Even);
			newActionsMenu_layout->setCrossAxisLineAlignment(AxisAlignment::Even);
			newActionsMenu_layout->ignoreInvisibleChildren(true);

			AxisLayoutOptions *newActionsMenu_layoutOptions = AxisLayoutOptions::create();

			newActionsMenu->setLayout(newActionsMenu_layout, true, false);
			newActionsMenu->setLayoutOptions(newActionsMenu_layoutOptions, true);

			// newTogglesMenu menu
			auto newTogglesMenu = CCMenu::create();
			newTogglesMenu->setID("options-menu"_spr);
			newTogglesMenu->ignoreAnchorPointForPosition(false);
			newTogglesMenu->setZOrder(1);

			CCScale9Sprite *newTogglesMenu_sprite = CCScale9Sprite::create("square02b_001.png");
			newTogglesMenu_sprite->setID("panel-options"_spr);
			newTogglesMenu_sprite->ignoreAnchorPointForPosition(false);
			newTogglesMenu_sprite->setScaledContentSize({150.f, 300.f});
			newTogglesMenu_sprite->setPosition({90.f, 160.f});
			newTogglesMenu_sprite->setOpacity(150);
			newTogglesMenu_sprite->setColor(ccColor3B(0, 0, 0));
			newTogglesMenu_sprite->setZOrder(0);

			AxisLayout *newTogglesMenu_layout = AxisLayout::create(Axis::Column);
			newTogglesMenu_layout->setGap(5.f);
			newTogglesMenu_layout->setAutoScale(true);
			newTogglesMenu_layout->setGrowCrossAxis(false);
			newTogglesMenu_layout->setCrossAxisOverflow(false);
			newTogglesMenu_layout->setAxisAlignment(AxisAlignment::Even);
			newTogglesMenu_layout->setCrossAxisAlignment(AxisAlignment::Even);
			newTogglesMenu_layout->setCrossAxisLineAlignment(AxisAlignment::Even);
			newTogglesMenu_layout->ignoreInvisibleChildren(true);

			AxisLayoutOptions *newTogglesMenu_layoutOptions = AxisLayoutOptions::create();

			newTogglesMenu->setLayout(newTogglesMenu_layout, true, false);
			newTogglesMenu->setLayoutOptions(newTogglesMenu_layoutOptions, true);

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
			auto ActionTitle = CCLabelBMFont::create("Creator Actions", "goldFont.fnt");
			ActionTitle->setScale(0.625);
			ActionTitle->setPosition({newActionsMenu_sprite->getContentWidth() / 2, newActionsMenu_sprite->getContentHeight() - 20.f});
			ActionTitle->ignoreAnchorPointForPosition(false);
			ActionTitle->setZOrder(1);

			// All Action Buttons //////////////////////////////////////////////////////////////////////////////////////
			for (const auto &pair : EditorEnum::actionNode)
			{
				auto validateName = EditorEnum::actionName[pair.second];
				auto validateIcon = EditorEnum::actionIcon[pair.second];

				if (validateName.empty() || validateIcon.empty())
				{
					log::error("Action of ID '{}' invalid or missing sprite name", pair.second.c_str());
				}
				else
				{
					log::debug("Creating action button of ID {}...", pair.second.c_str());

					auto actionButtonSprite = CCSprite::create("GJ_button_04.png");

					auto actionSprite = CCSprite::create(validateIcon.c_str());
					actionSprite->setAnchorPoint({0.5, 0.5});
					actionSprite->setPosition({actionButtonSprite->getScaledContentWidth() / 2, actionButtonSprite->getScaledContentHeight() / 2});
					actionSprite->setScale(0.625);

					actionButtonSprite->addChild(actionSprite);

					auto action = CCMenuItemSpriteExtra::create(
						actionButtonSprite,
						this,
						menu_selector(EditorPause::onAction));
					action->setID(pair.second);
					action->setZOrder(1);

					newActionsMenu->addChild(action);
					newActionsMenu->updateLayout();

					log::debug("Created action button {}", pair.second.c_str());
				};
			};

			// TOGGLE TAB //////////////////////////////////////////////////////////////////////////////////////

			// Options Title
			auto OptionTitle = CCLabelBMFont::create("Editor Options", "goldFont.fnt");
			OptionTitle->setScale(0.625);
			OptionTitle->setPosition({newTogglesMenu_sprite->getContentWidth() / 2.f, newTogglesMenu_sprite->getContentHeight() - 20.f});
			OptionTitle->ignoreAnchorPointForPosition(false);

			// All Option Buttons //////////////////////////////////////////////////////////////////////////////////////
			for (const auto &pair : EditorEnum::optionNode)
			{
				auto validateName = EditorEnum::optionName[pair.second];
				auto validateVar = EditorEnum::optionVar[pair.second];

				if (validateName.empty() || validateVar.empty())
				{
					log::error("Option of ID '{}' invalid or missing game variable", pair.second.c_str());
				}
				else
				{
					log::debug("Creating option button of ID {}...", pair.second.c_str());

					bool isToggled = gm->getGameVariable(validateVar.c_str());

					auto toggle = CCMenuItemToggler::create(
						CCSprite::create(EditorEnum::optionSpriteDisabled[pair.second].c_str()), CCSprite::create(EditorEnum::optionSpriteEnabled[pair.second].c_str()),
						this,
						menu_selector(EditorPause::onOption)); // this isnt right btw // well this is :]
					toggle->setID(pair.second);
					toggle->setZOrder(1);
					toggle->setScale(0.375);
					toggle->toggle(isToggled);

					newTogglesMenu->addChild(toggle);
					newTogglesMenu->updateLayout(true);

					log::debug("Created option button {}", pair.second.c_str());
				};
			};

			// RESUME BUTTON //////////////////////////////////////////////////////////////////////////////////////

			// Resume Button (pls fix this, it kept crashing the game and it does no logs)
			/*
			auto resumeButton_Sprite = CCSprite::create("r_resumeToEditor.png"_spr);
			resumeButton_Sprite->setScale(0.75);

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

			newActionsMenu->setContentWidth(newActionsMenu_sprite->getContentWidth());
			newActionsMenu->setPosition({newActionsMenu_sprite->getContentWidth() / 2, newActionsMenu_sprite->getContentHeight() * 0.45f});
			newActionsMenu->setScale(0.75);
			newActionsMenu->updateLayout(true);

			newTogglesMenu->setContentWidth(newTogglesMenu_sprite->getContentWidth());
			newTogglesMenu->setPosition({newTogglesMenu_sprite->getContentWidth() / 2, newTogglesMenu_sprite->getContentHeight() * 0.45f});
			newTogglesMenu->setScale(0.75);
			newTogglesMenu->updateLayout(true);

			// Add Menu into the Editor Pause Layer
			newActionsMenu_sprite->addChild(newActionsMenu);
			newTogglesMenu_sprite->addChild(newTogglesMenu);
			this->addChild(newResumeMenu);

			this->addChild(newActionsMenu_sprite);
			this->addChild(newTogglesMenu_sprite);
			infoMenu->addChild(infoMenuSprite);

			// Add Title to the Action Menu
			newActionsMenu_sprite->addChild(ActionTitle);

			// Add Title to the Toggles Menu
			newTogglesMenu_sprite->addChild(OptionTitle);

			bool isBetterEditLoaded = getThisLoader->isModLoaded("hjfod.betteredit");

			if (isBetterEditLoaded)
			{
				auto supportBeButton = this->getChildByIDRecursive("hjfod.betteredit/support-be-btn");

				if (supportBeButton)
				{
					supportBeButton->setVisible(false);
				};
			};

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

		auto validation = EditorEnum::actionName[nodeID];

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

		auto validation = EditorEnum::optionName[nodeID];

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
		auto validate = EditorEnum::actionName[actionID];

		if (validate.empty())
		{
			log::error("Cannot initiate editor action of invalid ID '{}'", actionID);
		}
		else
		{
			log::debug("Initiating editor action of ID {}...", actionID);

			if (actionID == EditorEnum::actionNode[EditorEnum::Action::BuildHelper])
			{
				EditorPauseLayer::onBuildHelper(sender);
				// }
				// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::CopyColorPlus])
				// {
				// 	EditorPauseLayer::onCopyWColor(sender);
				// }
				// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::PasteColorPlus])
				// {
				// 	EditorPauseLayer::onPasteWColor(sender);
			}
			else if (actionID == EditorEnum::actionNode[EditorEnum::Action::CreateExtras])
			{
				EditorPauseLayer::onCreateExtras(sender);
				// }
				// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::UnlockLayers])
				// {
				// 	EditorPauseLayer::onUnlockAllLayers(sender);
				// }
				// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::ResetUnused])
				// {
				// 	EditorPauseLayer::doResetUnused(sender);
				// }
				// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::CreateLoop])
				// {
				// 	EditorPauseLayer::onCreateLoop(sender);
				// }
				// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::UncheckPortals])
				// {
				// 	EditorPauseLayer::uncheckAllPortals(sender);
				// }
				// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::Keys])
				// {
				// 	EditorPauseLayer::onKeybindings(sender);
			};
		};
	};

	void initiateOption(std::string optionID, CCObject * sender)
	{
		auto nodeObject = as<CCNode *>(sender);
		auto togglerObject = as<CCMenuItemToggler *>(nodeObject);

		auto validate = EditorEnum::actionName[optionID];

		if (validate.empty())
		{
			log::error("Cannot initiate editor action of invalid ID '{}'", optionID);
		}
		else
		{
			log::debug("Toggling editor option of ID {}...", optionID);

			m_editorLayer->updateEditorMode();
			togglerObject->toggle(gm->getGameVariable(EditorEnum::optionVar[nodeObject->getID()].c_str()));
		};
	};
};