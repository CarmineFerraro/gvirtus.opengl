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

extern "C" void glGenBuffers(GLsizei n, GLuint *buffers) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    in->Add(n);
    in->Add(buffers, n);
    f->Execute("glGenBuffers");
    memmove(buffers, f->GetOutputBuffer()->AssignAll<char>(), n * sizeof(GLuint));
}

extern "C" GLuint glGenLists(GLsizei range) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    in->Add(range);
    f->Execute("glGenLists");
    GLuint result = f->GetOutputBuffer()->Get<GLuint > ();
    return result;
}

extern "C" void glGenTextures(GLsizei n, GLuint *textures) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    in->Add(n);
    in->Add(textures, n);
    f->Execute("glGenTextures");
    memmove(textures, f->GetOutputBuffer()->AssignAll<char>(), n * sizeof(GLuint));
}

extern "C" void glGetBufferParameteriv(GLenum target, GLenum value,
        GLint *data) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    in->Add(target);
    in->Add(value);
    f->Execute("glGetBufferParameteriv");
    *data = f->GetOutputBuffer()->Get<GLuint > ();
}

extern "C" GLenum glGetError(void) {
    Frontend *f = GetFrontend();
    f->Execute("glGetError");
    return f->GetOutputBuffer()->Get<GLenum>();
}

extern "C" const GLubyte* glGetString(GLenum name) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    in->Add(name);
    f->Execute("glGetString");
    Buffer *out = f->GetOutputBuffer();
    GLubyte *result = (GLubyte *) strdup(out->AssignString());
    return result;
}
