import Queue
import time


def func(ar, dim):
    result = 0
    queue = Queue.PriorityQueue()
    i = 0
    while i < dim:
        queue.put(ar[i])
        i += 1
    i = 0
    while i < dim - 1:
        a = queue.get()
        b = queue.get()
        c = a + b
        result += c
        queue.put(c)
        i += 1
    return result


arR = []
dime = 0
with open('huffman.in') as FileObj:
    indexx = 0
    for line in FileObj:
        if indexx == 0:
            dime = int(line.split(" ")[0])
        else:
            li = line.split(' ')
            arR = map(int, li)
        indexx += 1
out = open('huffman.out', 'w')
t0 = time.clock()
res = func(arR, dime)
print(time.clock())
out.write(str(res))
out.close()

