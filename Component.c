#include "Component.h"
#include <stdio.h>

component_functiontable component_table = {
	Component_constructor,
	Start,
	Update
};

void Component_constructor(Component *this)
{
    this->virtual_table = &component_table;
    this->enabled = 1;
}

void Start(Component *this)
{
    printf("Component is started\n");
}

void Update(Component *this)
{
	printf("updated Component\n");
}