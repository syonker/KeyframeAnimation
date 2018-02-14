
#include "Player.h"

Player::Player(Animation* newAnimation, Skeleton* newSkeleton) {

	animation = newAnimation;
	skeleton = newSkeleton;

	for (int i = 0; i < (newSkeleton->numDOFs+3); i++) {
		pose.push_back(0);
	}

	tStart = animation->tStart;
	tEnd = animation->tEnd;
	t = tStart;

	tInc = 0.001f;

}

Player::~Player() {

}

//called every frame
void Player::Evaluate() {

	animation->Evaluate(t, pose);

	PoseSkel();

	t += tInc;

	std::cerr << "t: " << t << std::endl;

}


//given a std::vector<float> pose, use this to pose the skeleton
void Player::PoseSkel() {

	rootTranslate = { 1,0,0,0,
					   0,1,0,0,
					   0,0,1,0,
					   pose[0],pose[1],pose[2],1 };

	std::cerr << "Pose[0] " << pose[0] << std::endl;
	std::cerr << "Pose[1] " << pose[1] << std::endl;
	std::cerr << "Pose[2] " << pose[2] << std::endl;



}