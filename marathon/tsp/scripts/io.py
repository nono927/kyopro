# read testcase
# expected format is as follows:
#   n
#   x1 y1
#   :
#   xn, yn
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

# read result
# expected format is as follows:
#   p1
#   :
#   pn
def read_result(filename, n):
    ret = []
    with open(filename, "r") as f:
        dat = f.read().split("\n")
        for i, x in enumerate(dat):
            if i >= n:
                break
            ret.append(int(x))
    return ret