import os
import argparse
import numpy as np
import matplotlib.pyplot as plt

def read_testcase(filename):
    xs, ys = [], []
    with open(filename, "r") as f:
        n = int(f.readline())
        points = f.read().split("\n")
        for i, p in enumerate(points):
            if i >= n:
                break
            x, y = p.split(" ")
            xs.append(int(x))
            ys.append(int(y))
    return xs, ys

def read_result(filename, n):
    ret = []
    with open(filename, "r") as f:
        dat = f.read().split("\n")
        for i, x in enumerate(dat):
            if i >= n:
                break
            ret.append(int(x))
    return ret

def visualize_route(xs, ys, ps, save_path):
    assert(len(xs) == len(ys))
    assert(len(xs) == len(ps))

    plt.figure()
    plt.scatter(xs, ys)
    for i in range(len(xs)):
        plt.annotate(i, xy=(xs[i], ys[i]))
    for i, p in enumerate(ps):
        v = ps[i-1]
        plt.plot([xs[v], xs[v], xs[p]], [ys[v], ys[p], ys[p]])
    plt.savefig(save_path)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--testcase", type=str)
    parser.add_argument("--result", type=str)
    parser.add_argument("--save_path", type=str)
    args = parser.parse_args()

    xs, ys = read_testcase(args.testcase)
    ps = read_result(args.result, len(xs))
    visualize_path(xs, ys, ps, args.save_path)
