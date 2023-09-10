#version 330 core

layout (location = 0) out vec4 color;

uniform float time;
uniform vec2 resolution;


void main()
{
	vec2 uv = (gl_FragCoord.xy * 2.f - resolution.xy) / resolution.y;
	float d = length(uv);

	vec3 oreol_color = vec3(0.4f, 0.143f, 0.5f);

	d = sin(d * 16.f - time) / 16.f;
	d = abs(d);
	d = 0.01f / d;

	oreol_color *= d;

	color = vec4(oreol_color, 1.f);
}
