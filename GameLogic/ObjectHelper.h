#pragma once  
#include "templates.h" 
#include "BoxCollider.h"
#include "Player.h"
#include "Rigidbody.h"
#include "TextMesh.h"
#include "MeshRenderer.h"
#include "Switcher.h"
#include "Pause.h"

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

#undef T 
#define T MeshRenderer 
#include "Object.h" 

#undef T 
#define T Switcher 
#include "Object.h" 

#undef T 
#define T Pause 
#include "Object.h" 