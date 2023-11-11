#pragma once

namespace hh::game {
	class CameraManager : public GameService {
	public:
		void AddComponent(CameraComponent* component);
		CameraComponent* GetComponent(int id);
		
		GAMESERVICE_CLASS_DECLARATION
	};
}
