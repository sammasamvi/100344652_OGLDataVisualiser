#ifndef HOMOGENCOORD_H
#define HOMOGENCOORD_H

// An immutable class representing a homogeneous coordinate in 3D space.
class homogenCoord
{
    private:
    	int _w;
    	int _x;
    	int _y;
    	int _z;
    
    	int  isVector(int rhs) const;
    	void copy(const homogenCoord& original);
    public:
    	homogenCoord(int x, int y, bool isVector);
    	homogenCoord(int x, int y, int z, bool isVector);
    	homogenCoord(int x, int y, int z, int w);
    	homogenCoord(const homogenCoord& original);
    
    	void         operator=(const homogenCoord& rhs);
    	homogenCoord operator+(const homogenCoord& rhs) const;
    	homogenCoord operator-(const homogenCoord& rhs) const;
    
    	int getW() const;
    	int getX() const;
    	int getY() const;
    	int getZ() const;
};


#endif