#include "spawner.h"
#include "../../level.h"

Spawner::Spawner(float x, float y, int amount, Level* level)
	: Entity(x, y), amount(amount), level(level)
{
}
