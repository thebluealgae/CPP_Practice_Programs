#include <iostream>
#include <random>

int main()
{
	int min = 0, max = 0;
	std::cout << "输入参与的人数：" << std::endl;
	std::cin >> max;

	const int p = max;

	while (max > 1)
	{
		--max;
	}
	min = max;

	std::random_device rd;
	std::default_random_engine e(rd());
	std::uniform_int_distribution<int> u(min, p);

	std::cout << u(e);

	std::cin.get();
	std::cin.get();
	return 0;
}