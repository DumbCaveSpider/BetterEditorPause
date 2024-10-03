#pragma once

#include <Geode/ui/Popup.hpp>
#include <Geode/cocos/include/cocos2d.h>

class CustomPopupLayer : public geode::Popup<>
{
public:
  static CustomPopupLayer *create();
  void show() override;

protected:
  bool setup() override;

  void infoPopup(CCObject *);
};