import os
import yaml
import argparse
import numpy as np

from scripts.gen_testcase import gen_tsp_testcase

testcase_root_dir = "testcases"

def gen_testcases(testname, num_nodes, num_cases, h, w):
    dirname = os.path.join(testcase_root_dir, testname)
    if not os.path.isdir(dirname):
        os.makedirs(dirname)
    for i in range(num_cases):
        fname = os.path.join(dirname, "case{}.txt".format(i))
        gen_tsp_testcase(fname, num_nodes, h, w)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--seed", type=int, default=1)
    args = parser.parse_args()

    np.random.seed(seed=args.seed)

    with open("config.yml", "r") as f:
        config = yaml.safe_load(f)

    for testname in config["testcases"]:
        cfg = config["testcases"][testname]
        gen_testcases(testname, cfg["num_nodes"], cfg["num_cases"], cfg["height"], cfg["width"])
