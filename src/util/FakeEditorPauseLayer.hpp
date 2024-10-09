#pragma once

#include <Geode/bindings/EditorPauseLayer.hpp>

using namespace geode::prelude;

struct FakeEditorPauseLayer final {
    char m_alloc[sizeof(EditorPauseLayer)];
    EditorPauseLayer* operator->() {
        return reinterpret_cast<EditorPauseLayer*>(&m_alloc);
    }
};

static FakeEditorPauseLayer* getFakeEditorPauseLayer(LevelEditorLayer* p0) {
    auto EPL = FakeEditorPauseLayer();
    EPL->m_editorLayer = p0;
    return EPL;
}