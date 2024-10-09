#include "util/EditorEnum.hpp"
#include "popups/CustomPopupLayer.hpp"

#include <Geode/Geode.hpp>
#include <Geode/Loader.hpp>

#include <Geode/modify/EditorPauseLayer.hpp>
#include <Geode/modify/DrawGridLayer.hpp>
#include <Geode/modify/GameObject.hpp>
#include <Geode/modify/EditorUI.hpp>

#include <Geode/binding/EditorPauseLayer.hpp>
#include <Geode/binding/LevelEditorLayer.hpp>
#include <Geode/binding/DrawGridLayer.hpp>
#include <Geode/binding/GameManager.hpp>
#include <Geode/binding/EditorUI.hpp>

using namespace geode::prelude;

auto getThisMod = geode::getMod();
auto getThisLoader = geode::Loader::get();

auto gm = GameManager::get();
auto winSize = CCDirector::sharedDirector()->getWinSize();

class $modify(DrawGridLayer)
{
	$override void draw()
	{
		bool origBool = m_editorLayer->m_previewMode;
		DrawGridLayer::draw();
		m_editorLayer->m_previewMode = origBool;
	};
};

// class $modify(EditorUI)
// {
// 	$override void selectObject(GameObject * obj, bool filter)
// 	{
// 		if (!static_cast<GameObject *>(obj)->shouldHide())
// 		{
// 			EditorUI::selectObject(obj, filter);
// 		};
// 	};
// };

class $modify(EditorPause, EditorPauseLayer)
{
	struct FakeEditorPauseLayer final
	{
		char m_alloc[sizeof(EditorPauseLayer)];
		EditorPauseLayer *operator->()
		{
			return reinterpret_cast<EditorPauseLayer *>(&m_alloc);
		};
	};

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
			auto guidelinesMenu = this->getChildByID("guidelines-menu");

			// check if player wants to enable new actions buttons
			if (getThisMod->getSettingValue<bool>("move-tools"))
			{
				actionsMenu->removeMeAndCleanup();
				smallActionsMenu->removeMeAndCleanup();

				// newActionsMenu menu
				auto newActionsMenu = CCMenu::create();
				newActionsMenu->setID("all-actions-menu"_spr);
				newActionsMenu->ignoreAnchorPointForPosition(false);
				newActionsMenu->setZOrder(1);

				// menu bg
				CCScale9Sprite *newActionsMenu_sprite = CCScale9Sprite::create("square02b_001.png");
				newActionsMenu_sprite->setID("panel-actions"_spr);
				newActionsMenu_sprite->ignoreAnchorPointForPosition(false);
				newActionsMenu_sprite->setScaledContentSize({150.f, 300.f});
				newActionsMenu_sprite->setPosition({this->getContentWidth() - 90.f, 160.f});
				newActionsMenu_sprite->setOpacity(150);
				newActionsMenu_sprite->setColor(ccColor3B(0, 0, 0));
				newActionsMenu_sprite->setZOrder(0);

				// menu layout for buttons
				AxisLayout *newActionsMenu_layout = AxisLayout::create(Axis::Row);
				newActionsMenu_layout->setGap(0.f);
				newActionsMenu_layout->setAutoScale(true);
				newActionsMenu_layout->setGrowCrossAxis(true);
				newActionsMenu_layout->setCrossAxisOverflow(false);
				newActionsMenu_layout->setAxisAlignment(AxisAlignment::Even);
				newActionsMenu_layout->setCrossAxisAlignment(AxisAlignment::Even);
				newActionsMenu_layout->setCrossAxisLineAlignment(AxisAlignment::Even);
				newActionsMenu_layout->ignoreInvisibleChildren(true);
				newActionsMenu_layout->setAxisReverse(false);

				// menu layout options
				AxisLayoutOptions *newActionsMenu_layoutOptions = AxisLayoutOptions::create();
				newActionsMenu_layoutOptions->setAutoScale(false);

				newActionsMenu->setLayout(newActionsMenu_layout, true, false);
				newActionsMenu->setLayoutOptions(newActionsMenu_layoutOptions, true);

				// ACTION TAB //////////////////////////////////////////////////////////////////////////////////////

				// Action Title
				auto ActionTitle = CCLabelBMFont::create("Creator Actions", "goldFont.fnt");
				ActionTitle->setScale(0.625);
				ActionTitle->setPosition({newActionsMenu_sprite->getContentWidth() / 2, newActionsMenu_sprite->getContentHeight() - 18.75f});
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

				newActionsMenu->setContentWidth(newActionsMenu_sprite->getContentWidth());
				newActionsMenu->setPosition({newActionsMenu_sprite->getContentWidth() / 2, newActionsMenu_sprite->getContentHeight() * 0.475f});
				newActionsMenu->setScale(0.825);
				newActionsMenu->updateLayout(true);

				newActionsMenu_sprite->addChild(ActionTitle);
				newActionsMenu_sprite->addChild(newActionsMenu);
				this->addChild(newActionsMenu_sprite);
			};

			// check if player wants to enable new options buttons
			if (getThisMod->getSettingValue<bool>("move-toggles"))
			{
				togglesMenu->removeMeAndCleanup();
				settingsMenu->removeMeAndCleanup();

				// newTogglesMenu menu
				auto newTogglesMenu = CCMenu::create();
				newTogglesMenu->setID("options-menu"_spr);
				newTogglesMenu->ignoreAnchorPointForPosition(false);
				newTogglesMenu->setZOrder(1);

				// menu bg
				CCScale9Sprite *newTogglesMenu_sprite = CCScale9Sprite::create("square02b_001.png");
				newTogglesMenu_sprite->setID("panel-options"_spr);
				newTogglesMenu_sprite->ignoreAnchorPointForPosition(false);
				newTogglesMenu_sprite->setScaledContentSize({150.f, 300.f});
				newTogglesMenu_sprite->setPosition({90.f, 160.f});
				newTogglesMenu_sprite->setOpacity(150);
				newTogglesMenu_sprite->setColor(ccColor3B(0, 0, 0));
				newTogglesMenu_sprite->setZOrder(0);

				// menu layout for buttons
				AxisLayout *newTogglesMenu_layout = AxisLayout::create(Axis::Column);
				newTogglesMenu_layout->setGap(5.f);
				newTogglesMenu_layout->setAutoScale(true);
				newTogglesMenu_layout->setGrowCrossAxis(false);
				newTogglesMenu_layout->setCrossAxisOverflow(false);
				newTogglesMenu_layout->setAxisAlignment(AxisAlignment::Even);
				newTogglesMenu_layout->setCrossAxisAlignment(AxisAlignment::Even);
				newTogglesMenu_layout->setCrossAxisLineAlignment(AxisAlignment::Even);
				newTogglesMenu_layout->ignoreInvisibleChildren(true);
				newTogglesMenu_layout->setAxisReverse(true);

				// menu layout options
				AxisLayoutOptions *newTogglesMenu_layoutOptions = AxisLayoutOptions::create();
				newTogglesMenu_layoutOptions->setAutoScale(true);

				newTogglesMenu->setLayout(newTogglesMenu_layout, true, false);
				newTogglesMenu->setLayoutOptions(newTogglesMenu_layoutOptions, true);

				// TOGGLE TAB //////////////////////////////////////////////////////////////////////////////////////

				// Options Title
				auto OptionTitle = CCLabelBMFont::create("Editor Options", "goldFont.fnt");
				OptionTitle->setScale(0.625);
				OptionTitle->setPosition({newTogglesMenu_sprite->getContentWidth() / 2.f, newTogglesMenu_sprite->getContentHeight() - 18.75f});
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
						toggle->toggle(isToggled);

						newTogglesMenu->addChild(toggle);
						newTogglesMenu->updateLayout(true);

						log::debug("Created option button {}", pair.second.c_str());
					};
				};

				newTogglesMenu->setContentWidth(newTogglesMenu_sprite->getContentWidth());
				newTogglesMenu->setPosition({newTogglesMenu_sprite->getContentWidth() / 2, newTogglesMenu_sprite->getContentHeight() * 0.475f});
				newTogglesMenu->setScale(0.8);
				newTogglesMenu->updateLayout(true);

				newTogglesMenu_sprite->addChild(OptionTitle);
				newTogglesMenu_sprite->addChild(newTogglesMenu);
				this->addChild(newTogglesMenu_sprite);
			};

			// check if player wants to enable new resume menu
			if (getThisMod->getSettingValue<bool>("move-resume"))
			{
				resumeMenu->removeMeAndCleanup();

				// newResumeMenu menu
				auto newResumeMenu = CCMenu::create();
				newResumeMenu->setID("resume_menu"_spr);
				newResumeMenu->ignoreAnchorPointForPosition(false);
				newResumeMenu->setScaledContentSize({200.f, 200.f});
				newResumeMenu->setPosition({this->getContentWidth() / 2.f, 170.f});

				// move guidelines menu
				guidelinesMenu->setPosition({this->getContentWidth() / 2.f, 60.f});

				// RESUME BUTTON //////////////////////////////////////////////////////////////////////////////////////

				// Resume Button

				auto resume_Sprite = CCSprite::create("r_resumeToEditor.png"_spr);
				resume_Sprite->setScale(0.8);

				auto resume_Button = CCMenuItemSpriteExtra::create(
					resume_Sprite,
					this,
					menu_selector(EditorPauseLayer::onResume));

				resume_Button->setZOrder(1);
				resume_Button->setPosition({newResumeMenu->getContentWidth() / 2.f, newResumeMenu->getContentHeight() - 30.f});
				resume_Button->ignoreAnchorPointForPosition(false);

				// saveAndPlay Button

				auto saveAndPlay_Sprite = CCSprite::create("r_saveAndPlay.png"_spr);
				saveAndPlay_Sprite->setScale(0.8);

				auto saveAndPlay_Button = CCMenuItemSpriteExtra::create(
					saveAndPlay_Sprite,
					this,
					menu_selector(EditorPauseLayer::onSaveAndPlay));

				saveAndPlay_Button->setZOrder(1);
				saveAndPlay_Button->setPosition({newResumeMenu->getContentWidth() / 2.f, newResumeMenu->getContentHeight() - 65.f});
				saveAndPlay_Button->ignoreAnchorPointForPosition(false);

				// saveAndExit Button

				auto saveAndExit_Sprite = CCSprite::create("r_saveAndExit.png"_spr);
				saveAndExit_Sprite->setScale(0.8);

				auto saveAndExit_Button = CCMenuItemSpriteExtra::create(
					saveAndExit_Sprite,
					this,
					menu_selector(EditorPauseLayer::onSaveAndExit));

				saveAndExit_Button->setZOrder(1);
				saveAndExit_Button->setPosition({newResumeMenu->getContentWidth() / 2.f, newResumeMenu->getContentHeight() - 100.f});
				saveAndExit_Button->ignoreAnchorPointForPosition(false);

				// Save Button

				auto Save_Sprite = CCSprite::create("r_saveLevel.png"_spr);
				Save_Sprite->setScale(0.8);

				auto Save_Button = CCMenuItemSpriteExtra::create(
					Save_Sprite,
					this,
					menu_selector(EditorPauseLayer::onSave));

				Save_Button->setZOrder(1);
				Save_Button->setPosition({newResumeMenu->getContentWidth() / 2.f, newResumeMenu->getContentHeight() - 135.f});
				Save_Button->ignoreAnchorPointForPosition(false);

				// Exit Without Save Button

				auto exitWithoutSave_Sprite = CCSprite::create("r_exitWithoutSave.png"_spr);
				exitWithoutSave_Sprite->setScale(0.8);

				auto exitWithoutSave_Button = CCMenuItemSpriteExtra::create(
					exitWithoutSave_Sprite,
					this,
					menu_selector(EditorPauseLayer::onExitNoSave));

				exitWithoutSave_Button->setZOrder(1);
				exitWithoutSave_Button->setPosition({newResumeMenu->getContentWidth() / 2.f, newResumeMenu->getContentHeight() - 170.f});
				exitWithoutSave_Button->ignoreAnchorPointForPosition(false);

				// Add Buttons to Resume Menu
				newResumeMenu->addChild(resume_Button);
				newResumeMenu->addChild(saveAndPlay_Button);
				newResumeMenu->addChild(saveAndExit_Button);
				newResumeMenu->addChild(Save_Button);
				newResumeMenu->addChild(exitWithoutSave_Button);

				this->addChild(newResumeMenu);
			};

			// check if player wants to enable new info labels
			if (getThisMod->getSettingValue<bool>("move-info"))
			{
				infoMenu->removeMeAndCleanup();

				// newinfoMenu background
				CCScale9Sprite *newTimeMenu_sprite = CCScale9Sprite::create("square02b_001.png");
				newTimeMenu_sprite->setID("time-menu"_spr);
				newTimeMenu_sprite->ignoreAnchorPointForPosition(false);
				newTimeMenu_sprite->setScaledContentSize({220.f, 100.f});
				newTimeMenu_sprite->setPosition({this->getContentWidth() / 2.f, 320.f});
				newTimeMenu_sprite->setOpacity(150);
				newTimeMenu_sprite->setColor(ccColor3B(0, 0, 0));
				newTimeMenu_sprite->setZOrder(0);

				// idk why geode doesnt have a freaking way to get the value of the object count, sfx and songs individually
				auto objectCount = as<CCLabelBMFont *>(infoMenu->getChildByID("object-count-label"));
				auto lengthLabel = as<CCLabelBMFont *>(infoMenu->getChildByID("length-label"));
				auto lengthNameLabel = as<CCLabelBMFont *>(infoMenu->getChildByID("length-name-label"));

				// TIME TAB //////////////////////////////////////////////////////////////////////////////////////

				// Should be the time spent on editor but this is just a test. Should use Timeul
				auto ObjectCount = CCLabelBMFont::create(CCString::createWithFormat("Objects: %i", LevelEditorLayer::get()->m_objectCount.value())->getCString(), "bigFont.fnt"); // what object count? am i stupid?
				ObjectCount->setScale(0.3);
				ObjectCount->setPosition({newTimeMenu_sprite->getContentWidth() / 2, newTimeMenu_sprite->getContentHeight() - 80.f});
				ObjectCount->ignoreAnchorPointForPosition(false);
				ObjectCount->setZOrder(1);

				newTimeMenu_sprite->addChild(ObjectCount);
				this->addChild(newTimeMenu_sprite);
			};

			// remove probably obtrusive support betteredit button, sowwy
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
			log::debug("Editor option {} valid", nodeID.c_str());

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
				this->onBuildHelper(sender);
			}
			// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::CopyColorPlus])
			//{
			//	this->onCopyWColor(sender);
			// }
			// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::PasteColorPlus])
			//{
			//	this->onPasteWColor(sender);
			// }
			else if (actionID == EditorEnum::actionNode[EditorEnum::Action::CreateExtras])
			{
				this->onCreateExtras(sender);
			}
			// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::UnlockLayers])
			//{
			//	this->onUnlockAllLayers(sender);
			// }
			// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::1Unused])
			//{
			//	this->doResetUnused(sender);
			// }
			// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::CreateLoop])
			//{
			//	this->onCreateLoop(sender);
			// }
			// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::UncheckPortals])
			//{
			//	this->uncheckAllPortals(sender);
			// }
			// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::Keys])
			//{
			//	this->onKeybindings(sender);
			// }
			// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::Regroup])
			//{
			//	this->onReGroup(sender);
			// }
			// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::ResetScroll])
			//{
			//	this->onResetScroll(sender);
			// }
			else if (actionID == EditorEnum::actionNode[EditorEnum::Action::SelectAll])
			{
				this->onSelectAll(sender);
			}
			else if (actionID == EditorEnum::actionNode[EditorEnum::Action::AlignX])
			{
				this->onAlignX(sender);
			}
			// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::NewGroupX])
			//{
			//	this->onNewGroupX(sender);
			// }
			else if (actionID == EditorEnum::actionNode[EditorEnum::Action::SelectAllLeft])
			{
				this->onSelectAllLeft(sender);
			}
			else if (actionID == EditorEnum::actionNode[EditorEnum::Action::AlignY])
			{
				this->onAlignY(sender);
			}
			// else if (actionID == EditorEnum::actionNode[EditorEnum::Action::NewGroupY])
			//{
			//	this->onNewGroupY(sender);
			// }
			else if (actionID == EditorEnum::actionNode[EditorEnum::Action::SelectAllRight])
			{
				this->onSelectAllRight(sender);
			};
		};
	};

	void initiateOption(std::string optionID, CCObject * sender)
	{
		auto nodeObject = as<CCNode *>(sender);
		auto togglerObject = as<CCMenuItemToggler *>(nodeObject);

		auto validate = EditorEnum::optionName[optionID];

		if (validate.empty())
		{
			log::error("Cannot initiate editor action of invalid ID '{}'", optionID);
		}
		else
		{
			log::debug("Toggling editor option of ID {}...", optionID);

			if (optionID == EditorEnum::optionNode[EditorEnum::Option::PreviewMode])
			{
				log::debug("Unknown protocol for action {}", optionID);
			}
			else if (optionID == EditorEnum::optionNode[EditorEnum::Option::PreviewAnimations])
			{
				EditorPause::togglePreviewAnim(sender);
			}
			else if (optionID == EditorEnum::optionNode[EditorEnum::Option::PreviewParticles])
			{
				m_editorLayer->updatePreviewParticles();
			}
			else if (optionID == EditorEnum::optionNode[EditorEnum::Option::PreviewShaders])
			{
				EditorPause::onNewToggles(sender);
			}
			else if (optionID == EditorEnum::optionNode[EditorEnum::Option::ShowHitboxes])
			{
				EditorPause::onNewToggles(sender);
			}
			else if (optionID == EditorEnum::optionNode[EditorEnum::Option::HideInvisible])
			{
				EditorPause::onNewToggles(sender);
			}
			else if (optionID == EditorEnum::optionNode[EditorEnum::Option::ShowGround])
			{
				m_editorLayer->m_groundLayer->setVisible(togglerObject->isToggled());
			}
			else if (optionID == EditorEnum::optionNode[EditorEnum::Option::ShowObjectInfo])
			{
				EditorPause::onNewToggles(sender);
			}
			else if (optionID == EditorEnum::optionNode[EditorEnum::Option::ShowGrid])
			{
				log::debug("Unknown protocol for action {}", optionID);
			}
			else if (optionID == EditorEnum::optionNode[EditorEnum::Option::SelectFilter])
			{
				EditorPause::onNewToggles(sender);
			}
			else if (optionID == EditorEnum::optionNode[EditorEnum::Option::IgnoreDamage])
			{
				EditorPause::onNewToggles(sender);
			};

			togglerObject->toggle(gm->getGameVariable(EditorEnum::optionVar[nodeObject->getID()].c_str()));
		};
	};

	void onNewToggles(CCObject * sender)
	{
		Notification::create("Button yes", NotificationIcon::Success, 2.f)->show();
	};
};