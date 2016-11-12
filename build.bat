mkdir build
pushd build

g++ -std=c++11 -DDEBUG -static-libstdc++ -static-libgcc -o opengl.exe ..\main.cpp ..\CTransformationMatrix.cpp ..\MainGame.cpp ..\GLSLProgram.cpp ..\Error.cpp ..\Sprite.cpp ..\lib\glfw3dll.a ..\lib\libglew32.dll.a -I ../include -L./ -lglew32 -lglfw3 -lopengl32

popd
