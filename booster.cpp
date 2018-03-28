#include "booster.h"
#include "main.h"

Booster::Booster(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y,z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 80 faces with 25 triangles each, so this makes 80*25=125 triangles, and 125*3 vertices
    float vertex_buffer_data[]={
        
        0,80,0,
        -25,0,25,
        -25,0,-25,

        0,80,0,
        -25,0,-25,
        25,0,-25,


        0,80,0,
        25,0,25,
        25,0,-25,

        0,80,0,
        25,0,25,
        -25,0,25,


       
    };



    this->object = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data, color, GL_FILL);
}

void Booster::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.80, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Booster::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

bounding_box_t Booster::bounding_box() {
    float x = this->position.x, y = this->position.y,z=this->position.z;
    bounding_box_t bbox = { x,y,z,50,80,50};
    return bbox;
}


void Booster::tick() {
   this->rotation +=0.5 ;
}

