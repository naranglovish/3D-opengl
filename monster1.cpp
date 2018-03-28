#include "monster1.h"
#include "main.h"

Monster1::Monster1(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y,z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    int i;
    float vertex_buffer_data[]={
   

        -250.0f,-680.0f,-250.0f, // triangle 1 : begin
        -250.0f,-680.0f, 250.0f,
        -250.0f, 680.0f, 250.0f, // triangle 1 : end
        250.0f, 680.0f,-250.0f, // triangle 2 : begin
        -250.0f,-680.0f,-250.0f,
        -250.0f, 680.0f,-250.0f, // triangle 2 : end
        250.0f,-680.0f, 250.0f,
        -250.0f,-680.0f,-250.0f,
        250.0f,-680.0f,-250.0f,
        250.0f, 680.0f,-250.0f,
        250.0f,-680.0f,-250.0f,
        -250.0f,-680.0f,-250.0f,
        -250.0f,-680.0f,-250.0f,
        -250.0f, 680.0f, 250.0f,
        -250.0f, 680.0f,-250.0f,
        250.0f,-680.0f, 250.0f,
        -250.0f,-680.0f, 250.0f,
        -250.0f,-680.0f,-250.0f,
        -250.0f, 680.0f, 250.0f,
        -250.0f,-680.0f, 250.0f,
        250.0f,-680.0f, 250.0f,
        250.0f, 680.0f, 250.0f,
        250.0f,-680.0f,-250.0f,
        250.0f, 680.0f,-250.0f,
        250.0f,-680.0f,-250.0f,
        250.0f, 680.0f, 250.0f,
        250.0f,-680.0f, 250.0f,
        250.0f, 680.0f, 250.0f,
        250.0f, 680.0f,-250.0f,
        -250.0f, 680.0f,-250.0f,
        250.0f, 680.0f, 250.0f,
        -250.0f, 680.0f,-250.0f,
        -250.0f, 680.0f, 250.0f,
        250.0f, 680.0f, 250.0f,
        -250.0f, 680.0f, 250.0f,
        250.0f,-680.0f, 250.0f



    };

    this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, COLOR_BOAT1, GL_FILL);
    //this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data+(36*3), COLOR_BOAT2, GL_FILL);
  //  this->object2 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data+72*9, COLOR_COIN, GL_FILL);


}

void Monster1::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    //draw3DObject(this->object1);
    //draw3DObject(this->object2);

}

void Monster1::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}


bounding_box_t Monster1::bounding_box() {
    float x = this->position.x, y = this->position.y, z=this->position.z;
    bounding_box_t bbox = { x,y,z,40,200,40};
    return bbox;
}

void Monster1::tick() {
this->rotation+=2;
this->position.y+=1;
// speed=1;
}

