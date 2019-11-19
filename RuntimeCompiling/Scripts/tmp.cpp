//#include<stdlib.h>
//#include <stdio.h> //https://en.wikibooks.org/wiki/C_Programming/Simple_input_and_output

#include <iostream>
#include "../GameObject.h"
#include <string>
//extern "C" void Increment(Vector2 &v) { v.x += v.x; v.y *= v.y; }
//extern "C" void F(Vector2 &v) { Increment(v); }
//extern "C" void add(Vector2 &v) { v.x += v.x; v.y += v.y; }

// -- Add extern "C" so they will be recognized by the c compiler and exporter -- //

extern "C" void Start()
{
	//printf("Start function\n");
	std::cout << "TEST HELLO" << std::endl;
	//Vector2 vec(1, 1);
	//printf("%d", vec.x);

	GameObject go;
	go.SetPosition(1, 1);

	std::cout << "x: " << go.GetPosition().x << std::endl;
	std::cout << "y: " << go.GetPosition().y << std::endl;

	//printf("position x: %d", go.x);

	//for (int i = 0; i < 3; i++)
	//{
	//	pos->x = i;
	//	//printf("HELLO");
	//	std::cout << "x: " << pos->x << std::endl;
	//	//printf("x: %d\n", go.GetPosition().x); // %d exclusive for int variables in output concantination
	//	//printf("y: %d\n", go.GetPosition().y); // %d exclusive for int variables in output concantination
	//}
}

void Print()
{
	printf("Print function called\n");
}

extern "C" void Update()
{
	printf("Update function\n");
	Print();
}





