IFLAGS =  -Iaby/include -Ilibs_osx_static/assimp/include -Ilibs_osx_static/glew/include -Ilibs_osx_static/glfw/include -Ilibs_osx_static/glm/include -Ilibs_osx_static/soil/include
CPPFLAGS = -std=c++11 -O3 -Wno-deprecated-declarations
CXX=clang++

GL_LIBS = -Llibs_osx_static/glfw/lib -lglfw3
GLEW_LIBS = -Llibs_osx_static/glew/lib -lglew
ASSIMP_LIBS = -Llibs_osx_static/assimp/lib -lassimp
SOIL_LIBS = -Llibs_osx_static/soil/lib -lsoil
OSX_LIBS = -framework OpenGL -framework Cocoa -framework QTKit -framework QuartzCore -framework AppKit -framework IOKit -framework OpenCL -framework VideoToolbox -framework AudioToolbox -framework VideoDecodeAcceleration -framework CoreGraphics -framework CoreServices -framework Security -framework Accelerate -framework ImageIO -framework CoreMedia -framework CoreVideo -framework AVFoundation -liconv -lm -llzma -lbz2 -lz -framework GLUT

ALL_LIBS = $(GL_LIBS) $(GLEW_LIBS) $(ASSIMP_LIBS) $(SOIL_LIBS) $(OSX_LIBS)

all : tp_start_glut




start_glut : src_glut/tp_start_glut.cpp
	$(CXX) -c $(IFLAGS) $(CPPFLAGS) src_glut/tp_start_glut.cpp

tp_start_glut : start_glut
	$(CXX) -o ./tp_start_glut tp_start_glut.o $(CPPFLAGS) $(ALL_LIBS)
	rm *.o







clean :
	rm src/*.o ./tp_start_glfw ./tp_start_glut
