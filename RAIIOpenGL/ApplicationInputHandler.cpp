#include "stdafx.h"
#include "ApplicationInputHandler.h"

#include "application.h"
#include "ApplicationCommands.h"
#include "KeyboardHandler.h"

ApplicationInputHandler::ApplicationInputHandler (Application& app_use) :
   app (app_use)
{
}


ApplicationInputHandler::~ApplicationInputHandler ()
{
}

std::vector<std::unique_ptr<ICommand>> ApplicationInputHandler::Handle (const KeyboardHandler& keyboard_handle) const
{
   std::vector<std::unique_ptr<ICommand>> app_commands;

   const auto& keyboard_key_status = keyboard_handle.GetKeyboardStatus ();

   for (const auto& key : keyboard_key_status)
   {
      if (key.second.current_status == GLFW_PRESS)
      {
         switch (key.first)
         {
         case GLFW_KEY_ESCAPE:
         
            app_commands.emplace_back(std::make_unique<ApplicationQuitCommand>(app));

            break;

         default:
         
            break;
         }
      }

   }

   return app_commands;
}
