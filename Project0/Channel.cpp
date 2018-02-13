
#include "Channel.h"

Channel::Channel() {

}

Channel::~Channel() {

}

bool Channel::Load(Tokenizer* token) {

	token->FindToken("extrapolate");
	token->SkipWhitespace();
	token->GetToken(extrapIn);
	token->SkipWhitespace();
	token->GetToken(extrapOut);

	token->FindToken("keys"); 
	numKeys = token->GetFloat();
	token->FindToken("{");

	//parse each keyframe
	for (int i = 0; i < numKeys; i++) {

		Keyframe* newKeyframe = new Keyframe();
		keyframes.push_back(newKeyframe);
		newKeyframe->Load(token);


	}

	token->FindToken("}");

	return true;

}

void Channel::Precompute() {

	Keyframe* currKey;

	//compute tangents from rules
	for (int i = 0; i < numKeys; i++) {

		currKey = keyframes[i];

		//compute tangIn
		if (strcmp(currKey->ruleIn, "flat") == 0) {

			currKey->tangIn = 0;

		}
		else if (strcmp(currKey->ruleIn, "linear") == 0) {

			if (i < numKeys - 1) {

				currKey->tangIn = ((keyframes[i+1]->value - currKey->value) / (keyframes[i + 1]->time - currKey->time));

			}
			else {

				currKey->tangIn = ((currKey->value - keyframes[i - 1]->value) / (currKey->time - keyframes[i - 1]->time));

			}

		}
		else if (strcmp(currKey->ruleIn, "smooth") == 0) {

			//use linear if first or last key
			if (i = 0) {
				currKey->tangIn = ((keyframes[i + 1]->value - currKey->value) / (keyframes[i + 1]->time - currKey->time));
			}
			else if (i == numKeys - 1) {
				currKey->tangIn = ((currKey->value - keyframes[i - 1]->value) / (currKey->time - keyframes[i - 1]->time));
			}
			//if not first or last key
			else {
				currKey->tangIn = ((keyframes[i + 1]->value - keyframes[i - 1]->value) / (keyframes[i + 1]->time - keyframes[i - 1]->time));
			}

		}


		//compute tangOut
		if (strcmp(currKey->ruleOut, "flat") == 0) {

			currKey->tangOut = 0;

		}
		else if (strcmp(currKey->ruleOut, "linear") == 0) {

			if (i < numKeys - 1) {

				currKey->tangOut = ((keyframes[i + 1]->value - currKey->value) / (keyframes[i + 1]->time - currKey->time));

			}
			else {

				currKey->tangOut = ((currKey->value - keyframes[i - 1]->value) / (currKey->time - keyframes[i - 1]->time));

			}

		}
		else if (strcmp(currKey->ruleOut, "smooth") == 0) {

			//use linear if first or last key
			if (i = 0) {
				currKey->tangOut = ((keyframes[i + 1]->value - currKey->value) / (keyframes[i + 1]->time - currKey->time));
			}
			else if (i == numKeys - 1) {
				currKey->tangOut = ((currKey->value - keyframes[i - 1]->value) / (currKey->time - keyframes[i - 1]->time));
			}
			//if not first or last key
			else {
				currKey->tangOut = ((keyframes[i + 1]->value - keyframes[i - 1]->value) / (keyframes[i + 1]->time - keyframes[i - 1]->time));
			}

		}


	}



	//compute cubic coefficients from tangent data
}

float Channel::Evaluate(float time) {

	float curr;
	float *currPtr = &curr;

	//t is before the first key (use extrapIn)
	if (time < keyframes[0]->time) {

		if (strcmp(extrapIn, "constant") == 0) {

			curr = keyframes[0]->value;

		}
		else if (strcmp(extrapIn, "linear") == 0) {

		}
		else if (strcmp(extrapIn, "cycle") == 0) {

		}
		else if (strcmp(extrapIn, "cycle_offset") == 0) {

		}
		else if (strcmp(extrapIn, "bounce") == 0) {

		}
		else {
			std::cerr << "INVALID EXTRAPIN!" << std::endl;
		}

	}

	//t is after the last key(use extrapOut)
	else if (time > keyframes[numKeys-1]->time) {

	}

	//t falls exactly on some key(return key value)
	else if (ExactlyOnKey(time, currPtr)) {
		//curr set in method already
	}
	
	//t falls between two keys(evaluate cubic equation)
	else {

	}


	return curr;

}

bool Channel::ExactlyOnKey(float time, float *value) {

	for (int i = 0; i < numKeys; i++) {

		if (keyframes[i]->time == time) {

			value = keyframes[i]->value;
			return true;
		}

	}

	return false;

}