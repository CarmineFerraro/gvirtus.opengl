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

#include "GL.h"

#include <GL/glx.h>

static Display *mspDpy = NULL;
GLXDrawable msDrawable = 0;

extern "C" GLXFBConfig * glXChooseFBConfig(Display * dpy, int screen,
        const int * attrib_list, int * nelements) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    in->Add(screen);
    int n = 0;
    for (n = 0; attrib_list[n] != None; n++);
    n++;
    in->Add(attrib_list, n);
    f->Execute("glXChooseFBConfig");
    Buffer *out = f->GetOutputBuffer();
    *nelements = out->Get<int>();
    GLXFBConfig *config = new GLXFBConfig[*nelements];
    for (n = 0; n < *nelements; n++)
        config[n] = (GLXFBConfig) out->Get<uint64_t > ();
    return config;
}

extern "C" XVisualInfo* glXChooseVisual(Display *dpy, int screen, int * attribList) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    in->AddString(XDisplayString(dpy));
    in->Add(screen);
    int n;
    for (n = 0; attribList[n] != None; n++);
    in->Add(attribList, n + 1);
    f->Execute("glXChooseVisual");
    if (f->GetExitCode() != 0)
        return NULL;
    Buffer *out = f->GetOutputBuffer();
    XVisualInfo *vis = out->Get<XVisualInfo > (1);
    vis->visual = out->Get<Visual > (1);
    out->Get<VisualID > ();

    XVisualInfo vis_template;
    vis_template.screen = screen;
    vis_template.visualid = XVisualIDFromVisual(DefaultVisual(dpy, screen));
    return XGetVisualInfo(dpy, VisualScreenMask | VisualIDMask,
            &vis_template, &n);
}

extern "C" GLXContext glXCreateContext(Display *dpy, XVisualInfo *vis,
        GLXContext shareList, Bool direct) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    //in->AddString(XDisplayString(dpy));
    //in->Add(vis);
    //in->Add(vis->visual);
    in->Add((uint64_t) shareList);
    in->Add(direct);
    f->Execute("glXCreateContext");
    if (f->GetExitCode() != 0)
        return NULL;
    Buffer *out = f->GetOutputBuffer();
    GLXContext ctx = (GLXContext) out->Get<uint64_t > ();
    return ctx;
}

extern "C" GLXContext glXCreateNewContext(Display * dpy, GLXFBConfig config,
        int render_type, GLXContext share_list, Bool direct) {
    int n;
    XVisualInfo vis_template;
    vis_template.screen = 0;
    vis_template.visualid = XVisualIDFromVisual(DefaultVisual(dpy, 0));

    return glXCreateContext(dpy, XGetVisualInfo(dpy, VisualScreenMask | VisualIDMask,
            &vis_template, &n), share_list, direct);
}

extern "C" const char *glXGetClientString(Display *dpy, int name) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    in->Add(name);
    f->Execute("glXGetClientString");
    return strdup(f->GetOutputBuffer()->AssignString());
}

extern "C" Display * glXGetCurrentDisplay() {
    return mspDpy;
}

extern "C" GLXDrawable glXGetCurrentReadDrawable() {
    return msDrawable;
}

extern "C" XVisualInfo * glXGetVisualFromFBConfig(Display * dpy,
        GLXFBConfig config) {

    int n;
    XVisualInfo vis_template;
    vis_template.screen = 0;
    vis_template.visualid = XVisualIDFromVisual(DefaultVisual(dpy, 0));

    return XGetVisualInfo(dpy, VisualScreenMask | VisualIDMask,
            &vis_template, &n);

}

extern "C" Bool glXIsDirect(Display * dpy,
        GLXContext ctx) {
    return False;
}

extern "C" Bool glXMakeContextCurrent(Display * display, GLXDrawable draw,
        GLXDrawable read, GLXContext ctx) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    in->Add(false);
    in->Add(draw);
    XWindowAttributes draw_attrib;
    XGetWindowAttributes(display, draw, &draw_attrib);
    in->Add(draw_attrib);
    in->Add(read);
    XWindowAttributes read_attrib;
    XGetWindowAttributes(display, read, &read_attrib);
    in->Add(read_attrib);
    in->Add((uint64_t) ctx);
    f->Execute("glXMakeContextCurrent");
    Buffer *out = f->GetOutputBuffer();
    Bool result = out->Get<Bool > ();
    InstantiateUpdater(display, draw, draw_attrib);
    InstantiateUpdater(display, read, read_attrib);
    return result;
}

extern "C" Bool glXMakeCurrent(Display *dpy, GLXDrawable drawable,
        GLXContext ctx) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    in->Add(drawable);
    XWindowAttributes attrib;
    XGetWindowAttributes(dpy, drawable, &attrib);
    in->Add(attrib);
    in->Add((uint64_t) ctx);
    //bool use_shm = mShmType != NONE;
    in->Add(false);
    f->Execute("glXMakeCurrent");
    Buffer *out = f->GetOutputBuffer();
    Bool result = out->Get<Bool > ();
    //mspShmName = strdup(out->AssignString());
    //pthread_t tid;
    //pthread_create(&tid, NULL, update, w);
    InstantiateUpdater(dpy, drawable, attrib);
    return result;
}

extern "C" Bool glXQueryExtension(Display *dpy, int *errorBase,
        int *eventBase) {
    Frontend *f = GetFrontend();
    f->Execute("glXQueryExtension");
    if (f->GetExitCode() != 0)
        return False;
    if (errorBase)
        *errorBase = f->GetOutputBuffer()->Get<int>();
    if (eventBase)
        *eventBase = f->GetOutputBuffer()->Get<int>();
    return True;
}

extern "C" const char *glXQueryExtensionsString(Display *dpy, int screen) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    //in->AddString(XDisplayString(dpy));
    in->Add(screen);
    f->Execute("glXQueryExtensionsString");
    Buffer *out = f->GetOutputBuffer();
    char *result = strdup(out->AssignString());
    return result;
}

extern "C" Bool glXQueryVersion(Display *dpy, int *major, int *minor) {
    mspDpy = dpy;
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    in->Add(major);
    in->Add(minor);
    f->Execute("glXQueryVersion");
    *major = f->GetOutputBuffer()->Get<int>();
    *minor = f->GetOutputBuffer()->Get<int>();
    return True;
}

extern "C" void glXSwapBuffers(Display *dpy, GLXDrawable drawable) {
    Frontend *f = GetFrontend();
    Buffer *in = f->GetInputBuffer();
    //in->AddString(XDisplayString(dpy));
    in->Add(drawable);
    f->Execute("glXSwapBuffers");
}
