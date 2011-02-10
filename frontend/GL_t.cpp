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

extern "C" void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    Buffer *in = AddRoutine("glTexParameteri");
    in->Add(target);
    in->Add(pname);
    in->Add(param);
}

extern "C" void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    Buffer *in = AddRoutine("glTranslatef");
    in->Add(x);
    in->Add(y);
    in->Add(z);
}

