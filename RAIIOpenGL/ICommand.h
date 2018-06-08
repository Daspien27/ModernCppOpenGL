#pragma once
class ICommand
{
public:
   ICommand ();
   virtual ~ICommand ();

   virtual void Execute () = 0;
};

