#pragma once

//forward declarations
class ICommand;

struct KeyActionHistory
{
   int last_recorded_status = GLFW_RELEASE;
   int current_status = GLFW_RELEASE;
};

class KeyboardHandler
{
public:
   using KeyboardStatus = std::unordered_map<int, KeyActionHistory>;
   
   KeyboardHandler ();
   ~KeyboardHandler ();

   void ProcessKey (int key, int action);
   const KeyboardStatus& GetKeyboardStatus () const;

protected:
    KeyboardStatus key_status = KeyboardStatus (GLFW_KEY_LAST);

};

