def func(arr, dim, num, constant):
    result = [-1] * dim
    i = 0
    while i < num:
        try_num = 0
        while True:
            h = (arr[i] % dim + constant * try_num) % dim
            if result[h] == -1 or result[h] == arr[i]:
                result[h] = arr[i]
                break
            try_num += 1
        i += 1
    return result


arR = []
dime = 0
constantt = 0
numm = 0
with open('input.txt') as FileObj:
    indexx = 0
    for line in FileObj:
        if indexx == 0:
            dime = int(line.split(" ")[0])
            constantt = int(line.split(" ")[1])
            numm = int(line.split(" ")[2])
            arR = [0]*numm
        else:
            arR[indexx - 1] = (int(line))
        indexx += 1
out = open('output.txt', 'w')
res = func(arR, dime, numm, constantt)
k = 0
while k < dime:
    out.write("%d " % res[k])
    k += 1
out.close()
