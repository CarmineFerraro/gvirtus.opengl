/*
 * gVirtuS -- A GPGPU transparent virtualization component.
 *
 * Copyright (C) 2009-2011  The University of Napoli Parthenope at Naples.
 *
 * This file is part of gVirtuS.
 *
 * gVirtuS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gVirtuS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gVirtuS; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Written by: Giuseppe Coviello <giuseppe.coviello@uniparthenope.it>,
 *             Department of Applied Science
 */

#include <GL/gl.h>

#include "GL.h"

extern "C" void glLightfv(GLenum light, GLenum pname, const GLfloat *params) {
    Buffer *in = AddRoutine("glLightfv");
    int n = 0;
    switch (pname) {
        case GL_AMBIENT:
        case GL_DIFFUSE:
        case GL_SPECULAR:
        case GL_POSITION:
            n = 4;
            break;
        case GL_SPOT_DIRECTION:
            n = 3;
            break;
        case GL_SPOT_EXPONENT:
        case GL_SPOT_CUTOFF:
        case GL_CONSTANT_ATTENUATION:
        case GL_LINEAR_ATTENUATION:
        case GL_QUADRATIC_ATTENUATION:
            n = 1;
            break;
    }
    in->Add(light);
    in->Add(pname);
    in->Add(params, n);
}

extern "C" void glLinkProgram(GLuint program) {
    Buffer *in = AddRoutine("glLinkProgram");
    in->Add(program);
}

extern "C" void glLoadIdentity(void) {
    AddRoutine("glLoadIdentity");
}

