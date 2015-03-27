#pragma once

#include "scene.h"

class uobject;

class uscene : public scene
{
public:
	uscene();
	~uscene();

	void init(uobject* root) override;
	uobject* getRoot(){ return _root; }

private:
	uobject* _root;
};

