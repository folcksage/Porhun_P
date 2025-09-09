#include <iostream>
#include "wav_lib.h"
#include "MovingAverage.h"

int main()
{
    WAVInfo info;
    char file_in[] = "input.wav";
    char file_out[] = "output.wav";

    int* sig_in_int;
    float* sig_in_float;
    float* sig_out_float;
    int* sig_out_int;

    // 0.1 Чтение WAV
    sig_in_int = wavread(file_in, info);

    // 0.2 Выделение памяти и преобразование в float
    sig_in_float = (float*)malloc(info.NumberOfSamples * sizeof(float));
    sig_out_float = (float*)malloc(info.NumberOfSamples * sizeof(float));
    memset(sig_in_float, 0, info.NumberOfSamples * sizeof(float));
    memset(sig_out_float, 0, info.NumberOfSamples * sizeof(float));

    for (int i = 0; i < info.NumberOfSamples; i++) {
        sig_in_float[i] = (float)(sig_in_int[i]) / 32768;
    }

    // 1.0 Применяем фильтр скользящего среднего
    MovingAverage filter(15); // N = 15
    filter.apply(sig_in_float, sig_out_float, info.NumberOfSamples);

    // 2.0 Преобразование float -> int
    sig_out_int = (int*)malloc(info.NumberOfSamples * sizeof(int));
    for (int i = 0; i < info.NumberOfSamples; i++) {
        sig_out_int[i] = (int)(sig_out_float[i] * 32768);
    }

    // 2.1 Запись результата в WAV
    wavwrite(file_out, info, sig_out_int);

    // Очистка памяти
    delete[] sig_in_int;
    delete[] sig_out_int;
    delete[] sig_in_float;
    delete[] sig_out_float;

    printf("Done. Press any key...\n");
    system("pause");
    return 0;
}
