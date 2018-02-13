
#include "Channel.h"

Channel::Channel() {

}

Channel::~Channel() {

}

bool Channel::Load(Tokenizer* token) {

	char* extrapIn;
	char* extrapOut;

	token->FindToken("extrapolate");
	token->SkipWhitespace();
	token->GetToken(extrapIn);
	token->SkipWhitespace();
	token->GetToken(extrapOut);

	token->FindToken("keys"); 
	numKeys = token->GetFloat;
	token->FindToken("{");

	//parse each keyframe
	for (int i = 0; i <= numKeys; i++) {

		Keyframe* newKeyframe = new Keyframe();
		newKeyframe->Load(token);

	}

	token->FindToken("}");

}

float Channel::Evaluate(float time) {


}