#include "stdafx.h"
#include "application.h"
#include "ApplicationInputHandler.h"
#include "ApplicationCommands.h"
#include "renderer.h"
#include "State.h"
#include "inputhandler.h"
#include "KeyboardHandler.h"

int main ()
{
   try
   {
      Application main_app;

      main_app.Run ();

   }
   catch (std::exception& e)
   {
      std::cerr << e.what () << std::endl;
   }
}

void Application::InitWindow ()
{
   if (!glfwInit ())
   {
      throw std::runtime_error ("GLFW failed to initialize.");
   }
   
   glfwWindowHint (GLFW_VERSION_MAJOR, 4);
   glfwWindowHint (GLFW_VERSION_MINOR, 6);
   glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
   
   window = glfwCreateWindow (400, 400, "RAIIOpenGL", nullptr, nullptr);

   if (window == nullptr)
   {
      throw std::runtime_error ("GLFW could not create a window.");
   }
   
   glfwSetKeyCallback (window, Application::KeyCallback);
   glfwSetWindowUserPointer (window, this);

}

void Application::InitGraphics ()
{
   glfwMakeContextCurrent (window);

   if (!gladLoadGLLoader ((GLADloadproc) glfwGetProcAddress))
   {
      throw std::runtime_error ("Failed to initialize GLAD");
   }

   glViewport (0, 0, 400, 400);
}

void Application::InitState ()
{
}

void Application::KeyCallback (GLFWwindow * window, int key, int scancode, int action, int mods)
{
   auto this_app = reinterpret_cast<Application*> (glfwGetWindowUserPointer (window));

   this_app->input_handler->ProcessKeyboardInput (key, action);
}

Application::Application () :
   renderer (std::make_unique<Renderer> ()),
   state (std::make_unique<State> ()),
   input_handler (std::make_unique<InputHandler> (*this)),
   app_input_handler (std::make_unique<ApplicationInputHandler> (*this))

{
   Init ();
}

Application::~Application ()
{
   glfwTerminate ();
}

void Application::Init ()
{
   InitWindow ();
   InitGraphics ();
   InitState ();
}

void Application::Run ()
{
   while (!glfwWindowShouldClose (window))
   {
      glfwPollEvents ();

      input_handler->HandleInputs (*this, *renderer, *state);

      glfwSwapBuffers (window);
   }
}

void Application::Exit ()
{
   glfwSetWindowShouldClose (window, true);
}

void Application::HandleInputs (const KeyboardHandler& keyboard_handler)
{
   
   auto app_commands = app_input_handler->Handle (keyboard_handler);

   for (auto&& app_command : app_commands)
   {
      app_command->Execute ();
   }


}