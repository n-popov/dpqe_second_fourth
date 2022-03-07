import json
from matplotlib import pyplot

if __name__ == '__main__':
    X, Y = zip(*json.loads(open('data.json').read()).items())
    X = tuple(map(int, X))
    print(X)
    print(Y)
    pyplot.plot(X, Y)
    pyplot.savefig('chart.png')