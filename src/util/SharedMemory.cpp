#include "util/SharedMemory.h"

//SHARED MEM STUFF

#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>
#include <cstdlib> //std::system
#include <sstream>
#include <string.h>


//SHARED MEM STUFF END

namespace dso
{
	using namespace boost::interprocess;


		SharedMemory::SharedMemory()
		{

			managed_shared_memory segment(create_only, "MySharedMemory", 65536);
			managed_shared_memory::size_type free_memory_before = segment.get_free_memory();
			this->shptr = segment.allocate(1024);
			managed_shared_memory::size_type free_memory_after = segment.get_free_memory();

			memset(this->buffer, '\0', sizeof(this->buffer));
			memset(this->opt, '\0', sizeof(this->opt));

			struct shm_remove
			{
				shm_remove() { shared_memory_object::remove("MySharedMemory"); }
				~shm_remove() { shared_memory_object::remove("MySharedMemory"); }
			} remover;



			std::cout << "Free Memeory Before : " << free_memory_before << std::endl;
			std::cout << "Free Memeory After  : " << free_memory_after << std::endl;
			std::cout << "Free Memeory Diff.  : " << free_memory_before - free_memory_after << std::endl;
		}

		void SharedMemory::writeToSharedMemory(std::string data)
		{
			memset(this->opt, '\0', sizeof(this->opt));
			//std::cin.getline(opt, sizeof(opt));
			memset(this->buffer, '\0', sizeof(this->buffer));

			int i;
			for (i = 0; i < data.length(); i++)
			{
				this->buffer[i] = data[i];
			}

			memset(this->shptr, '\0', 1024);
			memcpy((char*)this->shptr, this->buffer, strlen(this->buffer));
		}
	
}