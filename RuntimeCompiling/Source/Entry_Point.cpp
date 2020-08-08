#include "stdafx.h"

#include "Framework/Script_Engine.h"

//using namespace std;
//namespace fs = experimental::filesystem;
//
//#define LOG(x) cout << x << endl;

//int SimpleCompile();
//int ImportExample2();
//bool Compile();
//void Simulate();

//typedef VoidMethod_t;
//typedef ScriptableEntity;
//
//void * fLib;
//VoidMethod_t Start;
//VoidMethod_t Update;
//ScriptableEntity Factory;

int main()
{
	Framework::ScriptEngine Engine;
	Engine.LoadCPPFromFile("Scriptable_Actor");
	Engine.RunScripts();

	printf("Application closed...");
	return 0;
}

//
//void SampleCompile1()
//{
//	bool isQuit = false;
//
//	while (!isQuit)
//	{
//		cout << "Press 1 to compile & run....." << endl;
//		cout << "Press 3 to exit....." << endl;
//		int input = 0;
//		cin >> input;
//
//		if (input == 1)
//		{
//			system("cls");
//			Compile();
//			input = 0;
//		}
//		if (input == 3)
//		{
//			break;
//		}
//
//	}
//
//	const char* key = "P";
//	const unsigned char newKey = (const unsigned char)*key;
//	cout << newKey << endl;
//
//	cin.get();
//}

//
//int SimpleCompile()
//{
//	bool isQuit = false;
//
//	while (!isQuit)
//	{
//		cout << "Press 1 to compile & run....." << endl;
//		cout << "Press 3 to exit....." << endl;
//		int input = 0;
//		cin >> input;
//
//		if (input == 1)
//		{
//			system("cls");
//			Compile();
//			input = 0;
//		}
//		if (input == 3)
//		{
//			dlclose(fLib);
//			return 0;
//		}
//
//	}
//	return 0;
//}

//bool Compile()
//{
//	// create .cpp file
//	/*ofstream f("tmp.cpp");
//	f << "#include<stdlib.h>\n#include \"structs.h\"\n extern \"C\" void F(S &s) { s.a += s.a; s.b *= s.b; }\n";
//	f.close();*/
//
//	// -- RUN THIS APPLICATION IN x86 TO ENSURE DLL IS OPENED SUCCESSFULLY --/
//
//	// Create library
//	cout << "Creating lib\n" << endl;
//	system("C:/MinGW/bin/g++ -shared Scripts/FileEntity.cpp -o Scripts/CompiledBinaries/libentity.dll");
//	//system("C:/MinGW/bin/gcc -shared Scripts/Example.c -o Scripts/CompiledBinaries/Ex.dll");
//
//	// Load library        
//	fLib = dlopen("Scripts/CompiledBinaries/libentity.dll", RTLD_LAZY);
//	if (!fLib)
//	{	
//		char* m = dlerror();
//		cerr << "Cannot open library for .h file: " << dlerror() << '\n';
//		return 1;
//	}
//	
//	// Load function pointers
//	cout << "Loading symbols: ScriptableEntity\n" << endl;
//	//typedef void(*S_t)(Vector2&);
//	const char *dlsym_error = dlerror();
//	if (dlsym_error) 
//	{
//		cerr << "Cannot load symbol 'ScriptableEntity': " << dlsym_error << '\n';
//		dlclose(fLib);
//		return 1;
//	}
//
//	cout << "Compile successful. Running:\n" << endl;
//	if (fLib)
//	{
//		//Start = (VoidMethod_t)dlsym(fLib, "Start");
//		//Update = (VoidMethod_t)dlsym(fLib, "Update");
//		Factory = (ScriptableEntity)dlsym(fLib, "factory");
//		
//		Entity* e = Factory();
//		
//		/*e->Start();*/
//		int coord = e->GetTransform()->GetX();
//		
//		e->Update();
//
//		const char* name = e->GetName();
//		coord = e->GetTransform()->GetX();
//		std::cout << name << " " << coord << std::endl;
//		std::ofstream stream;
//		stream.open("debug_out.txt");
//		stream << name;
//		stream << coord;
//		stream.close();
//
//		// Run what is inside the functions
//		//Simulate();
//	}
//
//	{
//		//S_t F = (S_t)dlsym(fLib, "F");
//		//S_t add = (S_t)dlsym(fLib, "add");
//
//		//if (F) {
//		//	for (int i = 0; i < 11; i++) {
//		//		Vector2 pos;
//		//		pos.x = i;
//		//		pos.y = i;
//
//		//		// use function
//		//		F(pos);
//		//		//add(pos);
//		//		cout << pos.x << " " << pos.y << endl;
//		//	}
//		//}
//	}
//	
//	// Close dll
//	dlclose(fLib);
//	return true;
//}
//
//void Simulate()
//{
//	if (Start)
//		Start();
//	else
//		LOG("Symbol not loaded for function Start()");
//
//	if (Update)
//		Update();
//	else
//		LOG("Symbol not loaded for function Update()");
//}
//
//int ImportExample2()
//{
//	using std::cout;
//	using std::cerr;
//
//	cout << "C++ dlopen demo\n\n";
//
//	// open the library
//	cout << "Opening hello.so...\n";
//	void* handle = dlopen("./hello.so", RTLD_LAZY);
//
//	if (!handle) {
//		cerr << "Cannot open library: " << dlerror() << '\n';
//		return 1;
//	}
//
//	// load the symbol
//	cout << "Loading symbol hello...\n";
//	typedef void(*hello_t)();
//
//	// reset errors
//	dlerror();
//	hello_t hello = (hello_t)dlsym(handle, "hello");
//	const char *dlsym_error = dlerror();
//	if (dlsym_error) {
//		cerr << "Cannot load symbol 'hello': " << dlsym_error <<
//			'\n';
//		dlclose(handle);
//		return 1;
//	}
//
//	// use it to do the calculation
//	cout << "Calling hello...\n";
//	hello();
//
//	// close the library
//	cout << "Closing library...\n";
//	dlclose(handle);
//	return 0;
//}