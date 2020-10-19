#pragma once
#include "Math/Vector.h"

namespace fw
{
	class PlayerController;

	class PhysicsController
    {

    public:
        PhysicsController();
        virtual ~PhysicsController();

        void SetPosition(fw::vec2 position) { m_position = position; }
        void SetMaxVelocity(float speed) { m_MaxVelocity = vec2(speed,speed); }
        void SetRadius(float radius) { m_radius = radius; }

        fw::vec2 GetPosition() { return m_position; }
        vec2 GetMaxVelocity() { return m_MaxVelocity; }
        float GetRadius() { return m_radius; }
        vec2 GetCurrentVelocity() { return m_CurrentVelocity; }

        void Interpolate(float deltaTime);
      
        void Update(PlayerController* pPlayerController, float deltaTime);
        void HandleKeyPress(PlayerController* pPlayerController);
        void HandleKeyRelease(PlayerController* pPlayerController);
		
    private:
        fw::vec2 m_position;
        vec2 m_MaxVelocity;
        vec2 m_CurrentVelocity;
        vec2 m_MinVelocity;
        vec2 m_FinalVelocity;
		
        float m_radius;
    };
}