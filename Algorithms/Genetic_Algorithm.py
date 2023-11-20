import numpy as np

# Define the target function
def fitness_function(x):
    return 2 * x ** 2 + 5

# Genetic Algorithm Parameters
population_size = 100
mutation_rate = 0.1
generations = 50

# Initialize population
population = np.random.uniform(-10, 10, population_size)

# Main loop
for generation in range(generations):
    # Calculate fitness for each individual in the population
    fitness_scores = [fitness_function(ind) for ind in population]

    # Select the top-performing individuals (parents)
    selected_indices = np.argsort(fitness_scores)[:int(population_size/2)]
    parents = population[selected_indices]

    # Create offspring through crossover
    offspring = np.concatenate([np.random.choice(parents, 2) for _ in range(population_size - len(parents))])

    # Apply mutation
    mutation_mask = np.random.rand(population_size) < mutation_rate
    offspring += mutation_mask * np.random.uniform(-1, 1, population_size)

    # Replace the old population with the new generation
    population = np.concatenate([parents, offspring])

# Find the best solution in the final population
best_solution = population[np.argmin([fitness_function(ind) for ind in population])]

print("Best solution:", best_solution)
print("Minimum value:", fitness_function(best_solution))
