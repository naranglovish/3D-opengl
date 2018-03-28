#include "island.h"
#include "main.h"

Island::Island(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y,z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    int i;
    float vertex_buffer_data[70*361*9];
    
   for(int j=0;j<70;j++)
   { 
        for(i=j*360;i<(j+1)*360;i++)
        {
            vertex_buffer_data[9*i] = 0.0f;
            vertex_buffer_data[9*i+1] = j;
            vertex_buffer_data[9*i+2] = 0.0f;

            vertex_buffer_data[9*i+3] = (900-10*j)*cos((3.1457*i/180));
            vertex_buffer_data[9*i+5] = (1200-10*j)*sin(3.1457*i/180);
            vertex_buffer_data[9*i+4] = j;

            vertex_buffer_data[9*i+6] = (900-10*j)*cos(3.1457*(i+1)/180);
            vertex_buffer_data[9*i+8] = (1200-10*j)*sin(3.1457*(i+1)/180);
            vertex_buffer_data[9*i+7] = j;
        }
    }



 
    this->object = create3DObject(GL_TRIANGLES, 70*360*3, vertex_buffer_data, color, GL_FILL);

}

void Island::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
//    draw3DObject(this->object1);

}

void Island::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}


bounding_box_t Island::bounding_box() {
    float x = this->position.x, y = this->position.y, z=this->position.z;
    bounding_box_t bbox = { x,y,z,40,550,40};
    return bbox;
}

void Island::tick() {
 // speed=speed+1;
 // this->position.x = x + 200*cos(speed*M_PI/180.0f); 
 // this->position.z = z + 200*sin(speed*M_PI/180.0f);
 // if(speed==360)
 //    speed=1;
}

