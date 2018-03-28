#include "ball.h"
#include "main.h"
int ti=1;
Ball::Ball(float x, float y,float z, color_t color)  {
    this->position = glm::vec3(x, y,z);
    this->rotation = 0;
   //this->rotaion1 = 0;
   // this->rotaion2 = 0;

    speed = 1;
    speedy=0;
    acc_y=0;
    jump_flag=0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
   static const GLfloat vertex_buffer_data[]=
    {
        // 50.0f,30.0f,-30.0f,
        // 50.0f,30.0f,30.f,
        // -50,30,-30.0f,   
        //  50.0f, 30.0f,30.0f,
        // -50, 30,-30.0f,
        //  -50, 30,30.0f,  
       80.0f, 0.0f,-30.0f,
        80, 0, 30.0f,
        -80,0,-30.0f,   
         80.0f, 0.0f, 30.0f,
         -80,0,-30.0f,
         -80,0,30,
         80,30 ,-30,
        80,0,-30,
        -80,0,-30,
        80,30,-30,
        -80,0,-30,
        -80,30,-30,
        80,30,30,
        80,0,30,
        -80,0,30,
        80,30,30,
        -80,0,30,
        -80,30,30,
        80,30,-30,
        80,30,30,
        100,30,0,
        -80,30,-30,
        -80,30,30,
        -100,30,0,
        80,0,-30,
        80,0,30,
        100,0,0,
        -80,0,-30,
        -80,0,30,
        -100,0,0,   
        80,30,-30,
        100,0,0,
        100,30,0,
        80,30,-30,
        80,0,-30,
        100,0,0,
        80,30,30,
        100,0,0,
        100,30,0,
        80,30,30,
        80,0,30,
        100,0,0,
        -80,30,-30,
        -100,0,0,
        -100,30,0,
        -80,30,-30,
        -80,0,-30,
        -100,0,0,
        -80,30,30,
        -100,0,0,
        -100,30,0,
        -80,30,30,
        -80,0,30,
        -100,0,0,  
         30,-10,2.5,
         30,-10,2.5,
         27.5,100,0,
         30,-10,2.5,
         30,-10,-2.5,
         27.5,100,0,
         30,-10,-2.5,
         25,-10,-2.5,
         27.5,100,0,
         25,-10,-2.5,
         25,-10, 2.5,
         27.5,100,0,
         27.5,85,0,
         27.5, 45, 0,
         27.5, 45,-40,
         27.5,85,0,
         27.5,55,0,
         27.5,55,30,


        };      
        
        
       

    
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

    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data+6*3, COLOR_GREEN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 12+24, vertex_buffer_data+6*3+12*3, COLOR_RED, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 18, vertex_buffer_data+6*3+12*3+36*3, COLOR_BLUE, GL_FILL);

}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    //glm::mat4 rotate1    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    //glm::mat4 rotate2    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}

void Ball::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Ball::tick() {
if(ti%10==0)
    speed=-speed;
   // printf("%f\n",speed);
this->position.y+=speed;
ti=ti+1;
}

void Ball::Jump()
{
    if(jump_flag==1)
    {
        this->position.y+=speedy;
        speedy=speedy-acc_y;
    }
    if(this->position.y<5)
    {
        jump_flag=0;
        this->position.y=0;   
    }
}

bounding_box_t Ball::bounding_box() {
    float x = this->position.x, y = this->position.y, z=this->position.z;
    bounding_box_t bbox = { x,y,z,160,30,60};
    return bbox;
}

