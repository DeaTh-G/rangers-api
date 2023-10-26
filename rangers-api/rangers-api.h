#pragma once

#include "External/helpers.h"
// #include "External/sigscan.h"

// // Lua 5.4.1
// #include "External/Lua541/include/lua.hpp"

// Common Sonicteam Library

#ifndef EXPORTING_TYPES
#include "Sonicteam/math/math.h"
#include <functional>
#endif

#include "Sonicteam/System/IAllocator.h"

#include "Sonicteam/Utility/collections/Array.h"
#include "Sonicteam/Utility/collections/FixedArray.h"
#include "Sonicteam/Utility/collections/HashMap.h"
#include "Sonicteam/Utility/collections/MoveArray.h"
#include "Sonicteam/Utility/collections/MoveArray32.h"
#include "Sonicteam/Utility/collections/InPlaceMoveArray.h"
#include "Sonicteam/Utility/collections/PointerMap.h"
#include "Sonicteam/Utility/collections/StringMap.h"
#include "Sonicteam/Utility/BasicString.h"
#include "Sonicteam/Utility/Bitset.h"
#include "Sonicteam/Utility/Color.h"
#include "Sonicteam/Utility/NonCopyable.h"
#include "Sonicteam/Utility/Pair.h"
#include "Sonicteam/Utility/VariableString.h"

#include "Sonicteam/System/Singleton.h"
#include "Sonicteam/System/Mutex.h"
#include "Sonicteam/System/HeapBase.h"
#include "Sonicteam/System/TlsfHeap.h"
#include "Sonicteam/System/Delegate.h"

#include "Hedgehog/System/hhAllocator.h"
#include "Hedgehog/System/SingletonInitNode.h"

// Hedgehog Library
#include "Hedgehog/Base/System/Allocators.h"
#include "Hedgehog/Base/System/hhBaseObject.h"
#include "Hedgehog/Base/System/hhReferencedObject.h"
#include "Hedgehog/Base/System/RefByHandleObject.h"
#include "Hedgehog/Base/System/hhProperty.h"
#include "Hedgehog/Base/System/hhCollection.h"
#include "Hedgehog/Base/System/hhHandle.h"
#include "Hedgehog/Base/System/HandleManager.h"
#include "Hedgehog/Base/System/ReloaderListener.h"

// Hedgehog Universe Library
#include "Hedgehog/Base/Universe/hhMessage.h"
#include "Hedgehog/Base/Universe/hhMessenger.h"

#include "Hedgehog/Utility/TempString.h"
#include "Hedgehog/Utility/FSM/TinyFsm.h"
#include "Hedgehog/Utility/FSM/StateDesc.h"
#include "Hedgehog/Utility/FSM/State.h"
#include "Hedgehog/Utility/FSM/Hsm.h"

#include "Hedgehog/Base/Type/hhBaseTypes.h"
#include "Hedgehog/Base/Type/WorldPosition.h"
#include "Hedgehog/Base/Type/LogData.h"

#include "Hedgehog/GraphicsFoundation/Renderable.h"

// Hedgehog Framework
#include "Hedgehog/Framework/KeyEventHandler.h"
#include "Hedgehog/Framework/MouseEventHandler.h"
#include "Hedgehog/Framework/AppModule.h"
#include "Hedgehog/Framework/Application.h"

// HID
#include "Hedgehog/HID/InputDevice.h"
#include "Hedgehog/HID/InputDeviceFactory.h"
#include "Hedgehog/HID/ActiveDeviceManager.h"
#include "Hedgehog/HID/DeviceManager.h"
#include "Hedgehog/HID/DeviceManagerWin32.h"
#include "Hedgehog/HID/InputMap.h"

#include "Hedgehog/HID/InputDevices/Keyboard.h"
#include "Hedgehog/HID/InputDevices/KeyboardWin32.h"
#include "Hedgehog/HID/InputDevices/Mouse.h"
#include "Hedgehog/HID/InputDevices/MouseWin32.h"
#include "Hedgehog/HID/InputDevices/Gamepad.h"
#include "Hedgehog/HID/InputDevices/GamepadSteam.h"
#include "Hedgehog/HID/InputDevices/Pointing.h"
#include "Hedgehog/HID/InputDevices/PointingWin32.h"
#include "Hedgehog/HID/InputDevices/Vibration.h"
#include "Hedgehog/HID/InputDevices/VibrationWin32.h"

#include "Hedgehog/Filesystem/FileInfo.h"
#include "Hedgehog/Filesystem/FileBind.h"

// Resources
#include "Hedgehog/Resource/Uri.h"
#include "Hedgehog/Resource/InplaceUri.h"
#include "Hedgehog/Resource/TempInplaceUri.h"
#include "Hedgehog/Resource/ManagedResource.h"
#include "Hedgehog/Resource/Packfile.h"
#include "Hedgehog/Resource/ResourceLoader.h"
#include "Hedgehog/Resource/ResourceManager.h"

#include "Hedgehog/HID/ActiveDeviceManager.h"

// // // System Messages
// // #include "System/Messages/MsgRobChaosEmerald.h"

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
// #include "Hedgehog/Reflection/hhDataResource.h"
#include "Hedgehog/Reflection/hhDataValue.h"
// #include "Hedgehog/Reflection/hhVariantDataUtil.h"
// #include "Hedgehog/Reflection/hhRflSerializeUtil.h"

// Hedgehog Game Library
#include "Hedgehog/Game/GameService.h"
#include "Hedgehog/Game/GOComponent.h"
#include "Hedgehog/Game/GameObject.h"
#include "Hedgehog/Game/GameObjectLayer.h"
#include "Hedgehog/Game/GameApplication.h"
#include "Hedgehog/Game/GameManager.h"
#include "Hedgehog/Game/InputManager.h"
#include "Hedgehog/Game/InputComponent.h"
#include "Hedgehog/Game/ObjInfo.h"
#include "Hedgehog/Game/GameObjectRegistry.h"
#include "Hedgehog/Game/GOComponentRegistry.h"
#include "Hedgehog/Game/ObjInfoRegistry.h"
#include "Hedgehog/Game/GameObjectSystem.h"
#include "Hedgehog/Game/ErrorViewer.h"

#include "Hedgehog/Game/GOComponents/GOCInput.h"

#include "Hedgehog/Game/DevMenu/Menu.h"

#include "Hedgehog/Sound/GOCSound.h"

#include "SurfRide/Base.h"
#include "SurfRide/ReferencedObject.h"
#include "SurfRide/BinaryData.h"
#include "SurfRide/Camera.h"
#include "SurfRide/Animation.h"
#include "SurfRide/Layer.h"
#include "SurfRide/Scene.h"
#include "SurfRide/Project.h"
#include "SurfRide/UserData.h"
#include "SurfRide/Cast.h"
#include "SurfRide/ImageCast.h"
#include "SurfRide/ReferenceCast.h"

#include "Hedgehog/Font/ResBitmapFont.h"
#include "Hedgehog/Font/TextListener.h"
#include "Hedgehog/Font/FontContainer.h"
#include "Hedgehog/Text/ConverseTextListener.h"
#include "Hedgehog/Text/ConverseData.h"
#include "Hedgehog/Text/ConverseDataCollection.h"
#include "Hedgehog/Text/TagReplaceable.h"
#include "Hedgehog/Text/TagReplaceableCollection.h"
#include "Hedgehog/Text/TagReplacer.h"
#include "Hedgehog/Text/TextLanguageData.h"
#include "Hedgehog/Text/TextLanguageDataCollection.h"
#include "Hedgehog/Text/TextAppModule.h"

#include "Hedgehog/UI/ResSurfRideProject.h"
#include "Hedgehog/UI/SurfRideProjectContext.h"
#include "Hedgehog/UI/SurfRideHandle.h"
#include "Hedgehog/UI/GOCSprite.h"
#include "Hedgehog/UI/LayerController.h"
#include "Hedgehog/UI/TextListenerObject.h"
#include "Hedgehog/UI/UITextInterface.h"
#include "Hedgehog/UI/TextObjectUpdater.h"
#include "Hedgehog/UI/GOCUICollider.h"
#include "Hedgehog/UI/GOCUIComposition.h"
#include "Hedgehog/UI/Types.h"
#include "Hedgehog/UI/UIObject.h"
#include "Hedgehog/UI/UIElementBase.h"
#include "Hedgehog/UI/UIElement.h"
#include "Hedgehog/UI/UIElementGroup.h"
#include "Hedgehog/UI/UIElementGroupContainer.h"
#include "Hedgehog/UI/UITextElement.h"
#include "Hedgehog/UI/CastTextContainer.h"
#include "Hedgehog/UI/UIPanel.h"
#include "Hedgehog/UI/UIStackPanel.h"
#include "Hedgehog/UI/UIGridPanel.h"
#include "Hedgehog/UI/UIScrollBarElement.h"
#include "Hedgehog/UI/UIListViewElement.h"
#include "Hedgehog/UI/UIListener.h"
#include "Hedgehog/UI/UIManager.h"

// #include "System/Player/PlayerInformation.h"
// #include "System/Player/Blackboard.h"
// #include "System/Player/BlackboardBattle.h"
// #include "System/Player/Player.h"
// #include "System/Player/Sonic.h"


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

// Builtin RflCustomAttributes
// #include "ApplicationCommon/Reflection/CaptionAttribute.h"
// #include "ApplicationCommon/Reflection/RangeAttribute.h"


#include "ApplicationCommon/FSM/GOCTinyFsm2.h"
#include "ApplicationCommon/FSM/GOCHsm2.h"

#include "Application/Foundation/AppHeapManager.h"

#include "Application/Reflection/Types.h"

#include "Application/FSM/StateContext.h"

#include "Application/Resource/AppResourceManager.h"

#include "Application/Save/SaveDataAccessor.h"
#include "Application/Save/SaveManagerListener.h"
#include "Application/Save/Accessors/OptionData.h"

#include "Application/Level/LevelInfo.h"

#include "Application/Sound/CustomSound.h"

#include "Application/Text/AppTextListener.h"
#include "Application/Text/TextManager.h"

#include "Application/UI/AppUITextInterface.h"
#include "Application/UI/UIMusicSelect.h"

#include "Application/Game/GameMode.h"
#include "Application/Game/GameModeStage.h"

#include "Application/Game/MenuSelect.h"

#include "Application/Player/PlayerCounterTimer.h"
#include "Application/Player/PlayerHsmContext.h"
#include "Application/Player/GOCPlayerHsm.h"
#include "Application/Player/GOCPlayerState.h"
#include "Application/Player/PlayerStateBase.h"
#include "Application/Player/States.h"

#include "Application/MyApplication.h"
