//SHARED MEM STUFF
#pragma once
#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>
#include <cstdlib> //std::system
#include <sstream>
#include <string.h>


//SHARED MEM STUFF END
namespace dso
{
	using namespace boost::interprocess;

	class SharedMemory
	{
	public:
		char buffer[1024];
		char opt[10];
		void* shptr;

		SharedMemory();
		//~SharedMemory();

		void writeToSharedMemory(std::string data);
	};

}
