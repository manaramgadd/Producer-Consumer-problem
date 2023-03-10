# Producer-Consumer-problem
It is required to implement the Bounded-Buffer Producer/Consumer problem as learnt in the 
lectures. You may have up to 20 producers. Each Producer would declare the live price of a commodity 
(e.g., GOLD, SILVER, CRUDEOIL, COTTON, β¦). One Consumer would show a dashboard for the prices of all 
commodities. Producers and Consumer would run indefinitely sharing the prices through shared memory.
# Producers
Each producer is supposed to continuously declare the price of one commodity. For simplicity, we assume 
that each commodity price follows a normal distribution with parameters (π, π2). Therefore, producers 
will generate a new random price, share it with the consumer, and then sleep for an interval before 
producing the next price.
All producers are processes running the same codebase. Producers are to be run concurrently, either in 
separate terminals, or in the background. While running a producer, you will specify the following 
command line arguments:
β’ Commodity name (e.g., GOLD β Assume no more than 10 characters.)
β’ Commodity Price Mean; π β a double value.
β’ Commodity Price Standard Deviation; π β a double value.
β’ Length of the sleep interval in milliseconds; T β an integer. 
β’ Bounded-Buffer Size (number of entries); N β an integer.
Therefore, the command β./producer NATURALGAS 7.1 0.5 200 40β would run a producer that declares 
the current price of Natural Gas every 200ms according to a normal distribution with parameters 
(mean=0.5 and variance=0.25). The size of the shared bounded buffer is 40 entries.
Let the producer log what he does by writing to stderr.

# Consumer
The consumer is to print the current price of each commodity, along the average of the current and past 
4 readings. An Up/Down arrow to show whether the current Price (AvgPrice) got increased or decreased 
from the prior one. Until you receive current prices, use 0.00 for the current price of any commodity.
For simplicity, letβs limit the commodities to GOLD, SILVER, CRUDEOIL, NATURALGAS, ALUMINIUM, 
COPPER, NICKEL, LEAD, ZINC, MENTHAOIL, and COTTON. Show the commodities in alphabetical order.
While running the consumer, you will specify the following command line argument:
β’ Bounded-Buffer Size (number of entries); N β an integer.
# Below is an example output.
+-------------------------------------+

| Currency | Price | AvgPrice |

+-------------------------------------+

| ALUMINIUM | 0.00 | 0.00 |

| COPPER | 0.00 | 0.00 |

| ... |

| GOLD | 1810.31β | 1815.25β |

| ... |

| SILVER | 22.36β | 22.80β |

| ZINC | 0.00 | 0.00 |

+-------------------------------------+
