# coding=utf-8

if __name__ == '__main__':

    print('Please input the number of students:')
    n = int(input())
    names, scores = [], []
    for i in range(n):
        print('Please input the name of student ' + str(i + 1))
        names.append(input())
        print('Please input the score of student ' + str(i + 1))
        scores.append(int(input()))

    print('Input:')
    for i in range(n):
        print(names[i], scores[i])

    for i in range(n):
        max_index = i
        for j in range(i + 1, n):
            if scores[j] > scores[max_index]:
                max_index = j

        scores[i], scores[max_index] = scores[max_index], scores[i]
        names[i], names[max_index] = names[max_index], names[i]

    print('Sorted:')
    for i in range(n):
        print(names[i], scores[i])