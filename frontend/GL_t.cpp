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

extern "C" void glTexEnvi(GLenum target, GLenum pname, GLint param) {
    Buffer *in = AddRoutine("glTexEnvi");
    in->Add(target);
    in->Add(pname);
    in->Add(param);
}

extern "C" void glTexImage2D(GLenum target, GLint level, GLint internalFormat,
        GLsizei width, GLsizei height, GLint border, GLenum format,
        GLenum type, const GLvoid * data) {
    int components = 1;
    switch (format) {
        case GL_LUMINANCE_ALPHA:
            components = 2;
            break;
        case GL_RGB:
        case GL_BGR:
            components = 3;
            break;
        case GL_RGBA:
        case GL_BGRA:
            components = 4;
            break;
    }

    int size = width * height;
    switch (type) {
        case GL_UNSIGNED_BYTE:
        case GL_BYTE:
        case GL_BITMAP:
            size *= components;
            break;
        case GL_UNSIGNED_SHORT:
        case GL_SHORT:
            size *= components * sizeof (short);
            break;
        case GL_UNSIGNED_INT:
        case GL_INT:
            size *= components * sizeof (int);
            break;
        case GL_FLOAT:
            size *= components * sizeof (float);
            break;
        case GL_UNSIGNED_SHORT_5_6_5:
        case GL_UNSIGNED_SHORT_5_6_5_REV:
        case GL_UNSIGNED_SHORT_4_4_4_4:
        case GL_UNSIGNED_SHORT_4_4_4_4_REV:
        case GL_UNSIGNED_SHORT_5_5_5_1:
        case GL_UNSIGNED_SHORT_1_5_5_5_REV:
            size *= sizeof (short);
            break;
        case GL_UNSIGNED_INT_8_8_8_8:
        case GL_UNSIGNED_INT_8_8_8_8_REV:
        case GL_UNSIGNED_INT_10_10_10_2:
        case GL_UNSIGNED_INT_2_10_10_10_REV:
            size *= sizeof (int);
            break;
    }

    Buffer *in = AddRoutine("glTexImage2D");
    in->Add(target);
    in->Add(level);
    in->Add(internalFormat);
    in->Add(width);
    in->Add(height);
    in->Add(border);
    in->Add(format);
    in->Add(type);
    in->Add((const char *) data, size);
}

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

