# CS220 - Data Structures
## Waiting Line Simulation
### Description

For this assignment, you will use a queue to simulate a line of people at a popular restaurant chain - McMarty's. How does McMarty's know when to add cashiers to help cut down on the wait time? How do they know when there are too many cashiers, and those extra cashiers could be better used elsewhere?

One way to tackle this problem is to guess/check In Real Life™. This is an expensive and difficult way to find a solution, because it is slow, and the results may not always be representative due to so many environmental factors.

The easier way to tackle this problem is to write a simulation. Queues are an excellent fit for this sim, because a queuing system's objective is to utilize resources as fully as possibly, while keeping the wait time at an acceptable level.

### Simulation Algorithm

In this simulation, consider the following:

    There is one check-out line
    It takes one minute to serve a customer (but they may have to wait in line before being served)
    A random number of customers - between 0 and 2 - joins the line every minute

The random number, k, will be a number between 0-3.

    If k is 1, one customer is added to the line
    If k is 2, two customers will be added to the line
    If k is 0 or 3, no customers are added to the line

Our simulation will track:

    The total number of customers that McMarty's serves
    The total wait time - cumulative - of all McMarty's customers
    The longest wait time that any one customer encountered.

### Example Simulation

See the assignment on Moodle for an example simulation.

