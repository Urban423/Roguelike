#pragma once  
#include "templates.h" 
#include "BoxCollider.h"
#include "Player.h"
#include "Rigidbody.h"
#include "TextMesh.h"

#undef T 
#define T Player  
#include "Object.h"  

#undef T 
#define T BoxCollider  
#include "Object.h" 

#undef T 
#define T Rigidbody  
#include "Object.h" 

#undef T 
#define T TextMesh 
#include "Object.h" 