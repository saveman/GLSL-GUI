#ifndef SHADER_H
#define SHADER_H

#include "glslprogram.h"

struct LightInfo {
  vec4 Position;  // Light position in eye coords.
  vec3 Intensity; // A,D,S intensity
}; 

struct MaterialInfo {
  vec3 Ka;            // Ambient reflectivity
  vec3 Kd;            // Diffuse reflectivity
  vec3 Ks;            // Specular reflectivity
  float Shininess;    // Specular shininess factor
}; 

class ShapeDrawer
{
private:	
	GLSLProgram* prog;
	LightInfo Light;
	MaterialInfo Material;
	bool attachTex;

public:	
	
	ShapeDrawer();
	virtual ~ShapeDrawer(){};

	inline void setGLSLProgram(GLSLProgram* t_prog){prog =t_prog;};
	inline GLSLProgram& getGLSLProgram(){return *prog;};
	
	inline LightInfo& getLightInfo(){return Light;};
	inline void setLightInfo(LightInfo& t_light ){Light = t_light;};

	inline MaterialInfo& getMaterialInfo(){return Material;};
	inline void setMaterialInfo(MaterialInfo& t_material ){Material = t_material;};

	inline bool getTexStatus(){return attachTex;};
	inline void setTexStatus(bool t_attachTex ){attachTex = t_attachTex;};

	

	virtual void initScene()=0;
	virtual void render(vec3 translation, float rotation)=0;
};

#endif // SHADER_H
