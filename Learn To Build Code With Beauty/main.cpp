#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define TEMPERATURE_SENSOR 1
#define HUMIDITY_SENSOR 2
#define SENSOR_NUM 2

int simpleValue[SENSOR_NUM] = {0};
const int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int temperatureValue = 0;
int humidityValue = 0;

void init_Sample();
int sample_Sensor_Value(int);
int day_Of_Month(int);
void show();

void init_Sample() {
    temperatureValue = 0;
    humidityValue = 0;
}
int sample_Sensor_Value(int sensor_Code) {
    srand(time(0));
    switch (sensor_Code)
    {
    case TEMPERATURE_SENSOR:
        return (1 + rand() % 30);
        break;
    case HUMIDITY_SENSOR:
        return (rand() % 101);
        break;
    default:
        cout << "Sensor value is not accessible" << endl;
        break;
    }
}
int day_Of_Month(int month) {
    return dayOfMonth[month];
} 
void show(int sensor_Code) {
    cout << simpleValue[sensor_Code];
}

int main () {
    int insert_Month;

    init_Sample();

    cout << "__________本月温度湿度历史纪录__________" << endl;
    cout << "输入月份: ";
    cin >> insert_Month;
    for (int i = 1; i <= day_Of_Month(insert_Month); i++) {
        for (int j = 0; j < SENSOR_NUM; j++)
        simpleValue[j] = sample_Sensor_Value(j);
        cout << "第 " << i << " 天" << endl;
        cout << "温度: "; show(TEMPERATURE_SENSOR); cout << "摄氏度" << endl;
        cout << "湿度: "; show(HUMIDITY_SENSOR); cout << " %" << endl << endl;
    }
}