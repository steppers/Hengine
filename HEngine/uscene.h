#pragma once

#include "scene.h"
#include "uobject.h"

class uscene : public scene
{
public:
	uscene();
	~uscene();

	void init(uobject* root, state_manager* st_mng) override;
	uobject* getRoot(){ return _root; }

private:
	uobject* _root;
};

