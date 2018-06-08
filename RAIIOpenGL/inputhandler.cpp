#include "stdafx.h"
#include "InputHandler.h"
#include "KeyboardHandler.h"
#include "application.h"

void InputHandler::HandleAppInputs (Application & app)
{
}

void InputHandler::HandleRendererInputs (Renderer & renderer)
{
}

void InputHandler::HandleStateInputs (State & state)
{
}

InputHandler::InputHandler (Application& app) :
   keyboard_handler (std::make_unique<KeyboardHandler> ())
{
}


InputHandler::~InputHandler ()
{
}

void InputHandler::ProcessKeyboardInput (int key, int action)
{
   keyboard_handler->ProcessKey (key, action);
}

void InputHandler::HandleInputs (Application & app, Renderer & renderer, State & state)
{
   Application::HandleInputs (app, *keyboard_handler);
}
