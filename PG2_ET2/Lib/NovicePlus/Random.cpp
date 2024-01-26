#include "Random.h"

// staticメンバ変数の初期化
std::mt19937 Random::generator_(std::random_device{}());


Random::Random() { }
Random::~Random() { }


