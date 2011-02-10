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

GL_ROUTINE_HANDLER(TexImage2D) {
    GLenum target = in->Get<GLenum>();
    GLint level = in->Get<GLint>();
    GLint internalFormat = in->Get<GLint>();
    GLsizei width = in->Get<GLsizei>(); 
    GLsizei height = in->Get<GLsizei>();
    GLint border = in->Get<GLint>(); 
    GLenum format = in->Get<GLenum>();
    GLenum type = in->Get<GLenum>();
    GLvoid * data = (GLvoid *) in->AssignAll<char>();
    glTexImage2D(target, level, internalFormat, width, height, border, format,
            type, data);
    return new Result(0);
}

GL_ROUTINE_HANDLER(TexParameteri) {
    GLenum target = in->Get<GLenum>();
    GLenum pname = in->Get<GLenum>();
    GLint param = in->Get<GLint>();
    glTexParameteri(target, pname, param);
    return new Result(0);
}

GL_ROUTINE_HANDLER(Translatef) {
    GLfloat x = in->Get<GLfloat > ();
    GLfloat y = in->Get<GLfloat > ();
    GLfloat z = in->Get<GLfloat > ();
    glTranslatef(x, y, z);
    return new Result(0);
}


