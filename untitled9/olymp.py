import Queue as Q


def func(ar, _dim):
    _q = Q.Queue()
    _visit = [False] * _dim
    _index = _visit.index(False)
    _q.put(_index)
    while not _q.empty():
        _index = _q.get()
        _visit[_index] = True
        jndex = 0
        while jndex < _dim:
            if ar[_index][jndex] == 1 and not _visit[jndex]:
                _q.put(jndex)
                _visit[jndex] = True
            jndex += 1
    return 'YES' if _visit.count(False) == 0 else 'NO'


matrix = []
dim = 0
with open('input.in') as FileObj:
    index = 0
    for line in FileObj:
        if index == 0:
            dim = int(line.split(" ")[0])
            matrix = [0] * dim
        else:
            li = map(int, line.split(" "))
            matrix[index - 1] = li
        index += 1

out = file("output.out", "w")
out.write(func(matrix, dim))
out.close()
