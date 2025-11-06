#pragma once 

#include "Component.hpp"
#include "Circle.hpp"
#include "Plane.hpp"

class CollisionDetector {
    public :
        static bool detectCollision ( Component* a , Component* b ) ;
        static bool circleVsCircle ( Circle* a , Circle* b ) ;
        static bool circleVsPlane ( Circle* a , Plane* b ) ;

    };