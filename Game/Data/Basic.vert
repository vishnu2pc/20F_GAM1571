
attribute vec2 a_Position;
uniform float u_PosX;
uniform float u_PosY;

void main()
{
    vec2 pos = a_Position + vec2(u_PosX, u_PosY);

    gl_Position = vec4( pos, 0, 10 );
}
