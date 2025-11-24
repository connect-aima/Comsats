import numpy as np
import random

def create_8_queens_board():
    queens_board = np.full((8,8), '.')
    print(queens_board)

    # Place queens (represented by 'Q') on the board
    for row in range(0,8):
      col = random.randint(0, 7)
      print(row,col)
      queens_board[row, col] = 'Q'

    return queens_board

def board_chromosome(board):
  queens_positions = np.argwhere(board == 'Q')
  print('Q Positions',queens_positions)

   # Returns columns for all rows in a 2D matrix.
  cols = queens_positions[:, 1]
  print('chromosome', cols)

  return cols


def calculate_fitness_numpy(board):
    # Get the positions of the queens
    queens_positions = np.argwhere(board == 'Q')
    num_queens = len(queens_positions)
    #print(queens_positions)
    #print('num_queens',num_queens)

    # Extract rows and columns
    #rows = queens_positions[:, 0]
    cols = queens_positions[:, 1]

    #print(rows)
    print('cols',cols)
    #print(rows-cols)
    #print(rows+cols)

    #num_queens = 8

    # Count attacking pairs
    # Function to
    unique_cols, counts = np.unique(cols, return_counts=True)
    print('u_count', unique_cols,counts)
    # Apply check to keep only columns that appear exactly once
    # Numpy array indexing example
    unique_only = unique_cols[counts == 1]
    print('unique_only', unique_only)
    #row_attacks = num_queens - len(np.unique(rows))  # Count rows with multiple queens
    col_attacks = num_queens - len(unique_only)  # Count columns with multiple queens
    print(col_attacks)

    # Total attacking pairs
    total_attacks = col_attacks #+ main_diagonal_attacks
    # Fitness is the number of non-attacking queens
    fitness = num_queens - total_attacks
    return fitness


board1 = create_8_queens_board()
c1=board_chromosome(board1)
fb1=calculate_fitness_numpy(board1)
print(board1)
print('Chromosome',c1)
print('Fitness',fb1)

print('-----------------','\n')

board2 = create_8_queens_board()
c2=board_chromosome(board2)
fb2=calculate_fitness_numpy(board2)
print(board2)
print('Chromosome',c2)
print('Fitness',fb2)

print('-----------------')

board3 = create_8_queens_board()
c3=board_chromosome(board3)
fb3=calculate_fitness_numpy(board3)
print(board3)
print('Chromosome',c3)
print('Fitness',fb3)

print('-----------------')

board4 = create_8_queens_board()
c4=board_chromosome(board4)
fb4=calculate_fitness_numpy(board4)
print(board4)
print('Chromosome',c4)
print('Fitness',fb4)
print('-----------------')
def top_two_chromosomes(boards, chromosomes, fitness_values):
    # Combine fitness with corresponding boards and chromosomes
    combined = list(zip(fitness_values, boards, chromosomes))


    # Sort by fitness (ascending, so the smallest fitness comes first)
    sorted_combined = sorted(combined, key=lambda x: x[0])
    #combined.sort(key=lambda x: x[0])
    print('combined',combined)
    print('sorted_combined',sorted_combined)

    # Extract the top two boards and chromosomes based on fitness
    top_two = sorted_combined[-2:]

    return top_two

# Combine all the boards, chromosomes, and fitness values
boards = [board1, board2, board3, board4]
chromosomes = [c1, c2, c3, c4]
fitness_values = [fb1, fb2, fb3, fb4]

# Get the top two chromosomes and boards
top_two = top_two_chromosomes(boards, chromosomes, fitness_values)
print('top_two')
print(top_two)

parent1 = top_two[-1][2]  # Chromosome of the first top board
parent2 = top_two[-2][2]  # Chromosome of the second top board


def single_point_crossover(parent1, parent2):
    # Randomly choose a crossover point
    #crossover_point = np.random.randint(1, len(parent1) - 1)
    crossover_point=4
    print('crossoverpoint',crossover_point)

    # Create offspring by combining parts of parents at the crossover point
    offspring1 = np.concatenate((parent1[:crossover_point], parent2[crossover_point:]))
    offspring2 = np.concatenate((parent2[:crossover_point], parent1[crossover_point:]))

    return offspring1, offspring2

# Example parent chromosomes from your 8-queen boards
#parent1 = np.array([2, 5, 3, 6, 2, 6, 2, 7])  # Fitness 3
#parent2 = np.array([2, 4, 5, 3, 3, 1, 7, 0])  # Fitness 3

# Perform single-point crossover
offspring1, offspring2 = single_point_crossover(parent1, parent2)

print("Parent 1:", parent1)
print("Parent 2:", parent2)
print("Offspring 1:", offspring1)
print("Offspring 2:", offspring2)
