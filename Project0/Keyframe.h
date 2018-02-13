#pragma once

#include "Core.h"
#include "Tokenizer.h"
#include <iostream>

class Keyframe
{

public:

	Keyframe();
	~Keyframe();

	bool Load(Tokenizer* token);

	float time;
	float value;
	float tangIn, tangOut;
	char* ruleIn;
	char* ruleOut;
	float a, b, c, d;

private:

};