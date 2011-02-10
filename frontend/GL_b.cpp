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

#include <iostream>

using namespace std;

extern "C" void glBegin(GLenum mode) {
    Buffer *in = AddRoutine("glBegin");
    in->Add(mode);
}

extern "C" void glBindBuffer(GLenum target, GLuint buffer) {
    Buffer *in = AddRoutine("glBindBuffer");
    in->Add(target);
    in->Add(buffer);
}

extern "C" void glBindTexture(GLenum target, GLuint texture) {
    Buffer *in = AddRoutine("glBindTexture");
    in->Add(target);
    in->Add(texture);
}

extern "C" void glBufferData(GLenum target, GLsizeiptr size,
        const GLvoid * data, GLenum usage) {
    Buffer *in = AddRoutine("glBufferData");
    in->Add(target);
    in->Add(size);
    in->Add((bool) (data != NULL));
    if(data)
        in->Add((char *) data, size);
    in->Add(usage);
}

extern "C" void glBufferSubData(GLenum target, GLintptr offset, 
        GLsizeiptr size, const GLvoid *data) {
    Buffer *in = AddRoutine("glBufferSubData");
    in->Add(target);
    in->Add(offset);
    in->Add(size);
    in->Add((char *) data, size);
}