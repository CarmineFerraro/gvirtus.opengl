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

GL_ROUTINE_HANDLER(CallList) {
    GLuint list = in->Get<GLuint > ();
    glCallList(list);
    return new Result(0);
}

GL_ROUTINE_HANDLER(Clear) {
    GLbitfield mask = in->Get<GLbitfield > ();
    glClear(mask);
    return new Result(0);
}

GL_ROUTINE_HANDLER(ClearColor) {
    GLclampf red = in->Get<GLclampf > ();
    GLclampf green = in->Get<GLclampf > ();
    GLclampf blue = in->Get<GLclampf > ();
    GLclampf alpha = in->Get<GLclampf > ();
    glClearColor(red, green, blue, alpha);
    return new Result(0);
}

GL_ROUTINE_HANDLER(Color3f) {
    GLfloat red = in->Get<GLfloat>();
    GLfloat green = in->Get<GLfloat>();
    GLfloat blue = in->Get<GLfloat>();
    glColor3f(red, green, blue);
    return new Result(0);
}

GL_ROUTINE_HANDLER(Color3fv) {
    const GLfloat *v = in->AssignAll<GLfloat>();
    glColor3fv(v);
    return new Result(0);
}

GL_ROUTINE_HANDLER(ColorPointer) {
    GLint size = in->Get<GLint>();
    GLenum type = in->Get<GLenum>();
    GLsizei stride = in->Get<GLsizei>();
    const GLvoid *pointer = NULL;
    glColorPointer(size, type, stride, pointer);
    return new Result(0);
}

GL_ROUTINE_HANDLER(CompileShader) {
    GLuint shader = in->Get<GLuint>();
    glCompileShader(shader);
    return new Result(0);
}

GL_ROUTINE_HANDLER(CreateProgram) {
    Buffer *out = new Buffer();
    out->Add(glCreateProgram());
    return new Result(0, out);
}

GL_ROUTINE_HANDLER(CreateShader) {
    GLenum shaderType = in->Get<GLenum>();
    Buffer *out = new Buffer();
    out->Add(glCreateShader(shaderType));
    return new Result(0, out);
}

GL_ROUTINE_HANDLER(CullFace) {
    GLenum mode = in->Get<GLenum > ();
    glCullFace(mode);
    return new Result(0);
}
