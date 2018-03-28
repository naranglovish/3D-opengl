#include "gifts.h"
#include "main.h"

Gifts::Gifts(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y,z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    int i;
    float vertex_buffer_data[]={

        -25,-25,-25,
        -25,-25, 25,
        -25, 25, 25,
         25, 25,-25,
        -25,-25,-25,
        -25, 25,-25,
         25,-25, 25,
        -25,-25,-25,
         25,-25,-25,
         25, 25,-25,
         25,-25,-25,
        -25,-25,-25,
        -25,-25,-25,
        -25, 25, 25,
        -25, 25,-25,
         25,-25, 25,
        -25,-25, 25,
        -25,-25,-25,
        -25, 25, 25,
        -25,-25, 25,
         25,-25, 25,
         25, 25, 25,
         25,-25,-25,
         25, 25,-25,
         25,-25,-25,
         25, 25, 25,
         25,-25, 25,
         25, 25, 25,
         25, 25,-25,
        -25, 25,-25,
         25, 25, 25,
        -25, 25,-25,
        -25, 25, 25,
         25, 25, 25,
        -25, 25, 25,
         25,-25, 25

    };
    
 
    this->object = create3DObject(GL_TRIANGLES, 18, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 18, vertex_buffer_data+(18*3), COLOR_GIFT1, GL_FILL);
   // this->object1 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data+(360*9), COLOR_Gifts1, GL_FILL);

}

void Gifts::draw(glm::mat4 VP) {
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
 //   draw3DObject(this->object1);

}

void Gifts::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}


bounding_box_t Gifts::bounding_box() {
    float x = this->position.x, y = this->position.y, z=this->position.z;
    bounding_box_t bbox = { x,y,z,50,25,50};
    return bbox;
}

void Gifts::tick() {
this->rotation+=2;

}

