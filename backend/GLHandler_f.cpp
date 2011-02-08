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

#include "GL/gl.h"

#include "GLHandler.h"

GL_ROUTINE_HANDLER(Flush) {
    glFlush();
#if 0
    pThis->Lock();
    char *buffer = pThis->GetFramebuffer();
    glReadPixels(0, 0, 600, 450, GL_BGRA, GL_UNSIGNED_BYTE, buffer);
    for (int i = 0; i < 300 / 2; i++) {
        memmove(row, buffer + (299 - i) * 300 * sizeof (int), 300 * sizeof (int));
        memmove(buffer + (299 - i) * 300 * sizeof (int), buffer + i * 300 * sizeof (int), 300 * sizeof (int));
        memmove(buffer + i * 300 * sizeof (int), row, 300 * sizeof (int));
    }
    pThis->Unlock();
#endif

    return new Result(0);
}

GL_ROUTINE_HANDLER(Frustum) {
    GLdouble left = in->Get<GLdouble > ();
    GLdouble right = in->Get<GLdouble > ();
    GLdouble bottom = in->Get<GLdouble > ();
    GLdouble top = in->Get<GLdouble > ();
    GLdouble nearVal = in->Get<GLdouble > ();
    GLdouble farVal = in->Get<GLdouble > ();
    glFrustum(left, right, bottom, top, nearVal, farVal);
    return new Result(0);
}
