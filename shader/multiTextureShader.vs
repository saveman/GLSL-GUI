#version 430

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;
layout (location = 2) in vec2 VertexTexCoord;
layout (location = 3) in vec3 VertexColor;

out vec3 Position;
out vec3 Normal;
out vec2 TexCoord;
out vec3 Color;

uniform mat4 MVP;

void main()
{
    TexCoord = VertexTexCoord;
    Normal = VertexNormal;
    Position = VertexPosition;
	Color = VertexColor;
	
	gl_Position = MVP *vec4(VertexPosition,1.0);     
}
