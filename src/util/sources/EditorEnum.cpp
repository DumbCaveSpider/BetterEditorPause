#include "../EditorEnum.hpp"

#include <string>
#include <map>

#include <Geode/Geode.hpp>

#include <Geode/utils/web.hpp>

using namespace geode::prelude;

/*
editor actions
*/

std::map<EditorEnum::Action, std::string> EditorEnum::actionNode{
    {EditorEnum::Action::BuildHelper, "build-helper"_spr},
    {EditorEnum::Action::CopyColorPlus, "copy-col-plus"_spr},
    {EditorEnum::Action::PasteColorPlus, "paste-col-plus"_spr},
    {EditorEnum::Action::CreateExtras, "create-extras"_spr},
    {EditorEnum::Action::UnlockLayers, "unlock-layers"_spr},
    {EditorEnum::Action::ResetUnused, "reset-unused"_spr},
    {EditorEnum::Action::CreateLoop, "create-loop"_spr},
    {EditorEnum::Action::UncheckPortals, "uncheck-portals"_spr},

    {EditorEnum::Action::Keys, "keybinds"_spr},

    {EditorEnum::Action::Regroup, "regroup"_spr},
    {EditorEnum::Action::ResetScroll, "reset-scroll"_spr},
    {EditorEnum::Action::SelectAll, "select-all"_spr},
    {EditorEnum::Action::AlignX, "align-x"_spr},
    {EditorEnum::Action::NewGroupX, "new-group-x"_spr},
    {EditorEnum::Action::SelectAllLeft, "select-all-left"_spr},
    {EditorEnum::Action::AlignY, "align-y"_spr},
    {EditorEnum::Action::NewGroupY, "new-group-y"_spr},
    {EditorEnum::Action::SelectAllRight, "select-all-right"_spr}};

std::map<std::string, std::string> EditorEnum::actionName{
    {EditorEnum::actionNode[EditorEnum::Action::BuildHelper], "Build Helper"},
    {EditorEnum::actionNode[EditorEnum::Action::CopyColorPlus], "Copy Color +"},
    {EditorEnum::actionNode[EditorEnum::Action::PasteColorPlus], "Paste Color +"},
    {EditorEnum::actionNode[EditorEnum::Action::CreateExtras], "Create Extras"},
    {EditorEnum::actionNode[EditorEnum::Action::UnlockLayers], "Unlock Layers"},
    {EditorEnum::actionNode[EditorEnum::Action::ResetUnused], "Reset Unused"},
    {EditorEnum::actionNode[EditorEnum::Action::CreateLoop], "Create Loop"},
    {EditorEnum::actionNode[EditorEnum::Action::UncheckPortals], "Uncheck Portals"},

    {EditorEnum::actionNode[EditorEnum::Action::Keys], "Keybind Viewer"},

    {EditorEnum::actionNode[EditorEnum::Action::Regroup], "Regroup"},
    {EditorEnum::actionNode[EditorEnum::Action::ResetScroll], "Reset Scroll"},
    {EditorEnum::actionNode[EditorEnum::Action::SelectAll], "Select All"},
    {EditorEnum::actionNode[EditorEnum::Action::AlignX], "Align X"},
    {EditorEnum::actionNode[EditorEnum::Action::NewGroupX], "New Group X"},
    {EditorEnum::actionNode[EditorEnum::Action::SelectAllLeft], "Select All Left"},
    {EditorEnum::actionNode[EditorEnum::Action::AlignY], "Align Y"},
    {EditorEnum::actionNode[EditorEnum::Action::NewGroupY], "New Group Y"},
    {EditorEnum::actionNode[EditorEnum::Action::SelectAllRight], "Select All Right"}};

std::map<std::string, std::string> EditorEnum::actionIcon{
    {EditorEnum::actionNode[EditorEnum::Action::BuildHelper], "a_buildHelper.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::CopyColorPlus], "a_copyColor+.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::PasteColorPlus], "a_pasteColor+.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::CreateExtras], "a_createExtras.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::UnlockLayers], "a_unlockLayers.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::ResetUnused], "a_resetUnused.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::CreateLoop], "a_createLoop.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::UncheckPortals], "a_uncheckPortals.png"_spr},

    {EditorEnum::actionNode[EditorEnum::Action::Keys], "a_keys.png"_spr},

    {EditorEnum::actionNode[EditorEnum::Action::Regroup], "as_regroup.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::ResetScroll], "as_resetScroll.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::SelectAll], "as_selectAll.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::AlignX], "as_alignX.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::NewGroupX], "as_newGroupX.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::SelectAllLeft], "as_selectAllLeft.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::AlignY], "as_alignY.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::NewGroupY], "as_newGroupY.png"_spr},
    {EditorEnum::actionNode[EditorEnum::Action::SelectAllRight], "as_selectAllRight.png"_spr}};

/*
editor options
*/

std::map<EditorEnum::Option, std::string> EditorEnum::optionNode{
    {EditorEnum::Option::PreviewMode, "preview-mode"_spr},
    {EditorEnum::Option::PreviewAnimations, "preview-anim"_spr},
    {EditorEnum::Option::PreviewParticles, "preview-particles"_spr},
    {EditorEnum::Option::PreviewShaders, "preview-shaders"_spr},
    {EditorEnum::Option::ShowHitboxes, "show-hitboxes"_spr},
    {EditorEnum::Option::HideInvisible, "hide-invis"_spr},
    {EditorEnum::Option::ShowGround, "show-ground"_spr},
    {EditorEnum::Option::ShowObjectInfo, "show-object-info"_spr},
    {EditorEnum::Option::ShowGrid, "show-grid"_spr},
    {EditorEnum::Option::SelectFilter, "select-filter"_spr},
    {EditorEnum::Option::IgnoreDamage, "ignore-damage"_spr}};

std::map<std::string, std::string> EditorEnum::optionName{
    {EditorEnum::optionNode[EditorEnum::Option::PreviewMode], "Preview Mode"},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewAnimations], "Preview Animations"},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewParticles], "Preview Particles"},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewShaders], "Preview Shaders"},
    {EditorEnum::optionNode[EditorEnum::Option::ShowHitboxes], "Show Hitboxes"},
    {EditorEnum::optionNode[EditorEnum::Option::HideInvisible], "Hide Invisible"},
    {EditorEnum::optionNode[EditorEnum::Option::ShowGround], "Show Ground"},
    {EditorEnum::optionNode[EditorEnum::Option::ShowObjectInfo], "Show Object Information"},
    {EditorEnum::optionNode[EditorEnum::Option::ShowGrid], "Show Grid"},
    {EditorEnum::optionNode[EditorEnum::Option::SelectFilter], "Selection Filter"},
    {EditorEnum::optionNode[EditorEnum::Option::IgnoreDamage], "No-Clip"}};

std::map<std::string, std::string> EditorEnum::optionSpriteEnabled{
    {EditorEnum::optionNode[EditorEnum::Option::PreviewMode], "t_previewModeOn.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewAnimations], "t_previewAnimationsOn.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewParticles], "t_previewParticlesOn.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewShaders], "t_previewShadersOn.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::ShowHitboxes], "t_showHitboxesOn.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::HideInvisible], "t_hideInvisibleOn.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::ShowGround], "t_showGroundOn.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::ShowObjectInfo], "t_showObjectInfoOn.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::ShowGrid], "t_showGridOn.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::SelectFilter], "t_selectFilterOn.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::IgnoreDamage], "t_ignoreDamageOn.png"_spr}};

std::map<std::string, std::string> EditorEnum::optionSpriteDisabled{
    {EditorEnum::optionNode[EditorEnum::Option::PreviewMode], "t_previewModeOff.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewAnimations], "t_previewAnimationsOff.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewParticles], "t_previewParticlesOff.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewShaders], "t_previewShadersOff.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::ShowHitboxes], "t_showHitboxesOff.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::HideInvisible], "t_hideInvisibleOff.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::ShowGround], "t_showGroundOff.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::ShowObjectInfo], "t_showObjectInfoOff.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::ShowGrid], "t_showGridOff.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::SelectFilter], "t_selectFilterOff.png"_spr},
    {EditorEnum::optionNode[EditorEnum::Option::IgnoreDamage], "t_ignoreDamageOff.png"_spr}};

std::map<std::string, std::string> EditorEnum::optionVar{
    {EditorEnum::optionNode[EditorEnum::Option::PreviewMode], "0036"},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewAnimations], "0118"},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewParticles], "0117"},
    {EditorEnum::optionNode[EditorEnum::Option::PreviewShaders], "0158"},
    {EditorEnum::optionNode[EditorEnum::Option::ShowHitboxes], "0045"},
    {EditorEnum::optionNode[EditorEnum::Option::HideInvisible], "0121"},
    {EditorEnum::optionNode[EditorEnum::Option::ShowGround], "0037"},
    {EditorEnum::optionNode[EditorEnum::Option::ShowObjectInfo], "0041"},
    {EditorEnum::optionNode[EditorEnum::Option::ShowGrid], "0038"},
    {EditorEnum::optionNode[EditorEnum::Option::SelectFilter], "0064"},
    {EditorEnum::optionNode[EditorEnum::Option::IgnoreDamage], "0009"}};