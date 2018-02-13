#pragma once

#include "Core.h"
#include "Tokenizer.h"
#include <iostream>
#include "Keyframe.h"

class Channel
{

public:

	Channel();
	~Channel();

	bool Load(Tokenizer* token);
	float Evaluate(float time);

	std::vector<Keyframe*> keyframes;
	unsigned int numKeys;

	char extrapIn[256];
	char extrapOut[256];

private:

};