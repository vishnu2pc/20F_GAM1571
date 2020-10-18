#pragma once

class PhysicsController
{
	
public:
    PhysicsController();
    virtual ~PhysicsController();

    void SetPosition(vec2 position) { m_position = position; }
    void SetSpeed(int speed) { m_speed = speed; }
    void SetRadius(float radius) { m_radius = radius; }

    vec2 GetPosition() { return m_position; }
    int GetSpeed() { return m_speed; }
    float GetRadius() { return m_radius; }

private:
    vec2 m_position;
    int m_speed;
    float m_radius;
};