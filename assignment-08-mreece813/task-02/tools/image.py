import argparse

import matplotlib.pyplot as plt
import numpy as np


def parse_inputs():
    parser = argparse.ArgumentParser()
    parser.add_argument('fractal_data', type=argparse.FileType('rb'))
    parser.add_argument('output')
    return parser.parse_args()


def run():
    inputs = parse_inputs()

    width = np.fromfile(inputs.fractal_data, dtype=np.dtype('<i4'), count=1)[0]
    height = np.fromfile(inputs.fractal_data, dtype=np.dtype('<i4'), count=1)[0]
    data = np.fromfile(inputs.fractal_data, dtype=np.dtype('<i4')).reshape((width, height))

    plt.imshow(data)
    plt.savefig(inputs.output)


if __name__ == '__main__':
    run()
