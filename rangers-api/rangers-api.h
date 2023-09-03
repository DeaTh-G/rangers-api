#pragma once

#include "External/helpers.h"
// #include "External/sigscan.h"

// // Lua 5.4.1
// #include "External/Lua541/include/lua.hpp"

// // Common Sonicteam Library
// #include "Sonicteam/math/math.h"
#include "Sonicteam/System/IAllocator.h"
#include "Sonicteam/System/Singleton.h"
#include "Sonicteam/System/Mutex.h"
#include "Sonicteam/System/HeapBase.h"
#include "Sonicteam/System/TlsfHeap.h"
#include "Sonicteam/Utility/collections/Array.h"
#include "Sonicteam/Utility/collections/FixedArray.h"
#include "Sonicteam/Utility/collections/HashMap.h"
#include "Sonicteam/Utility/collections/MoveArray.h"
#include "Sonicteam/Utility/collections/InPlaceMoveArray.h"
#include "Sonicteam/Utility/collections/StringMap.h"
#include "Sonicteam/Utility/Bitset.h"
#include "Sonicteam/Utility/VariableString.h"

#include "Hedgehog/System/hhAllocator.h"

// Hedgehog Library
#include "Hedgehog/Base/System/hhBaseObject.h"
#include "Hedgehog/Base/System/hhReferencedObject.h"
#include "Hedgehog/Base/System/hhProperty.h"
#include "Hedgehog/Base/System/hhCollection.h"

// Hedgehog Universe Library
#include "Hedgehog/Base/Universe/hhMessage.h"
#include "Hedgehog/Base/Universe/hhMessenger.h"

#include "Hedgehog/Base/Type/hhBaseTypes.h"
#include "Hedgehog/Base/Type/WorldPosition.h"

// // // System Messages
// // #include "System/Messages/MsgRobChaosEmerald.h"

// // // Hedgehog Game Library
#include "Hedgehog/Game/GameService.h"
#include "Hedgehog/Game/GameStepListener.h"
#include "Hedgehog/Game/GOComponent.h"
#include "Hedgehog/Game/GameObject.h"
#include "Hedgehog/Game/GameDocument.h"
// #include "Hedgehog/Game/GameUpdateListener.h"
#include "Hedgehog/Game/GameObjectSystem.h"

// #include "System/Player/PlayerInformation.h"
// #include "System/Player/Blackboard.h"
// #include "System/Player/BlackboardBattle.h"
// #include "System/Player/Player.h"
// #include "System/Player/Sonic.h"

// Hedgehog Reflection Library
#include "Hedgehog/Reflection/hhInternalClassMember.h"
#include "Hedgehog/Reflection/hhRflEntity.h"
#include "Hedgehog/Reflection/hhRflArray.h"
#include "Hedgehog/Reflection/hhRflCustomAttribute.h"
#include "Hedgehog/Reflection/hhRflClassMember.h"
#include "Hedgehog/Reflection/hhRflClassEnum.h"
#include "Hedgehog/Reflection/hhRflClass.h"
#include "Hedgehog/Reflection/hhRflTypeInfo.h"
#include "Hedgehog/Reflection/hhRflRegistry.h"
#include "Hedgehog/Reflection/hhRflTypeInfoRegistry.h"
#include "Hedgehog/Reflection/hhRflClassNameRegistry.h"
#include "Hedgehog/Reflection/hhBuiltinTypeRegistry.h"
#include "Hedgehog/Reflection/hhDataResource.h"
#include "Hedgehog/Reflection/hhDataValue.h"
// #include "Hedgehog/Reflection/hhVariantDataUtil.h"
// #include "Hedgehog/Reflection/hhRflSerializeUtil.h"

// // System Game Object Components
// #include "System/Player/goc/goc_PlayerBlackboard.h"
// #include "System/Player/goc/goc_PlayerKinematicParams.h"

// #include "System/AppResourceManagerListener.h"

// // Save
// #include "System/Save/SaveManagerListener.h"

// // Services
// #include "System/Services/service_LevelInfo.h"
// #include "System/Services/service_PhotoMode.h"
// #include "System/Services/service_UIOverlay.h"

// // HUD
// #include "System/HUD/RequestOverlayBegin.h"
// #include "System/HUD/RequestOverlayTagReplace.h"
// #include "System/HUD/RequestOverlayCaption.h"

// #include "System/Script/ScriptSequence.h"

#include "Application/Save/SaveManagerListener.h"

#include "Application/Level/LevelInfo.h"
