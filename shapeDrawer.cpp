#include "ShapeDrawer.h"

ShapeDrawer::ShapeDrawer()
{
	prog=NULL;
	Light.Intensity=vec3(1.0f,1.0f,1.0f);
	Light.Position=vec4(1.0f,1.0f,1.0f,1.0f);
	Material.Kd=vec3(0.9f, 0.9f, 0.9f);
	Material.Ks=vec3(0.95f, 0.95f, 0.95f);
	Material.Ka=vec3(0.1f, 0.1f, 0.1f);
	Material.Shininess=100.0f;
	attachTex=false;
};

