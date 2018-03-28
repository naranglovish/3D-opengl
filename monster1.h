#include "main.h"

#ifndef MONSTER1_H
#define MONSTER1_H


class Monster1 {
public:
    Monster1() {}
    Monster1(float x, float y,float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    void Jump();
    double speed;
    double speedy;
    double acc_y;
    int jump_flag;
    bounding_box_t bounding_box();
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    // VAO *object3;
    // VAO *object4;
    // VAO *object5;
    // VAO *object6;
   
};

#endif // Monster1_H
