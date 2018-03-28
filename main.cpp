#include "main.h"
#include "timer.h"
#include "ball.h"
#include "flag.h"
#include "water.h"
#include "cloud.h"
#include "rock.h"
#include "pryamid.h"
#include "coin.h"
#include "enemy.h"
#include "booster.h"
#include "enemy1.h"
#include "canon.h"
#include "monster.h"
#include "monster1.h"
#include "gifts.h"
#include "island.h"
#include "person.h"
#include "leg.h"



using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;
int flag=0,h=0,booster_flag=0,count=1,fireballs=0,monster_time_count=0;
float x,y,z,cam_x,cam_y,cam_z,angle[51];
int prev_flag=0,island_flag=0,Monster_Health=100,Player_Health=100,score=0,string1,wind_count=0;
char str[100];
double xpos=0,prev_xpos=0;
bool right_button=false;

/**************************
* Customizable functions *
**************************/
Person person;
Leg leg;
Ball ball1,ball2;
Monster monster;
Monster1 monster1;
Island island; 
Gifts gifts[25];
Pryamid pryamid[200];
Enemy enemy[200];
Coin coin[200];
Flag flag1;
Water water1;
Cloud cloud1; 
Rock rock[1000];
Enemy1 enemy1[25];
Booster booster[100];
Canon canon[51]; 
Canon monster_ball;
Gifts gift1;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0,previos_x,previos_z;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

 //  printf("%f %f %f\n",cam_x,cam_y,cam_z );
  //  printf("%f %f %f\n",x,y,z );
    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye (cam_x,cam_y,cam_z);//printf("%f\n",y);   
     glm::vec3 target (x,y,z);
     glm::vec3 up (0, 1, 0);    
    // glm::vec3 eye (350,150,0);
    // glm::vec3 target (x,0, 0);
    //  glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    water1.draw(VP);
  if(island_flag==0)
   { 
    for(int i=0;i<1000;i++)
        rock[i].draw(VP);
    
    for(int k=0;k<100;k++)
    {
        booster[k].draw(VP);
    }
    
    for(int j=0;j<200;j++)
    {
        pryamid[j].draw(VP);
        coin[j].draw(VP);
        enemy[j].draw(VP);
       
    }
    for(int h=0;h<25;h++)
    {
        enemy1[h].draw(VP);
        gifts[h].draw(VP);
    }

    for(int h=0;h<50;h++)
        canon[h].draw(VP);
    }
    monster.draw(VP);
    monster1.draw(VP);
    monster_ball.draw(VP);
    gift1.draw(VP);
    
    ball1.draw(VP);
    island.draw(VP);
    person.draw(VP);
    leg.draw(VP);

  //  ball2.draw(VP);

   // flag1.draw(VP);
   // cloud1.draw(VP);  

}


void change_eye_0(float theta)
{
    if(island_flag==0)
    {
        cam_x = ball1.position.x+550*cos(theta);
        cam_y=250;
        cam_z = ball1.position.z-550*sin(theta);
    }
    else
    {
        cam_x = person.position.x+650*cos(theta);
        cam_y=550;
        cam_z = person.position.z-650*sin(theta);
    }   
}
void change_target_0(float theta)
{
    if(island_flag==0)
    {
        x = ball1.position.x;
        z = ball1.position.z;
        y=250;
    } 
    else{
      x = person.position.x;
        z = person.position.z;
        y=250;  
    }   //y=0;    
}

void change_eye_1(float theta)
{
        cam_x = ball1.position.x;
        cam_y = 2000;
        cam_z = ball1.position.z;
}
void change_target_1(float theta)
{
        x = ball1.position.x+1;
        y = ball1.position.y; 
        z = ball1.position.z;   
}
void change_eye_2(float theta)
{
        cam_x = ball1.position.x-60*cos(theta);
        cam_y = ball1.position.y+150;
        cam_z = ball1.position.z+60*sin(theta);
}
void change_target_2(float theta)
{
        x = ball1.position.x-80*cos(theta);
        y = ball1.position.y+150;
        z = ball1.position.z+80*sin(theta);       
}

void change_eye_3(float theta)
{
        cam_x = ball1.position.x+300;
        cam_y = 200;
        cam_z = ball1.position.z;
    
}
void change_target_3(float theta)
{
        x = ball1.position.x;
        y = ball1.position.y;
        z = ball1.position.z;
}


void fourviews()
{
    float theta = ball1.rotation*M_PI/180.0f;
    if(h==0)
    {
        change_eye_0(theta);
        change_target_0(theta);
    }
    if(h==1)
    {
        cam_y=200;
    }
    if(h==2)
    {
        change_eye_1(theta);
        change_target_1(theta);    
    }
    if(h==3)
    {
        change_eye_2(theta);
        change_target_2(theta);  //change_eye_3(theta);
        //change_target_3(theta);   
    }
    if(h==4)
    {

      //  change_eye_3(theta);
      change_target_3(theta);   
    }
}
void camera()
{
    h=(h+1)%5;
    fourviews();

}


void shoot_monster_canon(float x,float z)
{
        float t = sqrt((x-monster_ball.position.x)*(x-monster_ball.position.x)+(z-monster_ball.position.z)*(z-monster_ball.position.z));
        if(t<10)
        {
            monster_ball.set_position(0,0,0);
        }
        monster_ball.position.x+=50/8*(x-monster_ball.position.x)/t;
        monster_ball.position.z+=50/8*(z-monster_ball.position.z)/t;

//printf("hshsh\n");
}
void wind()
{
    if(island_flag==0)
    {
    wind_count++;
    float theta=ball1.rotation;
  //  printf("%f\n",theta);
    if(wind_count>1000 && wind_count<1030)
    {
        if(theta<90 && theta>=0)
        {
           ball1.set_position(ball1.position.x-30*cos(theta*M_PI/180.0f),ball1.position.y,ball1.position.z-25*sin(theta*M_PI/180.0f));
        } 
        if(theta<0 && theta>-90)
        {
           ball1.set_position(ball1.position.x-30*cos(theta*M_PI/180.0f),ball1.position.y,ball1.position.z-25*sin(theta*M_PI/180.0f));
        }
    }
    if(wind_count==1030)
        wind_count=0;
    }
}
void fire()
{
    canon[fireballs].canon_jump_flag=1;
    fireballs++;
    angle[fireballs]=ball1.rotation;
        
}
void shoot_canon()
{
    int i;
    for(i=0;i<fireballs;i++)
    {
        canon[i].position.x-=10*cos(angle[i+1]*M_PI/180.0f);
        canon[i].position.z+=10*sin(angle[i+1]*M_PI/180.0f);
        // if(canon[i].canon_jump_flag==1)
        // {
        //     canon[i].speedy=20;
        //     canon[i].acc_y=0.5;
        //     canon[i].Jump();
        //     canon[i].canon_jump_flag=0;
        // }
        // canon[i].Jump();
    }
    for(i=fireballs;i<50;i++)
    {
        canon[i].position.x=ball1.position.x;
        canon[i].position.z=ball1.position.z;
        canon[i].position.y=ball1.position.y;
    }
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int jump = glfwGetKey(window, GLFW_KEY_SPACE);
    
    //printf("%d\n",jump);
    float theta=ball1.rotation;
   // printf("%f\n",ball1.rotation );
    if (up) {
        if(island_flag==0)
        {    
            if(booster_flag==1)
            ball1.set_position(ball1.position.x-50*cos(theta*M_PI/180.0f),ball1.position.y,ball1.position.z+50*sin(theta*M_PI/180.0f));
            else
            ball1.set_position(ball1.position.x-10*cos(theta*M_PI/180.0f),ball1.position.y,ball1.position.z+10*sin(theta*M_PI/180.0f));

            ball1.tick();
        }
        else
        {
            float tht=leg.rotation;
            leg.set_position(leg.position.x-10*cos(tht*M_PI/180.0f),leg.position.y,leg.position.z+10*sin(tht*M_PI/180.0f));
            person.set_position(person.position.x-10*cos(tht*M_PI/180.0f),person.position.y,person.position.z+10*sin(tht*M_PI/180.0f));

        }
     //  printf("%f %f %f\n", ball1.position.x,ball1.position.y,ball1.position.z);
        // printf("%f\n", ball1.position.y);       
       // printf("%f\n",flag1.position.y);

    }
    if (down) {
        if(island_flag==0)
        {
            ball1.set_position(ball1.position.x+10*cos(theta*M_PI/180.0f),ball1.position.y,ball1.position.z-10*sin(theta*M_PI/180.0f));
            ball1.tick();
        }
        else
        {
            float tht=leg.rotation;
            leg.set_position(leg.position.x+10*cos(tht*M_PI/180.0f),leg.position.y,leg.position.z-10*sin(tht*M_PI/180.0f));
            person.set_position(person.position.x+10*cos(tht*M_PI/180.0f),person.position.y,person.position.z-10*sin(tht*M_PI/180.0f));            
              //  flag1.set_position(0,flag1.position.y+10);
        }
    }
    if(left)
    {
        if(island_flag==0)
        ball1.rotation+=1;
        else
        {
        leg.rotation+=1;
        person.rotation+=1;}
    }
    if(right)
    {
        if(island_flag==0)
        ball1.rotation-=1;
        else
        {
        leg.rotation-=1;
        person.rotation-=1;}

    }
    if(jump && ball1.position.y<5 && island_flag==0)
    {
        ball1.speedy=40;
        ball1.acc_y=2;
        ball1.jump_flag=1;
        ball1.Jump();
    }
}

void tick_elements() {
    string1 = sprintf(str,"BOAT HEALTH: %d  SCORE: %d  MONSTER HEALTH: %d",Player_Health,score,Monster_Health);
    glfwSetWindowTitle(window, str);

   // printf("%d\n",prev_flag);
    if(ball1.position.x<-13100 && ball1.position.x>-14900 && ball1.position.z<15200 && ball1.position.z>12800 && prev_flag==0)
    {
        person.set_position(ball1.position.x,70,ball1.position.z);
        leg.set_position(ball1.position.x,70,ball1.position.z);
        ball1.set_position(-1000,-10000,-1000000);
        island_flag=1; 
        prev_flag=1;
       // printf("%f\n",ball1.position.y);  // printf("asa\n");  //  prev_flag=1;
    }
    if((person.position.x>-13100 || person.position.x <-14900 || person.position.z>15200 || person.position.z<12800) && prev_flag==1)
    {
     //   printf("%f\n",ball1.position.y);
        ball1.set_position(person.position.x,5,person.position.z);
        person.set_position(-1000,-1000,-1000);
        leg.set_position(-1000,-1000,-1000);
        prev_flag=0;
        island_flag=0;
    }
   if(person.position.x<-13100 && person.position.x>-14900 && person.position.z<15200 && person.position.z>12800 && island_flag==1) 
   {
    if(detect_collision(person.bounding_box(),gift1.bounding_box()))
    {
        gift1.set_position(-1000,-1000,-10000000000);
        Player_Health+=20;
    }
   }
    if(ball1.position.x<-15000)
    {
        if(flag==0)
        {
            monster.set_position(ball1.position.x-5000*cos(ball1.rotation*M_PI/180.0f),monster.position.y,ball1.position.z+5000*sin(ball1.rotation*M_PI/180.0f));
            monster1.set_position(ball1.position.x-5000*cos(ball1.rotation*M_PI/180.0f),monster1.position.y,ball1.position.z+5000*sin(ball1.rotation*M_PI/180.0f));
            flag=1;
            monster_ball.set_position(ball1.position.x-5000*cos(ball1.rotation*M_PI/180.0f),0,ball1.position.z+5000*sin(ball1.rotation*M_PI/180.0f));
           // printf("we ara herejajajajajjajajajajaj\n");
        }

        if(monster.position.y<0)
            monster.tick();
        if(monster1.position.y<0)
            monster1.tick();

        if(monster.position.y>=0)
        {
            monster_time_count++;
           // printf("%d \n", monster_time_count);
            if(monster_time_count==500)
            {
                previos_x=ball1.position.x;
                previos_z=ball1.position.z;
                monster_ball.set_position(monster1.position.x,0,monster1.position.z);
                shoot_monster_canon(previos_x,previos_z);
                monster_time_count=0;
            }
        }
       //printf("%f\n",monster.position.y );

    }
    
    for(int k=0;k<25;k++)
    {
        enemy1[k].tick(ball1.position.x,ball1.position.z);
        gifts[k].tick();
    }
    gift1.tick();
    water1.tick();  
    ball1.Jump();   
    move_enemy();
    // /leg.tick();
    wind();

    for(int j=0;j<200;j++)
    {
        coin[j].tick();
        enemy[j].tick(pryamid[j].position.x,pryamid[j].position.z);
    //    booster[j].tick();
    }
    for(int k=0;k<100;k++)
    {
        booster[k].tick();
    }
    camera_rotation_angle =0;
    for(int j=0;j<1000;j++)
    {
        if(detect_collision(ball1.bounding_box(),rock[j].bounding_box()))
        {
            Player_Health-=5;  
            rock[j].set_position(0,-12131,12121);
        }
    }
    for(int i=0;i<200;i++)
    {
        if(detect_collision(ball1.bounding_box(),coin[i].bounding_box()))
        {
            coin[i].set_position(0,-1000000,0);
            score+=50;
        }
        if(detect_collision(ball1.bounding_box(),enemy[i].bounding_box()))
        {
            if(ball1.position.y-enemy[i].position.y>230)
                Player_Health+=5;
            else
                Player_Health-=5;
            enemy[i].set_position(0,-1000000,0);
          //  printf("%d\n",Player_Health);
        }

    }
    for(int i=0;i<100;i++)
    {
        if(detect_collision(ball1.bounding_box(),booster[i].bounding_box()))
        {
            booster[i].set_position(0,-1000000,0);
            booster_count();
            count=0;
        }
    }
    for(int i=0;i<25;i++)
    {
        if(detect_collision(ball1.bounding_box(),enemy1[i].bounding_box()))
        {
            enemy1[i].set_position(0,-1000000,0);
            Player_Health-=15;
           // printf("%d\n",Player_Health );
        }
        if(detect_collision(ball1.bounding_box(),gifts[i].bounding_box()))
        {
            gifts[i].set_position(-100292929,-1000000,0);
            Player_Health+=15;
         //   printf("%d\n",Player_Health );
        }
        
    }
    
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<50;j++)
        {
            if(detect_collision(canon[j].bounding_box(),enemy1[i].bounding_box()))
            { 
                gifts[i].set_position(enemy1[i].position.x,0,enemy1[i].position.z);
                enemy1[i].set_position(0,-1000000,0);
                canon[j].set_position(0,-2000000,0);
                //Player_Health+=15;
           //     printf("%d\n",Player_Health );
            }
        }
    }

    for(int j=0;j<50;j++)
    {
        if(detect_collision(canon[j].bounding_box(),monster.bounding_box()))
        {
            //enemy1[i].set_position(0,-1000000,0);
            canon[j].set_position(0,-2000000,0);
            Monster_Health-=20;
            //printf("%d\n",Player_Health );
        }
        if(Monster_Health==0)
        {
            monster1.set_position(0,-10000023232320,0);
            monster.set_position(0,-10000023232320,0);
        }
    }
    if(detect_collision(ball1.bounding_box(),monster_ball.bounding_box()))
    {
        Player_Health-=20;
        monster_ball.set_position(0,0,0);
    }
}     

void booster_count()
{
    if(count==0)
    {
        booster_flag=1;
    }
    count++;
    if(count==150)
    {
        booster_flag=0;
    }
 //   printf("%d %d\n",booster_flag,count);
}

void move_enemy()
{
    for(int i=0;i<25;i++){
        float t = sqrt((ball1.position.x-enemy1[i].position.x)*(ball1.position.x-enemy1[i].position.x)+(ball1.position.z-enemy1[i].position.z)*(ball1.position.z-enemy1[i].position.z));
        enemy1[i].position.x+=20/8*(ball1.position.x-enemy1[i].position.x)/t;
        enemy1[i].position.z+=20/8*(ball1.position.z-enemy1[i].position.z)/t;
    }

}
void drag()
{
    if(right_button==true)
    {
        helicopter1();
    }

}
void helicopter(float yoffset)
{
    if(h==4)
    {
       // printf("wada\n");
        cam_x = cam_x+yoffset*15;
        cam_y = 200;
        cam_z = cam_z;
    }
}
void helicopter1()
{
    if(h==4)
    {
        double ypos;
        glfwGetCursorPos(window,&xpos,&ypos);

        if(xpos-prev_xpos>0)
        {
            cam_x = cam_x;
            cam_y = 200;
            cam_z = cam_z-15;
            prev_xpos=xpos;       
        }
        else if(xpos-prev_xpos<0)
        {
            cam_x = cam_x;
            cam_y = 200;
            cam_z = cam_z+15;
            prev_xpos=xpos;      
        }
    }
}


void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    ball1       = Ball(350,5 ,0, COLOR_BOAT2);
    ball2       = Ball(100,0 ,0, COLOR_GREEN);
    //flag1       =Flag(650,0,COLOR_RED);
    water1      = Water(0,0,COLOR_WATER);
    
    monster     = Monster(-40000,-1040,0,COLOR_ENEMY);
    monster1     = Monster1(-40000,-1040,0,COLOR_BOAT2);
    //monster_ball = Canon(100,0,0,COLOR_RED);
    island      = Island(-14000,0,14000,COLOR_SAND);
    person      = Person(0,-1000,0,COLOR_RED);
    leg      = Leg(0,-1000,0,COLOR_RED);
    gift1    = Gifts(-14000,70,14000,COLOR_COIN);

   monster_ball = Canon(monster.position.x,-600,monster.position.z,COLOR_RED);
    
    for(int j=0;j<25;j++)
    {
        gifts[j]=Gifts(-1000,-19029,0,COLOR_GIFT);
    }

    for(int j=0;j<200;j++)
    {

        float a,b;
        a=-rand()%50000;
        b=rand()%50000-25000;   
        pryamid[j]  = Pryamid(a,0,b,COLOR_BOAT1);
        coin[j]     = Coin(a,400,b,COLOR_COIN);
        enemy[j]    = Enemy(a,0,b,COLOR_ENEMY);
    }

    for(int i=0;i<1000;i++)
    {
        float a,b;
        a=-rand()%100000;
        b=rand()%100000-50000;
        rock[i]=Rock(a,0,b,COLOR_ROCK);
    }
    for(int i=0;i<25;i++)
    {
        float a,b;
        a=-rand()%50000;
        b=rand()%20000-10000;
        enemy1[i]=Enemy1(a,0,b,COLOR_ENEMY);
    }

    for(int k=0;k<100;k++)
    {
        float a,b;
        a=-rand()%50000;
        b=rand()%50000-25000;
        booster[k]=Booster(a,0,b,COLOR_BOOSTER);
    }
    for(int h=0;h<50;h++)
    canon[h] = Canon(650,5,0,COLOR_CANON);




   // cloud1      =Cloud(-300,0,COLOR_CLOUD);
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 1080;
    int height = 1080;
   // printf("%f\n",ball1.position.y );

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            fourviews();
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
            booster_count();
            shoot_canon();
            shoot_monster_canon(previos_x,previos_z);
            if(right_button)
            drag();
   
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.length + b.length)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height)) &&
           (abs(a.z - b.z) * 2 < (a.breath + b.breath));
}

void reset_screen() {
    Matrices.projection = glm::perspective(1.0f, 1.0f, 1.0f, 20000000.0f);
}
