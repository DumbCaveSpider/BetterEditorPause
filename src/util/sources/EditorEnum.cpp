#include "../EditorEnum.hpp"

#include <string>
#include <map>

#include <Geode/Geode.hpp>

#include <Geode/utils/web.hpp>

using namespace geode::prelude;

/*
editor actions
*/

std::map<EditorEnum::EditorAction, std::string> EditorEnum::editorActionNode{
    {EditorEnum::EditorAction::BuildHelper, "build-helper"_spr},
    {EditorEnum::EditorAction::CopyColorPlus, "copy-col-plus"_spr},
    {EditorEnum::EditorAction::PasteColorPlus, "paste-col-plus"_spr},
    {EditorEnum::EditorAction::CreateExtras, "create-extras"_spr},
    {EditorEnum::EditorAction::UnlockLayers, "unlock-layers"_spr},
    {EditorEnum::EditorAction::ResetUnused, "reset-unused"_spr},
    {EditorEnum::EditorAction::CreateLoop, "create-loop"_spr},
    {EditorEnum::EditorAction::UncheckPortals, "uncheck-portals"_spr},
    {EditorEnum::EditorAction::Keys, "keybinds"_spr},

    {EditorEnum::EditorAction::Regroup, "regroup"_spr},
    {EditorEnum::EditorAction::ResetScroll, "reset-scroll"_spr},
    {EditorEnum::EditorAction::SelectAll, "select-all"_spr},
    {EditorEnum::EditorAction::AlignX, "align-x"_spr},
    {EditorEnum::EditorAction::AlignY, "align-y"_spr},
    {EditorEnum::EditorAction::NewGroupX, "new-group-x"_spr},
    {EditorEnum::EditorAction::NewGroupY, "new-group-y"_spr},
    {EditorEnum::EditorAction::SelectAllLeft, "select-all-left"_spr},
    {EditorEnum::EditorAction::SelectAllRight, "select-all-right"_spr}};

std::map<std::string, std::string> EditorEnum::editorActionName{
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::BuildHelper], "Build Helper"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::CopyColorPlus], "Copy Color +"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::PasteColorPlus], "Paste Color +"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::CreateExtras], "Create Extras"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::UnlockLayers], "Unlock Layers"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::ResetUnused], "Reset Unused"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::CreateLoop], "Create Loop"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::UncheckPortals], "Uncheck Portals"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::Keys], "Keybind Viewer"},

    {EditorEnum::editorActionNode[EditorEnum::EditorAction::Regroup], "Regroup"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::ResetScroll], "Reset Scroll"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::SelectAll], "Select All"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::AlignX], "Align X"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::AlignY], "Align Y"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::NewGroupX], "New Group X"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::NewGroupY], "New Group Y"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::SelectAllLeft], "Select All Left"},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::SelectAllRight], "Select All Right"}};

std::map<std::string, std::string> EditorEnum::editorActionIcon{
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::BuildHelper], "a_buildHelper.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::CopyColorPlus], "a_copyColor+.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::PasteColorPlus], "a_pasteColor+.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::CreateExtras], "a_createExtras.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::UnlockLayers], "a_unlockLayers.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::ResetUnused], "a_resetUnused.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::CreateLoop], "a_createLoop.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::UncheckPortals], "a_uncheckPortals.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::Keys], "a_keys.png"_spr},

    {EditorEnum::editorActionNode[EditorEnum::EditorAction::Regroup], "as_regroup.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::ResetScroll], "as_resetScroll.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::SelectAll], "as_selectAll.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::AlignX], "as_alignX.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::AlignY], "as_alignY.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::NewGroupX], "as_newGroupX.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::NewGroupY], "as_newGroupY.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::SelectAllLeft], "as_selectAllLeft.png"_spr},
    {EditorEnum::editorActionNode[EditorEnum::EditorAction::SelectAllRight], "as_selectAllRight.png"_spr}};

/*
editor options
*/

std::map<EditorEnum::EditorOption, std::string> EditorEnum::editorOptionNode{
    {EditorEnum::EditorOption::PreviewMode, "preview-mode"_spr}};

std::map<std::string, std::string> EditorEnum::editorOptionName{
    {EditorEnum::editorOptionNode[EditorEnum::EditorOption::PreviewMode], "Preview Mode"}};

std::map<std::string, std::string> EditorEnum::editorOptionVar{
    {EditorEnum::editorOptionNode[EditorEnum::EditorOption::PreviewMode], "0036"}};