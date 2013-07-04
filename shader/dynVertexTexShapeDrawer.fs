#version 430

in vec3 Position;
in vec3 Normal;
in vec2 TexCoord;

uniform sampler2D BrickTex;
uniform sampler2D MossTex;

struct LightInfo {
	vec4 Position;  // Light position in eye coords.
	vec3 Intensity; // A,D,S intensity
};
uniform LightInfo Light;

struct MaterialInfo {
	vec3 Ka;            // Ambient reflectivity
	vec3 Kd;            // Diffuse reflectivity
	vec3 Ks;            // Specular reflectivity
	float Shininess;    // Specular shininess factor
};
uniform MaterialInfo Material;

layout ( location = 0 ) out vec4 FragColor;

vec3 phongModel(vec3 kd) {
	vec3 n = Normal;
	if( !gl_FrontFacing ) n = -n;
	vec3 s = normalize(Light.Position.xyz - Position.xyz);
	vec3 v = normalize(-Position.xyz);
	vec3 r = reflect( -s, n );
	float sDotN = max( dot(s,n), 0.0 );
	vec3 diffuse = Light.Intensity * kd * sDotN;
	vec3 spec = vec3(0.0);
	if( sDotN > 0.0 )
		spec = Light.Intensity * Material.Ks *
		pow( max( dot(r,v), 0.0 ), Material.Shininess );

	return Material.Ka * Light.Intensity + diffuse + spec;
}

void main()
{
	FragColor = vec4( phongModel(Material.Kd) , 1.0 );
}
