#include "uscene.h"

uscene::uscene()
{
	_type = U_SCENE;
}

uscene::~uscene()
{

}

void uscene::init(uobject* root)
{
	_root = root;
}