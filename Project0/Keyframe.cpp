
#include "Keyframe.h"

Keyframe::Keyframe() {

}

Keyframe::~Keyframe() {

}

bool Keyframe::Load(Tokenizer* token) {

	char isLetter;

	time = token->GetFloat();
	value = token->GetFloat();
	token->SkipWhitespace();

	isLetter = token->CheckChar();

	//parse a word
	if ((97 <= isLetter) && (isLetter <= 122)) {

		token->GetToken(ruleIn);
		token->SkipWhitespace();
		token->GetToken(ruleOut);
		
	}
	//parse a num
	else {

		//ruleIn = "basic";
		//ruleOut = "basic";
		tangIn = token->GetFloat();
		tangOut = token->GetFloat();

	}

	return true;

}

void Keyframe::Precompute() {


	if (strcmp(ruleIn, "flat") == 0) {

		tangIn = 0;

	}
	else if (strcmp(ruleIn, "linear") == 0) {

	}
	else if (strcmp(ruleIn, "smooth") == 0) {

	}
	else {
		
	}



	if (strcmp(ruleOut, "flat") == 0) {

		tangOut = 0;

	}
	else if (strcmp(ruleOut, "linear") == 0) {

	}
	else if (strcmp(ruleOut, "smooth") == 0) {

	}
	else {

	}


}