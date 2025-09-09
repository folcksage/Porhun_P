
#include "MovingAverage.h"

MovingAverage::MovingAverage(int N) {
    windowSize = N;
    buffer.resize(N, 0.0f);
    index = 0;
    sum = 0.0f;
}

MovingAverage::~MovingAverage() {
    buffer.clear();
}

float MovingAverage::processSample(float x) {
    sum -= buffer[index];
    buffer[index] = x;
    sum += x;
    index = (index + 1) % windowSize;
    return sum / windowSize;
}

void MovingAverage::apply(float* input, float* output, int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        output[i] = processSample(input[i]);
    }
}
