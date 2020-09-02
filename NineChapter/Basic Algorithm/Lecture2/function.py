# coding=utf-8


def find_number(nums, target):
    for num in nums:
        if num == target:
            return True

    return False


def get_grade(score):
    if score >= 85:
        return 'A'
    elif score >= 75:
        return 'B'
    elif score >= 60:
        return 'C'
    else:
        return 'D'


def simple_print():
    print('I am a function')


def sum(a, b):
    return a + b


def swap(num1, num2):
    num1, num2 = num2, num1
    return num1, num2


if __name__ == '__main__':

    score = 78
    grade = get_grade(score)

    print(sum(10, 22))

    num1 = 10
    num2 = 20
    num1, num2 = swap(num1, num2)

    print(num1, num2)


    num_of_days = 7

    # 10, 20
    # 20, 10
    # num1 = ...
    # num2 = ...
