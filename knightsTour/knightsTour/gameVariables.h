/*
================= psuedo code ===================
findKnightsTour
If move (i.e. x and y values) invalid
return 0
put moveNumber on board
If board is full  <---Base case
print board
return 1
Call findKnightsTour 8 more times with the 8 possible moves, and returned result to TotalValidSolutions

return TotalValidSolutions;
*/