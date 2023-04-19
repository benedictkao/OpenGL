#include "Renderer.h"

#include <iostream>

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << file << ":" << line << std::endl << "[OpenGL Error] (" << error << "): " << function << std::endl;
        return false;
    }
    return true;
}