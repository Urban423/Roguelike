#include "templates.h"  
#include "Object.h"
#include "BoxCollider.h"
#include "Player.h"
#include "Rigidbody.h"
#include "ExitTrigger.h"
#include "TextMesh.h"
#include "MeshRenderer.h"
#include "Switcher.h"
#include "Pause.h"

#undef T  
#define T Player  
#include "Object.c"  

#undef T  
#define T BoxCollider  
#include "Object.c"  

#undef T 
#define T Rigidbody  
#include "Object.c" 

#undef T 
#define T TextMesh  
#include "Object.c" 

#undef T 
#define T MeshRenderer  
#include "Object.c" 

#undef T 
#define T Switcher  
#include "Object.c" 

#undef T 
#define T Pause  
#include "Object.c" 

#undef T 
#define T ExitTrigger
#include "Object.c" 