import matplotlib.pyplot as plt
import numpy as np


def main():
    with open("output.txt", "r") as f:
        label = f.readline()[:-1]
        data = np.array(list(map(float, f.readline().split())))
    if label == "Metropolis":
        # N(0, 1)っぽいはず
        plt.hist(data, bins=100)
    elif label == "Gibbs":
        # 楕円になるはず
        plt.scatter(data[::2], data[1::2])
    elif label == "Ising":
        # 相転移が見えるはず
        plt.plot(data[::2], data[1::2])
    else:
        raise ValueError(f"{label} is not supported")
    plt.show()


if __name__ == "__main__":
    main()
