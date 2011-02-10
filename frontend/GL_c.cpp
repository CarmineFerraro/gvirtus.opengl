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

extern "C" void glCallList(GLuint list) {
    Buffer *in = AddRoutine("glCallList");
    in->Add(list);
}

extern "C" void glClear(GLbitfield mask) {
    Buffer *in = AddRoutine("glClear");
    in->Add(mask);
}

extern "C" void glClearColor(GLclampf red, GLclampf green, GLclampf blue,
        GLclampf alpha) {
    Buffer *in = AddRoutine("glClearColor");
    in->Add(red);
    in->Add(green);
    in->Add(blue);
    in->Add(alpha);
}

extern "C" void glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    Buffer *in = AddRoutine("glColor3f");
    in->Add(red);
    in->Add(green);
    in->Add(blue);
}

extern "C" void glColor3fv(const GLfloat *v) {
    AddRoutine("glColor3fv")->Add(v, 3);
}

extern "C" void glColorPointer(GLint size, GLenum type, GLsizei stride, 
        const GLvoid *pointer) {
    Buffer *in = AddRoutine("glColorPointer");
    in->Add(size);
    in->Add(type);
    in->Add(stride);
}

extern "C" void glCompileShader(GLuint shader) {
    Buffer *in = AddRoutine("glCompileShader");
    in->Add(shader);
}

extern "C" GLuint glCreateProgram() {
    Frontend *f = GetFrontend();
    f->Execute("glCreateProgram");
    return f->GetOutputBuffer()->Get<GLuint>();
}

extern "C" GLuint glCreateShader(GLenum shaderType) {
    Frontend *f = GetFrontend();
    f->GetInputBuffer()->Add(shaderType);
    f->Execute("glCreateShader");
    return f->GetOutputBuffer()->Get<GLuint>();
}

extern "C" void glCullFace(GLenum mode) {
    Buffer *in = AddRoutine("glCullFace");
    in->Add(mode);
}
