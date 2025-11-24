graph = {}  


n = int(input("Enter number of nodes: "))

for i in range(n):
    node = input(f"Enter node {i+1} name: ")     
    neighbors = input(f"Enter neighbors of {node} (comma separated): ")  
   
    if neighbors.strip() == "":
        graph[node] = []
    else:
        graph[node] = neighbors.split(",")

print("\nGraph dictionary = ", graph)