#include "stdafx.h"
#include "ApplicationCommands.h"

#include "application.h"


void ApplicationQuitCommand::Execute ()
{
   this_command_app.Exit ();
}
