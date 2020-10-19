#pragma once

namespace fw {

    class vec2
    {
    public:
        vec2() { x = 0; y = 0; }
        vec2(float nx, float ny) { x = nx; y = ny; }

        vec2 operator * (float o) const { return vec2(x * o, y * o); }
        vec2 operator + (float o) const { return vec2(x + o, y + o); }
        vec2 operator - (float o) const { return vec2(x - o, y - o); }
        vec2 operator / (float o) const { return vec2(x / o, y / o); }

        vec2& operator *= (const float o) { x *= o; y *= o; return *this; }
        vec2& operator += (const float o) { x += o; y += o; return *this; }
        vec2& operator -= (const float o) { x -= o; y -= o; return *this; }
        vec2& operator /= (const float o)  { x /= o; y /= o; return *this; }

        vec2 operator * (vec2& o) const { return vec2(x * o.x, y * o.y); }
        vec2 operator + (vec2& o) const { return vec2(x + o.x, y + o.y); }
        vec2 operator - (vec2& o) const { return vec2(x - o.x, y - o.y); }
        vec2 operator / ( vec2& o) const { return vec2(x / o.x, y / o.y); }

        vec2& operator *= (const vec2& o) { x *= o.x; y *= o.y; return *this; }
        vec2& operator += (const vec2& o) { x += o.x; y += o.y; return *this; }
        vec2& operator -= (const vec2& o) { x -= o.x; y -= o.y; return *this; }
        vec2& operator /= (const vec2& o) { x /= o.x; y /= o.y; return *this; }

        vec2& operator = ( const vec2& o) = default;

        bool operator == ( vec2& o) const { return (x == o.x && y == o.y); }
        bool operator != ( vec2& o) const { return (x != o.x && y != o.y); }

        void SetVec2(const float a, const float b) { x = a; y = b; }
    	
        float Magnitude() const { return sqrtf(x * x + y * y); }
        float Distance(const vec2& o) const { return sqrtf((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y)); }
    	
        void Normalize() { x = x / Magnitude(); y = y / Magnitude(); }
        vec2 GetNormalizedVector() const { return vec2(x / Magnitude(), y/Magnitude()); }

        float Dot(const vec2& o) const { return x * o.x + y * o.y; }
    	
    public:
        float x;
        float y;      
    };

    class vec4
    {
    public:
        vec4() { x = 0; y = 0; z = 0; w = 0; }
        vec4(float nx, float ny, float nz, float nw) { x = nx; y = ny; z = nz; w = nw; }

        static const vec4 Red() { return vec4(1.0f, 0.0f, 0.0f, 1.0f); }
        static const vec4 Green() { return vec4(0.0f, 1.0f, 0.0f, 1.0f); }
        static const vec4 Blue() { return vec4(0.0f, 0.0f, 1.0f, 1.0f); }
        static const vec4 DarkBlue() { return vec4(0.0f, 0.0f, 0.3f, 1.0f); }
        static const vec4 LightBlue() { return vec4(0.0f, 0.5f, 1.0f, 1.0f); }
        static const vec4 White() { return vec4(1.0f, 1.0f, 1.0f, 1.0f); }
        static const vec4 Black() { return vec4(0.0f, 0.0f, 0.0f, 1.0f); }
        static const vec4 Grey() { return vec4(0.9f, 0.9f, 0.9f, 1.0f); }
        
    public:
        union
        {
            float x;
            float r;
        };
        union
        {
            float y;
            float g;
        };
        union
        {
            float z;
            float b;
        };
        union
        {
            float w;
            float a;
        };
    };
        
} // namespace fw