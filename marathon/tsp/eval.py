import subprocess
import os
import argparse
import glob

from scripts.io import *
from scripts.visualize import *
from scripts.score import *

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--testtype", type=str, default="small")
    args = parser.parse_args()

    dirname = os.path.join("testcases", args.testtype)
    num_testcases = len(glob.glob(os.path.join(dirname, "case*")))

    outdir = os.path.join("results", args.testtype)
    if not os.path.isdir(outdir):
        os.makedirs(outdir)

    with open(os.path.join(outdir, "log.txt"), "w") as f:
        sum_score = 0
        for i in range(10):
            case_name = os.path.join(dirname, "case{}.txt".format(i))
            out_name = os.path.join(outdir, "result{}.txt".format(i))
            subprocess.run(["build/main", case_name, out_name])

            xs, ys = read_testcase(case_name)
            ps = read_result(out_name, len(xs))
            save_path = os.path.join(outdir, "route{}.png".format(i))

            visualize_route(xs, ys, ps, save_path)
            score = calc_score(xs, ys, ps)
            sum_score += score
            f.write("case{} : score = {}\n".format(i, score))
        f.write("average = {}".format(sum_score / num_testcases))