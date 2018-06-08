#pragma once

//includes

//forward declarations
class Renderer;
class InputHandler;

//definitions
class Application
{

   void InitWindow ();
   void InitGraphics ();
   void InitState ();
   static void KeyCallback (GLFWwindow* window, int key, int scancode, int action, int mods);

public:

   Application ();
   ~Application ();
   void Init ();
   void Run ();
   void Exit ();
   static void HandleInputs (Application& app, KeyboardHandler& keyboard_handler);

private:
   GLFWwindow * window = nullptr;
   std::unique_ptr<Renderer> renderer = nullptr;
   std::unique_ptr<State> state = nullptr;
   std::unique_ptr<InputHandler> input_handler = nullptr;

};