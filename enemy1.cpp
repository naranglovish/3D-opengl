#include "enemy1.h"
#include "main.h"

Enemy1::Enemy1(float x, float y,float z, color_t color) {
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
        vertex_buffer_data[9*i+7] = 70.0f;
        vertex_buffer_data[9*i+8] = -40.0f;

        i++;

        
        vertex_buffer_data[9*i] =   0.0f;
        vertex_buffer_data[9*i+1] = 160.0f;
        vertex_buffer_data[9*i+2] = 40.0f;

        vertex_buffer_data[9*i+3] = 0.0f;
        vertex_buffer_data[9*i+4] = 70.0f;
        vertex_buffer_data[9*i+5] = 40.0f;

        vertex_buffer_data[9*i+6] = 0.0f;
        vertex_buffer_data[9*i+7] = 70.0f;
        vertex_buffer_data[9*i+8] = -40.0f;
     
        i++;

        vertex_buffer_data[9*i] =   0.0f;
        vertex_buffer_data[9*i+1] = 70.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = 0.0f;
        vertex_buffer_data[9*i+4] = 0.0f;
        vertex_buffer_data[9*i+5] = 40.0f;

        vertex_buffer_data[9*i+6] = 0.0f;
        vertex_buffer_data[9*i+7] = 0.0f;
        vertex_buffer_data[9*i+8] = 45.0f;
        
        i++;

        vertex_buffer_data[9*i] =   0.0f;
        vertex_buffer_data[9*i+1] = 70.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = 0.0f;
        vertex_buffer_data[9*i+4] = 0.0f;
        vertex_buffer_data[9*i+5] = -40.0f;

        vertex_buffer_data[9*i+6] = 0.0f;
        vertex_buffer_data[9*i+7] = 0.0f;
        vertex_buffer_data[9*i+8] = -45.0f;
     

        i++;

        vertex_buffer_data[9*i] =   0.0f;
        vertex_buffer_data[9*i+1] = 130.0f;
        vertex_buffer_data[9*i+2] = 40.0f;

        vertex_buffer_data[9*i+3] = 0.0f;
        vertex_buffer_data[9*i+4] = 90.0f;
        vertex_buffer_data[9*i+5] = 60.0f;

        vertex_buffer_data[9*i+6] = 0.0f;
        vertex_buffer_data[9*i+7] = 90.0f;
        vertex_buffer_data[9*i+8] = 65.0f;
        
        i++;

        vertex_buffer_data[9*i] =   0.0f;
        vertex_buffer_data[9*i+1] = 130.0f;
        vertex_buffer_data[9*i+2] = -40.0f;

        vertex_buffer_data[9*i+3] = 0.0f;
        vertex_buffer_data[9*i+4] = 90.0f;
        vertex_buffer_data[9*i+5] = -60.0f;

        vertex_buffer_data[9*i+6] = 0.0f;
        vertex_buffer_data[9*i+7] = 90.0f;
        vertex_buffer_data[9*i+8] = -65.0f;
     





        this->object = create3DObject(GL_TRIANGLES, 360*3, vertex_buffer_data, COLOR_COIN, GL_FILL);
        this->object1 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data+(360*9), COLOR_BOAT2, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data+(360*9)+4*9, COLOR_COIN, GL_FILL);


}

void Enemy1::draw(glm::mat4 VP) {
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
    draw3DObject(this->object2);

}

void Enemy1::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}


bounding_box_t Enemy1::bounding_box() {
    float x = this->position.x, y = this->position.y, z=this->position.z;
    bounding_box_t bbox = { x,y,z,40,200,40};
    return bbox;
}

void Enemy1::tick(float x,float z) {
//float theta=arctan()
//    speed=speed+1;
 //this->position.x+=;
 //mathis->position.z+=;    
 //if(speed==360)
   // speed=1;
}

