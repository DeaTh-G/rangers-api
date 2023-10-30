#pragma once

namespace hh::game {
    class alignas(8) GameObjectLayer : public hh::fnd::ReferencedObject
    {
    public:
        csl::ut::VariableString name;
        csl::ut::MoveArray<GameObject*> objects;
        uint32_t unk25;

        GameObjectLayer(csl::fnd::IAllocator* pAllocator, const char* name);
    };
}
