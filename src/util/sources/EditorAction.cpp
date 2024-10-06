#include "../EditorAction.hpp"

#include <string>
#include <map>

#include <Geode/Geode.hpp>

#include <Geode/utils/web.hpp>

using namespace geode::prelude;

std::map<EditorAction::EditorActionEnum, std::string> EditorAction::editorActionNode{
    {EditorAction::EditorActionEnum::BuildHelper, "build-helper"_spr},
    {EditorAction::EditorActionEnum::CopyColorPlus, "copy-col-plus"_spr},
    {EditorAction::EditorActionEnum::PasteColorPlus, "paste-col-plus"_spr},
    {EditorAction::EditorActionEnum::CreateExtras, "create-extras"_spr},
    {EditorAction::EditorActionEnum::UnlockLayers, "unlock-layers"_spr},
    {EditorAction::EditorActionEnum::ResetUnused, "reset-unused"_spr},
    {EditorAction::EditorActionEnum::CreateLoop, "create-loop"_spr},
    {EditorAction::EditorActionEnum::UncheckPortals, "uncheck-portals"_spr},
    {EditorAction::EditorActionEnum::Keys, "keybinds"_spr},

    {EditorAction::EditorActionEnum::Regroup, "regroup"_spr},
    {EditorAction::EditorActionEnum::ResetScroll, "reset-scroll"_spr},
    {EditorAction::EditorActionEnum::SelectAll, "select-all"_spr},
    {EditorAction::EditorActionEnum::AlignX, "align-x"_spr},
    {EditorAction::EditorActionEnum::AlignY, "align-y"_spr},
    {EditorAction::EditorActionEnum::NewGroupX, "new-group-x"_spr},
    {EditorAction::EditorActionEnum::NewGroupY, "new-group-y"_spr},
    {EditorAction::EditorActionEnum::SelectAllLeft, "select-all-left"_spr},
    {EditorAction::EditorActionEnum::SelectAllRight, "select-all-right"_spr}};

std::map<std::string, std::string> EditorAction::editorActionName{
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::BuildHelper], "Build Helper"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::CopyColorPlus], "Copy Color +"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::PasteColorPlus], "Paste Color +"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::CreateExtras], "Create Extras"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::UnlockLayers], "Unlock Layers"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::ResetUnused], "Reset Unused"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::CreateLoop], "Create Loop"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::UncheckPortals], "Uncheck Portals"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::Keys], "Keys"},

    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::Regroup], "Regroup"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::ResetScroll], "Reset Scroll"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::SelectAll], "Select All"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::AlignX], "Align X"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::AlignY], "Align Y"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::NewGroupX], "New Group X"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::NewGroupY], "New Group Y"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::SelectAllLeft], "Select All Left"},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::SelectAllRight], "Select All Right"}};

std::map<std::string, std::string> EditorAction::editorActionIcon{
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::BuildHelper], "a_buildHelper.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::CopyColorPlus], "a_copyColor+.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::PasteColorPlus], "a_pasteColor+.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::CreateExtras], "a_createExtras.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::UnlockLayers], "a_unlockLayers.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::ResetUnused], "a_resetUnused.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::CreateLoop], "a_createLoop.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::UncheckPortals], "a_uncheckPortals.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::Keys], "a_keys.png"_spr},

    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::Regroup], "as_regroup.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::ResetScroll], "as_resetScroll.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::SelectAll], "as_selectAll.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::AlignX], "as_alignX.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::AlignY], "as_alignY.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::NewGroupX], "as_newGroupX.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::NewGroupY], "as_newGroupY.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::SelectAllLeft], "as_selectAllLeft.png"_spr},
    {EditorAction::editorActionNode[EditorAction::EditorActionEnum::SelectAllRight], "as_selectAllRight.png"_spr}};