#include "Vector.h"

#define STAGE(word) std::cout << "\n ------------------ " << (word) << " ------------------" << std::endl 

int main()
{
	MineVectorRealisation<int> mVec = { 1, 2, 3, 4, 5, 6 };
	MineVectorRealisation<int> dVec(30);	

	STAGE("BEFORE");
	masInfo(mVec);
	masInfo(dVec);
	for (int i = 0; i < 50; ++i) {
		mVec.push_back(i);
	}

	STAGE("AFTER");
	masInfo(mVec);
	masInfo(dVec);
}