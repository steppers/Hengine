#pragma once

class vector3d
{
public:
	vector3d(){
		_x = 0; _y = 0; _z = 0;
	}
	vector3d(double x, double y, double z){
		_x = x;	_y = y;	_z = z;
	}
	~vector3d();

	vector3d* set(double x, double y, double z){
		_x = x;	_y = y;	_z = z;
		return this;
	}

	double getX(){ return _x; }
	double getY(){ return _y; }
	double getZ(){ return _z; }

	void add(vector3d val, vector3d dst){
		dst.set(val._x + _x, val._y + _y, val._z + _z);
	}

	void sub(vector3d val, vector3d dst){
		dst.set(_x - val._x, _y - val._y, _z - val._z);
	}

	vector3d* add(vector3d val){
		_x += val._x;
		_y += val._y;
		_z += val._z;
		return this;
	}

	vector3d* sub(vector3d val){
		_x -= val._x;
		_y -= val._y;
		_z -= val._z;
		return this;
	}

	void mul(double val, vector3d dst){
		dst.set(_x*val, _y*val, _z*val);
	}

	vector3d* mul(double val){
		_x *= val;
		_y *= val;
		_z *= val;
		return this;
	}

	double _x, _y, _z;
};