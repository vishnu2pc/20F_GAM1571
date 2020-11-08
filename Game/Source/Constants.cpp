#include "GamePCH.h"
#include "Constants.h"

float Player_Radius[] = { 0.4f, 0.3f, 0.3f };
float Player_Speed[] = { 7.0f, 5.0f,6.0f };
float Duration[] = { 6, 12, 15 };
float Arena_Radius[] = { 5.0f, 4.0f, 3.0f };
float Enemy_Size[] = { 0.3f, 0.2f, 0.3f };
float Spawn_Timer[] = { 0.5f, 0.5f, 0.5f };
float Enemy_Speed[] = { 4.0f, 0.75f, 3.0f };
ENEMY_BEHAVIOUR Enemy_Behaviour[] = { ENEMY_BEHAVIOUR::STATIC, ENEMY_BEHAVIOUR::DYNAMIC, ENEMY_BEHAVIOUR::STATIC };

vec4 Player_Color[] = { vec4::Red(),vec4::Green(),vec4::LightBlue() };
vec4 Enemy_Color[] = { vec4::Blue(),vec4::Red(),vec4::Black() };
vec4 Arena_Color[] = { vec4::Teal(), vec4::Purple(), vec4::PaleRed () };

