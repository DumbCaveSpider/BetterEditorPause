#pragma once

#include <map>
#include <string>

#include <Geode/Geode.hpp>

#include <Geode/utils/web.hpp>

#include <Geode/binding/EditorPauseLayer.hpp>

using namespace geode::prelude;

class EditorAction
{
public:
    enum class EditorActionEnum
    {
        BuildHelper = 1,
        CopyColorPlus = 2,
        PasteColorPlus = 3,
        CreateExtras = 4,
        UnlockLayers = 5,
        ResetUnused = 6,
        CreateLoop = 7,
        UncheckPortals = 8,
        Keys = 9,

        Regroup = 10,
        ResetScroll = 11,
        SelectAll = 12,
        AlignX = 13,
        AlignY = 14,
        NewGroupX = 15,
        NewGroupY = 16,
        SelectAllLeft = 17,
        SelectAllRight = 18
    };

    static std::map<EditorActionEnum, std::string> editorActionNode;
    static std::map<std::string, std::string> editorActionName;
    static std::map<std::string, std::string> editorActionIcon;
};