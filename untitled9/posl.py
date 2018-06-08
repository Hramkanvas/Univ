ar_reb = []
result = []
with open('input.txt') as FileObj:
    indexx = 0
    for line in FileObj:
        if indexx == 0:
            n_ver = int(line.split(" ")[0])
            result = [0] * n_ver
        else:
            li = line.split(" ")
            result[int(li[0]) - 1] += 1
            result[int(li[1]) - 1] += 1
        indexx += 1


def reverse_numeric(x, y):
    return y - x


result = sorted(result, cmp=reverse_numeric)
out = file("output.txt", "w")

out.write(' '.join(map(str,result)))
out.close()
