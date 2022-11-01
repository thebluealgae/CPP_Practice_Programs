#include <iostream>
#include <random>

int main()
{
	int leftNumber = 0, rightNumber = 0, guessNumber = 0;	//��ʼ���⼸��ֵ��ע�����Ա������г�ʼ��������������ܻ����һЩ����ֵֹ����⣡

	std::cout << "Please enter two numbers that will be used to construct an interval:" << std::endl;	//�涨һ�����䡣�𰸽�������������������ָ����
	std::cin >> leftNumber >> rightNumber;

	while (leftNumber >= rightNumber)	//�������������ֲ���������Ķ��壬��ôִ�и�ѭ����
	{
		std::cout << "The first number must be smaller than the second number!" << std::endl;
		std::cout << "Please re-enter both of the two numbers!" << std::endl;
		std::cin >> leftNumber >> rightNumber;
	}

	std::random_device rd;
	std::default_random_engine e(rd());
	std::uniform_int_distribution<int> u(leftNumber, rightNumber);
	int answer = u(e);
	//��������������ָ�������û��涨������Ĵ𰸵ġ�

	std::cout << "Please guess a number!" << std::endl;
	std::cin >> guessNumber;

	while (guessNumber != answer)	//������¶��ˣ��������ѭ��������һֱ�´𰸡�
	{
		if (guessNumber > leftNumber && guessNumber < answer)
		{
			std::cout << "Incorrect number lol! Guess it again!" << std::endl;
			leftNumber = guessNumber;
			std::cout << "Now the number you will guess is located in [" << leftNumber << ", " << rightNumber << "]" << std::endl;
		}

		if (guessNumber > answer && guessNumber < rightNumber)
		{
			std::cout << "Incorrect number lol! Guess it again!" << std::endl;
			rightNumber = guessNumber;
			std::cout << "Now the number you will guess is located in [" << leftNumber << ", " << rightNumber << "]" << std::endl;
		}

		if (guessNumber < leftNumber || guessNumber > rightNumber)
		{
			std::cout << "The guess number must be in the interval you set! Please re-enter!" << std::endl;
		}

		std::cin >> guessNumber;
	}

	if (guessNumber == answer)	//����¶Դ�ʱ��ִ�иú�����
	{
		std::cout << "Good job! You got the correct answer!";
	}

	std::cin.get();
	std::cin.get();
	return 0;
}