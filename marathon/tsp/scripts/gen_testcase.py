import numpy as np

# generate n nodes in 2D plain
# the size of plain is h x w
def gen_tsp_testcase(filename, n, h, w=None):
    if w is None:
        w = h
    assert(h > 0)
    assert(w > 0)
    assert(n <= h * w)

    points = np.arange(h * w)
    np.random.shuffle(points)

    with open(filename, "w") as f:
        f.write("%d\n" % n)
        for p in points[0:n]:
            f.write("%d %d\n" % (p // w, p % w))
