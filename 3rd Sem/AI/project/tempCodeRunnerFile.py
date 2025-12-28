import random
import math

# Step 1: City coordinates (x,y positions)
cities = [(0,0), (1,5), (5,2), (6,6), (8,3)]

# Step 2: Calculate distance between two cities
def distance(city1, city2):
    x1, y1 = city1
    x2, y2 = city2
    return math.sqrt((x1-x2)**2 + (y1-y2)**2)

# Step 3: One tour = list of city order [0,2,1,3,4]
class Tour:
    def __init__(self, order):
        self.order = order[:]  # copy the list
        self.distance = 0      # total distance will be calculated later
    
    def calc_distance(self):
        total = 0
        n = len(self.order)
        for i in range(n):
            # Distance between city i and next city
            total += distance(cities[self.order[i]], cities[self.order[(i+1)%n]])
        self.distance = total
        return total

# Step 4: Create random population (50 random tours)
def create_population(size):
    population = []
    for _ in range(size):
        order = list(range(len(cities)))  # [0,1,2,3,4]
        random.shuffle(order)             # shuffle to random order
        population.append(Tour(order))
    return population

# Step 5: Tournament selection (pick best from 3 random tours)
def select_parent(population):
    tournament = random.sample(population, 3)  # pick 3 random tours
    return min(tournament, key=lambda t: t.distance)  # return shortest

# Step 6: Simple crossover (mix two parents)
def crossover(parent1, parent2):
    start = random.randint(0, len(cities)-3)
    end = start + 2
    
    # Child gets segment from parent1
    child_order = [-1] * len(cities)
    for i in range(start, end+1):
        child_order[i] = parent1.order[i]
    
    # Fill rest from parent2 (avoid duplicates)
    for i in range(len(cities)):
        if child_order[i] == -1 and parent2.order[i] not in child_order:
            child_order[i] = parent2.order[i]
    
    # Fill any remaining spots
    remaining = [city for city in parent2.order if city not in child_order]
    j = 0
    for i in range(len(cities)):
        if child_order[i] == -1:
            child_order[i] = remaining[j]
            j += 1
    
    return Tour(child_order)

# Step 7: Swap mutation (swap 2 cities with 10% chance)
def mutate(tour, rate=0.1):
    if random.random() < rate:
        i, j = random.sample(range(len(tour.order)), 2)
        tour.order[i], tour.order[j] = tour.order[j], tour.order[i]

# Step 8: Main Genetic Algorithm
def genetic_algorithm():
    population = create_population(50)  # 50 random tours
    for tour in population:
        tour.calc_distance()              # calculate distance for all
    
    best_tour = min(population, key=lambda t: t.distance)
    
    for generation in range(100):         # 100 generations
        new_population = []
        
        # Keep best 5 tours (elitism)
        new_population.extend(sorted(population, key=lambda t: t.distance)[:5])
        
        # Create 45 new tours
        while len(new_population) < 50:
            parent1 = select_parent(population)
            parent2 = select_parent(population)
            child = crossover(parent1, parent2)
            mutate(child)
            child.calc_distance()
            new_population.append(child)
        
        population = new_population
        current_best = min(population, key=lambda t: t.distance)
        
        if current_best.distance < best_tour.distance:
            best_tour = current_best
        
        if generation % 20 == 0:
            print(f"Gen {generation}: Best distance = {best_tour.distance:.2f}")
    
    return best_tour

# Run it!
if __name__ == "__main__":
    best = genetic_algorithm()
    print("\n*** BEST TOUR FOUND ***")
    print("Order:", best.order)
    print("Cities:", [cities[i] for i in best.order])
    print("Total distance:", best.distance)
