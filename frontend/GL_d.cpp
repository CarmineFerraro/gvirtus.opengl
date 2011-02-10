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

extern "C" void glDeleteShader(GLuint shader) {
    AddRoutine("glDeleteShader")->Add(shader);
}

extern "C" void glDepthMask(GLboolean flag) {
    AddRoutine("glDepthMash")->Add(flag);
}

extern "C" void glDrawArrays(GLenum mode, GLint	first, GLsizei count) {
    Buffer *in = AddRoutine("glDrawArrays");
    in->Add(mode);
    in->Add(first);
    in->Add(count);
}

extern "C" void glDisable(GLenum cap) {
    Buffer *in = AddRoutine("glDisable");
    in->Add(cap);
}

extern "C" void glDisableClientState(GLenum cap) {
    Buffer *in = AddRoutine("glDisableClientState");
    in->Add(cap);
}