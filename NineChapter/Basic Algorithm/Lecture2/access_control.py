# coding=utf-8


class Student:

    def __init__(self, name='', score=0):
        self.name = name
        self.__score = score
        self.speak()

    def speak(self):
        print(self.name, self.__score)

    def set_score(self, score):
        self.__score = score

    def get_score(self):
        return self.__score


if __name__ == '__main__':
    stu_1 = Student('Jack', 10)
    print(stu_1.get_score())

