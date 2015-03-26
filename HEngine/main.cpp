#include "hex_engine.h"

#include "test_scene.h"

int main(void)
{
	hex_engine engine((scene_template*)new test_scene());
	engine.start();

	return 0;
}