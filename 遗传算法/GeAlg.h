#pragma once
#ifndef GEALG_H_
#define GEALG_H_
#include <vector>
#include <iostream>
#include "Chromosome.h"
using namespace std;
class GeAlg {
public:
	void select(); // ��Ȼѡ��
	void fitness(); // ���ﾺ��
	void next_generation(); // ������һ��
	void calc();
	int size() const { return pop.size(); }
	void print()
	{
		unsigned char a[100] = { 0 };
		vector<unsigned char> decode = best_one.decode();
		for (size_t i = 0; i<decode.size(); i++)
		{
			a[i] = decode[i];
		}
		cout << "��������:" << generation << " ��Ӧ��:" << best_fitness << " �����ͣ�" << a << endl;
	}
	GeAlg(int size, double mutation, double crossover, int mutation_max_step);
	virtual ~GeAlg();
private:
	double calc_fitness(std::vector<unsigned char> decoded);
	double total_fitness;// ��Ⱥ����Ӧ�ȣ����и�����Ӧ�ȵĺͣ�
	double best_fitness;// ����Ӧ�������Ӧ��
	Chromosome best_one;// ��õĸ���Ļ���
	double average_fitness;// ƽ����Ӧ��
	double worst_fitness;// ��ĸ���
	double mutation;// ͻ����
	int mutation_max_step;// ���ͻ����ٻ���
	double crossover;// ���滥����
	int generation;// ��������
	std::vector<Chromosome> pop;
};

#endif /* GEALG_H_ */

