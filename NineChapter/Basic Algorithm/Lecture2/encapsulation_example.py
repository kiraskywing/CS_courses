# coding=utf-8
from object_oriented_example import Student

if __name__ == '__main__':
    print('Please input the number of students:')
    n = int(input())
    students = []
    for i in range(n):
        print('Please input the name of student ' + str(i + 1))
        name = input()
        print('Please input the score of student ' + str(i + 1))
        score = int(input())
        students.append(Student(name, score))

    print('Input:')
    for student in students:
        student.speak()

    students.sort(key= lambda x: x.score, reverse=True)

    print('Sorted:')
    for student in students:
        student.speak()