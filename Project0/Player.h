#pragma once

#include "Core.h"
#include "Tokenizer.h"
#include <iostream>
#include "Animation.h"
#include "Skeleton.h"

class Player
{

public:

	Player(Animation* newAnimation, Skeleton* newSkeleton);
	~Player();

	Animation* animation;
	Skeleton* skeleton;

private:

};