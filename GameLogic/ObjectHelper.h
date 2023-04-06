#pragma once  
#include "templates.h" 
#include "ExampleClass.h"
#include "Player.h"
 
#undef T 
#define T ExampleClass  
#include "Object.h"  

#undef T 
#define T Player  
#include "Object.h"  