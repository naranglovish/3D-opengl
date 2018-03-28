#include "main.h"

#ifndef CLOUD_H
#define CLOUD_H


class Cloud {
public:
    Cloud() {}
    Cloud(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object;
};

#endif // BALL_H
