#include "scene_template.h"

class test_scene : scene_template
{
	void scene_template::load()
	{
		uobject* testObj = new uobject("Test 1", 0, 0, 0);
		testObj->addComponent(new graphics_component());
		root.addChild(testObj);

		uobject* testObj2 = new uobject("Test 2", 0, 0, 0);
		root.addChild(testObj2);
	}
};
