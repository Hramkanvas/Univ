import random

i = 0
ar = []
while i < 500000:
    i += 1
    ar.append(random.randint(1, 1e9))
ar.sort()
out = open('huffman.in', 'w')
out.write(str(500000) + '\n')
i = 0
while i < 500000:
    out.write("%d " % ar[i])
    i += 1
out.close()
