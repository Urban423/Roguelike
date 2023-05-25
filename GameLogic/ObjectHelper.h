#pragma once  
#include "templates.h" 
#include "BoxCollider.h"
#include "Player.h"
#include "Rigidbody.h"
#include "TextMesh.h"
#include "MeshRenderer.h"
#include "ExitTrigger.h"
#include "Switcher.h"
#include "Pause.h"
#include "WriteYourText.h"
#include "PainMaker.h"
#include "Coin.h"
#include "Enemy.h"
#include "Door.h"
#include "key.h"

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

#undef T 
#define T ExitTrigger 
#include "Object.h" 

#undef T 
#define T WriteYourText 
#include "Object.h" 

#undef T 
#define T Coin 
#include "Object.h" 

#undef T 
#define T PainMaker 
#include "Object.h" 

#undef T 
#define T Enemy 
#include "Object.h" 

#undef T 
#define T Door 
#include "Object.h" 

#undef T 
#define T Key
#include "Object.h" 