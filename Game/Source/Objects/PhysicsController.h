#pragma once

class PhysicsController
{
	
public:
    PhysicsController();
    virtual ~PhysicsController();

    void SetPosition(vec2 position) { m_position = position; }
    void SetSpeed(int speed) { m_speed = speed; }

private:
    vec2 m_position;
    int m_speed;
};