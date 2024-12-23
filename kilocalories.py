# Вводим вес и рост
def cal_bmi(weight, height):
    height_m = height / 100  # Преобразуем см в метры
    bmi = weight / (height_m ** 2)
    return bmi


# Расчёт нормального веса
def calc_target_weight(height_m):
    # Рассчитываем нормальный вес по индексу массы тела (ИМТ) 18.5 - 24.9
    min_weight = 18.5 * (height_m / 100) ** 2
    max_weight = 24.9 * (height_m / 100) ** 2
    return min_weight, max_weight


def calculate_caloric(weight, target_weight):
    caloric_difference = (target_weight - weight) * 7700  # 7700 ккал = 1 кг
    return caloric_difference


def main():
    print("Добро пожаловать в калькулятор килакалорий для достижения нормального веса!")

    weight = float(input("Введите ваш вес (в кг): "))
    height = float(input("Введите ваш рост (в см): "))
    age = int(input("Введите ваш возраст (в годах): "))

    bmi = cal_bmi(weight, height)
    min_weight, max_weight = calc_target_weight(height)

    print(f"Ваш ИМТ: {bmi:.2f}")
    print(f"Нормальный вес для вашего роста: от {min_weight:.2f} до {max_weight:.2f} кг")

    if weight < min_weight:
        caloric_need = calculate_caloric(weight, min_weight)
        print(f"Для достижения нормального веса вам нужно набрать {caloric_need:.2f} ккал.")
    elif weight > max_weight:
        caloric_need = calculate_caloric(weight, max_weight)
        print(f"Для достижения нормального веса вам нужно сбросить {abs(caloric_need):.2f} ккал.")
    else:
        print("Вы уже находитесь в нормальном весе!")

    if weight < min_weight:
        caloric_need = calculate_caloric(weight, min_weight)
        print(f"Или нужно набрать {caloric_need * 0.00013:.2f} килограмм.")
    elif weight > max_weight:
        caloric_need = calculate_caloric(weight, max_weight)
        print(f"Или нужно сбросить {caloric_need * 0.00013 * (-1):.2f} килограмм.")
    else:
        print("")


if __name__ == "__main__":
    main()
