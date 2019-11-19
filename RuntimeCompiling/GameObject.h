//#pragma once
//#ifndef GAMEOBJECT_H
//#define GAMEOBJECT_H
//
#include "Vector2.h"
//#include "stdafx.h"
#include <vector>
//
//#ifdef __cplusplus
//
//#endif  __cplusplus
//class GameObject
//{
//public:
//	GameObject() {}
//	~GameObject() {}
//private:
//	int x = 0;
//	int y = 0;
//};
//#else
//typedef
//struct GameObject
//	GameObject;
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//#if defined(__STDC__) || defined(__cplusplus)
//	extern void c_function(GameObject*); /*ANSI c prototypes*/
//	extern GameObject* cplusplus_callback_function(GameObject*);
//#else
//	extern void c_function(); /*K&R style*/
//	extern GameObject* cplusplus_callback_function();
//#endif
//
//#ifdef _cplusplus
//}
//#endif // _cplusplus
//
//#endif // !GAMEOBJECTH


//extern "C" struct GameObject
//{
//	int x = 1;
//	int y = 2;
class GameObject
{
public:
	GameObject() { position = new Vector2(0, 0); }
	~GameObject() {}

	void SetPosition(int _x, int _y) { position->x = _x, position->y = _y; }
	Vector2& GetPosition() { return *position; }

	//int x = 3;
	//int y = 1;
private:
	Vector2* position;
	std::vector<void*> scripts;
};
