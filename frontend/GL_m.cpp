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

extern "C" void *glMapBuffer(GLenum target, GLenum access) {
    return NULL;
}

extern "C" void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) {
    Buffer *in = AddRoutine("glMaterialfv");
    int n = 0;
    switch (pname) {
        case GL_AMBIENT:
        case GL_DIFFUSE:
        case GL_SPECULAR:
        case GL_EMISSION:
        case GL_AMBIENT_AND_DIFFUSE:
            n = 4;
            break;
        case GL_COLOR_INDEXES:
            n = 3;
            break;
        case GL_SHININESS:
            n = 1;
            break;
    }
    in->Add(face);
    in->Add(pname);
    in->Add(params, n);
}

extern "C" void glMatrixMode(GLenum mode) {
    Buffer *in = AddRoutine("glMatrixMode");
    in->Add(mode);
}

extern "C" void glMultMatrixd(const GLdouble *m) {
    Buffer *in = AddRoutine("glMultMatrixd");
    in->Add(m, 16);
}

extern "C" void glMultMatrixf(const GLfloat *m) {
    Buffer *in = AddRoutine("glMultMatrixf");
    in->Add(m, 16);
}
