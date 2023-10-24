#pragma once

namespace SurfRide {
    struct SRS_DATA {
        const char* name;
        uint32_t type;
        uint64_t value;
    };

    struct SRS_USERDATA {
        uint32_t count;
        SRS_DATA* items;
    };

    class UserData {
        SRS_USERDATA* userData;
    public:
        UserData(SRS_USERDATA* userData);
        int GetIndex(const char* name);

        bool GetBoolValue(int index);
        int GetIntValue(int index);
        unsigned int GetUIntValue(int index);
        float GetFloatValue(int index);
        const char* GetStringValue(int index);
    };
}
