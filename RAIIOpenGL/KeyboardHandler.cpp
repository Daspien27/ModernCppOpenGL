#include "stdafx.h"
#include "KeyboardHandler.h"

KeyboardHandler::KeyboardHandler ()
{
}


KeyboardHandler::~KeyboardHandler ()
{
}

void KeyboardHandler::ProcessKey (int key, int action)
{
   auto& Key = key_status[key];

   Key.last_recorded_status = Key.current_status;
   Key.current_status = action;
}

const KeyboardHandler::KeyboardStatus& KeyboardHandler::GetKeyboardStatus () const
{
   return key_status;
}
