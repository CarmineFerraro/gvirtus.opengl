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

GL_ROUTINE_HANDLER(Begin) {
    GLenum mode = in->Get<GLenum > ();
    glBegin(mode);
    return new Result(0);
}

GL_ROUTINE_HANDLER(BindBuffer) {
    GLenum target = in->Get<GLenum>();
    GLuint buffer = in->Get<GLuint>();
    glBindBuffer(target, buffer);
    return new Result(0);
}

GL_ROUTINE_HANDLER(BindTexture) {
    GLenum target = in->Get<GLenum>();
    GLuint texture = in->Get<GLuint>();
    glBindTexture(target, texture);
    return new Result(0);
}

GL_ROUTINE_HANDLER(BlendFunc) {
    GLenum sfactor = in->Get<GLenum>();
    GLenum dfactor = in->Get<GLenum>();
    glBlendFunc(sfactor, dfactor);
    return new Result(0);
}

GL_ROUTINE_HANDLER(BufferData) {
    GLenum target = in->Get<GLenum>();
    GLsizeiptr size = in->Get<GLsizeiptr>();
    GLvoid * data;
    if(in->Get<bool>())
        data = (GLvoid *) in->AssignAll<char *>();
    else
        data = NULL;
    GLenum usage = in->Get<GLenum>();
    glBufferData(target, size, data, usage);
    return new Result(0);
}

GL_ROUTINE_HANDLER(BufferSubData) {
    GLenum target = in->Get<GLenum>();
    GLintptr offset = in->Get<GLintptr>();
    GLsizeiptr size = in->Get<GLsizeiptr>();
    GLvoid * data = (GLvoid *) in->AssignAll<char *>();
    glBufferSubData(target, offset, size, data);
    return new Result(0);
}
