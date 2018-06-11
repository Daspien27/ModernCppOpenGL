#pragma once

//includes
#include "ICommand.h"

//forward declarations
class Application;

template <typename CommandName>
class ApplicationCommand : public ICommand
{
public:
   
   ApplicationCommand (Application & app) :
      this_command_app (app)
   {
   }

   void Execute () override
   {
      static_cast<CommandName*>(this)->Execute ();
   }

   ~ApplicationCommand () override = default;

protected:

   using Base = ApplicationCommand<CommandName>;
   Application& this_command_app;
};



class ApplicationQuitCommand :
   public ApplicationCommand<ApplicationQuitCommand>
{
public:
   ApplicationQuitCommand (Application& app) :
      Base (app)
   {
   }

   ~ApplicationQuitCommand () override = default;

   void Execute ();
};

