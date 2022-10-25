#include <iostream>
#include <random>

int main()
{
	int leftNumber = 0, rightNumber = 0, guessNumber = 0;	//��ʼ���⼸��ֵ��ע�����Ҫ�Ա������г�ʼ��������������ܻᵼ��һЩ����ֵֹ����⣡

	std::cout << "Please enter two numbers that will be used to construct an interval:" << std::endl;	//�涨һ�����䡣��ȷ�𰸽�������������������ָ����
	std::cin >> leftNumber >> rightNumber;

	if (leftNumber < rightNumber)
	{
		std::random_device rd;
		std::default_random_engine e(rd());
		std::uniform_int_distribution<int> u(leftNumber, rightNumber);
		int answer = u(e);
		//�������������������û��涨�����������𰸵ġ�

		std::cout << "Please guess a number!" << std::endl;
		std::cin >> guessNumber;

		while (guessNumber != answer)	//������¶��ˣ��������ѭ����һֱ�������ȷ�𰸵ġ�
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

			if (guessNumber < leftNumber || guessNumber > rightNumber)
			{
				std::cout << "The guess number must be in the interval you set! Please re-enter!" << std::endl;
			}

			std::cin >> guessNumber;
		}

		if (guessNumber == answer)	//����¶Դ�ʱ��ִ�иô��롣
		{
			std::cout << "Good job! You got the correct answer!";
		}

		std::cin.get();
		std::cin.get();
		return 0;
	}

	else
	{
		std::cerr << "Please enter both of the two numbers and make sure that the first number is smaller than the second number!";	//�������������ֲ���������Ķ��壬��ôִ�иô��롣

		std::cin.get();
		std::cin.get();
		return -1;
	}
}
//0x0049 0x0020 0x006C 0x006F 0x0076 0x0065 0x0020 0x0052 0x0075 0x0069 0x0078 0x0075 0x0065 0x0020 0x0044 0x0075 0x0061 0x006E 0x0021
//Perhaps you will figure out something interesting after successfully decoding these numbers...