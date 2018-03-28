#include "flag.h"
#include "main.h"

Flag::Flag(float x, float y, color_t color) {
    this->position = glm::vec3(x, y,0);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.

    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float vertex_buffer_data[30*9];
    int i=0;
    	
    	vertex_buffer_data[9*i] = 50.0f;
        vertex_buffer_data[9*i+1] = 30.0f;
        vertex_buffer_data[9*i+2] = -30.0f;

        vertex_buffer_data[9*i+3] = 50;
        vertex_buffer_data[9*i+4] = 30;
        vertex_buffer_data[9*i+5] = 30.0f;

        vertex_buffer_data[9*i+6] = 70;
        vertex_buffer_data[9*i+7] = 30;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;
        
        vertex_buffer_data[9*i] = -50.0f;
        vertex_buffer_data[9*i+1] = 30.0f;
        vertex_buffer_data[9*i+2] = -30.0f;

        vertex_buffer_data[9*i+3] = -50;
        vertex_buffer_data[9*i+4] = 30;
        vertex_buffer_data[9*i+5] = 30.0f;

        vertex_buffer_data[9*i+6] = -70;
        vertex_buffer_data[9*i+7] = 30;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;
        
        vertex_buffer_data[9*i] = 50.0f;
        vertex_buffer_data[9*i+1] = 0.0f;
        vertex_buffer_data[9*i+2] = -30.0f;

        vertex_buffer_data[9*i+3] = 50;
        vertex_buffer_data[9*i+4] = 0;
        vertex_buffer_data[9*i+5] = 30.0f;

        vertex_buffer_data[9*i+6] = 70;
        vertex_buffer_data[9*i+7] = 0;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;
        
        vertex_buffer_data[9*i] = -50.0f;
        vertex_buffer_data[9*i+1] = 0.0f;
        vertex_buffer_data[9*i+2] = -30.0f;

        vertex_buffer_data[9*i+3] = -50;
        vertex_buffer_data[9*i+4] = 0;
        vertex_buffer_data[9*i+5] = 30.0f;

        vertex_buffer_data[9*i+6] = -70;
        vertex_buffer_data[9*i+7] = 0;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;

        



        vertex_buffer_data[9*i] = 50.0f;
        vertex_buffer_data[9*i+1] = 30.0f;
        vertex_buffer_data[9*i+2] = -30.0f;

        vertex_buffer_data[9*i+3] = 70;
        vertex_buffer_data[9*i+4] = 0;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = 70;
        vertex_buffer_data[9*i+7] = 30;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;
        
        vertex_buffer_data[9*i] = 50.0f;
        vertex_buffer_data[9*i+1] = 30.0f;
        vertex_buffer_data[9*i+2] = -30.0f;

        vertex_buffer_data[9*i+3] = 50;
        vertex_buffer_data[9*i+4] = 0;
        vertex_buffer_data[9*i+5] = -30.0f;

        vertex_buffer_data[9*i+6] = 70;
        vertex_buffer_data[9*i+7] = 0;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;
        
        vertex_buffer_data[9*i] = 50.0f;
        vertex_buffer_data[9*i+1] = 30.0f;
        vertex_buffer_data[9*i+2] = 30.0f;

        vertex_buffer_data[9*i+3] = 70;
        vertex_buffer_data[9*i+4] = 0;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = 70;
        vertex_buffer_data[9*i+7] = 30;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;
        
        vertex_buffer_data[9*i] = 50.0f;
        vertex_buffer_data[9*i+1] = 30.0f;
        vertex_buffer_data[9*i+2] = 30.0f;

        vertex_buffer_data[9*i+3] = 50;
        vertex_buffer_data[9*i+4] = 0;
        vertex_buffer_data[9*i+5] = 30.0f;

        vertex_buffer_data[9*i+6] = 70;
        vertex_buffer_data[9*i+7] = 0;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;
        
        



        vertex_buffer_data[9*i] = -50.0f;
        vertex_buffer_data[9*i+1] = 30.0f;
        vertex_buffer_data[9*i+2] = -30.0f;

        vertex_buffer_data[9*i+3] = -70;
        vertex_buffer_data[9*i+4] = 0;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = -70;
        vertex_buffer_data[9*i+7] = 30;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;
        
        vertex_buffer_data[9*i] = -50.0f;
        vertex_buffer_data[9*i+1] = 30.0f;
        vertex_buffer_data[9*i+2] = -30.0f;

        vertex_buffer_data[9*i+3] = -50;
        vertex_buffer_data[9*i+4] = 0;
        vertex_buffer_data[9*i+5] = -30.0f;

        vertex_buffer_data[9*i+6] = -70;
        vertex_buffer_data[9*i+7] = 0;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;
        
        vertex_buffer_data[9*i] = -50.0f;
        vertex_buffer_data[9*i+1] = 30.0f;
        vertex_buffer_data[9*i+2] = 30.0f;

        vertex_buffer_data[9*i+3] = -70;
        vertex_buffer_data[9*i+4] = 0;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = -70;
        vertex_buffer_data[9*i+7] = 30;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;
        
        vertex_buffer_data[9*i] = -50.0f;
        vertex_buffer_data[9*i+1] = 30.0f;
        vertex_buffer_data[9*i+2] = 30.0f;

        vertex_buffer_data[9*i+3] = -50;
        vertex_buffer_data[9*i+4] = 0;
        vertex_buffer_data[9*i+5] = 30.0f;

        vertex_buffer_data[9*i+6] = -70;
        vertex_buffer_data[9*i+7] = 0;
        vertex_buffer_data[9*i+8] = 0.0f;   

        i++;
        




    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);
}

void Flag::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Flag::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Flag::tick() {
  // this->rotation += 0;
  // this->position.x -= speed;
   // this->position.y -= speed;
}

