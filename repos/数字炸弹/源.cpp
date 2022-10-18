#include <iostream>
#include <random>

int main()
{
	int leftNumber = 0, rightNumber = 0, guessNumber = 0;	//初始化这几个值，注意必须要对变量进行初始化操作，否则可能会导致一些奇奇怪怪的问题！

	std::cout << "Please enter two numbers that will be used to construct an interval:" << std::endl;	//让你规定一个区间。正确答案将从你给定的区间中随机指定。
	std::cin >> leftNumber >> rightNumber;

	if (leftNumber < rightNumber)
	{
		std::random_device rd;											//这几行
		std::default_random_engine e(rd());								//是用来生成
		std::uniform_int_distribution<int> u(leftNumber, rightNumber);	//含于用户规定的区间的
		int answer = u(e);												//随机答案的。

		std::cout << "Please guess a number!" << std::endl;
		std::cin >> guessNumber;

		while (guessNumber != answer)	//除非你猜对了，否则这个循环会一直让你猜正确答案的。
		{
			std::cout << "Incorrect number lol! Guess it again!" << std::endl;
			if (guessNumber > leftNumber && guessNumber < answer)
			{
				leftNumber = guessNumber;
				std::cout << "Now the number you will guess is located in [" << leftNumber << ", " << rightNumber << "]" << std::endl;
			}

			if (guessNumber > answer && guessNumber < rightNumber)
			{
				rightNumber = guessNumber;
				std::cout << "Now the number you will guess is located in [" << leftNumber << ", " << rightNumber << "]" << std::endl;
			}

			std::cin >> guessNumber;
		}

		if (guessNumber == answer)	//当你猜对答案时，执行该代码。
		{
			std::cout << "Good job! You got the correct answer!";
		}

		std::cin.get();
		std::cin.get();
		return 0;
	}

	else
	{
		std::cerr << "Please enter both of the two numbers and make sure that the first number is smaller than the second number!";	//如果你输入的数字不符合区间的定义，那么执行该代码。

		std::cin.get();
		std::cin.get();
		return -1;
	}
}
//0x0049 0x0020 0x006C 0x006F 0x0076 0x0065 0x0020 0x0052 0x0075 0x0069 0x0078 0x0075 0x0065 0x0020 0x0044 0x0075 0x0061 0x006E 0x0021
//Well, there is a series of numbers. Perhaps you will figure out something interesting after successfully decoding these numbers...
//If you indeed successfully decoded these numbers, DO NOT TELL ANYBODY ELSE THE ANSWER!