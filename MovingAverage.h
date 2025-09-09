// MovingAverage.h
#pragma once
#include <vector>

class MovingAverage {
private:
    int windowSize;
    std::vector<float> buffer;
    int index;
    float sum;

public:
    MovingAverage(int N);       // �����������
    ~MovingAverage();           // ����������

    float processSample(float x);   // ��������� ������ �������
    void apply(float* input, float* output, int numSamples); // ��������� ����� �������
};
