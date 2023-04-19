#shader vertex
#version 330 core

layout(location = 0) in vec4 position;										// take 0th index attribute

void main()
{
   gl_Position = position;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;										// take 0th index attribute

uniform vec4 u_Color;

void main()
{
   color = u_Color;															// RGBA format by default
};