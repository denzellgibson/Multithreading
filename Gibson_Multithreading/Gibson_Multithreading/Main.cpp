//Denzell Gibson
//CSC275 10:30am
//4/19/2017

#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::mutex m;
std::string message = "";
static const int num_threads = 10;

void editString(int i)
{
	m.lock();
	message.append("Thread#" + std::to_string(i) + " ");
	m.unlock();
}

int main()
{
	std::thread thread[num_threads];

	for (int i = 0; i < num_threads; ++i)
	{
		thread[i] = std::thread(editString, i);
	}

	for (int i = 0; i < num_threads; ++i)
	{
		thread[i].join();
	}

	std::cout << message << std::endl;

	system("pause");
	return 0;
}