/*
(AUDIO DEVICES ENABLED, 0x000C 0x000F 0x0007)
(DEVICES ARE NORMAL)
(BROADCAST SERVICE ENABLED:)
��������类��Ĺ�������������
(AUDIO DISABLED DUE TO AN UNEXCEPTED ACCIDENT THAT IS CALLED "SOCIAL DEATH")
*/
#include <iostream>
#include <random>

int main()
{
	int left = 0, right = 0, guess = 0;	//��ʼ�������Լ�������

	std::cout << "�涨������ը����������ɣ��������������ڼ���N�ı����䡣" << std::endl;	//�ȹ涨һ�����䣬Ȼ���á�ը�������������������
	std::cin >> left >> right;

	if (left < right)	//ȷ��������һ�����Ϻ���ѧ�涨�������䣬���򱨴�
	{
		std::random_device rd;								//�⼸��
		std::default_random_engine e(rd());					//����������
		std::uniform_int_distribution<int> u(left, right);	//�����û��涨�������
		int bomb = u(e);									//�����ը������

		std::cout << "���һ�����ɣ������ǲ��ǡ�ը�����ɣ�" << std::endl;
		std::cin >> guess;

		int* unk = &guess;

		if (guess == bomb)	//��һ�β²�
		{
			std::cout << "����ѽ����һ���ӾͲµ���ը�����ˣ�";
		}

		else
		{
			if (guess < bomb)	//�²�ֵ�ȡ�ը����С
			{
				std::cout << "����Ŷ����������Ҫ��[" << *unk << ", " << right << "]����������Ŷ��" << std::endl;
			}

			if (guess > bomb)	//�²�ֵ�ȡ�ը������
			{
				std::cout << "����Ŷ����������Ҫ��[" << left << ", " << *unk << "]����������Ŷ��" << std::endl;
			}

			int guess = 0;
			std::cout << "�ٲ�һ�����ɣ������ǲ��ǡ�ը�����ɣ�" << std::endl;
			std::cin >> guess;

			if (guess == bomb)	//�ڶ��β²�
			{
				std::cout << "�¶�������ը��������" << bomb << "��";
			}

			else
			{
				if (guess < bomb)	//�²�ֵ�ȡ�ը����С
				{
					if (guess > *unk)	//�²�ֵ�ȳ�ʼ�²�ֵ��
					{
						std::cout << "����Ŷ����������Ҫ��[" << guess << ", " << right << "]����������Ŷ��" << std::endl;
					}

					if (guess < *unk)	//�²�ֵ�ȳ�ʼ�²�ֵС
					{
						std::cout << "����Ŷ����������Ҫ��[" << guess << ", " << *unk << "]����������Ŷ��" << std::endl;
					}
				}

				if (guess > bomb)	//�²�ֵ�ȡ�ը������
				{
					if (guess > *unk)	//�²�ֵ�ȳ�ʼ�²�ֵ��
					{
						std::cout << "����Ŷ����������Ҫ��[" << *unk << ", " << guess << "]����������Ŷ��" << std::endl;
					}

					if (guess < *unk)	//�²�ֵ�ȳ�ʼ�²�ֵС
					{
						std::cout << "����Ŷ����������Ҫ��[" << left << ", " << guess << "]����������Ŷ��" << std::endl;
					}
				}

				int guess = 0;
				std::cout << "�ٲ�һ�����ɣ������ǲ��ǡ�ը�����ɣ�" << std::endl;
				std::cin >> guess;

				if (guess == bomb)	//�����β²�
				{
					std::cout << "�¶�������ը��������" << bomb << "��";
				}

				else
				{
					std::cout << "���ź����㻹û�¶ԣ���ը������ʵ��" << bomb << "��";
				}
			}
		}
	}

	else
	{
		std::cout << "����ĵ�һ�����ֱ���ȵڶ�������С��";
	}

	std::cin.get();
	std::cin.get();

	return 0;
}
//DEVELOPER: Rean Fei (Zhenyang Fei)