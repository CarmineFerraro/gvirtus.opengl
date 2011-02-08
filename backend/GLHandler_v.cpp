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

#include "GLHandler.h"

GL_ROUTINE_HANDLER(Vertex2f) {
    GLfloat x = in->Get<GLfloat>();
    GLfloat y = in->Get<GLfloat>();
    glVertex2f(x, y);
    return new Result(0);
}

GL_ROUTINE_HANDLER(Vertex2i) {
    GLint x = in->Get<GLint>();
    GLint y = in->Get<GLint>();
    glVertex2i(x, y);
    return new Result(0);
}

GL_ROUTINE_HANDLER(Vertex3f) {
    GLfloat x = in->Get<GLfloat > ();
    GLfloat y = in->Get<GLfloat > ();
    GLfloat z = in->Get<GLfloat > ();
    glVertex3f(x, y, z);
    return new Result(0);
}

GL_ROUTINE_HANDLER(VertexPointer) {
    GLint size = in->Get<GLint>();
    GLenum type = in->Get<GLenum>();
    GLsizei stride = in->Get<GLsizei>();
    glVertexPointer(size, type, stride, NULL);
    return new Result(0);
}

GL_ROUTINE_HANDLER(Viewport) {
    GLint x = in->Get<GLint > ();
    GLint y = in->Get<GLint > ();
    GLsizei width = in->Get<GLsizei > ();
    GLsizei height = in->Get<GLsizei > ();
    glViewport(x, y, width, height);
    return new Result(0);
}
