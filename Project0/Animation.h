#pragma once

#include "Core.h"
#include "Tokenizer.h"
#include <iostream>
#include "Channel.h"

class Animation
{

public:

	Animation();
	~Animation();

	bool Load(const char *file);
	//void Evaluate(float time, Pose &p);

	std::vector<Channel*> channels;

	float tStart, tEnd;
	unsigned int numChannels;

private:

};