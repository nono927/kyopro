import os
import random
import argparse
import numpy as np

# generate testcase
# type of each element is str

def gen_vector(n, vmin, vmax):
    ret = []
    vals = np.random.randint(vmin, vmax, n)
    for val in vals:
        ret.append(str(val))
    return ret

def gen_string(n, is_uppercase=False):
    ret = str()
    a = ord('A') if is_uppercase else ord('a')
    vals = np.random.randint(0, 26, n)
    for val in vals:
        ret += chr(a + val)
    return ret

def gen_tree(n):
    a = np.arange(1, n+1)
    np.random.shuffle(a)
    ret = []
    for i in range(1, n):
        u = a[i]
        par = a[np.random.randint(0, i)]
        if np.random.rand() < 0.5:
            ret.append([str(u), str(par)])
        else:
            ret.append([str(par), str(u)])
    np.random.shuffle(ret)
    return ret

# write to file

def write_int(f, n):
    f.write(str(n))
    f.write("\n")

def write_rand_vector(f, n, vmin, vmax):
    v = gen_vector(n, vmin, vmax)
    f.write(" ".join(v))
    f.write("\n")

def write_rand_string(f, n, is_uppercase=False):
    s = gen_string(n, is_uppercase)
    f.write(s)
    f.write("\n")

def write_rand_tree(f, n):
    es = gen_tree(n)
    for e in es:
        f.write(" ".join(e))
        f.write("\n")

# main
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--num_cases", type=int, default=1)
    parser.add_argument("--dirname", type=str, default="testcases")
    parser.add_argument("--seed", type=int, default=1)
    args = parser.parse_args()

    np.random.seed(seed=args.seed)
    if not os.path.isdir(args.dirname):
        os.makedirs(args.dirname)

    for i in range(args.num_cases):
        fname = os.path.join(args.dirname, "case{}.txt".format(i))
        with open(fname, "w") as f:
            n = np.random.randint(5, 20)
            write_int(f, n)
            write_rand_vector(f, n, 1, 100)

