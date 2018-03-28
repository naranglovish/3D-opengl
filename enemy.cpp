#include "enemy.h"
#include "main.h"

Enemy::Enemy(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y,z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    int i;
    float vertex_buffer_data[500*9];
    
    for(i=0;i<360;i++)
    {
        vertex_buffer_data[9*i] = 0.0f;
        vertex_buffer_data[9*i+1] = 200.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+5] = 30*cos((3.1457*i/180));
        vertex_buffer_data[9*i+4] = 200+30*sin(3.1457*i/180);
        vertex_buffer_data[9*i+3] = 0.0f;

        vertex_buffer_data[9*i+8] = 30*cos(3.1457*(i+1)/180);
        vertex_buffer_data[9*i+7] = 200+30*sin(3.1457*(i+1)/180);
        vertex_buffer_data[9*i+6] = 0.0f;

    }

        vertex_buffer_data[9*i] =   0.0f;
        vertex_buffer_data[9*i+1] = 170.0f;
        vertex_buffer_data[9*i+2] = -2.0f;

        vertex_buffer_data[9*i+3] = 0.0f;
        vertex_buffer_data[9*i+4] = 170.0f;
        vertex_buffer_data[9*i+5] = 2.0f;

        vertex_buffer_data[9*i+6] = 0.0f;
        vertex_buffer_data[9*i+7] = 160.0f;
        vertex_buffer_data[9*i+8] = -2.0f;

        i++;

        vertex_buffer_data[9*i] =   0.0f;
        vertex_buffer_data[9*i+1] = 160.0f;
        vertex_buffer_data[9*i+2] = 2.0f;

        vertex_buffer_data[9*i+3] = 0.0f;
        vertex_buffer_data[9*i+4] = 170.0f;
        vertex_buffer_data[9*i+5] = 2.0f;

        vertex_buffer_data[9*i+6] = 0.0f;
        vertex_buffer_data[9*i+7] = 160.0f;
        vertex_buffer_data[9*i+8] = -2.0f;

        
        i++;


        vertex_buffer_data[9*i] =   0.0f;
        vertex_buffer_data[9*i+1] = 160.0f;
        vertex_buffer_data[9*i+2] = -40.0f;

        vertex_buffer_data[9*i+3] = 0.0f;
        vertex_buffer_data[9*i+4] = 160.0f;
        vertex_buffer_data[9*i+5] = 40.0f;

        vertex_buffer_data[9*i+6] = 0.0f;
        vertex_buffer_data[9*i+7] = 100.0f;
        vertex_buffer_data[9*i+8] = -40.0f;

        i++;

        
        vertex_buffer_data[9*i] =   0.0f;
        vertex_buffer_data[9*i+1] = 160.0f;
        vertex_buffer_data[9*i+2] = 40.0f;

        vertex_buffer_data[9*i+3] = 0.0f;
        vertex_buffer_data[9*i+4] = 100.0f;
        vertex_buffer_data[9*i+5] = 40.0f;

        vertex_buffer_data[9*i+6] = 0.0f;
        vertex_buffer_data[9*i+7] = 100.0f;
        vertex_buffer_data[9*i+8] = -40.0f;
     
        
        i++;

        this->object = create3DObject(GL_TRIANGLES, 360*3, vertex_buffer_data, color, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data+(360*9), COLOR_ENEMY1, GL_FILL);

}

void Enemy::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);

}

void Enemy::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}


bounding_box_t Enemy::bounding_box() {
    float x = this->position.x, y = this->position.y, z=this->position.z;
    bounding_box_t bbox = { x,y,z,40,550,40};
    return bbox;
}

void Enemy::tick(float x,float z) {
 speed=speed+1;
 this->position.x = x + 200*cos(speed*M_PI/180.0f); 
 this->position.z = z + 200*sin(speed*M_PI/180.0f);
 if(speed==360)
    speed=1;
}
