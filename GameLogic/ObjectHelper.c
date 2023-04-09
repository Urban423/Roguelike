#include "templates.h"  
#include "Object.h"
#include "ExampleClass.h"
#include "BoxCollider.h"
#include "Player.h"
 
#undef T  
#define T ExampleClass  
#include "Object.c"    

#undef T  
#define T Player  
#include "Object.c"  

#undef T  
#define T BoxCollider  
#include "Object.c"  