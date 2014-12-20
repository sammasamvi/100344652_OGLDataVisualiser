#ifndef HOMOGENEOUS_COORDINATE_H
#define HOMOGENEOUS_COORDINATE_H

class hCoordinate
{
    private:
		bool   _w;
		float  _x;
		float  _y;
		float  _z;

		void assign_from(const hCoordinate& hCoordinate);
		bool resutl_is_not_vector(int rhs_w);
    public:
		hCoordinate();
		~hCoordinate();
		hCoordinate(float x, float y);
		hCoordinate(float x, float y, float z);
		hCoordinate(float x, float y, float z, bool w);
		hCoordinate(const hCoordinate& original);

		const int   get_w()                const;
		const float get_x()                const;
		const float get_y()                const;
		const float get_z()                const;

		void               operator=(const hCoordinate& rhs);
		const hCoordinate* operator+(const hCoordinate& rhs);
		const hCoordinate* operator-(const hCoordinate& rhs);
};

#endif