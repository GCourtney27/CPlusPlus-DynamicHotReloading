#include "FileEntity.h"
#include <iostream>

FileEntity::FileEntity()
{
	std::cout << "Created Entity!" << std::endl;
	m_name = "Hello World!";
}

void FileEntity::Start()
{
	std::cout << "Hello from Start Method" << std::endl;
}

void FileEntity::Update()
{
	std::cout << "Hello from Update method!" << std::endl;
	GetTransform()->SetX(300);
}

const char* FileEntity::GetName()
{
	return m_name;
}

extern "C" FileEntity* factory(void)
{
return new FileEntity; 
}