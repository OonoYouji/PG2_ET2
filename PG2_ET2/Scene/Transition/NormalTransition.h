#pragma once

// Base -----
#include "ITransition.h"

#include <cmath>

class NormalTransition final
	: public ITransition {
public: // member method

	// Constructor & Destructor
	NormalTransition();
	~NormalTransition();

	// default method
	void Init() override;
	void Updata() override;
	void Draw() override;
	void Finalize() override;

private: // member object

	int inFrame_;
	int outFrame_;

	float inFrameLimit_;
	float outFrameLimit_;

	uint32_t color_;

};

