#include <iostream>
#include <random>

int main()
{
	int max = 0;
	std::cout << "输入参与的人数：" << std::endl;
	std::cin >> max;

	std::random_device rd;
	std::default_random_engine e(rd());
	std::uniform_int_distribution<int> u(1, max);

	std::cout << u(e);

	std::cin.get();
	std::cin.get();
	return 0;
}