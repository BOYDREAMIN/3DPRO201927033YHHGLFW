#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#pragma comment(lib, "OpenGL32")
   
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
        GLFWwindow* window;
        glfwSetErrorCallback(error_callback);
        if (!glfwInit())
            exit(EXIT_FAILURE);
        window = glfwCreateWindow(1080, 1080, "Simple example", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);
        glfwSetKeyCallback(window, key_callback);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        while (!glfwWindowShouldClose(window))
        {
            float ratio;
            int width, height;
            glfwGetFramebufferSize(window, &width, &height);
            ratio = width / (float)height;

            glClearColor(0.0f, 0.0f, 0.0f, 0.1f);
            glClear(GL_COLOR_BUFFER_BIT);

            //** 윗 반원 그리기 **//

            for (float i = 0; i <= 180; i += 0.1f) {

                glm::vec2 harfjirum;
                harfjirum.x = cos(glm::radians(i));
                harfjirum.y = sin(glm::radians(90.0f-i));

                glBegin(GL_LINE_STRIP);
                glColor4f(0.9f, 0.0f, 0.0f, 1.0f);
                glVertex3f(0.0f, 0.0f, 0.0f);
                glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
                glVertex3f(harfjirum.x, harfjirum.y, 0.0f);

            }
            
            //** 밑반원 그리기 **//

            for (float i = 0; i >= -180; i -= 0.1f) {

                glm::vec2 harfjirum;
                harfjirum.x = cos(glm::radians(i));
                harfjirum.y = sin(glm::radians(90.0f - i));

                glClearColor(0.0f, 0.0f, 0.0f, 0.1f);
                glClear(GL_COLOR_BUFFER_BIT);

                glBegin(GL_LINE_STRIP);
                glColor4f(0.9f, 0.0f, 0.0f, 1.0f);
                glVertex3f(0.0f, 0.0f, 0.0f);
                glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
                glVertex3f(harfjirum.x, harfjirum.y, 0.0f);
            }

            //** 반지름 1.0 **//
            
           /* glBegin(GL_LINE_STRIP);
            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(1.0, 0.0f, 0.0f);*/

            glEnd();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwDestroyWindow(window);
        glfwTerminate();

        exit(EXIT_SUCCESS);
    }
//}