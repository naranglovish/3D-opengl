#include "cloud.h"
#include "main.h"

Cloud::Cloud(float x, float y, color_t color) {
    this->position = glm::vec3(x, y,0);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float vertex_buffer_data[2*9];
    int i=0;

        vertex_buffer_data[9*i] = 0.0f;
        vertex_buffer_data[9*i+1] = 10000.0f;
        vertex_buffer_data[9*i+2] = 1000.0f;

        vertex_buffer_data[9*i+3] = 0.0f;
        vertex_buffer_data[9*i+4] = 200.0f;
        vertex_buffer_data[9*i+5] = 1000.0f;

        vertex_buffer_data[9*i+6] = 0.0f;
        vertex_buffer_data[9*i+7] = 200.0f;
        vertex_buffer_data[9*i+8] = -1000.0f;   
        i++;

        vertex_buffer_data[9*i] = 0.0f;
        vertex_buffer_data[9*i+1] = 200.0f;
        vertex_buffer_data[9*i+2] = -1000.0f;

        vertex_buffer_data[9*i+3] = 0.0f;
        vertex_buffer_data[9*i+4] = 10000.0f;
        vertex_buffer_data[9*i+5] = 1000.0f;

        vertex_buffer_data[9*i+6] = 0.0f;
        vertex_buffer_data[9*i+7] = 10000.0f;
        vertex_buffer_data[9*i+8] = -1000.0f;   
        

    
    //  for(i=0;i<10;i++)
    //  {
    //     -5.0f,-5.0f,-5.0f, // triangle 5 : begin
    //     -5.0f,-5.0f, 5.0f,
    //     -5.0f, 5.0f, 5.0f, // triangle 5 : end
    //     5.0f, 5.0f,-5.0f, // triangle 2 : begin
    //     -5.0f,-5.0f,-5.0f,
    //     -5.0f, 5.0f,-5.0f, // triangle 2 : end
    //     5.0f,-5.0f, 5.0f,
    //     -5.0f,-5.0f,-5.0f,
    //     5.0f,-5.0f,-5.0f,
    //     5.0f, 5.0f,-5.0f,
    //     5.0f,-5.0f,-5.0f,
    //     -5.0f,-5.0f,-5.0f,
    //     -5.0f,-5.0f,-5.0f,
    //     -5.0f, 5.0f, 5.0f,
    //     -5.0f, 5.0f,-5.0f,
    //     5.0f,-5.0f, 5.0f,
    //     -5.0f,-5.0f, 5.0f,
    //     -5.0f,-5.0f,-5.0f,
    //     -5.0f, 5.0f, 5.0f,
    //     -5.0f,-5.0f, 5.0f,
    //     5.0f,-5.0f, 5.0f,
    //     5.0f, 5.0f, 5.0f,
    //     5.0f,-5.0f,-5.0f,
    //     5.0f, 5.0f,-5.0f,
    //     5.0f,-5.0f,-5.0f,
    //     5.0f, 5.0f, 5.0f,
    //     5.0f,-5.0f, 5.0f,
    //     5.0f, 5.0f, 5.0f,
    //     5.0f, 5.0f,-5.0f,
    //     -5.0f, 5.0f,-5.0f,
    //     5.0f, 5.0f, 5.0f,
    //     -5.0f, 5.0f,-5.0f,
    //     -5.0f, 5.0f, 5.0f,
    //     5.0f, 5.0f, 5.0f,
    //     -5.0f, 5.0f, 5.0f,
    //     5.0f,-5.0f, 5.0f
    // };

    this->object = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, color, GL_FILL);
}

void Cloud::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Cloud::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Cloud::tick() {
   this->rotation = -10.15165021;
  // this->position.x -= speed;
   // this->position.y -= speed;
}

