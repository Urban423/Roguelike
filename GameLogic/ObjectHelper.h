#pragma once  
#include "templates.h" 
#include "BoxCollider.h"
#include "Player.h"

#undef T 
#define T Player  
#include "Object.h"  

#undef T 
#define T BoxCollider  
#include "Object.h" 