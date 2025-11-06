#pragma once
#include "CollisionManifold.hpp"
#include <vector>

class CollisionResolver {
    int m_iterations = 100;

public:
    void resolve(std::vector<CollisionManifold> manifolds);
};