# coding=utf-8

# Array or Matrix and Loop
scores = [90, 95, 92, 89, 100, 91]

my_score = scores[0]
scores[0] = 100


# [100, 95, 92, 89, 100, 91]
# for score in scores:
#     print(score)
#
# for i in range(len(scores)):
#     print(scores[i])

# for (i, score) in enumerate(scores):
#     print(i, score)

target = 89
found = False

for score in scores:
    if score == target:
        found = True
        break


scores = [50, 95, 43, 89, 100, 91]

for score in scores:
    if score < 60:
        continue
    print(score)


i = 0
while i < len(scores):
    print(scores[i])
    i += 1


multi_scores = [[95, 88, 54], [67, 25]]

for scores in multi_scores:
    for score in scores:
        print(score)


for i in range(len(multi_scores)):
    for j in range(len(multi_scores[i])):
        print(multi_scores[i][j])