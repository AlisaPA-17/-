#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double cal_bmi(double weight, double height) {
    double height_m = height / 100;  // Convert cm to meters
    double bmi = weight / pow(height_m, 2);
    return bmi;
}

// Calculate target weight
pair<double, double> calc_target_weight(double height_m) {
    // Calculate normal weight based on BMI index (18.5 - 24.9)
    double min_weight = 18.5 * pow(height_m / 100, 2);
    double max_weight = 24.9 * pow(height_m / 100, 2);
    return make_pair(min_weight, max_weight);
}

double calculate_caloric(double weight, double target_weight) {
    double caloric_difference = (target_weight - weight) * 7700;  // 7700 kcal = 1 kg
    return caloric_difference;
}

int main() {
    cout << "Добро пожаловать в калькулятор килакалорий для достижения нормального веса!" << endl;

    double weight, height;
    int age;

    cout << "Введите ваш вес (в кг): ";
    cin >> weight;
    cout << "Введите ваш рост (в см): ";
    cin >> height;
    cout << "Введите ваш возраст (в годах): ";
    cin >> age;

    double bmi = cal_bmi(weight, height);
    auto [min_weight, max_weight] = calc_target_weight(height);

    cout << fixed << setprecision(2);
    cout << "Ваш ИМТ: " << bmi << endl;
    cout << "Нормальный вес для вашего роста: от " << min_weight << " до " << max_weight << " кг" << endl;

    if (weight < min_weight) {
        double caloric_need = calculate_caloric(weight, min_weight);
        cout << "Для достижения нормального веса вам нужно набрать " << caloric_need << " ккал." << endl;
    } else if (weight > max_weight) {
        double caloric_need = calculate_caloric(weight, max_weight);
        cout << "Для достижения нормального веса вам нужно сбросить " << abs(caloric_need) << " ккал." << endl;
    } else {
        cout << "Вы уже находитесь в нормальном весе!" << endl;
    }

    if (weight < min_weight) {
        double caloric_need = calculate_caloric(weight, min_weight);
        cout << "Или нужно набрать " << caloric_need * 0.00013 << " килограмм." << endl;
    } else if (weight > max_weight) {
        double caloric_need = calculate_caloric(weight, max_weight);
        cout << "Или нужно сбросить " << caloric_need * 0.00013 * (-1) << " килограмм." << endl;
    } else {
        cout << "" << endl;
    }

    return 0;
}

