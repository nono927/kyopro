import os
import argparse
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

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--num_nodes", type=int, default=10)
    parser.add_argument("--num_cases", type=int, default=1)
    parser.add_argument("--dirname", type=str, default="testcase")
    parser.add_argument("--seed", type=int, default=1)
    args = parser.parse_args()

    np.random.seed(seed=args.seed)
    if not os.path.isdir(args.dirname):
        os.makedirs(args.dirname)

    for i in range(args.num_cases):
        fname = os.path.join(args.dirname, "case{}.txt".format(i))
        gen_tsp_testcase(fname, args.num_nodes, 100)

