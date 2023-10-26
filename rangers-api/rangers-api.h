#pragma once

#include "External/helpers.h"
#include "External/sigscan.h"

// Lua 5.4.1
#include "External/Lua541/include/lua.hpp"

// Common Sonicteam Math Library
#include "cslib/csl/math/math.h"

// Common Sonicteam Foundation Library
#include "cslib/csl/fnd/IAllocator.h"

// Common Sonicteam Utility Library
#include "cslib/csl/ut/fixedarray.h"
#include "cslib/csl/ut/movearray.h"
#include "cslib/csl/ut/objectmovearray.h"
#include "cslib/csl/ut/stringmap.h"

#include "Hedgehog/System/hhAllocator.h"

// Hedgehog Library
#include "Hedgehog/Base/Universe/hhHandleManager.h"
#include "Hedgehog/Base/System/hhBaseObject.h"
#include "Hedgehog/Base/System/hhReferencedObject.h"

// Hedgehog Universe Library
#include "Hedgehog/Base/Universe/hhMessage.h"
#include "Hedgehog/Base/Universe/hhMessenger.h"
#include "Hedgehog/Base/Universe/hhMessageManager.h"

#include "Hedgehog/Base/Universe/hhHandleManager.inl"

// System Messages
#include "System/Messages/MsgRobChaosEmerald.h"

// Hedgehog Game Library
#include "Hedgehog/Game/GameService.h"
#include "Hedgehog/Game/GameStepListener.h"
#include "Hedgehog/Game/GOComponent.h"
#include "Hedgehog/Game/GameObject.h"
#include "Hedgehog/Game/GameManager.h"
#include "Hedgehog/Game/GameUpdateListener.h"

// Save
#include "System/Save/SaveManagerListener.h"

// System Player
#include "System/Player/Blackboard/Blackboard.h"
#include "System/Player/Blackboard/BlackboardBattle.h"
#include "System/Player/Blackboard/BlackboardItem.h"
#include "System/Player/Blackboard/BlackboardStatus.h"

#include "System/Player/PlayerInformation.h"
#include "System/Player/PlayerHsmContext.h"
#include "System/Player/PlayerVisual.h"
#include "System/Player/VisualHuman.h"
#include "System/Player/VisualSuperSonic.h"
#include "System/Player/Player.h"
#include "System/Player/SonicContext.h"
#include "System/Player/Sonic.h"

// System Game Object Components
#include "System/Player/goc/goc_PlayerBlackboard.h"
#include "System/Player/goc/goc_PlayerVisual.h"
#include "System/Player/goc/goc_PlayerKinematicParams.h"

#include "System/AppResourceManagerListener.h"

// Services
#include "System/Services/service_ChallengeTimeManager.h"
#include "System/Services/service_EnemyManager.h"
#include "System/Services/service_StageInfo.h"
#include "System/Services/service_LevelInfo.h"
#include "System/Services/service_PhotoMode.h"
#include "System/Services/service_ScriptSequenceManager.h"
#include "System/Services/service_UIOverlay.h"

// HUD
#include "System/HUD/RequestOverlayBegin.h"
#include "System/HUD/RequestOverlayTagReplace.h"
#include "System/HUD/RequestOverlayCaption.h"

#include "System/Script/ScriptSequence.h"
