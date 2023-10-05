#pragma once

#include "External/helpers.h"
#include "External/sigscan.h"

// Lua 5.4.1
#include "External/Lua541/include/lua.hpp"

// Common Sonicteam Library
#include "cslib/csl/math/math.h"

#include "Sonicteam/System/IAllocator.h"
#include "cslib/csl/ut/array.h"
#include "cslib/csl/ut/fixedarray.h"
#include "cslib/csl/ut/movearray.h"
#include "cslib/csl/ut/stringmap.h"

#include "Hedgehog/System/hhAllocator.h"

// Hedgehog Library
#include "Hedgehog/Base/System/hhBaseObject.h"
#include "Hedgehog/Base/System/hhReferencedObject.h"

// Hedgehog Universe Library
#include "Hedgehog/Base/Universe/hhMessage.h"
#include "Hedgehog/Base/Universe/hhMessenger.h"

// System Messages
#include "System/Messages/MsgRobChaosEmerald.h"

// Hedgehog Game Library
#include "Hedgehog/Game/GameService.h"
#include "Hedgehog/Game/GameStepListener.h"
#include "Hedgehog/Game/GOComponent.h"
#include "Hedgehog/Game/GameObject.h"
#include "Hedgehog/Game/GameDocument.h"
#include "Hedgehog/Game/GameUpdateListener.h"

#include "System/Player/PlayerInformation.h"
#include "System/Player/Blackboard.h"
#include "System/Player/BlackboardBattle.h"
#include "System/Player/Player.h"
#include "System/Player/Sonic.h"
#include "System/Player/PlayerHsmContext.h"

// System Game Object Components
#include "System/Player/goc/goc_PlayerBlackboard.h"
#include "System/Player/goc/goc_PlayerKinematicParams.h"

#include "System/AppResourceManagerListener.h"

// Save
#include "System/Save/SaveManagerListener.h"

// Services
#include "System/Services/service_LevelInfo.h"
#include "System/Services/service_PhotoMode.h"
#include "System/Services/service_UIOverlay.h"

// HUD
#include "System/HUD/RequestOverlayBegin.h"
#include "System/HUD/RequestOverlayTagReplace.h"
#include "System/HUD/RequestOverlayCaption.h"

#include "System/Script/ScriptSequence.h"