**The Art Gallery**
by Cullen Watson

**Problem:**
An art gallery has given you a list of paintings with their value and associated dimensions. The goal is to place each picture along one wall of given dimensions so that the placement gives you the highest value of paintings. However, you are only able to place the paintings along the center of the wall, so width is the only factor that determines if there's space left along the wall.

Algorithms used to Solve the Problem:

**BRUTE FORCE ALGORITHM**
This method uses every possible subset of paintings and then determines the total width and value of each subset. If the placement has a width that is less than or equal to the wall and a value greater than the current highest value placement, the new placement is the winner. Continue this process for every subset of the list of paintings.

**MOST VALUABLE FIRST ALGORITHM**
Alternatively to the brute force is the most valuable first algorithm. This sorts the entire list of paintings in descending order of value. It then repeatedly places onto the wall the next highest value painting that will fit. This process continues until there is no more room on the wall.

**SELF-DESIGNED HEURISTIC ALGORITHM**
Due to brute force being a very slow algorithm and most valuable first alogrrithm being very quick, this algorithm is a medium between the two. Instead of repeatedly placing each most valuable piece onto the wall, this algorithm first checks its width. If the width is larger than 1000, it skips onto the next painting. This way we can still have a quick algorithm but also takes into consideration how large the painting is to get more accurate results.

**BUILDING THE PROJECT**
After cloning the repo, navigate to the working directory in the command prompt of the project folder. Once there, create a build folder and navigate to it. Build the program by typing 'cmake ..' and then typing 'make'. Afterwards, to run the exe for Mac/Linux type: './22s_pa01_cullenw ../input/input.txt'. Change the second argument to use your own preferred input file. The 3 output files (one for each algo) will be outputted in the build directory.

**Performance of Each Algo**
The brute force algo was near instant for about 25 paintings. However, with just an increase in 5 paintings, the run time increased to 35 seconds, which makes sense for a O(2^n) time complexity. For that reason, the brute force algorithm will only run if the input file has less than 30 paintings. On the other hand, the two other algos had near instant runtime even up to the max limit of 100,000 paintings, as shown by the flat lines in the graph. In terms of highest value paintings performance, the brute force always won of course. In terms of the custom algo and high value algo, if the input size is fairly large with a large variety of pictures sizes, the custom algo did perform better due to taking into consideration the sizing. However for small datasets, the highest value first algo and custom algo performed similar.


<img width="363" alt="image" src="https://user-images.githubusercontent.com/78247585/153641026-87ccf077-0e11-45bb-a440-092c0ef40814.png">

