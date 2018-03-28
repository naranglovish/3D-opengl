#include "main.h"

#ifndef BALL_H
#define BALL_H


class Ball {
public:
    Ball() {}
    Ball(float x, float y,float z, color_t color);
    glm::vec3 position;
    float rotation;
    float rotation1;
    float rotation2;
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
    VAO *object3;
    // VAO *object4;
    // VAO *object5;
    // VAO *object6;
   
};

#endif // BALL_H
