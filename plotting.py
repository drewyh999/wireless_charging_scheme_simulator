import matplotlib.pyplot as plt


class coordinates:
    def __init__(self, x_s: list, y_s: list):
        self.x_s = x_s
        self.y_s = y_s


class edge:
    def __init__(self, x_s: list, y_s: list):
        self.x_s = x_s
        self.y_s = y_s


def plot_deployment(graph, placement: coordinates):
    fig, ax = plt.subplots(1, 1)
    ax.plot(placement.x_s, placement.y_s, 'rx', label='charger')
    return ax


def main():
    p = coordinates([1, 2, 3], [2, 3, 4])
    plot_deployment([], p)
    plt.show()


if __name__ == '__main__':
    main()
