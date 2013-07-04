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
	


	float freq;
	float velocity;
	float amp;

public:	
	int drawMode;
	int modeMask;
	unsigned int backTexID;
	unsigned int frontTexID;

public:	
	ShapeDrawer();
	virtual ~ShapeDrawer(){};

	inline void setGLSLProgram(GLSLProgram* t_prog){prog =t_prog;};
	inline GLSLProgram& getGLSLProgram(){return *prog;};

	inline LightInfo& getLightInfo(){return Light;};
	inline void setLightInfo(LightInfo& t_light ){Light = t_light;};

	inline MaterialInfo& getMaterialInfo(){return Material;};
	inline void setMaterialInfo(MaterialInfo& t_material ){Material = t_material;};


	inline void setFreq(float t_freq)
	{
		freq=t_freq;
	}
	inline float getFreq()
	{
		return freq;
	}

	inline void setVelocity(float t_velocity)
	{
		velocity=t_velocity;
	}
	inline float getVelocity()
	{
		return velocity;
	}

	inline void setAmp(float t_amp)
	{
		amp=t_amp;
	}
	inline float getAmp()
	{
		return amp;
	}
	virtual void initScene()=0;
	virtual void render(vec3 translation, float rotation)=0;
};

#endif // SHADER_H
