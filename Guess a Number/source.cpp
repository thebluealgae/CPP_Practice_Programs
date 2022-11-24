#include <iostream>
#include <random>

using namespace std;

int main()
{
	int leftNumber = 0, rightNumber = 0, guessNumber = 0;	//��ʼ���⼸��ֵ��ע�����Ա������г�ʼ��������������ܻ����һЩ����ֵֹ����⣡

	cout << "Please enter two numbers that will be used to construct an interval:" << endl;	//�涨һ�����䡣�𰸽�������������������ָ����
	cin >> leftNumber >> rightNumber;

	while (leftNumber >= rightNumber)	//�������������ֲ���������Ķ��壬��ôִ�и�ѭ����
	{
		cout << "The first number must be smaller than the second number!" << endl;
		cout << "Please re-enter both of the two numbers!" << endl;
		cin >> leftNumber >> rightNumber;
	}

	random_device rd;
	default_random_engine e(rd());
	uniform_int_distribution<int> u(leftNumber, rightNumber);
	int answer = u(e);
	//��������������ָ�������û��涨������Ĵ𰸵ġ�

	cout << "Please guess a number!" << endl;
	cin >> guessNumber;

	while (guessNumber != answer)	//������¶��ˣ��������ѭ��������һֱ�´𰸡�
	{
		if (guessNumber > leftNumber && guessNumber < answer)
		{
			cout << "Incorrect number lol! Guess it again!" << endl;
			leftNumber = guessNumber;
			cout << "Now the number you will guess is located in [" << leftNumber << ", " << rightNumber << "]" << endl;
		}

		if (guessNumber > answer && guessNumber < rightNumber)
		{
			cout << "Incorrect number lol! Guess it again!" << endl;
			rightNumber = guessNumber;
			cout << "Now the number you will guess is located in [" << leftNumber << ", " << rightNumber << "]" << endl;
		}

		if (guessNumber < leftNumber || guessNumber > rightNumber)
		{
			cout << "The guess number must be in the interval you set! Please re-enter!" << endl;
		}

		cin >> guessNumber;
	}

	if (guessNumber == answer)	//����¶Դ�ʱ��ִ�иú�����
	{
		cout << "Good job! You got the correct answer!";
	}

	cin.get();
	cin.get();
	return 0;
}