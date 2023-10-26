#pragma once

namespace app::game {
    class MenuSelect : public hh::game::GameObject {
    public:
        hh::fnd::Reference<hh::game::dmenu::Menu> menu;
        csl::ut::MoveArray32<void*> unk1;
        csl::ut::MoveArray32<void*> unk2;

		virtual void Initialize(hh::game::GameManager* gameManager) override;
		virtual void Update(uint64_t unkParam, uint64_t unkParam2) override;
    };
}