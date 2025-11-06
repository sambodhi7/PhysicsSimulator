#include "CollisionResolver.hpp"

void CollisionResolver::resolve(std::vector<CollisionManifold> manifolds) {
    for(int i=0;i<m_iterations;i++){
        for (auto& m : manifolds) {
            m.applyImpulse();
            m.applyPositionalCorrection();
        }
    }
  
}