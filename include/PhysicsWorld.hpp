// singleton class that manages the physics simulation 
class PhysicsWorld
{
    private :  
     PhysicsWorld () ;

   public : 
     static PhysicsWorld& getInstance(); 
     void update ( float dt) ;
     void renderAll(Renderer& renderer);
};
