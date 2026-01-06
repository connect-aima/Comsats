Graph is basically a network of nodes and edges and is a non-hierarchical data structure.
Nodes are also called vertices, and the connections between them are called edges.
We can move from one node to another through these edges.
Graphs can be directed or undirected, weighted or unweighted, and cycles may exist or not depending on the type of graph.
Major applications of graphs include social networks, maps and navigation, computer networks, recommendation systems, web page ranking, AI search algorithms, dependency analysis, and routing problems.

Types of Graph Based on Edges (All Possible Combinations)

### **1. Directed Unweighted Graph**

Edges have **direction**, no weights.
You can go from one node to another in **one-way only**.

**Example:**
A → B → C
Here A to B is allowed, but B to A is not.

---

### **2. Directed Weighted Graph**

Edges have **direction** and also **weights** (cost, distance, time).

**Example:**
A → B (5)
B → C (2)
A → C (10)

Means you can go one-way and each edge has its own value.

---

### **3. Undirected Unweighted Graph**

Edges have **no direction** and **no weight**.
Connection is **two-way** automatically.

**Example:**
A — B — C
A — B means you can go both A↔B.

---

### **4. Undirected Weighted Graph**

Edges have **no direction**, but every edge has a **weight**.

**Example:**
A — B (10)
B — C (3)

Means A and B are connected both ways, with weight 10.

---

# **Connected and Non-Connected Graph**

### **Connected Graph**

All nodes are joined somehow; you can reach any node from any other node.

**Example:**
A — B — C — D
Every node is connected.

---

### **Disconnected Graph**

Graph is broken into pieces; some nodes cannot reach others.

**Example:**
A — B      C — D
Two separate parts.


