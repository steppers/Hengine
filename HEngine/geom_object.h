#pragma once

#include "vector3d.h"
#include "game_object.h"
#include "system.h"

class geom_object
{
public:
	geom_object(){}
	geom_object(double posX, double posY, double posZ){
		geom_object(posX, posY, posZ, 0, 0, 0);
	}
	geom_object(double posX, double posY, double posZ,
					double rotX, double rotY, double rotZ){
		geom_object(posX, posY, posZ, rotX, rotY, rotZ, 1, 1, 1);
	}
	geom_object(double posX, double posY, double posZ,
					double rotX, double rotY, double rotZ,
					double sclX, double sclY, double sclZ){
		pos.set(posX, posY, posZ);
		rot.set(rotX, rotY, rotZ);
		scl.set(sclX, sclY, sclZ);
	}

	~geom_object();

	void setSystem(System* sys){
		_system = sys;
	}

	void setUObject(game_object* object){ parent = object; }
	game_object* getUObject(){ return parent; }

	void move(vector3d amount){
		pos.add(amount);
	}

	void rotate(vector3d amount){
		rot.add(amount);
	}

	void change(){
		if (changed == false)
		{
			changed = true;
			//parent->registerChange(_system);
		}
	}

private:
	vector3d pos;
	vector3d rot;
	vector3d scl;
	bool changed = false;

	game_object* parent;
	System* _system;
};

