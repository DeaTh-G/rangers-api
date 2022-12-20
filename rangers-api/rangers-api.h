#pragma once

// Lua 5.4.1
#include "../Lua541/include/lua.hpp"

// Common Sonicteam Library
#include "Sonicteam/System/IAllocator.h"
#include "Sonicteam/Utility/collections/Array.h"
#include "Sonicteam/Utility/collections/MoveArray.h"
#include "Sonicteam/Utility/collections/StringMap.h"

#include "Hedgehog/System/hhAllocator.h"

// Hedgehog Library
#include "Hedgehog/Base/System/hhBaseObject.h"
#include "Hedgehog/Base/System/hhReferencedObject.h"

// Hedgehog Universe Library
#include "Hedgehog/Base/Universe/hhMessage.h"
#include "Hedgehog/Base/Universe/hhMessenger.h"

// System Messages
#include "System/Messages/MsgRobChaosEmerald.h"

// Hedgehog Game Libary
#include "Hedgehog/Game/GameService.h"
#include "Hedgehog/Game/GameDocument.h"
#include "Hedgehog/Game/GameUpdateListener.h"
#include "Hedgehog/Game/GameStepListener.h"

#include "System/AppResourceManagerListener.h"

// Save
#include "System/Save/SaveManagerListener.h"

// Services
#include "System/Services/service_UIOverlay.h"

// HUD
#include "System/HUD/RequestOverlayBegin.h"
#include "System/HUD/RequestOverlayTagReplace.h"
#include "System/HUD/RequestOverlayCaption.h"

#include "System/Script/ScriptSequence.h"