#include "stdafx.h"
#include "application.h"

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
   glfwInit ();

   glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
   glfwWindowHint (GLFW_VERSION_MAJOR, 4);
   glfwWindowHint (GLFW_VERSION_MINOR, 6);

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
   input_handler (std::make_unique<InputHandler> (*this))

{
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
      input_handler->HandleInputs (*this, *renderer, *state);
   }
}

void Application::Exit ()
{
   glfwSetWindowShouldClose (window, true);
}

void Application::HandleInputs (Application& app, KeyboardHandler & keyboard_handler)
{

}
