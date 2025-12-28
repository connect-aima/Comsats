import random
import math

# Step 1: Take user input for cities
cities = {}
num_cities = int(input("Enter number of cities: "))

for i in range(num_cities):
    coords = input(f"Enter x and y coordinates for city {i} separated by space: ").split()
    x, y = float(coords[0]), float(coords[1])
    cities[i] = (x, y)

print("\nCities entered:", cities)

# Step 2: Calculate distance between two cities
def distance(city1, city2):
    x1, y1 = city1
    x2, y2 = city2
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


class Tour:
    def __init__(self, order):
        self.order = order[:] 
        self.distance = 0      

    def calc_distance(self):
        total = 0
        n = len(self.order)
        for i in range(n):
            total += distance(cities[self.order[i]], cities[self.order[(i + 1) % n]])
        self.distance = total
        return total


def create_population(size):
    population = []
    for _ in range(size):
        order = list(cities.keys())  
        random.shuffle(order)
        population.append(Tour(order))
    return population

# Step 5: Tournament selection
def select_parent(population):
    tournament = random.sample(population, 3)
    return min(tournament, key=lambda t: t.distance)

# Step 6: Crossover
def crossover(parent1, parent2):
    start = random.randint(0, len(cities) - 3)
    end = start + 2

    child_order = [-1] * len(cities)
    for i in range(start, end + 1):
        child_order[i] = parent1.order[i]

    for i in range(len(cities)):
        if child_order[i] == -1 and parent2.order[i] not in child_order:
            child_order[i] = parent2.order[i]

    remaining = [city for city in parent2.order if city not in child_order]
    j = 0
    for i in range(len(cities)):
        if child_order[i] == -1:
            child_order[i] = remaining[j]
            j += 1

    return Tour(child_order)

# Step 7: Mutation
def mutate(tour, rate=0.1):
    if random.random() < rate:
        i, j = random.sample(range(len(tour.order)), 2)
        tour.order[i], tour.order[j] = tour.order[j], tour.order[i]

# Step 8: Main Genetic Algorithm
def genetic_algorithm():
    population = create_population(50)
    for tour in population:
        tour.calc_distance()

    best_tour = min(population, key=lambda t: t.distance)

    for generation in range(100):
        new_population = []

        new_population.extend(sorted(population, key=lambda t: t.distance)[:5])

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

# Run the algorithm
if __name__ == "__main__":
    best = genetic_algorithm()
    print("\n*** BEST TOUR FOUND ***")
    print("Order of cities:", best.order)
    print("Coordinates of cities in order:", [cities[i] for i in best.order])
    print("Total distance:", best.distance)
