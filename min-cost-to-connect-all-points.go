package main

import "sort"

type UnionFind struct {
	parent []int
	size   []int
}

// Initialize a new Union-Find data structure with 'n' elements.
func NewUnionFind(n int) *UnionFind {
	uf := UnionFind{
		parent: make([]int, n),
		size:   make([]int, n),
	}
	for i := 0; i < n; i++ {
		uf.parent[i] = i // Each element is its own parent initially
		uf.size[i] = 1   // Each set has a size of 1 initially
	}
	return &uf
}

// Find the root (leader) of the set to which 'x' belongs.
func (uf *UnionFind) Find(x int) int {
	if uf.parent[x] != x {
		uf.parent[x] = uf.Find(uf.parent[x]) // Path compression
	}
	return uf.parent[x]
}

// Union the sets containing 'x' and 'y'.
func (uf *UnionFind) Union(x, y int) {
	rootX := uf.Find(x)
	rootY := uf.Find(y)

	if rootX != rootY {
		// Attach the smaller set to the larger set to keep the tree balanced.
		if uf.size[rootX] < uf.size[rootY] {
			uf.parent[rootX] = rootY
			uf.size[rootY] += uf.size[rootX]
		} else {
			uf.parent[rootY] = rootX
			uf.size[rootX] += uf.size[rootY]
		}
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func minCostConnectPoints(points [][]int) int {
	n := len(points)
	edges := make([][]int, 0)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			dist := abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])
			edges = append(edges, []int{i, j, dist})
		}
	}
	sort.Slice(edges, func(i, j int) bool {
		return edges[i][2] < edges[j][2]
	})

	uf := NewUnionFind(n)
	res := 0
	for _, edge := range edges {
		if uf.Find(edge[0]) != uf.Find(edge[1]) {
			uf.Union(edge[0], edge[1])
			res += edge[2]
		}
	}
	return res
}
