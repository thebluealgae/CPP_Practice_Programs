#include <iostream>
#include <random>

using namespace std;

int main()
{
	int leftNumber = 0, rightNumber = 0, guessNumber = 0;	//初始化这几个值。注意必须对变量进行初始化操作，否则可能会出现一些奇奇怪怪的问题！

	cout << "Please enter two numbers that will be used to construct an interval:" << endl;	//规定一个区间。答案将从你给定的区间中随机指定。
	cin >> leftNumber >> rightNumber;

	while (leftNumber >= rightNumber)	//如果你输入的数字不符合区间的定义，那么执行该循环。
	{
		cout << "The first number must be smaller than the second number!" << endl;
		cout << "Please re-enter both of the two numbers!" << endl;
		cin >> leftNumber >> rightNumber;
	}

	random_device rd;
	default_random_engine e(rd());
	uniform_int_distribution<int> u(leftNumber, rightNumber);
	int answer = u(e);
	//上面四行是用来指定属于用户规定的区间的答案的。

	cout << "Please guess a number!" << endl;
	cin >> guessNumber;

	while (guessNumber != answer)	//除非你猜对了，否则这个循环会让你一直猜答案。
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

	if (guessNumber == answer)	//当你猜对答案时，执行该函数。
	{
		cout << "Good job! You got the correct answer!";
	}

	cin.get();
	cin.get();
	return 0;
}