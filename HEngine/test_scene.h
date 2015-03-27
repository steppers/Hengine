#include "scene_template.h"

class test_scene : scene_template
{
	void scene_template::load()
	{
		uobject* testObj = new uobject("TEST-OBJECT", 0, 0, 0);
		testObj->addComponent(new graphics_component());
		root.addChild(testObj);
	}
};
