artifact_weight = 5
facial_weight = 5

artifact_list = 'TFTFT'
artifact_list = list(artifact_list)
facial_list = 'FFTFT'
facial_list = list(facial_list)
correct_list = 'FTFFT'
correct_list = list(correct_list)

def weight_change(set, weight_list, w1, w2):
    for i in range(len(weight_list)):
        if weight_list[i] == set[i]:
            if w1 == 10:
                w1 += 0
                if w2 == 0:
                    continue
                else:
                    w2 -= 1
            else:
                w1 += 1
                if w2 == 0:
                    continue
                else:
                    w2 -= 1
    for i in range(len(weight_list)):
        if weight_list[i] != set[i]:
            if w1 == 0:
                w1 -= 0
                if w2 == 10:
                    continue
                else:
                    w2 += 1
            else:
                w1 -= 1
                if w2 == 10:
                    continue
                else:
                    w2 += 1
    tuple = (w1, w2)
    return tuple

tuple = weight_change(correct_list, artifact_list, artifact_weight, facial_weight)
artifact_weight = tuple[0]
facial_weight = tuple[1]

tuple = weight_change(correct_list, facial_list, facial_weight, artifact_weight)
facial_weight = tuple[0]
artifact_weight = tuple[1]


print("Artifact Weight:", artifact_weight)
print("Facial Weight:", facial_weight)
