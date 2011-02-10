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

GL_ROUTINE_HANDLER(GenBuffers) {
    GLsizei n = in->Get<GLsizei>();
    GLuint *buffers = in->AssignAll<GLuint>();
    glGenBuffers(n, buffers);
    Buffer *out = new Buffer();
    out->Add<GLuint>(buffers, n);
    return new Result(0, out);
}

GL_ROUTINE_HANDLER(GenLists) {
    GLsizei range = in->Get<GLsizei > ();
    GLuint result = glGenLists(range);
    Buffer *out = new Buffer();
    out->Add(result);
    return new Result(0, out);
}

GL_ROUTINE_HANDLER(GenTextures) {
    GLsizei n = in->Get<GLsizei>();
    GLuint *textures = in->AssignAll<GLuint>();
    glGenTextures(n, textures);
    Buffer *out = new Buffer();
    out->Add<GLuint>(textures, n);
    return new Result(0, out);
}

GL_ROUTINE_HANDLER(GetBufferParameteriv) {
    GLenum target = in->Get<GLenum>();
    GLenum value = in->Get<GLenum>();
    GLint data;
    glGetBufferParameteriv(target, value, &data);
    Buffer *out = new Buffer();
    out->Add(data);
    return new Result(0, out);
}

GL_ROUTINE_HANDLER(GetError) {
    Buffer *out = new Buffer();
    out->Add(glGetError());
    return new Result(0, out);
}

GL_ROUTINE_HANDLER(GetString) {
    GLenum name = in->Get<GLenum>();
    Buffer *out = new Buffer();
    out->AddString((char *) glGetString(name));
    return new Result(0, out);
}

