#pragma once

class ICommand;

struct KeyBinding
{
   int last_recorded_status = GLFW_RELEASE;
   int current_status = GLFW_RELEASE;
   std::unique_ptr<ICommand> binded_command = nullptr;
};

class KeyboardHandler
{
public:
   KeyboardHandler ();
   ~KeyboardHandler ();

   void ProcessKey (int key, int action);

protected:
   std::unordered_map<int, std::unique_ptr<KeyBinding>> key_status = std::unordered_map<int, std::unique_ptr<KeyBinding>> (GLFW_KEY_LAST);

};

