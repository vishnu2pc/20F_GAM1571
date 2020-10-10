
attribute vec2 a_Position;

uniform vec2 u_ObjectPos;

void main()
{
    vec2 pos = a_Position;
    pos+= u_ObjectPos;

    pos = pos/5 -1;
    
    gl_Position = vec4( pos, 0, 1 );
}
