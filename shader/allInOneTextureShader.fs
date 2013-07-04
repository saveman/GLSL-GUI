#version 430

in vec3 Position;
in vec3 Normal;
in vec2 TexCoord;
in vec3 Color;

uniform sampler2D BackTex;
uniform sampler2D FrondTex;

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

layout( location = 0 ) out vec4 FragColor;

void phongModel( vec3 pos, vec3 norm, out vec3 ambAndDiff, out vec3 spec ) {
    vec3 n = Normal;
    if( !gl_FrontFacing ) n = -n;
    vec3 s = normalize(Light.Position.xyz - Position.xyz);
    vec3 v = normalize(-Position.xyz);
    vec3 r = reflect( -s, n );
    float sDotN = max( dot(s,n), 0.0 );

	spec = vec3(0.0);
    if( sDotN > 0.0 )
        spec = Light.Intensity * Material.Ks *
            pow( max( dot(r,v), 0.0 ), Material.Shininess );
    vec3 diffuse = Light.Intensity * Material.Kd * sDotN;
	vec3 ambient = Light.Intensity * Material.Ka;

	ambAndDiff = ambient + diffuse;
}

void main() {
    vec3 ambAndDiff, spec;
    vec4 brickTexColor = texture( BackTex, TexCoord );
    vec4 mossTexColor = texture( FrondTex, TexCoord );
    phongModel(Position, Normal, ambAndDiff, spec );
    vec4 texColor = mix(brickTexColor, mossTexColor, mossTexColor.a);
    FragColor = vec4(ambAndDiff, 1.0 ) * texColor + vec4(spec,1);
}