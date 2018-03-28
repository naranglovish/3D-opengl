#include "main.h"

#ifndef PRYAMID_H
#define PRYAMID_H


class Pryamid {
public:
    Pryamid() {}
    Pryamid(float x, float y,float z, color_t color);
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
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    // VAO *object3;
    // VAO *object4;
    // VAO *object5;
    // VAO *object6;
   
};

#endif // Pryamid_H
