#pragma once

#include <map>
#include <string>

#include <Geode/Geode.hpp>

#include <Geode/utils/web.hpp>

#include <Geode/binding/EditorPauseLayer.hpp>

using namespace geode::prelude;

class EditorEnum
{
public:
    enum class Action
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
        NewGroupX = 14,
        SelectAllLeft = 15,
        AlignY = 16,
        NewGroupY = 17,
        SelectAllRight = 18
    };

    enum class Option
    {
        PreviewMode = 1,
        PreviewAnimations = 2,
        PreviewParticles = 3,
        PreviewShaders = 4,
        ShowHitboxes = 5,
        HideInvisible = 6,
        ShowGround = 7,
        ShowObjectInfo = 8,
        ShowGrid = 9,
        SelectFilter = 10,
        IgnoreDamage = 11
    };

    static std::map<Action, std::string> actionNode;
    static std::map<std::string, std::string> actionName;
    static std::map<std::string, std::string> actionIcon;

    static std::map<Option, std::string> optionNode;
    static std::map<std::string, std::string> optionName;
    static std::map<std::string, std::string> optionSpriteEnabled;
    static std::map<std::string, std::string> optionSpriteDisabled;
    static std::map<std::string, std::string> optionVar;
};