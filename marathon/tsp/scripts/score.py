# calculate score
def calc_score(xs, ys, ps):
    score = 0
    for i, p in enumerate(ps):
        v = ps[i-1]
        score += abs(xs[p] - xs[v]) + abs(ys[p] - ys[v])
    return score