#ifndef TEMPLATES_H_
#define TEMPLATES_H_
#include "TimeSystem.h"

#define CAT(X,Y) X##_##Y
#define TEMPLATE(X,Y) CAT(X,Y)
#define template(X,Y) CAT(X,Y)
#define STRINGCLASS(X) printf(#X "\n");
#define includeTime extern TimeSystem Time;
#define includeInput extern KeyCodes KeyCode;

#endif 