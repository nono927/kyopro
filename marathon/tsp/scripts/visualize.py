import matplotlib.pyplot as plt

# visualize route
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