#pragma once

#include <iostream>
#include <random>

//template <typename T>
class Random {
public: // member method

	// Constructor & Destructor
	Random();
	~Random();

private: // member obejct

	static std::mt19937 generator_;

public: // user method

	static int Int(int min, int max) {
		std::uniform_int_distribution<int> distribution(min, max);
		return distribution(generator_);
	}

	static float Float(float min, float max) {
		std::uniform_real_distribution<float> distribution(min, max);
		return distribution(generator_);
	}

};

