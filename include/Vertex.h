#pragma once 

struct Vertex{
	struct Position{
		float x;
		float y;
		float z;
	} position;
	
	struct Color{
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	} color;
	
	float padding[4];
};