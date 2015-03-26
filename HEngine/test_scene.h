#include "scene_template.h"

class test_scene : scene_template
{
	void scene_template::load()
	{
		game_object* testObj = new game_object();
		root.addChild(testObj);
	}
};
