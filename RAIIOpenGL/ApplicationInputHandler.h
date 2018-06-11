#pragma once

//forward decalarations
class Application;
class KeyboardHandler;
class ICommand;

class ApplicationInputHandler
{
public:
   explicit ApplicationInputHandler (Application& app_use);
   ~ApplicationInputHandler ();

   std::vector<std::unique_ptr<ICommand>> Handle (const KeyboardHandler& keyboard_handle) const;

private:

   Application& app;
};

