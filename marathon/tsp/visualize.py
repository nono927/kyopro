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

def visualize_path(xs, ys, path):
    assert(len(xs) == len(ys))
    assert(len(xs) == len(path))

    plt.scatter(xs, ys)
    for i in range(len(xs)):
        plt.annotate(i, xy=(xs[i], ys[i]))
        plt.plot([xs[i-1], xs[i], xs[i]], [ys[i-1], ys[i-1], ys[i]])
    plt.show()

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--testcase", type=str)
    parser.add_argument("--result", type=str)
    args = parser.parse_args()

    xs, ys = read_testcase(args.testcase)
    path = read_result(args.result, len(xs))
    visualize_path(xs, ys, path)
