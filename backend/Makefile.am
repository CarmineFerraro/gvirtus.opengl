backendlibdir = $(libdir)/backend
backendlib_LTLIBRARIES = libopengl-backend.la
libopengl_backend_la_SOURCES = \
GLHandler.cpp\
GLHandler.h\
GLHandler_b.cpp\
GLHandler_c.cpp\
GLHandler_d.cpp\
GLHandler_e.cpp\
GLHandler_f.cpp\
GLHandler_g.cpp\
GLHandler_i.cpp\
GLHandler_l.cpp\
GLHandler_m.cpp\
GLHandler_n.cpp\
GLHandler_o.cpp\
GLHandler_p.cpp\
GLHandler_r.cpp\
GLHandler_s.cpp\
GLHandler_t.cpp\
GLHandler_v.cpp\
GLHandler_x.cpp

libopengl_backend_la_LIBADD = -lGL

GLHandler.h: GLHandler_handlers.h
GLHandler.cpp: GLHandler_handlerspair.h

GLHandler_handlers.h: *.cpp
	grep GL_ROUTINE_HANDLER\( *.cpp | sed 's|:| |' | awk '{ print $$2 ";"}' > GLHandler_handlers.h

GLHandler_handlerspair.h: GLHandler_handlers.h
	sed -e 's|GL_ROUTINE_HANDLER||' -e 's|);||' GLHandler_handlers.h | awk '{ print "mspHandlers->insert(GL_ROUTINE_HANDLER_PAIR" $$1 "));" }' > GLHandler_handlerspair.h
