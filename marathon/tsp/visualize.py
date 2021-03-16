import argparse

from scripts.io import *
from scripts.visualize import *

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--testcase", type=str)
    parser.add_argument("--result", type=str)
    parser.add_argument("--save_path", type=str)
    args = parser.parse_args()

    xs, ys = read_testcase(args.testcase)
    ps = read_result(args.result, len(xs))
    visualize_route(xs, ys, ps, args.save_path)
