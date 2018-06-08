def func(ar, dim):
    _visit = [False] * dim
    _markD = [0] * dim
    _markI = [-1]*dim
    _global_index = [0]

    def dfs(ind, _dol):
        _visit[ind] = True
        _markI[ind] = _global_index[0]
        _global_index[0] += 1
        if _dol == 1:
            _markD[ind] = 2
            _dol = 2
        else:
            _markD[ind] = 1
            _dol = 1
        jndex = 0
        while jndex < dim:
            if ar[ind][jndex] == 0 and _visit[jndex] and ind != jndex:
                if _markD[ind] == _markD[jndex]:
                    return -1
            if ar[ind][jndex] == 0 and not _visit[jndex] and ind != jndex:
                dfs(jndex, _dol)
            jndex += 1
        return 0

    while _visit.count(False) != 0:
        index = _visit.index(False)
        _global_index = dfs(index, 1)
    return _markD


arR = []
dime = 0
with open('input.txt') as FileObj:
    indexx = 0
    for line in FileObj:
        if indexx == 0:
            dime = int(line.split(" ")[0])
        else:
            arr = map(int, line.split(" "))
            arR.append(arr)
        indexx += 1
out = open('output.txt', 'w')
res = func(arR, dime)
for it in res:
    out.write("%d " % it)
out.close()