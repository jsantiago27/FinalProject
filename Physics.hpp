//
//  Physics.hpp
//  glutapp
//
//  Created by Jefferson Santiago on 12/6/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Physics_hpp
#define Physics_hpp

#include <tuple>

class Physics {
protected:

    static const float gravity;
    float velYo; // Initial Y Velocity
    float velocity_y(float v0, int time);
    
  public:
    Physics();
    ~Physics();

    std::tuple<float> jump(float v0, float y, int time);
 
};
#endif /* Physics_hpp */


