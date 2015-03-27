#include "uscene.h"

uscene::uscene()
{
	_type = U_SCENE;
}

uscene::~uscene()
{

}

void uscene::init(uobject* root, state_manager* st_mng)
{
	_root = root;
}