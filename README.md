**The Art Gallery**
by Cullen Watson

**Problem:**
An art gallery has given you a list of paintings with their value and associated dimensions. The goal is to place each picture along one wall of given dimensions so that the placement gives you the highest value of paintings. However, you are only able to place the paingings along the center of the wall, so width is the only factor that can determine if there's space left along the wall.

Algorithms used to Solve the Problem:

**BRUTE FORCE ALGORITHM**
This method uses every possible subset of paintings and then determines the total width and value of each subset. If the placement has a width that is less than or equal to the wall and a value greater than the current highest value placement, the new placement is the winner. Continue this process for every subset of the list of paintings.

**MOST VALUABLE FIRST ALGORITHM**
Alternatively to the brute force is the most valuable first algorithm. This sorts the total list of paintings on descending order of value. It then repeatedly places onto the wall the next hihghest value painting that will fit. This process continues until there is no more room on the wall.

**SELF-DESIGNED HEURISTIC ALGORITHM**
Due to brute force being a very slow algorithm and most valuable first alogrrithm being very quick, the self-designed algorithm is medium between the two. Instead of repeatedly placing each most valuable piece onto the wall, this algorithm first checks its width. If the width is larger than 1000, it skips onto the next painting. This way we can still have a quick algorithm but takes into consideration how large the painting is to get more accurate results.

**BUILDING THE PROJECT**
After cloning the repo, navigate the working directory of command promppt to the folder where main.cpp is located. Once there, type g++ main.cpp to compile the program. Afterwards, to run type ./(name of executable)
