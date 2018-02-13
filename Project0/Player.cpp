
#include "Player.h"

Player::Player(Animation* newAnimation, Skeleton* newSkeleton) {

	animation = newAnimation;
	skeleton = newSkeleton;

	for (int i = 0; i < newSkeleton->numDOFs; i++) {
		pose.push_back(0);
	}

	tStart = animation->tStart;
	tEnd = animation->tEnd;
	t = tStart;

	tInc = 0.01f;

}

Player::~Player() {

}

//called every frame
void Player::Evaluate() {

	animation->Evaluate(t, pose);

	t += tInc;

}


//given a std::vector<float> pose, use this to pose the skeleton
void Player::PoseSkel() {



}