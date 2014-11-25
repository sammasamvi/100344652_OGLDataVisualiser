#ifndef HOMOGENCOORD_H
#define HOMOGENCOORD_H

// An immutable class representing a homogeneous coordinate in 3D space.
class homogenCoord
{
private:
	float _w;
	float _x;
	float _y;
	float _z;

	static bool resultIsVector(float lhs_w, float rhs_w);

public:
	homogenCoord(float x, float y, bool isVector);
	homogenCoord(float x, float y, float z, bool isVector);
	homogenCoord(const homogenCoord& original);

	homogenCoord& operator=(const homogenCoord& rhs);
	homogenCoord& operator+(const homogenCoord& rhs) const;
	homogenCoord& operator-(const homogenCoord& rhs) const;

	float getW();
	float getX();
	float getY();
	float getZ();
};

#endif