#ifndef VBOPLANE_H
#define VBOPLANE_H

#include "drawable.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
using glm::vec4;

class VBOPlane : public Drawable
{
private:
    unsigned int vaoHandle;
    int faces;

public:
	VBOPlane(float xsize, float zsize, int xdivs, int zdivs);
    void render() const;
};

#endif // VBOPLANE_H
