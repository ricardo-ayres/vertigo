#include <stdio.h>
#include <string.h>

#include "mgui.h"
#include "../bool.h"
#include "../objects/objects.h"
#include "../vertigo.h"



void mgerror(char *text)
{
     MMessageDialog("Fatal error", text, "Exit", NULL);
     errorexit(0);
}



void mgwarning(char *text)
{
     MMessageDialog("Warning", text, "OK", NULL);
}
