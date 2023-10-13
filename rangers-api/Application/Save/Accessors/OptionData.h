#pragma once

namespace app::save {
    struct OptionData {

    };
    
    class OptionAc : public SaveDataAccessor<OptionData> {
        OptionAc(hh::game::GameObject* gameObject) {}
    };
}
