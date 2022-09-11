/*
(AUDIO DEVICES ENABLED, 0x000C 0x000F 0x0007)
(DEVICES ARE NORMAL)
(BROADCAST SERVICE ENABLED:)
我是神里绫华的狗！（超大声）
(AUDIO DISABLED DUE TO AN UNEXCEPTED ACCIDENT THAT IS CALLED "SOCIAL DEATH")
*/
#include <iostream>
#include <random>

int main()
{
	int left = 0, right = 0, guess = 0;	//初始化区间以及待猜数

	std::cout << "规定包含“炸弹”的区间吧！其中区间是属于集合N的闭区间。" << std::endl;	//先规定一个区间，然后让“炸弹”生成在这个区间内
	std::cin >> left >> right;

	if (left < right)	//确保区间是一个“合乎数学规定”的区间，否则报错
	{
		std::random_device rd;								//这几行
		std::default_random_engine e(rd());					//是用来生成
		std::uniform_int_distribution<int> u(left, right);	//含于用户规定的区间的
		int bomb = u(e);									//随机“炸弹”的

		std::cout << "请猜一个数吧！看看是不是“炸弹”吧！" << std::endl;
		std::cin >> guess;

		int* unk = &guess;

		if (guess == bomb)	//第一次猜测
		{
			std::cout << "厉害呀！你一下子就猜到“炸弹”了！";
		}

		else
		{
			if (guess < bomb)	//猜测值比“炸弹”小
			{
				std::cout << "不对哦！你现在需要在[" << *unk << ", " << right << "]这个区间猜了哦。" << std::endl;
			}

			if (guess > bomb)	//猜测值比“炸弹”大
			{
				std::cout << "不对哦！你现在需要在[" << left << ", " << *unk << "]这个区间猜了哦。" << std::endl;
			}

			int guess = 0;
			std::cout << "再猜一个数吧！看看是不是“炸弹”吧！" << std::endl;
			std::cin >> guess;

			if (guess == bomb)	//第二次猜测
			{
				std::cout << "猜对啦！“炸弹”就是" << bomb << "！";
			}

			else
			{
				if (guess < bomb)	//猜测值比“炸弹”小
				{
					if (guess > *unk)	//猜测值比初始猜测值大
					{
						std::cout << "不对哦！你现在需要在[" << guess << ", " << right << "]这个区间猜了哦。" << std::endl;
					}

					if (guess < *unk)	//猜测值比初始猜测值小
					{
						std::cout << "不对哦！你现在需要在[" << guess << ", " << *unk << "]这个区间猜了哦。" << std::endl;
					}
				}

				if (guess > bomb)	//猜测值比“炸弹”大
				{
					if (guess > *unk)	//猜测值比初始猜测值大
					{
						std::cout << "不对哦！你现在需要在[" << *unk << ", " << guess << "]这个区间猜了哦。" << std::endl;
					}

					if (guess < *unk)	//猜测值比初始猜测值小
					{
						std::cout << "不对哦！你现在需要在[" << left << ", " << guess << "]这个区间猜了哦。" << std::endl;
					}
				}

				int guess = 0;
				std::cout << "再猜一个数吧！看看是不是“炸弹”吧！" << std::endl;
				std::cin >> guess;

				if (guess == bomb)	//第三次猜测
				{
					std::cout << "猜对啦！“炸弹”就是" << bomb << "！";
				}

				else
				{
					std::cout << "很遗憾，你还没猜对！“炸弹”其实是" << bomb << "！";
				}
			}
		}
	}

	else
	{
		std::cout << "输入的第一个数字必须比第二个数字小！";
	}

	std::cin.get();
	std::cin.get();

	return 0;
}
//DEVELOPER: Rean Fei (Zhenyang Fei)