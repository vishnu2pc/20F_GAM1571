#pragma once

namespace fw {

    class vec2
    {
    public:
        vec2() { x = 0; y = 0; }
        vec2(float nx, float ny) { x = nx; y = ny; }

        vec2 operator*(float o) const { return vec2(x * o, y * o); }
        vec2 operator+(float o) const { return vec2(x + o, y + o); }
        vec2 operator-(float o) const { return vec2(x - o, y - o); }
        vec2 operator/(float o) const { return vec2(x / o, y / o); }

        vec2 operator*=(const float o)  { x *= o; y *= o; return *this; }
        vec2 operator+=(const float o)  { x += o; y += o; return *this; }
        vec2 operator-=(const float o)  { x -= o; y -= o; return *this; }
        vec2 operator/=(const float o)  { x /= o; y /= o; return *this; }

        vec2 operator*( vec2& o) const { return vec2(x * o.x, y * o.y); }
        vec2 operator+( vec2& o) const { return vec2(x + o.x, y + o.y); }
        vec2 operator-( vec2& o) const { return vec2(x - o.x, y - o.y); }
        vec2 operator/( vec2& o) const { return vec2(x / o.x, y / o.y); }

        vec2 operator*=(const vec2& o) { x *= o.x; y *= o.y; return *this; }
        vec2 operator+=(const vec2& o) { x += o.x; y += o.y; return *this; }
        vec2 operator-=(const vec2& o) { x -= o.x; y -= o.y; return *this; }
        vec2 operator/=(const vec2& o) { x /= o.x; y /= o.y; return *this; }

        vec2 operator=(const vec2& o)  { x = o.x; y = o.y; return *this; }
        bool operator!=(const vec2& o) { return (x == o.x && y == o.y); }

        float Magnitude() { return sqrtf(x * x + y * y); }
        float Distance(const vec2& o) { return sqrtf((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y)); }
    	
        void Normalize() { x = x / Magnitude(); y = y / Magnitude(); }
        vec2 GetNormalizedVector() { return vec2(x / Magnitude(), y/Magnitude()); }

        float Dot(const vec2& o) { return x * o.x + y * o.y; }
    	
    public:
        float x;
        float y;
    };

} // namespace fw