uniform float u_Time;

void main()
{
    gl_FragColor = vec4( 1 + sin(u_Time), 1 + cos(u_Time) , 1 - tan(u_Time), 1 );
};
