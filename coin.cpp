#include "coin.h"
#include "main.h"

Coin::Coin(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y,z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    int i;
    float vertex_buffer_data[380*9];
    
    for(i=0;i<360;i++)
    {
        vertex_buffer_data[9*i] = 0.0f;
        vertex_buffer_data[9*i+1] = 0.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = 50*cos((3.1457*i/180));
        vertex_buffer_data[9*i+4] = 50*sin(3.1457*i/180);
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = 50*cos(3.1457*(i+1)/180);
        vertex_buffer_data[9*i+7] = 50*sin(3.1457*(i+1)/180);
        vertex_buffer_data[9*i+8] = 0.0f;

    }


    this->object = create3DObject(GL_TRIANGLES, 360*3, vertex_buffer_data, color, GL_FILL);
}

void Coin::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Coin::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}


bounding_box_t Coin::bounding_box() {
    float x = this->position.x, y = this->position.y, z=this->position.z;
    bounding_box_t bbox = { x,y,z,40,200,40};
    return bbox;
}

void Coin::tick() {
   this->rotation += 10;
  // this->position.x -= speed;
   // this->position.y -= speed;
}

