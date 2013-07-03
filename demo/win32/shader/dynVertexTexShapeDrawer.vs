#version 430

#define FLAG 1
#define SCREW 2

layout (location = 0 ) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;
layout (location = 2) in vec2 VertexTexCoord;

out vec4 Position;
out vec3 Normal;
out vec2 TexCoord;

uniform float Time;
uniform float Freq = 2.5;
uniform float Velocity = 2.5;
uniform float Amp = 0.2;

uniform mat4 ModelViewMatrix;
uniform mat3 NormalMatrix;
uniform mat4 MVP;

uniform int mode=0;

void main()
{
    vec4 pos = vec4(VertexPosition,1.0);
    float u = Freq * pos.x - Velocity * Time;

	if(mode==FLAG)
	    pos.z = Amp * sin( u );
	else if(mode==SCREW)
		pos.y = pos.y * sin( u );

	Position = pos;

    vec3 n = vec3(0.0);
    n.zx = normalize(vec2(cos( u ), 1.0));
	Normal = n;  
	
	TexCoord = VertexTexCoord;

    gl_Position = MVP * pos;
}
