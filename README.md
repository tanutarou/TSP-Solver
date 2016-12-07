# TSP-Solver
Traveling Salesman Problem Solver

実装:brute force,動的計画法

## Compile

```
make
```

## Usage

```
make_input > input
10 #ノード数を入力(20が限界)

tsp < input > output #outputに経路と最適コスト出力

python visualizer.py #経路の可視化
```

inputの２行目を"dp"から"brute"に変えることで、brute forceでの実行可能

