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
    MovingAverage(int N);       // Конструктор
    ~MovingAverage();           // Деструктор

    float processSample(float x);   // Обработка одного отсчёта
    void apply(float* input, float* output, int numSamples); // Обработка всего сигнала
};
