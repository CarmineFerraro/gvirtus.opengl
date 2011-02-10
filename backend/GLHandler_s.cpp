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

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>

#include "GLHandler.h"

GL_ROUTINE_HANDLER(Scalef) {
    GLfloat x = in->Get<GLfloat>();
    GLfloat y = in->Get<GLfloat>();
    GLfloat z = in->Get<GLfloat>();
    glScalef(x, y, z);
    return new Result(0);
}

GL_ROUTINE_HANDLER(ShadeModel) {
    GLenum mode = in->Get<GLenum > ();
    glShadeModel(mode);
    return new Result(0);
}

GL_ROUTINE_HANDLER(ShaderSource) {
    GLuint shader = in->Get<GLuint>();
    GLsizei count = in->Get<GLsizei>();
    GLchar **string = new GLchar*[count];
    GLint *length = new GLint[count];
    for(int i = 0; i < count; i++) {
        string[i] = (GLchar *) in->AssignString();
        length[i] = strlen((char *) string[i]);
    }
    glShaderSource(shader, count, (const GLchar **) string, length);
    return new Result(0);
}