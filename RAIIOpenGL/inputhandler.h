#pragma once

class Application;
class Renderer;
class State;
class KeyboardHandler;

class InputHandler
{
private:
   void HandleAppInputs (Application& app);
   void HandleRendererInputs (Renderer& renderer);
   void HandleStateInputs (State& state);

public:
   InputHandler (Application& app);
   ~InputHandler ();

   void ProcessKeyboardInput (int key, int action);
   void HandleInputs (Application& app, Renderer& renderer, State& state);

private:
   
   std::unique_ptr<KeyboardHandler> keyboard_handler;
};

