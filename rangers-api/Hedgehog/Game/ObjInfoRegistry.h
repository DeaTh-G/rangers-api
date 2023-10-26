#pragma once

namespace hh::game
{
    class ObjInfoRegistry : fnd::BaseObject {
        csl::ut::MoveArray<ObjInfoClass*> objInfos;
        csl::ut::StringMap<ObjInfoClass*> objInfosByName;
    public:
        ObjInfoRegistry(csl::fnd::IAllocator* pAllocator);
    };
}
