#ifndef OGL_STRUCTS_H
#define OGL_STRUCTS_H

// Marks out a location in 2D space.
struct point
{
	int x;
	int y;
};

// Marks out a location in 3D space.
struct point3D : public point
{
	int z;
};

#endif