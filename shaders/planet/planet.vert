#version 330 core

layout(location = 0) in vec3 position; // Position of the vertex
layout(location = 1) in vec3 normal;   // Normal of the vertex
layout(location = 5) in vec2 texCoord; // UV texture coordinates
layout(location = 9) in float elevation; // elevation of vertex
layout(location = 10) in float arrowOffset; // Sideways offset for billboarded normal arrows

out vec3 color; // Computed color for this vertex
out vec2 texc;

// Transformation matrices
uniform mat4 p;
uniform mat4 v;
uniform mat4 m;

// Light data
const int MAX_LIGHTS = 10;
uniform int lightTypes[MAX_LIGHTS];         // 0 for point, 1 for directional
uniform vec3 lightPositions[MAX_LIGHTS];    // For point lights
uniform vec3 lightDirections[MAX_LIGHTS];   // For directional lights
//uniform vec3 lightAttenuations[MAX_LIGHTS]; // Constant, linear, and quadratic term
uniform vec3 lightColors[MAX_LIGHTS];

// Material data
uniform vec3 ocean_color;
uniform vec3 shore_color;
uniform vec3 land_color;
uniform vec3 mountain_color;
uniform vec3 mountain_cap_color;
uniform bool smoothColors;
uniform float shininess;
uniform vec2 repeatUV;

uniform bool useLighting;     // Whether to calculate lighting using lighting equation
uniform bool useArrowOffsets; // True if rendering the arrowhead of a normal for Shapes

const float DEEP_OCEAN_END = 0.85;
const float OCEAN_END = 1.001;
const float BEACH_END = 1.005;
const float LAND_END = 1.05;
const float LAND_HIGH_END = 1.09;
const float MOUNTAIN_END = 1.18;

float getLocationInBand(float bandStart, float bandEnd, float position) {
    float bandWidth = bandEnd - bandStart;
    float locationInBand = position - bandStart;
    float fraction = locationInBand / bandWidth;
    fraction = max(0, fraction - 0.2f); // adjust to weight towards current band color
    return fraction;
}

void main() {
    vec3 deep_ocean_color = 0.8f * ocean_color;
    vec3 land_high_color = 0.5 * land_color;

    texc = texCoord * repeatUV;

    vec4 position_cameraSpace = v * m * vec4(position, 1.0);
    vec4 normal_cameraSpace = vec4(normalize(mat3(transpose(inverse(v * m))) * normal), 0);

    vec4 position_worldSpace = m * vec4(position, 1.0);
    vec4 normal_worldSpace = vec4(normalize(mat3(transpose(inverse(m))) * normal), 0);

    if (useArrowOffsets) {
        // Figure out the axis to use in order for the triangle to be billboarded correctly
        vec3 offsetAxis = normalize(cross(vec3(position_cameraSpace), vec3(normal_cameraSpace)));
        position_cameraSpace += arrowOffset * vec4(offsetAxis, 0);
    }

    vec3 diffuse_col;
    if (smoothColors) {
        if (elevation < OCEAN_END) {
            diffuse_col = mix(deep_ocean_color, ocean_color, getLocationInBand(DEEP_OCEAN_END, OCEAN_END, elevation));
        } else if (elevation < BEACH_END) {
            diffuse_col = mix(shore_color, land_color, getLocationInBand(OCEAN_END, BEACH_END, elevation));
        } else if (elevation < LAND_END) {
            diffuse_col = mix(land_color, mountain_color, getLocationInBand(BEACH_END, LAND_END, elevation));
        } else if (elevation < MOUNTAIN_END) {
            diffuse_col = mix(mountain_color, mountain_cap_color, getLocationInBand(LAND_END, MOUNTAIN_END, elevation));
        } else {
            diffuse_col = mountain_cap_color; // mountain caps
        }
    } else {
        if (elevation < DEEP_OCEAN_END) {
            diffuse_col = deep_ocean_color; // deep ocean
        } else if (elevation < OCEAN_END) {
            diffuse_col = ocean_color; // ocean
        } else if (elevation < BEACH_END) {
            diffuse_col = shore_color; // beach
        } else if (elevation < LAND_END) {
            diffuse_col = land_color; // land
        } else if (elevation < LAND_HIGH_END) {
            diffuse_col = land_high_color; // high land
        }else if (elevation < MOUNTAIN_END) {
            diffuse_col = mountain_color; // mountains
        } else {
            diffuse_col = mountain_cap_color; // mountain caps
        }
    }

    vec3 ambient_col = 0.25 * diffuse_col;
    vec3 specular_col = vec3(0.2f, 0.2f, 0.2f);

    gl_Position = p * position_cameraSpace;

    color = ambient_col.xyz; // Add ambient component

    for (int i = 0; i < MAX_LIGHTS; i++) {
        vec4 vertexToLight = vec4(0);
        // Point Light
        if (lightTypes[i] == 0) {
            vertexToLight = normalize(v * vec4(lightPositions[i], 1) - position_cameraSpace);
        } else if (lightTypes[i] == 1) {
            // Dir Light
            vertexToLight = normalize(v * vec4(-lightDirections[i], 0));
        }

        // Add diffuse component
        float diffuseIntensity = max(0.0, dot(vertexToLight, normal_cameraSpace));
        color += max(vec3(0), lightColors[i] * diffuse_col * diffuseIntensity);

        // Add specular component
        vec4 lightReflection = normalize(-reflect(vertexToLight, normal_cameraSpace));
        vec4 eyeDirection = normalize(vec4(0,0,0,1) - position_cameraSpace);
        float specIntensity = pow(max(0.0f, dot(eyeDirection, lightReflection)), shininess);
        color += max (vec3(0.f), lightColors[i] * specular_col * specIntensity);
    }
    color = clamp(color, 0.0, 1.0);
}
