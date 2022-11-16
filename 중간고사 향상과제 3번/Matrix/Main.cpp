<<<<<<<< HEAD:ì¤‘ê°„ê³ ì‚¬ í–¥ìƒê³¼ì œ 3ë²ˆ/Matrix/Main.cpp
#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>

#include "MuSoenMath.h"

#pragma comment(lib, "OpenGL32")
#define PI 3.14

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;

float radians(float a)
{
    float radian;

    radian = a * PI / 180;

    return radian;
}

struct Vertex
{
    Math::vec1x3 pos;
    float r, g, b, a;
};

struct Transform
{
    Math::mat3 translate;
    Math::mat3 scale;
    Math::mat3 rotation;
};


Vertex star[5];             // static mesh
Vertex transformedStar[5];  //È­¸é¿¡ ±×¸± ¿À¸Á¼º
Vertex circle[360];             // static mesh 
Vertex transformedCircle[360];  // È­¸é¿¡ ±×·ÁÁú ¿ø

Transform transform;  //world Çà·ÄÀÌ µÉ transform

//<¹®Á¦>////////Àü¿ªº¯¼ö ¾²´Â°÷////////////////////////////////////////////////////////////

static float scaleValue = 0.7f;
static bool scale = true;

static float rotateValue = 1.0f;

static Math::mat3 translateM(
    1, 0, 0,
    0, 1, 0,
    0.001/60.f, 0, 1
);

//////////////////////////////////////////////////////////////////////////////////////////

void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();


    //object»ý¼ººÎ
     /// Star(¿À¸Á¼º) »ý¼º
    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {
        star[i].pos = Math::vec1x3(-sin(radians((float)theta)) * 0.5f, cos(radians((float)theta)) * 0.5f, 1.f);

        star[i].r = 0.3f;
        star[i].g = 0.0f;
        star[i].b = theta / 360.0f;
        star[i].a = 0.7f;

        transformedStar[i] = star[i];

        i++;
    }

    // ¿ø »ý¼º
    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].pos = Math::vec1x3(-sin(radians((float)theta)) * 0.5f, cos(radians((float)theta)) * 0.5f, 1.f);

        circle[theta].r = 0.3f;
        circle[theta].g = 0.0f;
        circle[theta].b = (float)theta / 360.0f;
        circle[theta].a = 0.7f;

        transformedCircle[theta] = circle[theta];
    }

    //Æ®·£½ºÆû ÃÊ±âÈ­ (±âº»Çü Á¦°ø)
    transform.translate = Math::mat3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
    transform.rotation = Math::mat3(
        cos(0.0f), -sin(0.0f), 0,
        sin(0.0f), cos(0.0f), 0,
        0, 0, 1
    );
    transform.scale = Math::mat3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );


}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        //Update·ÎÁ÷
        //<¹®Á¦>//////////////////////////////////////////////////////////////////////////////////

        //1. translate ¸¦ ÇÁ·¹ÀÓ´ç ¿À¸¥ÂÊÀ¸·Î 0.001¾¿ ´©Àû½ÃÄÑ¼­ ¹°Ã¼¸¦ ÀÌµ¿ÇØº¸¼¼¿ä.
        //2. Rotation À» ÇÁ·¹ÀÓ´ç 1µµ¾¿ ´©Àû½ÃÄÑ¼­ ¹°Ã¼¸¦ È¸Àü½ÃÄÑº¸¼¼¿ä.
        //3. ScaleÀº ÃÊ´ç 0.01¾¿ ÃÖ´ë 1.3¹è±îÁö ´Ã¾î³µ´Ù°¡ 0.7¹è±îÁö ÁÙ¾îµéµµ·Ï ¸¸µå½Ã¿À (¹Ýº¹)
        //   (1.3¹è ÀÌ»óÀÌ µÇ¸é ÁÙ¾îµé°í 0.7¹è ÀÌÇÏ°¡ µÇ¸é ´Ù½Ã ´Ã¾î³ª°Ô ¸¸µå½Ã¿À)

        //ÀÌµ¿

        transform.translate = transform.translate * translateM;

        //È¸Àü
        transform.rotation = transform.rotation * Math::mat3(
            cos(radians(rotateValue)), -sin(radians(rotateValue)), 0,
            sin(radians(rotateValue)), cos(radians(rotateValue)), 0,
            0, 0, 1
        );

        //Å©±â Á¶Àý
        if (scale == true) {
            transform.scale = transform.scale + Math::mat3(
                0.01, 0, 0,
                0, 0.01, 0,
                0, 0, 1
            );
            scaleValue += 0.01f;
            if (scaleValue >= 1.3f)
            {
                scale = false;
            }
        }
        else if (scale == false)
        {
            transform.scale = transform.scale + Math::mat3(
                -0.01, 0, 0,
                0, -0.01, 0,
                0, 0, 1
            );
            scaleValue -= 0.01f;
            if (scaleValue <= 0.7f)
            {
                scale = true;
            }
        }


        //////////////////////////////////////////////////////////////////////////////////////////


        for (int i = 0; i < 360; i++)
        {

            transformedCircle[i].pos = transform.translate * transform.rotation * transform.scale * circle[i].pos;
            
        }

        for (int i = 0; i < 5; i++)
        {
            transformedStar[i].pos = transform.translate * transform.rotation * transform.scale * star[i].pos;
        }

        //»ö ÃÊ±âÈ­
        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //¼±µÎ²²
        glLineWidth(7.0f);
        //¿À¸Á¼º ±×¸®±â
        glBegin(GL_LINE_STRIP);

        int a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vector[0][0], transformedStar[a].pos.vector[0][1], 0.0f);
        a = 3;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vector[0][0], transformedStar[a].pos.vector[0][1], 0.0f);
        a = 1;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vector[0][0], transformedStar[a].pos.vector[0][1], 0.0f);
        a = 4;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vector[0][0], transformedStar[a].pos.vector[0][1], 0.0f);
        a = 2;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vector[0][0], transformedStar[a].pos.vector[0][1], 0.0f);

        a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vector[0][0], transformedStar[a].pos.vector[0][1], 0.0f);
        glEnd();

        //¿ø±×¸®±â
        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
            glVertex3f(transformedCircle[theta].pos.vector[0][0], transformedCircle[theta].pos.vector[0][1], 0.0f);
        }
        glEnd();



        //È­¸é ½º¿Ò
        glfwSwapBuffers(window);
        glfwPollEvents();

        //·»´õ½Ã°£ ÃøÁ¤
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        string fps_s = "FPS : " + to_string(fps);
        cout << fps_s << endl;

    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init();
    Update();
    Release();

    exit(EXIT_SUCCESS);
========
#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#pragma comment(lib, "OpenGL32")

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;


struct Vertex
{
    glm::vec3 pos;
    float r, g, b, a;
};

struct Transform
{
    glm::mat3 translate;
    glm::mat3 scale;
    glm::mat3 rotation;
};


Vertex star[5];             // static mesh
Vertex transformedStar[5];  //È­¸é¿¡ ±×¸± ¿À¸Á¼º
Vertex circle[360];             // static mesh 
Vertex transformedCircle[360];  // È­¸é¿¡ ±×·ÁÁú ¿ø

Transform transform;  //world Çà·ÄÀÌ µÉ transform

//<¹®Á¦>////////Àü¿ªº¯¼ö ¾²´Â°÷////////////////////////////////////////////////////////////

static float scaleValue = 0.7f;
static bool scale = true;

static float rotateValue = 1.0f;

static glm::mat3 translateM(
    1, 0, 0,
    0, 1, 0,
    0.001f, 0, 1
);

 //////////////////////////////////////////////////////////////////////////////////////////

void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();


    //object»ý¼ººÎ
     /// Star(¿À¸Á¼º) »ý¼º
    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {

        star[i].pos.x = -glm::sin(glm::radians(theta)) * 0.5f;
        star[i].pos.y = glm::cos(glm::radians(theta)) * 0.5f;
        star[i].pos.z = 1.0f;

        star[i].r = 0.3f;
        star[i].g = 0.0f;
        star[i].b = theta / 360.0f;
        star[i].a = 0.7f;

        transformedStar[i] = star[i];

        i++;
    }

    // ¿ø »ý¼º
    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].pos.x = -glm::sin(glm::radians((float)theta)) * 0.5;
        circle[theta].pos.y = glm::cos(glm::radians((float)theta)) * 0.5;
        circle[theta].pos.z = 1.0f;

        circle[theta].r = 0.3f;
        circle[theta].g = 0.0f;
        circle[theta].b = (float)theta / 360.0f;
        circle[theta].a = 0.7f;

        transformedCircle[theta] = circle[theta];
    }

    //Æ®·£½ºÆû ÃÊ±âÈ­ (±âº»Çü Á¦°ø)
    transform.translate = glm::mat3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
    transform.rotation = glm::mat3(
        glm::cos(glm::radians(0.0f)), -glm::sin(glm::radians(0.0f)), 0,
        glm::sin(glm::radians(0.0f)), glm::cos(glm::radians(0.0f)), 0,
        0, 0, 1
    );
    transform.scale = glm::mat3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );


}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        //Update·ÎÁ÷
        //<¹®Á¦>//////////////////////////////////////////////////////////////////////////////////

        //1. translate ¸¦ ÇÁ·¹ÀÓ´ç ¿À¸¥ÂÊÀ¸·Î 0.001¾¿ ´©Àû½ÃÄÑ¼­ ¹°Ã¼¸¦ ÀÌµ¿ÇØº¸¼¼¿ä.
        //2. Rotation À» ÇÁ·¹ÀÓ´ç 1µµ¾¿ ´©Àû½ÃÄÑ¼­ ¹°Ã¼¸¦ È¸Àü½ÃÄÑº¸¼¼¿ä.
        //3. ScaleÀº ÃÊ´ç 0.01¾¿ ÃÖ´ë 1.3¹è±îÁö ´Ã¾î³µ´Ù°¡ 0.7¹è±îÁö ÁÙ¾îµéµµ·Ï ¸¸µå½Ã¿À (¹Ýº¹)
        //   (1.3¹è ÀÌ»óÀÌ µÇ¸é ÁÙ¾îµé°í 0.7¹è ÀÌÇÏ°¡ µÇ¸é ´Ù½Ã ´Ã¾î³ª°Ô ¸¸µå½Ã¿À)
        
        //ÀÌµ¿

        transform.translate = transform.translate * translateM;

        //È¸Àü
        transform.rotation *= glm::mat3(
            glm::cos(glm::radians(rotateValue)), -glm::sin(glm::radians(rotateValue)), 0,
            glm::sin(glm::radians(rotateValue)), glm::cos(glm::radians(rotateValue)), 0,
            0, 0, 1
        );

        //Å©±â Á¶Àý
        if (scale == true) {
            transform.scale += glm::mat3(
                0.01, 0, 0,
                0, 0.01, 0,
                0, 0, 1
            );
            scaleValue += 0.01f;
            if (scaleValue >= 1.3f)
            {
                scale = false;
            }
        }
        else if (scale == false)
        {
            transform.scale += glm::mat3(
                -0.01, 0, 0,
                0, -0.01, 0,
                0, 0, 1
            );
            scaleValue -= 0.01f;
            if (scaleValue <= 0.7f)
            {
                scale = true;
            }
        }

        cout << transformedCircle->pos.x;

        //////////////////////////////////////////////////////////////////////////////////////////


        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i].pos = transform.translate * transform.rotation * transform.scale * circle[i].pos;
        }

        for (int i = 0; i < 5; i++)
        {
            transformedStar[i].pos = transform.translate * transform.rotation * transform.scale * star[i].pos;
        }

        //»ö ÃÊ±âÈ­
        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //¼±µÎ²²
        glLineWidth(7.0f);
        //¿À¸Á¼º ±×¸®±â
        glBegin(GL_LINE_STRIP);

        int a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 3;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 1;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 4;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 2;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);

        a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        glEnd();

        //¿ø±×¸®±â
        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
            glVertex3f(transformedCircle[theta].pos.x, transformedCircle[theta].pos.y, 0.0f);
        }
        glEnd();



        //È­¸é ½º¿Ò
        glfwSwapBuffers(window);
        glfwPollEvents();

        //·»´õ½Ã°£ ÃøÁ¤
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        string fps_s = "FPS : " + to_string(fps);
        cout << fps_s << endl;

    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init();
    Update();
    Release();

    exit(EXIT_SUCCESS);
>>>>>>>> ebb1374fd6bdf612058387bdca694780504207a9:6ì£¼ì°¨/kadai.cpp
}