#include "templates.h"  
#include "Object.h"
#include "ExampleClass.h"
 
#undef T  
#define T ExampleClass  
#include "Object.c"    
