#pragma once
#include "Math/Vector.h"

namespace fw
{
    class PhysicsController
    {

    public:
        PhysicsController();
        virtual ~PhysicsController();

        void SetPosition(fw::vec2 position) { m_position = position; }
        void SetSpeed(int speed) { m_speed = speed; }
        void SetRadius(float radius) { m_radius = radius; }

        fw::vec2 GetPosition() { return m_position; }
        int GetSpeed() { return m_speed; }
        float GetRadius() { return m_radius; }

    private:
        fw::vec2 m_position;
        int m_speed;
        float m_radius;
    };
}