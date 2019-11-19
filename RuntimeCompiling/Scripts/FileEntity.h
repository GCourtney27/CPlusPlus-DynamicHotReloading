#include "../Entity.h"

class FileEntity : public Entity
{
public:
	FileEntity();
	~FileEntity() {}
	FileEntity* factory();

	void Start() override;
	void Update() override;

	const char* GetName() override;

private:
	const char* m_name = nullptr;
};