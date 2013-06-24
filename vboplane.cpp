#include "vboplane.h"
#include "cookbookogl.h"

VBOPlane::VBOPlane(float xsize, float ysize, int xdivs, int ydivs, vec4 color=vec4(0.5,0.5,0.5,1.0))
{    
    faces = xdivs * ydivs;

    float * v = new float[3 * (xdivs + 1) * (ydivs + 1)];
	float * n = new float[3 * (xdivs + 1) * (ydivs + 1)];
	float * c = new float[3 * (xdivs + 1) * (ydivs + 1)];

    float * tex = new float[2 * (xdivs + 1) * (ydivs + 1)];
    unsigned int * el = new unsigned int[6 * xdivs * ydivs];

    float x2 = xsize / 2.0f;
    float y2 = ysize / 2.0f;
    float iFactor = (float)ysize / ydivs;
    float jFactor = (float)xsize / xdivs;
    float texi = 1.0f / ydivs;
    float texj = 1.0f / xdivs;
    float x, y;
    int vidx = 0, tidx = 0;

    for( int i = 0; i <= ydivs; i++ ) {
        y = iFactor * i - y2;
        for( int j = 0; j <= xdivs; j++ ) {
            x = jFactor * j - x2;
            v[vidx] = x;
            v[vidx+1] = y;
            v[vidx+2] = 0.0f;
			n[vidx] = 0.0f;
			n[vidx+1] = 0.0f;
			n[vidx+2] = 1.0f;
			
			c[vidx] = color.x;
			c[vidx+1] = color.y;
			c[vidx+2] = color.z;

            vidx += 3;
            tex[tidx] = j * texi;
            tex[tidx+1] = i * texj;
            tidx += 2;
        }
    }

    unsigned int rowStart, nextRowStart;
    int idx = 0;
    for( int i = 0; i < ydivs; i++ ) {
        rowStart = i * (xdivs+1);
        nextRowStart = (i+1) * (xdivs+1);
        for( int j = 0; j < xdivs; j++ ) {
            el[idx] = rowStart + j;
            el[idx+1] = nextRowStart + j;
            el[idx+2] = nextRowStart + j + 1;
            el[idx+3] = rowStart + j;
            el[idx+4] = nextRowStart + j + 1;
            el[idx+5] = rowStart + j + 1;
            idx += 6;
        }
    }

    unsigned int handle[5];
    glGenBuffers(5, handle);

	glGenVertexArrays( 1, &vaoHandle );
    glBindVertexArray(vaoHandle);

    glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
    glBufferData(GL_ARRAY_BUFFER, 3 * (xdivs+1) * (ydivs+1) * sizeof(float), v, GL_STATIC_DRAW);
    glVertexAttribPointer( (GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)) );
    glEnableVertexAttribArray(0);  // Vertex position

	glBindBuffer(GL_ARRAY_BUFFER, handle[1]);
    glBufferData(GL_ARRAY_BUFFER, 3 * (xdivs+1) * (ydivs+1) * sizeof(float), n, GL_STATIC_DRAW);
    glVertexAttribPointer( (GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)) );
    glEnableVertexAttribArray(1);  // Vertex normal

    glBindBuffer(GL_ARRAY_BUFFER, handle[2]);
    glBufferData(GL_ARRAY_BUFFER, 2 * (xdivs+1) * (ydivs+1) * sizeof(float), tex, GL_STATIC_DRAW);
    glVertexAttribPointer( (GLuint)2, 2, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)) );
    glEnableVertexAttribArray(2);  // Texture coords

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * xdivs * ydivs * sizeof(unsigned int), el, GL_STATIC_DRAW);// Vertex index

	
	glBindBuffer(GL_ARRAY_BUFFER, handle[4]);
    glBufferData(GL_ARRAY_BUFFER, 3 * (xdivs+1) * (ydivs+1) * sizeof(float), c, GL_STATIC_DRAW);
    glVertexAttribPointer( (GLuint)3, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)) );
    glEnableVertexAttribArray(3);  // Color value

    glBindVertexArray(0);
    
    delete [] v;
	delete [] n;
	delete [] c;
    delete [] tex;
    delete [] el;
}

void VBOPlane::render() const {
    glBindVertexArray(vaoHandle);
    glDrawElements(GL_TRIANGLES, 6 * faces, GL_UNSIGNED_INT, ((GLubyte *)NULL + (0)));
}
